import os
import ROOT as r
import numpy as np
import plottery.plottery as ply
import itertools


# basedir = "outputs_2017_Oct31/"
# outdir = "plots_fit_2017_Oct31"
# basedir = "outputs_2018_Oct31/"
# outdir = "plots_fit_2018_Oct31"

# basedir = "outputs_SS_2018/"
# outdir = "plots_mtfit/fit_SS_2018_Nov29"
# basedir = "outputs_SS_2017/"
# outdir = "plots_mtfit/fit_SS_2017_Nov29"

# basedir = "outputs_FT_2017/"
# outdir = "plots_mtfit/fit_FT_2017_Nov29"
# basedir = "outputs_FT_2018/"
# outdir = "plots_mtfit/fit_FT_2018_Nov29"

# basedir = "v25jec6/outputs_SS_2017/"
# outdir = "v25jec6/plots_mtfit/fit_SS_2017_Nov29"
# basedir = "v25jec32/outputs_SS_2017/"
# outdir = "v25jec32/plots_mtfit/fit_SS_2017_Nov29"



def make_plots_info(basedir,outdir,year):
    # basedir = "outputs_test/"
    # outdir = "outputs_test/plots_mtfit/fit_test_19Jan7"
    # year = 2018
    d_postfits = {}
    d_sfs = {}
    def get_fname(proc,iso):
        # return "{}/rate_histos_{}_LooseEMVA{}.root".format(basedir, proc, "_IsoTrigs" if iso else "")
        return "{}/y{}_rate_histos_{}_LooseEMVA{}.root".format(basedir, year, proc, "_IsoTrigs" if iso else "")

    lumi = {"2016":"35.9","2017":"41.5","2018":"58.8"}[str(year)]

    for flavstr,iso,extra,use_postfit,use_inviso_data_template in itertools.product(
            ["el","mu"],
            [True,False],
            ["","mt_"],
            [False,True],
            [False,True],
            ):

        f_dy = r.TFile(get_fname("dy",iso))
        f_wjets = r.TFile(get_fname("wjets",iso))
        f_data = r.TFile(get_fname("data_{}".format(flavstr),iso))
        f_qcd = r.TFile(get_fname("qcd_{}".format(flavstr),iso))
        f_ttjets = r.TFile(get_fname("ttjets",iso))

        do_fit = not any(x in extra for x in ["mt_", "pt_", "met_","dphi_"])
        if "mt_" in extra:
            extra = extra.replace("mt_","")

        histname = "mt_cr_"
        histname_secondary = "mt_cr_noiso_"

        hname = "histo_{}{}{}".format(histname,extra,flavstr)
        hname_inviso = "histo_{}{}{}".format(histname_secondary,extra,flavstr)


        h_dy = f_dy.Get(hname)
        h_wjets = f_wjets.Get(hname)
        h_ttjets = f_ttjets.Get(hname)
        h_data = f_data.Get(hname)
        if use_inviso_data_template:
            h_qcd_template = f_data.Get(hname_inviso)
        else:
            h_qcd_template = f_qcd.Get(hname)
        h_qcd_mc = f_qcd.Get(hname)

        if not h_qcd_template:
            h_qcd_template = h_qcd_mc.Clone("qcd_data")
        else:
            h_dy_inviso = f_dy.Get(hname_inviso)
            h_wjets_inviso = f_wjets.Get(hname_inviso)
            if use_inviso_data_template:
                h_qcd_template.Add(h_dy_inviso, -1.)
                h_qcd_template.Add(h_wjets_inviso, -1.)
            h_qcd_inviso_mc = f_qcd.Get(hname_inviso)

        h_ewk = h_wjets.Clone("h_ewk")
        h_ewk.Add(h_dy)
        h_ewk.Add(h_ttjets)

        wjets_to_data = h_data.Integral() / h_wjets.Integral()
        dy_to_data = h_data.Integral() / h_dy.Integral()
        qcd_to_data = h_data.Integral() / h_qcd_template.Integral()
        ewk_to_data = h_data.Integral() / h_ewk.Integral()
        h_wjets.Scale(wjets_to_data)
        h_dy.Scale(dy_to_data)
        h_qcd_template.Scale(qcd_to_data)
        h_ewk.Scale(ewk_to_data)

        # do_fit = "_pt_" in hname
        if do_fit:


            mc = r.TObjArray(2)
            mc.Add(h_ewk)
            mc.Add(h_qcd_template)
            fit = r.TFractionFitter(h_data,mc,"Q")
            fit.Constrain(0, 0.4,1.0) # ewk
            # fit.Constrain(1, 0.0,0.6) # DY
            fit.Constrain(1, 0.1,0.8) # QCD
            # fit.SetRangeX(h_wjets.FindBin(70.), h_wjets.FindBin(120.))
            fit.Fit()
            fracs = []
            frac_errs = []
            for i in range(2):
                f = r.Double()
                ferr = r.Double()
                fit.GetResult(i,f,ferr)
                # print i,f,ferr
                fracs.append(f)
                frac_errs.append(ferr)
            # print fracs
            # print frac_errs
            scales = fracs
            d_postfits[(flavstr,iso,use_inviso_data_template)] = scales
            d_sfs[(flavstr,iso,use_inviso_data_template)] = scales[0]*ewk_to_data, scales[1]*qcd_to_data
            del fit

        else:

            if use_postfit and (flavstr,iso,use_inviso_data_template) in d_postfits:
                scales = d_postfits[(flavstr,iso,use_inviso_data_template)]
            else:
                scales = np.ones(2)

        ewk_fit, qcd_fit = scales

        h_ewk.Scale(ewk_fit)
        h_qcd_template.Scale(qcd_fit)

        h_qcd_mc.Scale(h_qcd_template.Integral()/h_qcd_mc.Integral())
        h_qcd_inviso_mc.Scale(h_qcd_template.Integral()/h_qcd_inviso_mc.Integral())

        # if do_fit:
        #     print "fit info: {} {} {} {}".format(
        #             flavstr,
        #             iso,
        #             ewk_fit*ewk_to_data,
        #             qcd_fit*qcd_to_data,
        #             )

        xlabel = "m_{T}"
        if "pt" in extra: xlabel = "p_{T}"
        if "met" in extra: xlabel = "MET"
        if "dphi" in extra: xlabel = "#Delta#phi"

        if do_fit or not use_postfit: 
            # don't plot the prefit
            continue

        if do_fit or use_postfit:
            # colors = [18,r.kOrange+1, r.kAzure-2]
            colors = [18,r.kOrange+1]
            do_histline = True
            do_histline_only = False
            do_stack = True
            do_points = False
            extra_text = [
                    "EWK norm: {:.2f}".format(ewk_fit*ewk_to_data),
                    "QCD norm: {:.2f}".format(qcd_fit*qcd_to_data),
                    ]
            # print extra_text
        else:
            colors = [13,r.kOrange+1, r.kAzure-2]
            do_histline = False
            do_histline_only = True
            do_stack = False
            do_points = True
            extra_text = []

        hsyst = h_qcd_template.Clone("hsyst")
        hsyst.Reset()
        for ibin in range(0,hsyst.GetNbinsX()+2):
            ewkerr2 = h_ewk.GetBinError(ibin)**2.
            ewkerr2 += (0.1*h_ewk.GetBinContent(ibin))**2.
            qcderr2 = h_qcd_template.GetBinError(ibin)**2.
            qcderr2 += (0.1*h_qcd_template.GetBinContent(ibin))**2.
            # plottery expects central value of syst hist to be the error
            hsyst.SetBinContent(ibin, (ewkerr2+qcderr2)**0.5)

        for do_log in [False]:

            suffix = ""
            if use_postfit and not do_fit:
                suffix = "_postfit"
            if use_inviso_data_template:
                suffix += "_datatemp"
            else:
                suffix += "_mctemp"
            outname = "{}/{}_{}_{}_{}_{}{}.pdf".format(
                    outdir,
                    "y"+str(year),
                    flavstr,
                    "iso" if iso else "noniso",
                    "mt" if not extra else extra.replace("_",""),
                    "log" if do_log else "lin",
                    suffix,
                    )

            ply.plot_hist(
                data=h_data,
                bgs=[h_qcd_template,h_ewk],
                colors = colors,
                legend_labels = ["QCD template","EWK (W+DY+t#bar{t})"],
                syst = hsyst,
                sigs = [h_qcd_mc,
                    h_qcd_inviso_mc,
                    # h_ttjets
                    ],
                sig_labels = ["QCD MC [norm to gray]",
                    "QCD MC inviso [n.t.g.]",
                    # "t#bar{t} (unscaled)"
                    ],
                options = {
                    "do_stack": do_stack,
                    "draw_points": do_points,
                    "extra_text": extra_text,
                    "extra_text_xpos": 0.65,
                    "extra_text_ypos": 0.50,
                    "legend_scalex": 1.2,
                    "legend_scaley": 1.6,
                    "legend_smart": False,
                    "ratio_range":[0.5,2.0],
                    "xaxis_label":xlabel,
                    # "yaxis_range": [0,30e6],
                    "yaxis_log": do_log,
                    "output_name": outname,
                    "legend_percentageinbox": True,
                    "cms_label": "Preliminary",
                    "lumi_value": lumi,
                    "show_bkg_errors": True,
                    # "ratio_range": [0.,4.0],
                    "bkg_sort_method": "unsorted",
                    "hist_line_none": do_histline,
                    # "hist_line_only": do_histline_only,
                    # "output_ic": True,
                    }
                )

    # print d_sfs
    # os.system("niceplots plots_fit_ptthresh plots_test2_Apr23")


    # # iso
    # QCD template electrons  muons
    # MC           {:.02f}    {:.02f}
    # Data         {:.02f}    {:.02f}
    # # noniso
    # QCD template electrons  muons
    # MC           {:.02f}    {:.02f}
    # Data         {:.02f}    {:.02f}

    # print r"""
    # % iso
    #       QCD template & electrons &  muons \\
    #       \hline\hline
    #       MC        & {:.2f} & {:.2f} \\
    #       data      & {:.2f} & {:.2f} \\
    #       \hline
    # % noniso
    #       QCD template & electrons &  muons \\
    #       \hline\hline
    #       MC        & {:.2f} & {:.2f} \\
    #       data      & {:.2f} & {:.2f} \\
    #       \hline
    # """.format(
    #         d_sfs[("el",True,False)][0],
    #         d_sfs[("mu",True,False)][0],
    #         d_sfs[("el",True,True)][0],
    #         d_sfs[("mu",True,True)][0],
    #         d_sfs[("el",False,False)][0],
    #         d_sfs[("mu",False,False)][0],
    #         d_sfs[("el",False,True)][0],
    #         d_sfs[("mu",False,True)][0],
    #         )

    # print "TString dir = \"{}\";".format(basedir)
    # print "float mt_sf_el_iso =    {:.3f};".format(d_sfs[("el",True,False)][0])
    # print "float mt_sf_el_noniso = {:.3f};".format(d_sfs[("el",False,False)][0])
    # print "float mt_sf_mu_iso =    {:.3f};".format(d_sfs[("mu",True,False)][0])
    # print "float mt_sf_mu_noniso = {:.3f};".format(d_sfs[("mu",False,False)][0])
    # print "int year = {};".format(year)

    os.system("mkdir -p {}/mtfits/".format(basedir))
    os.system("cp -r {}/*.pdf {}/mtfits/".format(outdir,basedir))

    return d_sfs

def print_infos(infos):

    for year,d_sfs in sorted(infos):
        # d_sfs = infos[year]
        # print "TString dir = \"{}\";".format(basedir)
        print "int year = {};".format(year)
        print "float mt_sf_el_iso =    {:.3f};".format(d_sfs[("el",True,False)][0])
        print "float mt_sf_el_noniso = {:.3f};".format(d_sfs[("el",False,False)][0])
        print "float mt_sf_mu_iso =    {:.3f};".format(d_sfs[("mu",True,False)][0])
        print "float mt_sf_mu_noniso = {:.3f};".format(d_sfs[("mu",False,False)][0])

    for year,d_sfs in sorted(infos):
        # d_sfs[(flavstr,iso,use_inviso_data_template)]
        print r"""
\multirow{{2}}{{*}}{{{year}}} & MC        & {mcisoe:.3f} & {mcisom:.3f} & {mcnonisoe:.3f} & {mcnonisom:.3f} \\
        & data      & {dataisoe:.3f} & {dataisom:.3f} & {datanonisoe:.3f} & {datanonisom:.3f} \\ \hline
    """.format(
            year=year,
            mcisoe=d_sfs[("el",True,False)][0],
            mcisom=d_sfs[("mu",True,False)][0],
            mcnonisoe=d_sfs[("el",False,False)][0],
            mcnonisom=d_sfs[("mu",False,False)][0],
            dataisoe=d_sfs[("el",True,True)][0],
            dataisom=d_sfs[("mu",True,True)][0],
            datanonisoe=d_sfs[("el",False,True)][0],
            datanonisom=d_sfs[("mu",False,True)][0],
            )

if __name__ == "__main__":

    infos = []
    for year in [2016,2017,2018]:
    # for year in [2018]:
    # for year in [2016]:
        # infos.append([year, make_plots_info(basedir="outputs_test/", outdir="outputs_test/plots_mtfit/fit_test_19Jan7", year=year)])
        infos.append([year, make_plots_info(basedir="outputs_19Jan28//", outdir="outputs_19Jan28//plots_mtfit/fit_19Jan28", year=year)])

    print_infos(infos)
    # os.system("ic y2018/outputs_test/plots_mtfit/fit_test_19Jan7_el_iso_mt_lin_postfit_mctemp.pdf")
