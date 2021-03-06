import os
import numpy as np
import uproot

import sys
sys.path.insert(0,'/home/users/namin/.local/lib/python2.7/site-packages/')
from matplottery.plotter import plot_stack, plot_2d
from matplottery.utils import Hist1D, Hist2D

from multiprocessing import Pool as ThreadPool

f = uproot.open("histos__LooseEMVA_coneCorr_HH.root")
# f = uproot.open("histos__LooseEMVA_soup_inSitu_coneCorr_HH.root")

# for k in sorted(f.keys()):
#     print k

outdir = "plots_SS_2017_19Jan25"

varnames = ["HT", "L1PT", "L2PT", "LFake", "LTrue", "MET", "MTMIN", "NJET", "NB", "MATCH", "L1ETA", "L2ETA"]
# varnames = ["NB"]
flavs = ["_el","_mu",""]
# varnames = ["MATCH"]
# flavs = [""]

# If using multiprocessing, there's bug with matplotlib -- see note in analysis/yields/plot_all.py
# so can't first plot the PTETA stuff

# for flav in ["_el","_mu"]:
#     var = "PTETA"
#     obs_ttbar = Hist2D(f["Npn_histo_{}_obs{}TTBAR;1".format(var,flav)])
#     # obs_wjets = Hist2D(f["Npn_histo_{}_obs{}WJets;1".format(var,flav)])
#     pred = Hist2D(f["Npn_histo_{}_pred{};1".format(var,flav)])
#     # obs = obs_ttbar+obs_wjets
#     obs = obs_ttbar
#     ratio = pred/obs
#     ratio._counts = np.nan_to_num(ratio._counts)
#     ratio._errors = np.nan_to_num(ratio._errors)
#     xticks,yticks = pred.get_edges()
#     opts = {
#             "do_colz": True,
#             "colz_fmt": ".1e",
#             "logx": True,
#             "xticks": xticks,
#             "yticks": yticks,
#             "cms_type": "Simulation",
#             # "lumi": "41.3",
#             "lumi": "-1",
#             "xlabel": "$p_{T}$ corr. [GeV]",
#             "ylabel": "$|\\eta|$",
#             }
#     for ext in ["pdf","png"]:
#         opts["cmap"] = "Blues_r"
#         opts["zrange"] = []
#         plot_2d(obs, filename="{}/h2_obs{}.{}".format(outdir,flav,ext), title="obs", **opts)
#         plot_2d(pred, filename="{}/h2_pred{}.{}".format(outdir,flav,ext), title="pred", **opts)
#         opts["cmap"] = "RdBu_r"
#         opts["zrange"] = [0.,2.]
#         plot_2d(ratio, filename="{}/h2_ratio{}.{}".format(outdir,flav,ext), title="pred/obs", **opts)
#     # os.system("ic plots/h2_ratio_el.png")


def plot_var(var):
    global f, outdir, flavs
    # for var in varnames:
    for flav in flavs:
        obs_ttbar = Hist1D(f["Npn_histo_{}_obs{}TTBAR;1".format(var,flav)], color=(1.0,1.0,0.04), label="$t\\bar{t}$")
        obs_wjets = Hist1D(f["Npn_histo_{}_obs{}WJets;1".format(var,flav)], color=(1.0,0.76,0.04), label="W+jets")
        pred = Hist1D(f["Npn_histo_{}_pred{};1".format(var,flav)],label="Prediction")


        for h in [obs_ttbar,obs_wjets,pred]:
        # for h in [obs_ttbar,pred]:
            h.set_attr("label", "{} [{:.1f}]".format(h.get_attr("label"),h.get_integral()))

        xticks = []
        if "MATCH" in var:
            # xticks = ["unmatched","b","c","photon","light"]
            xticks = ["unmatched (0)","b (-1)","c (-2)","photon (-3)","light (-4)"]

        for ext in ["png","pdf"]:
        # for ext in ["png"]:
            fname = "{}/{}{}.{}".format(outdir,var,flav,ext)
            plot_stack(bgs=[obs_ttbar,obs_wjets], data=pred, title="",
            # plot_stack(bgs=[obs_ttbar], data=pred, title="",
                    xlabel="{}".format(var),
                    ylabel="Entries",
                    filename=fname,
                    cms_type = "Preliminary",
                    lumi = "41.5",
                    # ratio_range=[0.,2.],
                    ratio_range=[0.5,1.5],
                    mpl_hist_params = {
                        "edgecolor": "k",
                        "linewidth": 0.5,
                        },
                    do_bkg_syst=True,
                    xticks=xticks,
                    )
            # os.system("ic {}".format(fname))
            # print "Wrote {}".format(fname)
    return fname

os.nice(10)

# map(plot_var, varnames)

pool = ThreadPool(12)
for res in pool.imap_unordered(plot_var,varnames):
    if res:
        print "Wrote {}".format(res)
                    

# os.system("NOCONVERT=true niceplots plots plots_fakerateclosure_Apr30")
# os.system("NOCONVERT=true niceplots plots plots_fakerateclosure_Jun12")
# os.system("NOCONVERT=true niceplots plots plots_fakerateclosure_Jun17")
# os.system("NOCONVERT=true niceplots plots plots_fakerateclosurecheck_Jul2") # old WPs for QCD FR applied to tt1l (v1.06_v2_oldiso)
# os.system("NOCONVERT=true niceplots plots plots_fakeclosure1wnfo2_Jul6") # new WPs for QCD FR applied to inclusive tt (v1.06_v2)
# os.system("NOCONVERT=true niceplots plots plots_fakeclosureinsitu_Aug2")
# os.system("NOCONVERT=true niceplots plots plots_fakeclosure1wnfo1_Jul6") # new WPs for QCD FR applied to inclusive tt (v1.06_v2)
# os.system("NOCONVERT=true niceplots plots plots_fakeclosureextrapt_Apr24")
# os.system("NOCONVERT=true niceplots plots plots_fakeclosurenolooseemva_Apr22")
