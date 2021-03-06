#!/usr/bin/env python

import os
import sys
import analysis.utils.pyrun as pyrun
import argparse
import fnmatch
import operator
import glob
import ast
import time

def make_obj(fpatts=[],options="",treename="t"):
    if type(fpatts) == str: fpatts = [fpatts]
    ch = r.TChain(treename)
    for fpatt in fpatts:
        ch.Add(fpatt)
    return {"ch": ch, "options": options}

def get_fastsim_procnames_single(fname, procbase="fs_t1tttt", range1=[], range2=[]):
    f = r.TFile(fname)
    counts = f.Get("counts")
    xaxis = counts.GetXaxis()
    yaxis = counts.GetYaxis()
    valid_points = []
    for ix in range(1,counts.GetNbinsX()+1):
        for iy in range(1,counts.GetNbinsY()+1):
            v = counts.GetBinContent(ix,iy)
            if v < 100: continue
            ex = xaxis.GetBinLowEdge(ix)
            ey = yaxis.GetBinLowEdge(iy)
            m1, m2 = int(ex),int(max(ey,1))
            if len(range1) == 2 and not (range1[0] <= m1 <= range1[1]): continue
            if len(range2) == 2 and not (range2[0] <= m2 <= range2[1]): continue
            valid_points.append([m1,m2])
    strs = map(lambda x:"{}_m{}_m{}".format(procbase,x[0],x[1]), valid_points)
    return strs

def get_fastsim_procnames(fnames, procbase="fs_t1tttt", range1=[], range2=[], filt=""):
    # if user specified --proc, don't bother looking up mass points if this process won't be matched later
    if filt and not fnmatch.fnmatch(procbase+"_",filt): 
        return []
    # calls _single implementation and takes set union of all fnames fed in
    # if fnames is not a list (just one thing), then make it a list to keep this reverse compatible
    if type(fnames) is not list: fnames = [fnames]
    ret = sorted(list(reduce(
            operator.__and__,
            [ set(get_fastsim_procnames_single(fname, procbase=procbase, range1=range1, range2=range2))
                for fname in fnames ]
            )))
    print "Found {} points for {} in range1={} and range2={}".format(len(ret),procbase,range1,range2)
    return ret

if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument("-o", "--out", help="output directory", default="outputs")
    parser.add_argument("-e", "--extra_options", help="quoted string of extra options", default="")
    parser.add_argument(      "--plot_kwargs", help="""kwargs to pass to plotter e.g., '{"show_mcfakes": True,}'""", default="")
    parser.add_argument("-t", "--tag", help="tag for bookkeeping and output directory location", default="v3.08_allyears_tmp")
    parser.add_argument(      "--ss", help="same-sign instead of four top looping", action="store_true")

    parser.add_argument("-y", "--year", help="year, if you only want to run one", default="")
    parser.add_argument(      "--proc", help="process, if you only want to run one/some. accepts wildcards if quoted.", default="", type=str)
    parser.add_argument(      "--excludeproc", help="opposite of proc", default="", type=str)
    parser.add_argument(      "--skip_already_done", help="skip procs if already in limits folder", action="store_true")
    parser.add_argument(      "--slim", help="smaller subset of processes", action="store_true")
    parser.add_argument(      "--ncpu", help="number of cpus", default=25, type=int)
    parser.add_argument(      "--maxprocs", help="maximum number of chains", default=-1, type=int)

    parser.add_argument("-n", "--noloop", help="skip looping/scanchain", action="store_true")
    parser.add_argument("-s", "--shapes", help="make shape hists and copy to limit directory tag folder", action="store_true")
    parser.add_argument("-p", "--plots", help="make plots and copy to the limit directory tag folder", action="store_true")
    parser.add_argument("-f", "--fastsim", help="include fastsim scans", action="store_true")
    parser.add_argument("-v", "--verbosity", help="verbosity level (0 = default,1,2)", default=0, type=int)

    args = parser.parse_args()

    plot_kwargs = {} if not args.plot_kwargs else ast.literal_eval(args.plot_kwargs)

    try:
        args.year = int(args.year)
    except:
        pass

    import ROOT as r
    r.gROOT.SetBatch()


    if not args.noloop:
        if os.path.isfile(".lastcompile.tmp"):
            with open(".lastcompile.tmp","r") as fh:
                lastcompile = fh.read().strip()
                if lastcompile != ("ss" if args.ss else "ft"):
                    print "Last compilation was different, so doing `rm yieldMaker_C.so`"
                    os.system("rm yieldMaker_C.so")
        if args.ss:
            print "Enabling SSLOOP preprocessor macro"
            # define SSLOOP preprocessor
            r.gSystem.SetFlagsOpt(r.gSystem.GetFlagsOpt() + " -DSSLOOP=1")
            r.gROOT.ProcessLine(".L ../../common/CORE/Tools/MT2/MT2Utility.cc+")
            r.gROOT.ProcessLine(".L ../../common/CORE/Tools/MT2/MT2.cc+")
        r.gROOT.ProcessLine(".L ../../common/CORE/Tools/goodrun.cc+")
        # r.gROOT.ProcessLine(".L ../../common/CORE/Tools/goodrun.cc++") # FIXME uaf-1 vs uaf-10
        r.gROOT.ProcessLine(".L ../misc/class_files/v8.02/SS.cc+")
        r.gROOT.ProcessLine(".L ../../common/CORE/Tools/dorky/dorky.cc+")
        r.gROOT.ProcessLine(".L yieldMaker.C+")
        with open(".lastcompile.tmp","w") as fh: fh.write("ss" if args.ss else "ft")


    years_to_consider = [
            # "2016_94x",
            2016,
            2017,
            2018,
            ]

    # for _ in range(10): print "SKIMTEST"
    if args.ss:
        basedirs = {

                # "2016_94x": "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.09_all/output/year_2016_94x/",
                2016: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.31/output/year_2016_94x/skimfix/",
                2017: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.31/output/year_2017/skimfix/",
                2018: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.31//output/year_2018/skimfix/",
                # 2018: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.31_jec15///output/year_2018/skimfix/",

                # "2016_94x": "/home/users/namin/2018/fourtop/all/FTAnalysis/analysis/yields/local/year_2016_94x/",
                # 2016: "/home/users/namin/2018/fourtop/all/FTAnalysis/analysis/yields/local/year_2016//",
                # 2017: "/home/users/namin/2018/fourtop/all/FTAnalysis/analysis/yields/local/year_2017//",
                # 2018: "/home/users/namin/2018/fourtop/all/FTAnalysis/analysis/yields/local/year_2018//",

                }

    else:
        basedirs = {

                # "2016_94x": "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.09_all/output/year_2016_94x/",
                # 2016: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.24/output/year_2016/skimfix//",
                # 2017: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.24/output/year_2017//skimfix/",
                # 2018: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.28//output/year_2018/skimfix//",

                # "2016_94x": "/home/users/namin/2018/fourtop/all/FTAnalysis/analysis/yields/local/year_2016_94x/",
                2016: "/home/users/namin/2018/fourtop/all/FTAnalysis/analysis/yields/local/year_2016//",
                # 2016: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.29//output/year_2016_94x/skimfix/", # FIXME
                2017: "/home/users/namin/2018/fourtop/all/FTAnalysis/analysis/yields/local/year_2017//",
                2018: "/home/users/namin/2018/fourtop/all/FTAnalysis/analysis/yields/local/year_2018//",

                }

    # print "FIXME revert 2016"
    # print "uncomment HHAT for 2016"
    # print "uncomment HIGGS for 2016"
    # # print "uncomment ISRFSR for 2016"
    # # print "uncomment TTSLht500 TTDLht500 (two places)"


    outputdir = args.out
    extra_global_options = args.extra_options
    options = {
            # "2016_94x": "Data2016 94x quiet {} evaluateBDT ".format(extra_global_options),

            # 2016: "Data2016 quiet {} evaluateBDT ".format(extra_global_options),
            # 2017: "Data2017 quiet {} evaluateBDT minPtFake18 ".format(extra_global_options),
            # 2018: "Data2018 quiet {} evaluateBDT minPtFake18 ".format(extra_global_options),

            2016: "Data2016 quiet {} evaluateBDT ".format(extra_global_options),
            2017: "Data2017 quiet {} evaluateBDT minPtFake18 ".format(extra_global_options),
            2018: "Data2018 quiet {} evaluateBDT minPtFake18 ".format(extra_global_options),

                # 2016: "Data2016 quiet {} new2016FRBins ".format(extra_global_options),
                # 2017: "Data2017 quiet {} partialUnblind ".format(extra_global_options),
                # 2018: "Data2018 quiet {} partialUnblind ".format(extra_global_options),

            }


    if not args.ss:

        chs = {

                # "2016_94x": {

                #     # "fakes": make_obj([
                #     #     basedirs["2016_94x"]+"Data*.root",
                #     #     ] , options=options["2016_94x"]+" doFakes doData "),
                #     # "flips": make_obj(basedirs["2016_94x"]+"Data*.root", options=options["2016_94x"]+" doFlips doData "),
                #     # "data": make_obj(basedirs["2016_94x"]+"Data*.root", options=options["2016_94x"] + " doData "),
                #     # "tttt": make_obj(basedirs["2016_94x"]+"TTTTnew.root", options=options["2016_94x"]),

                #     },
                2016: {

                    "fakes": make_obj([
                        basedirs[2016]+"Data*.root",
                        basedirs[2016]+"TTWnlo.root",
                        basedirs[2016]+"TTZnlo.root",
                        basedirs[2016]+"TTHtoNonBB.root",
                        ] , options=options[2016]+" doFakes doData "),
                    "flips": make_obj(basedirs[2016]+"Data*.root", options=options[2016]+" doFlips doData "),
                    "data": make_obj(basedirs[2016]+"Data*.root", options=options[2016] + " doData "),
                    "tttt": make_obj(basedirs[2016]+"TTTTnew.root", options=options[2016]),
                    "ttttisrup": make_obj(basedirs[2016]+"TTTTisrup.root", options=options[2016]),
                    "ttttisrdn": make_obj(basedirs[2016]+"TTTTisrdown.root", options=options[2016]),
                    "ttttfsrup": make_obj(basedirs[2016]+"TTTTfsrup.root", options=options[2016]),
                    "ttttfsrdn": make_obj(basedirs[2016]+"TTTTfsrdown.root", options=options[2016]),
                    # "fakes_mc": make_obj(basedirs[2016]+"TTBAR*.root", options=options[2016]+ " doFakesMC "),
                    "fakes_mc": make_obj([
                        basedirs[2016]+"TTBAR_PH.root",
                        basedirs[2016]+"TTSLht500.root",
                        basedirs[2016]+"TTDLht500.root",
                        basedirs[2016]+"WJets_HT200To400.root",
                        basedirs[2016]+"WJets_HT400To600.root",
                        basedirs[2016]+"WJets_HT600To800.root",
                        basedirs[2016]+"WJets_HT800To1200.root",
                        ] , options=options[2016]+ " doTruthFake doStitch "),
                    # "fakes_mcwj": make_obj([
                    #     basedirs[2016]+"WJets_HT200To400.root",
                    #     basedirs[2016]+"WJets_HT400To600.root",
                    #     basedirs[2016]+"WJets_HT600To800.root",
                    #     basedirs[2016]+"WJets_HT800To1200.root",
                    #     ] , options=options[2016]+ " doTruthFake "),
                    # "fakes_mcwjhybrid": make_obj([
                    #     basedirs[2016]+"WJets_HT200To400.root",
                    #     basedirs[2016]+"WJets_HT400To600.root",
                    #     basedirs[2016]+"WJets_HT600To800.root",
                    #     basedirs[2016]+"WJets_HT800To1200.root",
                    #     ] , options=options[2016]+ " doFakesMC "),
                    "fakes_mchybrid": make_obj([
                        basedirs[2016]+"TTBAR_PH.root",
                        basedirs[2016]+"TTSLht500.root",
                        basedirs[2016]+"TTDLht500.root",
                        basedirs[2016]+"WJets_HT200To400.root",
                        basedirs[2016]+"WJets_HT400To600.root",
                        basedirs[2016]+"WJets_HT600To800.root",
                        basedirs[2016]+"WJets_HT800To1200.root",
                        ] , options=options[2016]+ " doFakesMC doStitch "),
                    "ttw": make_obj(basedirs[2016]+"TTWnlo.root", options=options[2016]),
                    "tth": make_obj(basedirs[2016]+"TTHtoNonBB.root", options=options[2016]),
                    "ttz": make_obj([
                        basedirs[2016]+"TTZnlo.root",
                        basedirs[2016]+"TTZLOW.root",
                        ] , options=options[2016]),
                    "xg": make_obj([
                        basedirs[2016]+"TGext.root",
                        basedirs[2016]+"TTGdilep.root",
                        basedirs[2016]+"TTGsinglelepbar.root",
                        basedirs[2016]+"TTGsinglelep.root",
                        basedirs[2016]+"WGToLNuGext.root",
                        basedirs[2016]+"ZG.root",
                        ],options=options[2016] + " doXgamma "),
                    "ttvv": make_obj([
                        basedirs[2016]+"TTHH.root",
                        basedirs[2016]+"TTWH.root",
                        basedirs[2016]+"TTWW.root",
                        basedirs[2016]+"TTWZ.root",
                        basedirs[2016]+"TTZH.root",
                        basedirs[2016]+"TTZZ.root",
                        ],options=options[2016]),
                    "rares": make_obj([
                        basedirs[2016]+"GGHtoZZto4L.root",
                        basedirs[2016]+"QQWW.root",
                        basedirs[2016]+"TWZ.root",
                        basedirs[2016]+"TZQ.root",
                        basedirs[2016]+"VHtoNonBB.root",
                        basedirs[2016]+"WWDPS.root",
                        basedirs[2016]+"WWW.root",
                        basedirs[2016]+"WWZ.root",
                        basedirs[2016]+"WZ.root",
                        basedirs[2016]+"WZG.root",
                        basedirs[2016]+"WWG.root",
                        basedirs[2016]+"WZZ.root",
                        basedirs[2016]+"ZZ.root",
                        basedirs[2016]+"ZZZ.root",
                        basedirs[2016]+"TTTJ.root",
                        basedirs[2016]+"TTTW.root",
                        ],options=options[2016]),

                    # "higgsh350": make_obj([ basedirs[2016]+"Higgs_ttH_350.root", basedirs[2016]+"Higgs_tHW_350.root", basedirs[2016]+"Higgs_tHq_350.root", ],options=options[2016]),
                    # "higgsh370": make_obj([ basedirs[2016]+"Higgs_ttH_370.root", basedirs[2016]+"Higgs_tHW_370.root", basedirs[2016]+"Higgs_tHq_370.root", ],options=options[2016]),
                    # "higgsh390": make_obj([ basedirs[2016]+"Higgs_ttH_390.root", basedirs[2016]+"Higgs_tHW_390.root", basedirs[2016]+"Higgs_tHq_390.root", ],options=options[2016]),
                    # "higgsh410": make_obj([ basedirs[2016]+"Higgs_ttH_410.root", basedirs[2016]+"Higgs_tHW_410.root", basedirs[2016]+"Higgs_tHq_410.root", ],options=options[2016]),
                    # "higgsh430": make_obj([ basedirs[2016]+"Higgs_ttH_430.root", basedirs[2016]+"Higgs_tHW_430.root", basedirs[2016]+"Higgs_tHq_410.root", ],options=options[2016]),
                    # "higgsh450": make_obj([ basedirs[2016]+"Higgs_ttH_450.root", basedirs[2016]+"Higgs_tHW_450.root", basedirs[2016]+"Higgs_tHq_450.root", ],options=options[2016]),
                    # "higgsh470": make_obj([ basedirs[2016]+"Higgs_ttH_470.root", basedirs[2016]+"Higgs_tHW_470.root", basedirs[2016]+"Higgs_tHq_470.root", ],options=options[2016]),
                    # "higgsh490": make_obj([ basedirs[2016]+"Higgs_ttH_490.root", basedirs[2016]+"Higgs_tHW_490.root", basedirs[2016]+"Higgs_tHq_490.root", ],options=options[2016]),
                    # "higgsh510": make_obj([ basedirs[2016]+"Higgs_ttH_510.root", basedirs[2016]+"Higgs_tHW_510.root", basedirs[2016]+"Higgs_tHq_510.root", ],options=options[2016]),
                    # "higgsh530": make_obj([ basedirs[2016]+"Higgs_ttH_530.root", basedirs[2016]+"Higgs_tHW_530.root", basedirs[2016]+"Higgs_tHq_530.root", ],options=options[2016]),
                    # "higgsh550": make_obj([ basedirs[2016]+"Higgs_ttH_550.root", basedirs[2016]+"Higgs_tHW_550.root", basedirs[2016]+"Higgs_tHq_550.root", ],options=options[2016]),
                    # "higgsh570": make_obj([ basedirs[2016]+"Higgs_ttH_570.root", basedirs[2016]+"Higgs_tHW_570.root", basedirs[2016]+"Higgs_tHq_570.root", ],options=options[2016]),
                    # "higgsh590": make_obj([ basedirs[2016]+"Higgs_ttH_590.root", basedirs[2016]+"Higgs_tHW_590.root", basedirs[2016]+"Higgs_tHq_590.root", ],options=options[2016]),
                    # "higgsh610": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),
                    # "higgsh630": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),
                    # "higgsh650": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),

                    # "higgsa350": make_obj([ basedirs[2016]+"Higgs_ttH_350.root", basedirs[2016]+"Higgs_tHW_350.root", basedirs[2016]+"Higgs_tHq_350.root", ],options=options[2016]),
                    # "higgsa370": make_obj([ basedirs[2016]+"Higgs_ttH_370.root", basedirs[2016]+"Higgs_tHW_370.root", basedirs[2016]+"Higgs_tHq_370.root", ],options=options[2016]),
                    # "higgsa390": make_obj([ basedirs[2016]+"Higgs_ttH_390.root", basedirs[2016]+"Higgs_tHW_390.root", basedirs[2016]+"Higgs_tHq_390.root", ],options=options[2016]),
                    # "higgsa410": make_obj([ basedirs[2016]+"Higgs_ttH_410.root", basedirs[2016]+"Higgs_tHW_410.root", basedirs[2016]+"Higgs_tHq_410.root", ],options=options[2016]),
                    # "higgsa430": make_obj([ basedirs[2016]+"Higgs_ttH_430.root", basedirs[2016]+"Higgs_tHW_430.root", basedirs[2016]+"Higgs_tHq_410.root", ],options=options[2016]),
                    # "higgsa450": make_obj([ basedirs[2016]+"Higgs_ttH_450.root", basedirs[2016]+"Higgs_tHW_450.root", basedirs[2016]+"Higgs_tHq_450.root", ],options=options[2016]),
                    # "higgsa470": make_obj([ basedirs[2016]+"Higgs_ttH_470.root", basedirs[2016]+"Higgs_tHW_470.root", basedirs[2016]+"Higgs_tHq_470.root", ],options=options[2016]),
                    # "higgsa490": make_obj([ basedirs[2016]+"Higgs_ttH_490.root", basedirs[2016]+"Higgs_tHW_490.root", basedirs[2016]+"Higgs_tHq_490.root", ],options=options[2016]),
                    # "higgsa510": make_obj([ basedirs[2016]+"Higgs_ttH_510.root", basedirs[2016]+"Higgs_tHW_510.root", basedirs[2016]+"Higgs_tHq_510.root", ],options=options[2016]),
                    # "higgsa530": make_obj([ basedirs[2016]+"Higgs_ttH_530.root", basedirs[2016]+"Higgs_tHW_530.root", basedirs[2016]+"Higgs_tHq_530.root", ],options=options[2016]),
                    # "higgsa550": make_obj([ basedirs[2016]+"Higgs_ttH_550.root", basedirs[2016]+"Higgs_tHW_550.root", basedirs[2016]+"Higgs_tHq_550.root", ],options=options[2016]),
                    # "higgsa570": make_obj([ basedirs[2016]+"Higgs_ttH_570.root", basedirs[2016]+"Higgs_tHW_570.root", basedirs[2016]+"Higgs_tHq_570.root", ],options=options[2016]),
                    # "higgsa590": make_obj([ basedirs[2016]+"Higgs_ttH_590.root", basedirs[2016]+"Higgs_tHW_590.root", basedirs[2016]+"Higgs_tHq_590.root", ],options=options[2016]),
                    # "higgsa610": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),
                    # "higgsa630": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),
                    # "higgsa650": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),

                    # "higgsb350": make_obj([ basedirs[2016]+"Higgs_ttH_350.root", basedirs[2016]+"Higgs_tHW_350.root", basedirs[2016]+"Higgs_tHq_350.root", ],options=options[2016]),
                    # "higgsb370": make_obj([ basedirs[2016]+"Higgs_ttH_370.root", basedirs[2016]+"Higgs_tHW_370.root", basedirs[2016]+"Higgs_tHq_370.root", ],options=options[2016]),
                    # "higgsb390": make_obj([ basedirs[2016]+"Higgs_ttH_390.root", basedirs[2016]+"Higgs_tHW_390.root", basedirs[2016]+"Higgs_tHq_390.root", ],options=options[2016]),
                    # "higgsb410": make_obj([ basedirs[2016]+"Higgs_ttH_410.root", basedirs[2016]+"Higgs_tHW_410.root", basedirs[2016]+"Higgs_tHq_410.root", ],options=options[2016]),
                    # "higgsb430": make_obj([ basedirs[2016]+"Higgs_ttH_430.root", basedirs[2016]+"Higgs_tHW_430.root", basedirs[2016]+"Higgs_tHq_410.root", ],options=options[2016]),
                    # "higgsb450": make_obj([ basedirs[2016]+"Higgs_ttH_450.root", basedirs[2016]+"Higgs_tHW_450.root", basedirs[2016]+"Higgs_tHq_450.root", ],options=options[2016]),
                    # "higgsb470": make_obj([ basedirs[2016]+"Higgs_ttH_470.root", basedirs[2016]+"Higgs_tHW_470.root", basedirs[2016]+"Higgs_tHq_470.root", ],options=options[2016]),
                    # "higgsb490": make_obj([ basedirs[2016]+"Higgs_ttH_490.root", basedirs[2016]+"Higgs_tHW_490.root", basedirs[2016]+"Higgs_tHq_490.root", ],options=options[2016]),
                    # "higgsb510": make_obj([ basedirs[2016]+"Higgs_ttH_510.root", basedirs[2016]+"Higgs_tHW_510.root", basedirs[2016]+"Higgs_tHq_510.root", ],options=options[2016]),
                    # "higgsb530": make_obj([ basedirs[2016]+"Higgs_ttH_530.root", basedirs[2016]+"Higgs_tHW_530.root", basedirs[2016]+"Higgs_tHq_530.root", ],options=options[2016]),
                    # "higgsb550": make_obj([ basedirs[2016]+"Higgs_ttH_550.root", basedirs[2016]+"Higgs_tHW_550.root", basedirs[2016]+"Higgs_tHq_550.root", ],options=options[2016]),
                    # "higgsb570": make_obj([ basedirs[2016]+"Higgs_ttH_570.root", basedirs[2016]+"Higgs_tHW_570.root", basedirs[2016]+"Higgs_tHq_570.root", ],options=options[2016]),
                    # "higgsb590": make_obj([ basedirs[2016]+"Higgs_ttH_590.root", basedirs[2016]+"Higgs_tHW_590.root", basedirs[2016]+"Higgs_tHq_590.root", ],options=options[2016]),
                    # "higgsb610": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),
                    # "higgsb630": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),
                    # "higgsb650": make_obj([ basedirs[2016]+"Higgs_ttH_610.root", basedirs[2016]+"Higgs_tHW_610.root", basedirs[2016]+"Higgs_tHq_610.root", ],options=options[2016]),

                    "hhat0p0": make_obj([ basedirs[2016]+"newhhat/HHAT_0p0.root" ],options=options[2016]),
                    "hhat0p08": make_obj([ basedirs[2016]+"newhhat/HHAT_0p08.root" ],options=options[2016]),
                    "hhat0p12": make_obj([ basedirs[2016]+"newhhat/HHAT_0p12.root" ],options=options[2016]),
                    "hhat0p16": make_obj([ basedirs[2016]+"newhhat/HHAT_0p16.root" ],options=options[2016]),

                    },
                2017: {

                    "fakes": make_obj([
                        basedirs[2017]+"Data*.root",
                        basedirs[2017]+"TTWnlo.root",
                        basedirs[2017]+"TTZnlo.root",
                        basedirs[2017]+"TTHtoNonBB.root",
                        ] , options=options[2017]+" doFakes doData "),
                    "flips": make_obj(basedirs[2017]+"Data*.root", options=options[2017]+" doFlips "),
                    "data": make_obj(basedirs[2017]+"Data*.root", options=options[2017]+" doData "),
                    # "fakes_mc": make_obj(basedirs[2017]+"TTBAR*.root", options=options[2017]+ " doFakesMC "),
                    # "fakes_mc": make_obj([
                    #     basedirs[2017]+"TTDL.root",
                    #     basedirs[2017]+"TTSLtop.root",
                    #     basedirs[2017]+"TTSLtopbar.root",
                    #     ] , options=options[2017]+ " doTruthFake "),
                    "fakes_mc": make_obj([
                        basedirs[2017]+"TTBAR*.root",
                        basedirs[2017]+"WJets_HT200To400.root",
                        basedirs[2017]+"WJets_HT400To600.root",
                        basedirs[2017]+"WJets_HT600To800.root",
                        basedirs[2017]+"WJets_HT800To1200.root",
                        basedirs[2017]+"WJets_HT1200To2500.root",
                        ] , options=options[2017]+ " doSkipMatching "),
                    # "fakes_mcwj": make_obj([
                    #     basedirs[2017]+"WJets_HT200To400.root",
                    #     basedirs[2017]+"WJets_HT400To600.root",
                    #     basedirs[2017]+"WJets_HT600To800.root",
                    #     basedirs[2017]+"WJets_HT800To1200.root",
                    #     basedirs[2017]+"WJets_HT1200To2500.root",
                    #     ] , options=options[2017]+ " doTruthFake "),
                    # "fakes_mcwjhybrid": make_obj([
                    #     basedirs[2017]+"WJets_HT200To400.root",
                    #     basedirs[2017]+"WJets_HT400To600.root",
                    #     basedirs[2017]+"WJets_HT600To800.root",
                    #     basedirs[2017]+"WJets_HT800To1200.root",
                    #     basedirs[2017]+"WJets_HT1200To2500.root",
                    #     ] , options=options[2017]+ " doFakesMC "),
                    "fakes_mchybrid": make_obj([
                        basedirs[2017]+"TTDL.root",
                        basedirs[2017]+"TTSLtop.root",
                        basedirs[2017]+"TTSLtopbar.root",
                        basedirs[2017]+"WJets_HT200To400.root",
                        basedirs[2017]+"WJets_HT400To600.root",
                        basedirs[2017]+"WJets_HT600To800.root",
                        basedirs[2017]+"WJets_HT800To1200.root",
                        basedirs[2017]+"WJets_HT1200To2500.root",
                        ] , options=options[2017]+ " doFakesMC "),

                    "tttt": make_obj(basedirs[2017]+"TTTTnew.root", options=options[2017]),
                    "ttw": make_obj(basedirs[2017]+"TTWnlo.root", options=options[2017]),
                    "tth": make_obj(basedirs[2017]+"TTHtoNonBB.root", options=options[2017]),
                    "ttz": make_obj([
                        basedirs[2017]+"TTZnlo.root",
                        basedirs[2017]+"TTZLOW.root",
                        ] , options=options[2017]),

                    # "tttt": make_obj("/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.09_newdeepflavv2//output/year_2017/TTTTnew.root", options=options[2017]),
                    # "ttw": make_obj("/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.09_newdeepflavv2//output/year_2017/TTWnlo.root", options=options[2017]),
                    # "tth": make_obj("/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.09_newdeepflavv2//output/year_2017/TTHtoNonBB.root", options=options[2017]),
                    # "ttz": make_obj([
                    #     "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.09_newdeepflavv2//output/year_2017/TTZnlo.root",
                    #     basedirs[2017]+"TTZLOW.root",
                    #     ] , options=options[2017]),

                    "xg": make_obj([
                        basedirs[2017]+"TGext.root",
                        basedirs[2017]+"TTGdilep.root",
                        basedirs[2017]+"TTGsinglelepbar.root",
                        basedirs[2017]+"TTGsinglelep.root",
                        basedirs[2017]+"WGToLNuGext.root",
                        basedirs[2017]+"ZG.root",
                        ],options=options[2017] + " doXgamma "),
                    "ttvv": make_obj([
                        basedirs[2017]+"TTHH.root",
                        basedirs[2017]+"TTWH.root",
                        basedirs[2017]+"TTWW.root",
                        basedirs[2017]+"TTWZ.root",
                        basedirs[2017]+"TTZH.root",
                        basedirs[2017]+"TTZZ.root",
                        ],options=options[2017]),
                    "rares": make_obj([
                        basedirs[2017]+"GGHtoZZto4L.root",
                        basedirs[2017]+"QQWW.root",
                        basedirs[2017]+"TWZ.root",
                        basedirs[2017]+"TZQ.root",
                        basedirs[2017]+"VHtoNonBB.root",
                        basedirs[2017]+"WWDPS.root",
                        basedirs[2017]+"WWW.root",
                        basedirs[2017]+"WWZ.root",
                        basedirs[2017]+"WZ.root",
                        basedirs[2017]+"WZG.root",
                        basedirs[2017]+"WWG.root",
                        basedirs[2017]+"WZZ.root",
                        basedirs[2017]+"ZZ.root",
                        basedirs[2017]+"ZZZ.root",
                        basedirs[2017]+"TTTJ.root",
                        basedirs[2017]+"TTTW.root",
                        ],options=options[2017]),

                    "higgsh350": make_obj([ basedirs[2017]+"Higgs_ttH_350.root", basedirs[2017]+"Higgs_tHW_350.root", basedirs[2017]+"Higgs_tHq_350.root", ],options=options[2017]),
                    "higgsh370": make_obj([ basedirs[2017]+"Higgs_ttH_375.root", basedirs[2017]+"Higgs_tHW_375.root", basedirs[2017]+"Higgs_tHq_375.root", ],options=options[2017]),
                    "higgsh390": make_obj([ basedirs[2017]+"Higgs_ttH_400.root", basedirs[2017]+"Higgs_tHW_400.root", basedirs[2017]+"Higgs_tHq_400.root", ],options=options[2017]),
                    "higgsh410": make_obj([ basedirs[2017]+"Higgs_ttH_400.root", basedirs[2017]+"Higgs_tHW_400.root", basedirs[2017]+"Higgs_tHq_400.root", ],options=options[2017]),
                    "higgsh430": make_obj([ basedirs[2017]+"Higgs_ttH_425.root", basedirs[2017]+"Higgs_tHW_425.root", basedirs[2017]+"Higgs_tHq_425.root", ],options=options[2017]),
                    "higgsh450": make_obj([ basedirs[2017]+"Higgs_ttH_450.root", basedirs[2017]+"Higgs_tHW_450.root", basedirs[2017]+"Higgs_tHq_450.root", ],options=options[2017]),
                    "higgsh470": make_obj([ basedirs[2017]+"Higgs_ttH_475.root", basedirs[2017]+"Higgs_tHW_475.root", basedirs[2017]+"Higgs_tHq_475.root", ],options=options[2017]),
                    "higgsh490": make_obj([ basedirs[2017]+"Higgs_ttH_500.root", basedirs[2017]+"Higgs_tHW_500.root", basedirs[2017]+"Higgs_tHq_500.root", ],options=options[2017]),
                    "higgsh510": make_obj([ basedirs[2017]+"Higgs_ttH_500.root", basedirs[2017]+"Higgs_tHW_500.root", basedirs[2017]+"Higgs_tHq_500.root", ],options=options[2017]),
                    "higgsh530": make_obj([ basedirs[2017]+"Higgs_ttH_525.root", basedirs[2017]+"Higgs_tHW_525.root", basedirs[2017]+"Higgs_tHq_525.root", ],options=options[2017]),
                    "higgsh550": make_obj([ basedirs[2017]+"Higgs_ttH_550.root", basedirs[2017]+"Higgs_tHW_550.root", basedirs[2017]+"Higgs_tHq_550.root", ],options=options[2017]),
                    "higgsh570": make_obj([ basedirs[2017]+"Higgs_ttH_575.root", basedirs[2017]+"Higgs_tHW_575.root", basedirs[2017]+"Higgs_tHq_575.root", ],options=options[2017]),
                    "higgsh590": make_obj([ basedirs[2017]+"Higgs_ttH_600.root", basedirs[2017]+"Higgs_tHW_600.root", basedirs[2017]+"Higgs_tHq_600.root", ],options=options[2017]),
                    "higgsh610": make_obj([ basedirs[2017]+"Higgs_ttH_600.root", basedirs[2017]+"Higgs_tHW_600.root", basedirs[2017]+"Higgs_tHq_600.root", ],options=options[2017]),
                    "higgsh630": make_obj([ basedirs[2017]+"Higgs_ttH_625.root", basedirs[2017]+"Higgs_tHW_625.root", basedirs[2017]+"Higgs_tHq_625.root", ],options=options[2017]),
                    "higgsh650": make_obj([ basedirs[2017]+"Higgs_ttH_650.root", basedirs[2017]+"Higgs_tHW_650.root", basedirs[2017]+"Higgs_tHq_650.root", ],options=options[2017]),

                    "higgsa350": make_obj([ basedirs[2017]+"Higgs_ttH_350.root", basedirs[2017]+"Higgs_tHW_350.root", basedirs[2017]+"Higgs_tHq_350.root", ],options=options[2017]),
                    "higgsa370": make_obj([ basedirs[2017]+"Higgs_ttH_375.root", basedirs[2017]+"Higgs_tHW_375.root", basedirs[2017]+"Higgs_tHq_375.root", ],options=options[2017]),
                    "higgsa390": make_obj([ basedirs[2017]+"Higgs_ttH_400.root", basedirs[2017]+"Higgs_tHW_400.root", basedirs[2017]+"Higgs_tHq_400.root", ],options=options[2017]),
                    "higgsa410": make_obj([ basedirs[2017]+"Higgs_ttH_400.root", basedirs[2017]+"Higgs_tHW_400.root", basedirs[2017]+"Higgs_tHq_400.root", ],options=options[2017]),
                    "higgsa430": make_obj([ basedirs[2017]+"Higgs_ttH_425.root", basedirs[2017]+"Higgs_tHW_425.root", basedirs[2017]+"Higgs_tHq_425.root", ],options=options[2017]),
                    "higgsa450": make_obj([ basedirs[2017]+"Higgs_ttH_450.root", basedirs[2017]+"Higgs_tHW_450.root", basedirs[2017]+"Higgs_tHq_450.root", ],options=options[2017]),
                    "higgsa470": make_obj([ basedirs[2017]+"Higgs_ttH_475.root", basedirs[2017]+"Higgs_tHW_475.root", basedirs[2017]+"Higgs_tHq_475.root", ],options=options[2017]),
                    "higgsa490": make_obj([ basedirs[2017]+"Higgs_ttH_500.root", basedirs[2017]+"Higgs_tHW_500.root", basedirs[2017]+"Higgs_tHq_500.root", ],options=options[2017]),
                    "higgsa510": make_obj([ basedirs[2017]+"Higgs_ttH_500.root", basedirs[2017]+"Higgs_tHW_500.root", basedirs[2017]+"Higgs_tHq_500.root", ],options=options[2017]),
                    "higgsa530": make_obj([ basedirs[2017]+"Higgs_ttH_525.root", basedirs[2017]+"Higgs_tHW_525.root", basedirs[2017]+"Higgs_tHq_525.root", ],options=options[2017]),
                    "higgsa550": make_obj([ basedirs[2017]+"Higgs_ttH_550.root", basedirs[2017]+"Higgs_tHW_550.root", basedirs[2017]+"Higgs_tHq_550.root", ],options=options[2017]),
                    "higgsa570": make_obj([ basedirs[2017]+"Higgs_ttH_575.root", basedirs[2017]+"Higgs_tHW_575.root", basedirs[2017]+"Higgs_tHq_575.root", ],options=options[2017]),
                    "higgsa590": make_obj([ basedirs[2017]+"Higgs_ttH_600.root", basedirs[2017]+"Higgs_tHW_600.root", basedirs[2017]+"Higgs_tHq_600.root", ],options=options[2017]),
                    "higgsa610": make_obj([ basedirs[2017]+"Higgs_ttH_600.root", basedirs[2017]+"Higgs_tHW_600.root", basedirs[2017]+"Higgs_tHq_600.root", ],options=options[2017]),
                    "higgsa630": make_obj([ basedirs[2017]+"Higgs_ttH_625.root", basedirs[2017]+"Higgs_tHW_625.root", basedirs[2017]+"Higgs_tHq_625.root", ],options=options[2017]),
                    "higgsa650": make_obj([ basedirs[2017]+"Higgs_ttH_650.root", basedirs[2017]+"Higgs_tHW_650.root", basedirs[2017]+"Higgs_tHq_650.root", ],options=options[2017]),

                    "higgsb350": make_obj([ basedirs[2017]+"Higgs_ttH_350.root", basedirs[2017]+"Higgs_tHW_350.root", basedirs[2017]+"Higgs_tHq_350.root", ],options=options[2017]),
                    "higgsb370": make_obj([ basedirs[2017]+"Higgs_ttH_375.root", basedirs[2017]+"Higgs_tHW_375.root", basedirs[2017]+"Higgs_tHq_375.root", ],options=options[2017]),
                    "higgsb390": make_obj([ basedirs[2017]+"Higgs_ttH_400.root", basedirs[2017]+"Higgs_tHW_400.root", basedirs[2017]+"Higgs_tHq_400.root", ],options=options[2017]),
                    "higgsb410": make_obj([ basedirs[2017]+"Higgs_ttH_400.root", basedirs[2017]+"Higgs_tHW_400.root", basedirs[2017]+"Higgs_tHq_400.root", ],options=options[2017]),
                    "higgsb430": make_obj([ basedirs[2017]+"Higgs_ttH_425.root", basedirs[2017]+"Higgs_tHW_425.root", basedirs[2017]+"Higgs_tHq_425.root", ],options=options[2017]),
                    "higgsb450": make_obj([ basedirs[2017]+"Higgs_ttH_450.root", basedirs[2017]+"Higgs_tHW_450.root", basedirs[2017]+"Higgs_tHq_450.root", ],options=options[2017]),
                    "higgsb470": make_obj([ basedirs[2017]+"Higgs_ttH_475.root", basedirs[2017]+"Higgs_tHW_475.root", basedirs[2017]+"Higgs_tHq_475.root", ],options=options[2017]),
                    "higgsb490": make_obj([ basedirs[2017]+"Higgs_ttH_500.root", basedirs[2017]+"Higgs_tHW_500.root", basedirs[2017]+"Higgs_tHq_500.root", ],options=options[2017]),
                    "higgsb510": make_obj([ basedirs[2017]+"Higgs_ttH_500.root", basedirs[2017]+"Higgs_tHW_500.root", basedirs[2017]+"Higgs_tHq_500.root", ],options=options[2017]),
                    "higgsb530": make_obj([ basedirs[2017]+"Higgs_ttH_525.root", basedirs[2017]+"Higgs_tHW_525.root", basedirs[2017]+"Higgs_tHq_525.root", ],options=options[2017]),
                    "higgsb550": make_obj([ basedirs[2017]+"Higgs_ttH_550.root", basedirs[2017]+"Higgs_tHW_550.root", basedirs[2017]+"Higgs_tHq_550.root", ],options=options[2017]),
                    "higgsb570": make_obj([ basedirs[2017]+"Higgs_ttH_575.root", basedirs[2017]+"Higgs_tHW_575.root", basedirs[2017]+"Higgs_tHq_575.root", ],options=options[2017]),
                    "higgsb590": make_obj([ basedirs[2017]+"Higgs_ttH_600.root", basedirs[2017]+"Higgs_tHW_600.root", basedirs[2017]+"Higgs_tHq_600.root", ],options=options[2017]),
                    "higgsb610": make_obj([ basedirs[2017]+"Higgs_ttH_600.root", basedirs[2017]+"Higgs_tHW_600.root", basedirs[2017]+"Higgs_tHq_600.root", ],options=options[2017]),
                    "higgsb630": make_obj([ basedirs[2017]+"Higgs_ttH_625.root", basedirs[2017]+"Higgs_tHW_625.root", basedirs[2017]+"Higgs_tHq_625.root", ],options=options[2017]),
                    "higgsb650": make_obj([ basedirs[2017]+"Higgs_ttH_650.root", basedirs[2017]+"Higgs_tHW_650.root", basedirs[2017]+"Higgs_tHq_650.root", ],options=options[2017]),

                    "hhat0p0": make_obj([ basedirs[2017]+"newhhat/HHAT_0p0.root" ],options=options[2017]),
                    "hhat0p08": make_obj([ basedirs[2017]+"newhhat/HHAT_0p08.root" ],options=options[2017]),
                    "hhat0p12": make_obj([ basedirs[2017]+"newhhat/HHAT_0p12.root" ],options=options[2017]),
                    "hhat0p16": make_obj([ basedirs[2017]+"newhhat/HHAT_0p16.root" ],options=options[2017]),

                    },
                2018: {

                    # "fakes": make_obj([
                    #     basedirs[2018]+"Data*.root",
                    #     basedirs[2018]+"TTWnlo.root",
                    #     basedirs[2018]+"TTZnlo.root",
                    #     basedirs[2018]+"TTHtoNonBB.root",
                    #     ] , options=options[2018]+" doFakes doData "),
                    # "flips": make_obj(basedirs[2018]+"Data*.root", options=options[2018]+" doFlips "),
                    # "data": make_obj(basedirs[2018]+"Data*.root", options=options[2018]+" doData "),

                    "fakes": make_obj([
                        basedirs[2018]+"ReRecoData*.root",
                        basedirs[2018]+"Data*Dv2.root",
                        basedirs[2018]+"TTWnlo.root",
                        basedirs[2018]+"TTZnlo.root",
                        basedirs[2018]+"TTHtoNonBB.root",
                        ] , options=options[2018]+" doFakes doData "),
                    "flips": make_obj([basedirs[2018]+"ReRecoData*.root",basedirs[2018]+"Data*Dv2.root"], options=options[2018]+" doFlips "),
                    "data": make_obj([basedirs[2018]+"ReRecoData*.root",basedirs[2018]+"Data*Dv2.root"], options=options[2018]+" doData "),

                    "tttt": make_obj(basedirs[2018]+"TTTTnew.root", options=options[2018]),
                    # "fakes_mc": make_obj(basedirs[2017]+"TTBAR*.root", options=options[2018]+ " doFakesMC "),
                    # "fakes_mc": make_obj([
                    #     basedirs[2018]+"TTDL.root",
                    #     basedirs[2018]+"TTSLtop.root",
                    #     basedirs[2018]+"TTSLtopbar.root",
                    #     ] , options=options[2018]+ " doTruthFake "),
                    "fakes_mc": make_obj([
                        basedirs[2018]+"TTBAR*.root",
                        basedirs[2018]+"WJets_HT200To400.root",
                        basedirs[2018]+"WJets_HT400To600.root",
                        basedirs[2018]+"WJets_HT600To800.root",
                        basedirs[2018]+"WJets_HT800To1200.root",
                        ] , options=options[2018]+ " doSkipMatching "),
                    # "fakes_mcwj": make_obj([
                    #     basedirs[2018]+"WJets_HT200To400.root",
                    #     basedirs[2018]+"WJets_HT400To600.root",
                    #     basedirs[2018]+"WJets_HT600To800.root",
                    #     basedirs[2018]+"WJets_HT800To1200.root",
                    #     ] , options=options[2018]+ " doTruthFake "),
                    # "fakes_mcwjhybrid": make_obj([
                    #     basedirs[2018]+"WJets_HT200To400.root",
                    #     basedirs[2018]+"WJets_HT400To600.root",
                    #     basedirs[2018]+"WJets_HT600To800.root",
                    #     basedirs[2018]+"WJets_HT800To1200.root",
                    #     ] , options=options[2018]+ " doFakesMC "),
                    "fakes_mchybrid": make_obj([
                        basedirs[2018]+"TTDL.root",
                        basedirs[2018]+"TTSLtop.root",
                        basedirs[2018]+"TTSLtopbar.root",
                        basedirs[2018]+"WJets_HT200To400.root",
                        basedirs[2018]+"WJets_HT400To600.root",
                        basedirs[2018]+"WJets_HT600To800.root",
                        basedirs[2018]+"WJets_HT800To1200.root",
                        ] , options=options[2018]+ " doFakesMC "),
                    "ttw": make_obj(basedirs[2018]+"TTWnlo.root", options=options[2018]),
                    "tth": make_obj(basedirs[2018]+"TTHtoNonBB.root", options=options[2018]),
                    "ttz": make_obj([
                        basedirs[2018]+"TTZnlo.root",
                        basedirs[2018]+"TTZLOW.root",
                        ] , options=options[2018]),
                    "xg": make_obj([
                        basedirs[2018]+"TGext.root",
                        basedirs[2018]+"TTGdilep.root",
                        basedirs[2018]+"TTGsinglelepbar.root",
                        basedirs[2018]+"TTGsinglelep.root",
                        basedirs[2018]+"WGToLNuGext.root",
                        basedirs[2018]+"ZG.root",
                        ],options=options[2018] + " doXgamma "),
                    "ttvv": make_obj([
                        basedirs[2018]+"TTHH.root",
                        basedirs[2018]+"TTWH.root",
                        basedirs[2018]+"TTWW.root",
                        basedirs[2018]+"TTWZ.root",
                        basedirs[2018]+"TTZZ.root",
                        ],options=options[2018]),
                    "rares": make_obj([
                        basedirs[2018]+"GGHtoZZto4L.root",
                        basedirs[2018]+"QQWW.root",
                        basedirs[2018]+"TWZ.root",
                        basedirs[2018]+"TZQ.root",
                        basedirs[2018]+"VHtoNonBB.root",
                        basedirs[2018]+"WWDPS.root",
                        basedirs[2018]+"WWW.root",
                        basedirs[2018]+"WWZ.root",
                        basedirs[2018]+"WZ.root",
                        basedirs[2018]+"WZG.root",
                        basedirs[2018]+"WZZ.root",
                        basedirs[2018]+"ZZ.root",
                        basedirs[2018]+"ZZZ.root",
                        basedirs[2018]+"TTTJ.root",
                        basedirs[2018]+"TTTW.root",
                        ],options=options[2018]),

                    "higgsh350": make_obj([ basedirs[2018]+"Higgs_ttH_375.root", basedirs[2018]+"Higgs_tHW_375.root", basedirs[2018]+"Higgs_tHq_375.root", ],options=options[2018]+"  "),
                    "higgsh370": make_obj([ basedirs[2018]+"Higgs_ttH_375.root", basedirs[2018]+"Higgs_tHW_375.root", basedirs[2018]+"Higgs_tHq_375.root", ],options=options[2018]+"  "),
                    "higgsh390": make_obj([ basedirs[2018]+"Higgs_ttH_400.root", basedirs[2018]+"Higgs_tHW_400.root", basedirs[2018]+"Higgs_tHq_400.root", ],options=options[2018]+"  "),
                    "higgsh410": make_obj([ basedirs[2018]+"Higgs_ttH_400.root", basedirs[2018]+"Higgs_tHW_400.root", basedirs[2018]+"Higgs_tHq_400.root", ],options=options[2018]+"  "),
                    "higgsh430": make_obj([ basedirs[2018]+"Higgs_ttH_425.root", basedirs[2018]+"Higgs_tHW_425.root", basedirs[2018]+"Higgs_tHq_425.root", ],options=options[2018]+"  "),
                    "higgsh450": make_obj([ basedirs[2018]+"Higgs_ttH_425.root", basedirs[2018]+"Higgs_tHW_450.root", basedirs[2018]+"Higgs_tHq_450.root", ],options=options[2018]+"  "),
                    "higgsh470": make_obj([ basedirs[2018]+"Higgs_ttH_475.root", basedirs[2018]+"Higgs_tHW_475.root", basedirs[2018]+"Higgs_tHq_475.root", ],options=options[2018]+"  "),
                    "higgsh490": make_obj([ basedirs[2018]+"Higgs_ttH_500.root", basedirs[2018]+"Higgs_tHW_500.root", basedirs[2018]+"Higgs_tHq_500.root", ],options=options[2018]+"  "),
                    "higgsh510": make_obj([ basedirs[2018]+"Higgs_ttH_500.root", basedirs[2018]+"Higgs_tHW_500.root", basedirs[2018]+"Higgs_tHq_500.root", ],options=options[2018]+"  "),
                    # "higgsh530": make_obj([ basedirs[2018]+"Higgs_ttH_525.root", basedirs[2018]+"Higgs_tHW_525.root", basedirs[2018]+"Higgs_tHq_525.root", ],options=options[2018]+"  "),
                    "higgsh530": make_obj([ basedirs[2018]+"Higgs_ttH_525.root", basedirs[2018]+"Higgs_tHW_525.root", basedirs[2018]+"Higgs_tHq_526.root", ],options=options[2018]+"  "),
                    "higgsh550": make_obj([ basedirs[2018]+"Higgs_ttH_550.root", basedirs[2018]+"Higgs_tHW_550.root", basedirs[2018]+"Higgs_tHq_550.root", ],options=options[2018]+"  "),
                    "higgsh570": make_obj([ basedirs[2018]+"Higgs_ttH_575.root", basedirs[2018]+"Higgs_tHW_575.root", basedirs[2018]+"Higgs_tHq_575.root", ],options=options[2018]+"  "),
                    "higgsh590": make_obj([ basedirs[2018]+"Higgs_ttH_575.root", basedirs[2018]+"Higgs_tHW_600.root", basedirs[2018]+"Higgs_tHq_600.root", ],options=options[2018]+"  "),
                    "higgsh610": make_obj([ basedirs[2018]+"Higgs_ttH_625.root", basedirs[2018]+"Higgs_tHW_600.root", basedirs[2018]+"Higgs_tHq_600.root", ],options=options[2018]+"  "),
                    "higgsh630": make_obj([ basedirs[2018]+"Higgs_ttH_625.root", basedirs[2018]+"Higgs_tHW_625.root", basedirs[2018]+"Higgs_tHq_625.root", ],options=options[2018]+"  "),
                    "higgsh650": make_obj([ basedirs[2018]+"Higgs_ttH_650.root", basedirs[2018]+"Higgs_tHW_650.root", basedirs[2018]+"Higgs_tHq_650.root", ],options=options[2018]+"  "),

                    "higgsa350": make_obj([ basedirs[2018]+"Higgs_ttH_375.root", basedirs[2018]+"Higgs_tHW_375.root", basedirs[2018]+"Higgs_tHq_375.root", ],options=options[2018]+"  "),
                    "higgsa370": make_obj([ basedirs[2018]+"Higgs_ttH_375.root", basedirs[2018]+"Higgs_tHW_375.root", basedirs[2018]+"Higgs_tHq_375.root", ],options=options[2018]+"  "),
                    "higgsa390": make_obj([ basedirs[2018]+"Higgs_ttH_400.root", basedirs[2018]+"Higgs_tHW_400.root", basedirs[2018]+"Higgs_tHq_400.root", ],options=options[2018]+"  "),
                    "higgsa410": make_obj([ basedirs[2018]+"Higgs_ttH_400.root", basedirs[2018]+"Higgs_tHW_400.root", basedirs[2018]+"Higgs_tHq_400.root", ],options=options[2018]+"  "),
                    "higgsa430": make_obj([ basedirs[2018]+"Higgs_ttH_425.root", basedirs[2018]+"Higgs_tHW_425.root", basedirs[2018]+"Higgs_tHq_425.root", ],options=options[2018]+"  "),
                    "higgsa450": make_obj([ basedirs[2018]+"Higgs_ttH_425.root", basedirs[2018]+"Higgs_tHW_450.root", basedirs[2018]+"Higgs_tHq_450.root", ],options=options[2018]+"  "),
                    "higgsa470": make_obj([ basedirs[2018]+"Higgs_ttH_475.root", basedirs[2018]+"Higgs_tHW_475.root", basedirs[2018]+"Higgs_tHq_475.root", ],options=options[2018]+"  "),
                    "higgsa490": make_obj([ basedirs[2018]+"Higgs_ttH_500.root", basedirs[2018]+"Higgs_tHW_500.root", basedirs[2018]+"Higgs_tHq_500.root", ],options=options[2018]+"  "),
                    "higgsa510": make_obj([ basedirs[2018]+"Higgs_ttH_500.root", basedirs[2018]+"Higgs_tHW_500.root", basedirs[2018]+"Higgs_tHq_500.root", ],options=options[2018]+"  "),
                    # "higgsa530": make_obj([ basedirs[2018]+"Higgs_ttH_525.root", basedirs[2018]+"Higgs_tHW_525.root", basedirs[2018]+"Higgs_tHq_525.root", ],options=options[2018]+"  "),
                    "higgsa530": make_obj([ basedirs[2018]+"Higgs_ttH_525.root", basedirs[2018]+"Higgs_tHW_525.root", basedirs[2018]+"Higgs_tHq_526.root", ],options=options[2018]+"  "),
                    "higgsa550": make_obj([ basedirs[2018]+"Higgs_ttH_550.root", basedirs[2018]+"Higgs_tHW_550.root", basedirs[2018]+"Higgs_tHq_550.root", ],options=options[2018]+"  "),
                    "higgsa570": make_obj([ basedirs[2018]+"Higgs_ttH_575.root", basedirs[2018]+"Higgs_tHW_575.root", basedirs[2018]+"Higgs_tHq_575.root", ],options=options[2018]+"  "),
                    "higgsa590": make_obj([ basedirs[2018]+"Higgs_ttH_575.root", basedirs[2018]+"Higgs_tHW_600.root", basedirs[2018]+"Higgs_tHq_600.root", ],options=options[2018]+"  "),
                    "higgsa610": make_obj([ basedirs[2018]+"Higgs_ttH_625.root", basedirs[2018]+"Higgs_tHW_600.root", basedirs[2018]+"Higgs_tHq_600.root", ],options=options[2018]+"  "),
                    "higgsa630": make_obj([ basedirs[2018]+"Higgs_ttH_625.root", basedirs[2018]+"Higgs_tHW_625.root", basedirs[2018]+"Higgs_tHq_625.root", ],options=options[2018]+"  "),
                    "higgsa650": make_obj([ basedirs[2018]+"Higgs_ttH_650.root", basedirs[2018]+"Higgs_tHW_650.root", basedirs[2018]+"Higgs_tHq_650.root", ],options=options[2018]+"  "),

                    "higgsb350": make_obj([ basedirs[2018]+"Higgs_ttH_375.root", basedirs[2018]+"Higgs_tHW_375.root", basedirs[2018]+"Higgs_tHq_375.root", ],options=options[2018]+"  "),
                    "higgsb370": make_obj([ basedirs[2018]+"Higgs_ttH_375.root", basedirs[2018]+"Higgs_tHW_375.root", basedirs[2018]+"Higgs_tHq_375.root", ],options=options[2018]+"  "),
                    "higgsb390": make_obj([ basedirs[2018]+"Higgs_ttH_400.root", basedirs[2018]+"Higgs_tHW_400.root", basedirs[2018]+"Higgs_tHq_400.root", ],options=options[2018]+"  "),
                    "higgsb410": make_obj([ basedirs[2018]+"Higgs_ttH_400.root", basedirs[2018]+"Higgs_tHW_400.root", basedirs[2018]+"Higgs_tHq_400.root", ],options=options[2018]+"  "),
                    "higgsb430": make_obj([ basedirs[2018]+"Higgs_ttH_425.root", basedirs[2018]+"Higgs_tHW_425.root", basedirs[2018]+"Higgs_tHq_425.root", ],options=options[2018]+"  "),
                    "higgsb450": make_obj([ basedirs[2018]+"Higgs_ttH_425.root", basedirs[2018]+"Higgs_tHW_450.root", basedirs[2018]+"Higgs_tHq_450.root", ],options=options[2018]+"  "),
                    "higgsb470": make_obj([ basedirs[2018]+"Higgs_ttH_475.root", basedirs[2018]+"Higgs_tHW_475.root", basedirs[2018]+"Higgs_tHq_475.root", ],options=options[2018]+"  "),
                    "higgsb490": make_obj([ basedirs[2018]+"Higgs_ttH_500.root", basedirs[2018]+"Higgs_tHW_500.root", basedirs[2018]+"Higgs_tHq_500.root", ],options=options[2018]+"  "),
                    "higgsb510": make_obj([ basedirs[2018]+"Higgs_ttH_500.root", basedirs[2018]+"Higgs_tHW_500.root", basedirs[2018]+"Higgs_tHq_500.root", ],options=options[2018]+"  "),
                    # "higgsb530": make_obj([ basedirs[2018]+"Higgs_ttH_525.root", basedirs[2018]+"Higgs_tHW_525.root", basedirs[2018]+"Higgs_tHq_525.root", ],options=options[2018]+"  "),
                    "higgsb530": make_obj([ basedirs[2018]+"Higgs_ttH_525.root", basedirs[2018]+"Higgs_tHW_525.root", basedirs[2018]+"Higgs_tHq_526.root", ],options=options[2018]+"  "),
                    "higgsb550": make_obj([ basedirs[2018]+"Higgs_ttH_550.root", basedirs[2018]+"Higgs_tHW_550.root", basedirs[2018]+"Higgs_tHq_550.root", ],options=options[2018]+"  "),
                    "higgsb570": make_obj([ basedirs[2018]+"Higgs_ttH_575.root", basedirs[2018]+"Higgs_tHW_575.root", basedirs[2018]+"Higgs_tHq_575.root", ],options=options[2018]+"  "),
                    "higgsb590": make_obj([ basedirs[2018]+"Higgs_ttH_575.root", basedirs[2018]+"Higgs_tHW_600.root", basedirs[2018]+"Higgs_tHq_600.root", ],options=options[2018]+"  "),
                    "higgsb610": make_obj([ basedirs[2018]+"Higgs_ttH_625.root", basedirs[2018]+"Higgs_tHW_600.root", basedirs[2018]+"Higgs_tHq_600.root", ],options=options[2018]+"  "),
                    "higgsb630": make_obj([ basedirs[2018]+"Higgs_ttH_625.root", basedirs[2018]+"Higgs_tHW_625.root", basedirs[2018]+"Higgs_tHq_625.root", ],options=options[2018]+"  "),
                    "higgsb650": make_obj([ basedirs[2018]+"Higgs_ttH_650.root", basedirs[2018]+"Higgs_tHW_650.root", basedirs[2018]+"Higgs_tHq_650.root", ],options=options[2018]+"  "),

                    "hhat0p0": make_obj([ basedirs[2018]+"newhhat/HHAT_0p0.root" ],options=options[2018]),
                    "hhat0p08": make_obj([ basedirs[2018]+"newhhat/HHAT_0p08.root" ],options=options[2018]),
                    "hhat0p12": make_obj([ basedirs[2018]+"newhhat/HHAT_0p12.root" ],options=options[2018]),
                    "hhat0p16": make_obj([ basedirs[2018]+"newhhat/HHAT_0p16.root" ],options=options[2018]),

                    }
                }

    if args.ss:

        options = {
                # 2016: "Data2016 quiet {} ".format(extra_global_options),
                # 2017: "Data2017 quiet {} minPtFake18 ".format(extra_global_options),
                # 2018: "Data2018 quiet {} minPtFake18 ".format(extra_global_options),
                # 2016: "Data2016 quiet {} ".format(extra_global_options),
                # 2017: "Data2017 quiet {} minPtFake18 partialUnblind ".format(extra_global_options),
                # 2018: "Data2018 quiet {} minPtFake18 partialUnblind ".format(extra_global_options),

                2016: "Data2016 quiet {} new2016FRBins ".format(extra_global_options),
                # 2017: "Data2017 quiet {} partialUnblind ".format(extra_global_options),
                # 2018: "Data2018 quiet {} partialUnblind ".format(extra_global_options),
                2017: "Data2017 quiet {} ".format(extra_global_options),
                2018: "Data2018 quiet {} ".format(extra_global_options),
                # 2017: "Data2017 quiet {} ".format(extra_global_options),
                # 2018: "Data2018 quiet {} ".format(extra_global_options),
                }


        chs = {

                2016: {

                    "fakes": make_obj([
                        basedirs[2016]+"Data*.root",
                        basedirs[2016]+"TTWnlo.root",
                        basedirs[2016]+"TTZnlo.root",
                        basedirs[2016]+"TTHtoNonBB.root",
                        basedirs[2016]+"QQWW.root",
                        basedirs[2016]+"WZ.root",
                        ] , options=options[2016]+" doFakes doData "),
                    "flips": make_obj(basedirs[2016]+"Data*.root", options=options[2016]+" doFlips doData "),
                    "data": make_obj(basedirs[2016]+"Data*.root", options=options[2016] + " doData "),
                    "fakes_mc": make_obj([
                        basedirs[2016]+"TTBAR_PH.root",
                        basedirs[2016]+"WJets_HT*.root",
                        basedirs[2016]+"ST*.root",
                        ] , options=options[2016]+ " doSkipMatching "),
                    "fakes_mchybrid": make_obj([
                        basedirs[2016]+"TTBAR_PH.root",
                        ] , options=options[2016]+ " doFakesMC "),
                    "ttw": make_obj(basedirs[2016]+"TTWnlo.root", options=options[2016]),
                    "tth": make_obj(basedirs[2016]+"TTHtoNonBB.root", options=options[2016]),
                    "ttz": make_obj([
                        basedirs[2016]+"TTZnlo.root",
                        basedirs[2016]+"TTZLOW.root",
                        ] , options=options[2016]),
                    "ww": make_obj(basedirs[2016]+"QQWW.root", options=options[2016]),
                    "wz": make_obj([
                        basedirs[2016]+"WZ.root",
                        ],options=options[2016]),
                    "xg": make_obj([
                        basedirs[2016]+"TGext.root",
                        basedirs[2016]+"TTGdilep.root",
                        basedirs[2016]+"TTGsinglelepbar.root",
                        basedirs[2016]+"TTGsinglelep.root",
                        basedirs[2016]+"WGToLNuGext.root",
                        basedirs[2016]+"ZG.root",
                        ],options=options[2016] + " doXgamma "),
                    "rares": make_obj([
                        basedirs[2016]+"GGHtoZZto4L.root",
                        basedirs[2016]+"TWZ.root",
                        basedirs[2016]+"TZQ.root",
                        basedirs[2016]+"VHtoNonBB.root",
                        basedirs[2016]+"WWDPS.root",
                        basedirs[2016]+"WWG.root",
                        basedirs[2016]+"WWW.root",
                        basedirs[2016]+"WWZ.root",
                        basedirs[2016]+"WZG.root",
                        basedirs[2016]+"WZZ.root",
                        basedirs[2016]+"ZZ.root",
                        basedirs[2016]+"ZZcont*.root",
                        basedirs[2016]+"ZZZ.root",
                        basedirs[2016]+"TTTTnew.root",
                        basedirs[2016]+"TTHH.root",
                        basedirs[2016]+"TTWH.root",
                        basedirs[2016]+"TTWW.root",
                        basedirs[2016]+"TTWZ.root",
                        basedirs[2016]+"TTZH.root",
                        basedirs[2016]+"TTZZ.root",
                        basedirs[2016]+"TTTJ.root",
                        basedirs[2016]+"TTTW.root",
                        ],options=options[2016]),

                    "rpv_t1tbs_m1000": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1000.root" ],options=options[2016]),
                    "rpv_t1tbs_m1100": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1100.root" ],options=options[2016]),
                    "rpv_t1tbs_m1200": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1200.root" ],options=options[2016]),
                    "rpv_t1tbs_m1300": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1300.root" ],options=options[2016]),
                    "rpv_t1tbs_m1400": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1400.root" ],options=options[2016]),
                    "rpv_t1tbs_m1500": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1500.root" ],options=options[2016]),
                    "rpv_t1tbs_m1600": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1600.root" ],options=options[2016]),
                    "rpv_t1tbs_m1700": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1700.root" ],options=options[2016]),
                    "rpv_t1tbs_m1800": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1800.root" ],options=options[2016]),
                    "rpv_t1tbs_m1900": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino1900.root" ],options=options[2016]),
                    "rpv_t1tbs_m2000": make_obj([ basedirs[2016]+"RPV_T1tbs_mGluino2000.root" ],options=options[2016]),

                    # "fcnc_tthut": make_obj([ basedirs[2016]+"FCNC_hut_top.root",  basedirs[2016]+"FCNC_hut_antitop.root"  ],options=options[2016]),

                    # "zzcont": make_obj(basedirs[2016]+"ZZcont*.root", options=options[2016]), # NOTE in rares
                    # "zzreg": make_obj(basedirs[2016]+"ZZ.root", options=options[2016]),
                    # "test_wwdps": make_obj(basedirs[2016]+"WWDPS.root", options=options[2016]),
                    },
                2017: {

                    "fakes": make_obj([
                        basedirs[2017]+"Data*.root",
                        basedirs[2017]+"TTWnlo.root",
                        basedirs[2017]+"TTZnlo.root",
                        basedirs[2017]+"TTHtoNonBB.root",
                        basedirs[2017]+"QQWW.root",
                        basedirs[2017]+"WZ.root",
                        ] , options=options[2017]+" doFakes doData "),
                    "flips": make_obj(basedirs[2017]+"Data*.root", options=options[2017]+" doFlips "),
                    "data": make_obj(basedirs[2017]+"Data*.root", options=options[2017]+" doData "),
                    "fakes_mc": make_obj([
                        basedirs[2017]+"TTBAR*.root",
                        basedirs[2017]+"WJets_HT*.root",
                        basedirs[2017]+"ST*.root",
                        ] , options=options[2017]+ " doSkipMatching "),
                    "fakes_mchybrid": make_obj([
                        basedirs[2017]+"TTBAR*.root",
                        ] , options=options[2017]+ " doFakesMC "),
                    "ttw": make_obj(basedirs[2017]+"TTWnlo.root", options=options[2017]),
                    "tth": make_obj(basedirs[2017]+"TTHtoNonBB.root", options=options[2017]),
                    "ttz": make_obj([
                        basedirs[2017]+"TTZnlo.root",
                        basedirs[2017]+"TTZLOW.root",
                        ] , options=options[2017]),
                    "ww": make_obj(basedirs[2017]+"QQWW.root", options=options[2017]),
                    "wz": make_obj([
                        basedirs[2017]+"WZ.root",
                        ],options=options[2017]),
                    "xg": make_obj([
                        basedirs[2017]+"TGext.root",
                        basedirs[2017]+"TTGdilep.root",
                        basedirs[2017]+"TTGsinglelepbar.root",
                        basedirs[2017]+"TTGsinglelep.root",
                        basedirs[2017]+"WGToLNuGext.root",
                        basedirs[2017]+"ZG.root",
                        ],options=options[2017] + " doXgamma "),
                    "rares": make_obj([
                        basedirs[2017]+"GGHtoZZto4L.root",
                        basedirs[2017]+"TWZ.root",
                        basedirs[2017]+"TZQ.root",
                        basedirs[2017]+"VHtoNonBB.root",
                        basedirs[2017]+"WWDPS.root",
                        basedirs[2017]+"WWG.root",
                        basedirs[2017]+"WWW.root",
                        basedirs[2017]+"WWZ.root",
                        basedirs[2017]+"WZG.root",
                        basedirs[2017]+"WZZ.root",
                        basedirs[2017]+"ZZ.root",
                        basedirs[2017]+"ZZcont*.root",
                        basedirs[2017]+"ZZZ.root",
                        basedirs[2017]+"TTTTnew.root",
                        basedirs[2017]+"TTHH.root",
                        basedirs[2017]+"TTWH.root",
                        basedirs[2017]+"TTWW.root",
                        basedirs[2017]+"TTWZ.root",
                        basedirs[2017]+"TTZH.root",
                        basedirs[2017]+"TTZZ.root",
                        basedirs[2017]+"TTTJ.root",
                        basedirs[2017]+"TTTW.root",
                        ],options=options[2017]),

                    "rpv_t1tbs_m1000": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1000.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1100": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1100.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1200": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1200.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1300": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1300.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1400": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1400.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1500": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1500.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1600": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1600.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1700": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1700.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1800": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1800.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m1900": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino1900.root" ],options=options[2017]+"  "),
                    "rpv_t1tbs_m2000": make_obj([ basedirs[2017]+"RPV_T1tbs_mGluino2000.root" ],options=options[2017]+"  "),

                    # "fcnc_tthut": make_obj([ basedirs[2017]+"FCNC_hut_top.root",  basedirs[2017]+"FCNC_hut_antitop.root"  ],options=options[2017]),

                    # "zzcont": make_obj(basedirs[2017]+"ZZcont*.root", options=options[2017]), # NOTE in rares
                    # "zzreg": make_obj(basedirs[2017]+"ZZ.root", options=options[2017]),

                    },
                2018: {

                    "fakes": make_obj([
                        basedirs[2018]+"ReRecoData*.root",
                        basedirs[2018]+"Data*Dv2.root",
                        basedirs[2018]+"TTWnlo.root",
                        basedirs[2018]+"TTZnlo.root",
                        basedirs[2018]+"TTHtoNonBB.root",
                        basedirs[2018]+"QQWW.root",
                        basedirs[2018]+"WZ.root",
                        ] , options=options[2018]+" doFakes doData "),
                    "flips": make_obj([basedirs[2018]+"ReRecoData*.root",basedirs[2018]+"Data*Dv2.root"], options=options[2018]+" doFlips "),
                    "data": make_obj([basedirs[2018]+"ReRecoData*.root",basedirs[2018]+"Data*Dv2.root"], options=options[2018]+" doData "),

                    "fakes_mc": make_obj([
                        basedirs[2018]+"TTBAR*.root",
                        basedirs[2018]+"WJets.root",
                        basedirs[2018]+"ST*.root",
                        ] , options=options[2018]+ " doSkipMatching "),
                    "fakes_mchybrid": make_obj([
                        basedirs[2018]+"TTBAR*.root",
                        ] , options=options[2018]+ " doFakesMC "),
                    "ttw": make_obj(basedirs[2018]+"TTWnlo.root", options=options[2018]),
                    "tth": make_obj(basedirs[2018]+"TTHtoNonBB.root", options=options[2018]),
                    "ttz": make_obj([
                        basedirs[2018]+"TTZnlo.root",
                        basedirs[2018]+"TTZLOW.root",
                        ] , options=options[2018]),
                    "ww": make_obj(basedirs[2018]+"QQWW.root", options=options[2018]),
                    "wz": make_obj([
                        basedirs[2018]+"WZ.root",
                        ],options=options[2018]),
                    "xg": make_obj([
                        basedirs[2018]+"TGext.root",
                        basedirs[2018]+"TTGdilep.root",
                        basedirs[2018]+"TTGsinglelepbar.root",
                        basedirs[2018]+"TTGsinglelep.root",
                        basedirs[2018]+"WGToLNuGext.root",
                        basedirs[2018]+"ZG.root",
                        ],options=options[2018] + " doXgamma "),
                    "rares": make_obj([
                        basedirs[2018]+"GGHtoZZto4L.root",
                        basedirs[2018]+"TWZ.root",
                        basedirs[2018]+"TZQ.root",
                        basedirs[2018]+"VHtoNonBB.root",
                        basedirs[2018]+"WWDPS.root",
                        basedirs[2018]+"WWG.root",
                        basedirs[2018]+"WWW.root",
                        basedirs[2018]+"WWZ.root",
                        basedirs[2018]+"WZG.root",
                        basedirs[2018]+"WZZ.root",
                        basedirs[2018]+"ZZ.root",
                        basedirs[2018]+"ZZcont*.root",
                        basedirs[2018]+"ZZZ.root",
                        basedirs[2018]+"TTTTnew.root",
                        basedirs[2018]+"TTHH.root",
                        basedirs[2018]+"TTWH.root",
                        basedirs[2018]+"TTWW.root",
                        basedirs[2018]+"TTWZ.root",
                        basedirs[2018]+"TTZH.root",
                        basedirs[2018]+"TTZZ.root",
                        basedirs[2018]+"TTTJ.root",
                        basedirs[2018]+"TTTW.root",
                        ],options=options[2018]),

                    "rpv_t1tbs_m1000": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1000.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1100": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1100.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1200": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1200.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1300": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1300.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1400": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1400.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1500": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1500.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1600": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1600.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1700": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1700.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1800": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1800.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m1900": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino1900.root" ],options=options[2018]+"  "),
                    "rpv_t1tbs_m2000": make_obj([ basedirs[2018]+"RPV_T1tbs_mGluino2000.root" ],options=options[2018]+"  "),

                    # "fcnc_tthut": make_obj([ basedirs[2017]+"FCNC_hut_top.root",  basedirs[2017]+"FCNC_hut_antitop.root"  ],options=(options[2017]+" FakeLumi2018")),

                    # "zzcont": make_obj(basedirs[2018]+"ZZcont*.root", options=options[2018]), # NOTE, i put this into rares
                    # "zzreg": make_obj(basedirs[2018]+"ZZ.root", options=options[2018]),

                    }
                }

    # for year in years_to_consider:
    #     print "------- {} ------".format(year)
    #     for proc,obj in chs[year].items():
    #         print "\t", proc, "\t\t", ",".join(sorted(map(lambda x:x.split("/")[-1].split(".")[0],[x.GetTitle() for x in obj["ch"].GetListOfFiles()])))
    # sys.exit()


    do_slim = args.slim
    if args.fastsim:

        ####################################
        ############ T1TTTT ################
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T1TTTT.root",
                    basedirs[2017]+"T1TTTT.root",
                    basedirs[2018]+"T1TTTT.root",
                    ], procbase="fs_t1tttt", range1=[600,2200], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1600_m600",
                "m1800_m100",
                "m1800_m1000",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T1TTTT.root", options=options[y])

        ####################################
        ############ T6TTWW ################
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T6TTWW.root",
                    basedirs[2017]+"T6TTWW.root",
                    basedirs[2018]+"T6TTWW.root",
                    ], procbase="fs_t6ttww", range1=[250,1400], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1000_m600",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T6TTWW.root", options=options[y])

        ####################################
        ############ T5QQQQVV ##############
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T5QQQQVV_main.root",
                    basedirs[2017]+"T5QQQQVV_main.root",
                    basedirs[2018]+"T5QQQQVV_main.root",
                    ], procbase="fs_t5qqqqvv", range1=[600,2000], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1250_m1050",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T5QQQQVV_main.root", options=options[y])

        ####################################
        ############ T5QQQQVV DM20 #########
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T5QQQQVV_dm20.root",
                    basedirs[2017]+"T5QQQQVV_dm20.root",
                    basedirs[2018]+"T5QQQQVV_dm20.root",
                    ], procbase="fs_t5qqqqvvdm20", range1=[600,2000], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1450_m150",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T5QQQQVV_dm20.root", options=options[y])

        ####################################
        ############ T5QQQQWW ##############
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T5QQQQVV_main.root",
                    basedirs[2017]+"T5QQQQVV_main.root",
                    basedirs[2018]+"T5QQQQVV_main.root",
                    ], procbase="fs_t5qqqqww", range1=[600,2000], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1250_m1050",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T5QQQQVV_main.root", options=options[y])

        ####################################
        ############ T5QQQQWW DM20 #########
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T5QQQQVV_dm20.root",
                    basedirs[2017]+"T5QQQQVV_dm20.root",
                    basedirs[2018]+"T5QQQQVV_dm20.root",
                    ], procbase="fs_t5qqqqwwdm20", range1=[600,2000], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m950_m850",
                "m900_m600",
                "m1400_m150",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T5QQQQVV_dm20.root", options=options[y])

        ####################################
        ############ T5TTTT ################
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T5TTTT.root",
                    basedirs[2017]+"T5TTTT.root",
                    basedirs[2018]+"T5TTTT.root",
                    ], procbase="fs_t5tttt", range1=[600,2300], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1800_m100",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T5TTTT.root", options=options[y])

        ####################################
        ############ T5TTCC ################
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T5TTCC_both.root",
                    basedirs[2017]+"T5TTCC_both.root",
                    basedirs[2018]+"T5TTCC_both.root",
                    ], procbase="fs_t5ttcc", range1=[800,2300], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1400_m150", # FIXME
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T5TTCC_both.root", options=options[y])

        ####################################
        ############ T1TTBB ################
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T1TTBB.root",
                    basedirs[2017]+"T1TTBB.root",
                    basedirs[2018]+"T1TTBB.root",
                    ], procbase="fs_t1ttbb", range1=[800,2300], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1400_m150",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T1TTBB.root", options=options[y])

        ####################################
        ############ T6TTHZ (0% Z) ########
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T6TTHZ_both.root",
                    basedirs[2017]+"T6TTHZ_both.root",
                    basedirs[2018]+"T6TTHZ_both.root",
                    ], procbase="fs_t6tthzbrh", range1=[200,1300], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "t6tthzbrh_m600_m375",
                "t6tthzbrh_m600_m575",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T6TTHZ_both.root", options=options[y])

        ####################################
        ############ T6TTHZ (50% Z) ########
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T6TTHZ_both.root",
                    basedirs[2017]+"T6TTHZ_both.root",
                    basedirs[2018]+"T6TTHZ_both.root",
                    ], procbase="fs_t6tthzbrb", range1=[200,1300], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "t6tthzbrb_m600_m375",
                "t6tthzbrb_m600_m575",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T6TTHZ_both.root", options=options[y])

        ####################################
        ############ T6TTHZ (100% Z) ########
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T6TTHZ_both.root",
                    basedirs[2017]+"T6TTHZ_both.root",
                    basedirs[2018]+"T6TTHZ_both.root",
                    ], procbase="fs_t6tthzbrz", range1=[200,1300], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "t6tthzbrz_m600_m375",
                "t6tthzbrz_m600_m575",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T6TTHZ_both.root", options=options[y])

        ####################################
        ############ T1QQQQL (RPV) #########
        ####################################
        procnames = get_fastsim_procnames([
                    basedirs[2016]+"T1QQQQL_main.root",
                    basedirs[2017]+"T1QQQQL_main.root",
                    basedirs[2018]+"T1QQQQL_main.root",
                    ], procbase="fs_t1qqqql", range1=[1600,2700], filt=args.proc)
        if do_slim:
            procnames = [pn for pn in procnames if any(x in pn for x in [
                "m1600_m1",
                "m2400_m1",
                ])]
        for pn in procnames: 
            for y in [2016,2017,2018]:
                chs[y][pn] = make_obj(basedirs[y]+"T1QQQQL_main.root", options=options[y])

    def run_chain((index,info)):
        ch, options, outputdir = info
        t0 = time.time()
        ret = r.getyields(ch, options, outputdir)
        t1 = time.time()
        return index, [ret, ch.GetTitle(), t1-t0]

    to_run = []
    already_done = []
    if args.skip_already_done and os.path.exists("../limits/{}/".format(args.tag)):
        parse = lambda x: x.rsplit("/",1)[1].split("_histos")[0]
        already_done = map(parse,glob.glob("../limits/{}/*_srhh_2016.root".format(args.tag)))
        print "Skipping up to {} processes (e.g., {}, ...)".format(len(already_done),already_done[0])
    for year in years_to_consider:
        if (args.year) and (year != args.year): continue
        for proc,obj in chs[year].items():
            # if (len(args.proc) > 0) and (proc != args.proc): continue
            if (len(args.proc) > 0) and not fnmatch.fnmatch(proc,args.proc): continue
            if (len(args.excludeproc) > 0) and fnmatch.fnmatch(proc,args.excludeproc): continue
            if args.skip_already_done and (proc in already_done): continue
            opts = obj["options"]
            if args.verbosity >= 1:
                opts = opts.replace("quiet","")
            if args.year and args.proc and "*" not in args.proc:  # if one process, show the progress bar
                opts = opts.replace("quiet","")
            # Change chain titles to proc so that we output the right root file name
            obj["ch"].SetTitle("{}".format(proc))
            to_run.append([obj["ch"], opts, outputdir])
            if args.verbosity >= 2:
                print "Adding:", obj["ch"].GetTitle(), opts, outputdir

    print "Running on {} chains".format(len(to_run))

    if args.maxprocs > 0:
        print "Actually, you specified a maximum of {} chains, so taking the first ones".format(args.maxprocs)
        to_run = to_run[:args.maxprocs]

    os.system("mkdir -p {}".format(outputdir))

    # Make sure all the requested root files actually exist
    for ch,opts,_ in to_run:
        for fname in [str(x.GetTitle()) for x in ch.GetListOfFiles()]:
            if not os.path.exists(fname):
                print "[!] {} does not exist!".format(fname)

    # to_run = [t for t in to_run if "doXgamma" in t[1]]
    # print to_run

    # to_run = [t for t in to_run if ("doData " in t[1] and "2016" in t[1] and "Fake" not in t[1] and "Flip" not in t[1])]
    # to_run[0][1] = to_run[0][1].replace("quiet","")
    # print to_run
    # run_chain((0,to_run[0]))

    # to_run = [t for t in to_run if ("doFakes " in t[1] and "2016" in t[1])]
    # to_run[0][1] = to_run[0][1].replace("quiet","")
    # print to_run
    # run_chain((0,to_run[0]))

    procnames = list(set([x[0].GetTitle() for x in to_run]))
    fastsim_procnames = [pn for pn in procnames if "fs_" in pn]
    higgs_procnames = [pn for pn in procnames if "higgs" in pn]
    oblique_procnames = [pn for pn in procnames if "hhat" in pn]
    rpv_procnames = [pn for pn in procnames if "rpv" in pn]
    fcnc_procnames = [pn for pn in procnames if "fcnc" in pn]
    # print higgs_procnames

    if not args.noloop:

        def callback(ret):
            pass
        # if len(to_run) < 30:
        #     def callback(ret):
        #         ret, proc, t = ret
        #         print "Processed {} in {:.1f} seconds".format(proc,t)
        # else:
        #     def callback(ret):
        #         pass

        if len(to_run) > 3000:
            print "[!] You might want to kill this at some point and run the rest with --skip_already_done because of memory leaks"

        # Now run them
        if len(to_run) == 1:
            print "Running one chain"
            map(run_chain,enumerate(to_run))
            print "Done"
        else:
            os.nice(4)
            runner = pyrun.Runner(nproc=min(args.ncpu,len(to_run)), func=run_chain, dot_type=(3 if len(to_run)<500 else 0))
            runner.add_args(to_run)
            runner.run(print_callback=callback)

    if args.tag:
        outdir_limits = "../limits/{}/".format(args.tag)
        os.system("mkdir -p {}".format(outdir_limits))
        os.system("cp ../misc/signal_regions.h {}/".format(outdir_limits))
        os.system("cp ../misc/bdt.h {}/".format(outdir_limits))
        os.system("cp yieldMaker.C make_shape_hists.py py_doAll.py plot_all.py {}/".format(outdir_limits))

        if args.shapes:
            import make_shape_hists
            regions = ["SRCR","SRDISC"] if not "noBDT" in extra_global_options else ["SRCR"]
            make_shape_hists.make_root_files(
                    outputdir=outdir_limits,
                    inputdir=args.out,
                    extra_procs=fastsim_procnames+higgs_procnames+oblique_procnames+rpv_procnames+fcnc_procnames,
                    regions=regions,
                    verbose=(args.verbosity >= 2),
                    doss=args.ss,
                    )

        if args.plots:
            # numba njit causes segfault when pyroot has been imported (more specifically, once we've gotten a root MethodProxy somehow)
            # so prevent uproot from importing it (which prevents the njit)
            # https://github.com/scikit-hep/uproot/issues/58
            # https://stackoverflow.com/questions/1350466/preventing-python-code-from-importing-certain-modules
            import sys
            sys.modules["numba"] = None
            import plot_all


            signames = ["tttt"]
            if args.ss:
                signames = ["fs_t1tttt_m1600_m600"]
                # signames = fastsim_procnames[:1]
            plot_all.make_plots(
                    outputdir="{}/plots/".format(outdir_limits),
                    inputdir=args.out,
                    year=2016,
                    lumi="35.9",
                    other_years = [],
                    doss=args.ss,
                    signames=signames,
                    **plot_kwargs
                    )

            plot_all.make_plots(
                    outputdir="{}/plots/".format(outdir_limits),
                    inputdir=args.out,
                    year=2017,
                    lumi=("41.5"),
                    other_years = [],
                    doss=args.ss,
                    signames=signames,
                    **plot_kwargs
                    )

            plot_all.make_plots(
                    outputdir="{}/plots/".format(outdir_limits),
                    inputdir=args.out,
                    year=2018,
                    lumi=("59.7"),
                    other_years = [],
                    doss=args.ss,
                    signames=signames,
                    **plot_kwargs
                    )

            plot_all.make_plots(
                    outputdir="{}/plots/".format(outdir_limits),
                    inputdir=args.out,
                    year=2018,
                    # lumi="136.3", # 2016+2017+2018 --> 35.922+41.53+58.83 = 136.3
                    lumi=("137"),
                    other_years = [2016,2017],
                    doss=args.ss,
                    signames=signames,
                    **plot_kwargs
                    )

    print "end"
