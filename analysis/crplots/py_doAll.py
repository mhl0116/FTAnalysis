import os
import analysis.utils.pyrun as pyrun
import ROOT as r
r.gROOT.SetBatch()

r.gROOT.ProcessLine(".L ../misc/class_files/v8.02/SS.cc+")
r.gROOT.ProcessLine(".L ../../common/CORE/Tools/dorky/dorky.cc+")
r.gROOT.ProcessLine(".L ScanChain.C+")


years_to_consider = [
        # 2016,
        2017,
        # 2018,
        ]

basedirs ={
        2016: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.08_all/output/year_2016/",
        2017: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.08_all/output/year_2017/",
        2018: "/nfs-7/userdata/namin/tupler_babies/merged/FT/v3.08_all/output/year_2018/",
        }

outputdir = "outputs_temp"
options = {
        2016: "useInclusiveSFs Data2016 quiet ",
        2017: "useInclusiveSFs Data2017 minPtFake18 quiet ",
        2018: "useInclusiveSFs Data2018 minPtFake18 quiet ",
        }

def make_objs(fpatts=[],options="",treename="t"):
    if type(fpatts) == str: fpatts = [fpatts]
    ch = r.TChain(treename)
    for fpatt in fpatts:
        ch.Add(fpatt)
    return {"ch": ch, "options": options}

chs = {
        2016: {
            "tt": make_objs(basedirs[2016]+"TTBAR*.root", options=options[2016]),
            "fakes": make_objs(basedirs[2016]+"Data*.root", options=options[2016]+" doFakes"),
            "flips": make_objs(basedirs[2016]+"Data*.root", options=options[2016]+" doFlips"),
            "data": make_objs(basedirs[2016]+"Data*.root", options=options[2016]),
            "ttw": make_objs(basedirs[2016]+"TTWnlo.root", options=options[2016]),
            "tth": make_objs(basedirs[2016]+"TTHtoNonBB.root", options=options[2016]),
            "dy": make_objs([
                basedirs[2016]+"DY_high.root",
                basedirs[2016]+"DY_low.root",
                ], options=options[2016]),
            "wjets": make_objs(basedirs[2016]+"WJets*.root", options=options[2016]),
            "ttfake": make_objs(basedirs[2016]+"TTBAR*.root", options=options[2016]+ "doTruthFake"),
            # "ttlomg": make_objs(basedirs[2016]+"TTLOMG.root", options=options[2016]),
            # "ttslph": make_objs(basedirs[2016]+"TTSLPH.root", options=options[2016]),
            "ttz": make_objs([
                basedirs[2016]+"TTZnlo.root",
                basedirs[2016]+"TTZLOW.root",
                ]
                , options=options[2016]),
            "vv": make_objs([
                basedirs[2016]+"WZ.root",
                basedirs[2016]+"QQWW.root",
                basedirs[2016]+"WWDPS.root",
                basedirs[2016]+"ZZ.root",
                ],options=options[2016]),
            "rares": make_objs([
                basedirs[2016]+"TTG.root",
                basedirs[2016]+"WZG.root",
                basedirs[2016]+"WGToLNuGext.root",
                basedirs[2016]+"VHtoNonBB.root",
                basedirs[2016]+"GGHtoZZto4L.root",
                basedirs[2016]+"ZG.root",
                basedirs[2016]+"WZZ.root",
                basedirs[2016]+"ZZZ.root",
                basedirs[2016]+"WWZ.root",
                basedirs[2016]+"WWW.root",
                basedirs[2016]+"TZQ.root",
                basedirs[2016]+"TWZ.root",
                basedirs[2016]+"TTZZ.root",
                basedirs[2016]+"TTWZ.root",
                basedirs[2016]+"TTWW.root",
                basedirs[2016]+"TTWH.root",
                basedirs[2016]+"TTHH.root",
                basedirs[2016]+"TTTW.root",
                basedirs[2016]+"TTTJ.root",
                ],options=options[2016]),
            "singletop": make_objs([
                basedirs[2016]+"ST1.root",
                basedirs[2016]+"ST2.root",
                ],options=options[2016]),
            },
        2017: {

            "tt": make_objs(basedirs[2017]+"TTBAR*.root", options=options[2017]),
            "fakes": make_objs(basedirs[2017]+"Data*.root", options=options[2017]+" doFakes"),
            "flips": make_objs(basedirs[2017]+"Data*.root", options=options[2017]+" doFlips"),
            "data": make_objs(basedirs[2017]+"Data*.root", options=options[2017]),
            "ttw": make_objs(basedirs[2017]+"TTWnlo.root", options=options[2017]),
            "tth": make_objs(basedirs[2017]+"TTHtoNonBB.root", options=options[2017]),
            "dy": make_objs([
                basedirs[2017]+"DY_high.root",
                basedirs[2017]+"DY_low.root",
                ], options=options[2017]),
            "wjets": make_objs(basedirs[2017]+"WJets.root", options=options[2017]),
            "ttfake": make_objs(basedirs[2017]+"TTBAR*.root", options=options[2017]+ "doTruthFake"),
            # "ttlomg": make_objs(basedirs[2017]+"TTLOMG.root", options=options[2017]),
            # "ttslph": make_objs(basedirs[2017]+"TTSLPH.root", options=options[2017]),
            "ttdl0jet": make_objs([
                basedirs[2017]+"TTdilep0jet.root",
                "/home/users/namin/2018/fourtop/all/FTAnalysis/babymaking/batch/output_isr_ttdilep0jet.root",
                ], options=options[2017]),
            "ttdl1jet": make_objs([
                basedirs[2017]+"TTdilep1jet.root",
                "/home/users/namin/2018/fourtop/all/FTAnalysis/babymaking/batch/output_isr_ttdilep1jet.root",
                ], options=options[2017]),
            "ttz": make_objs([
                basedirs[2017]+"TTZnlo.root",
                basedirs[2017]+"TTZLOW.root",
                ]
                , options=options[2017]),
            "vv": make_objs([
                basedirs[2017]+"WZ.root",
                basedirs[2017]+"QQWW.root",
                basedirs[2017]+"WW.root",
                basedirs[2017]+"WWDPS.root",
                basedirs[2017]+"ZZ.root",
                ],options=options[2017]),
            "rares": make_objs([
                basedirs[2017]+"WZG.root",
                basedirs[2017]+"WZZ.root",
                basedirs[2017]+"ZZZ.root",
                basedirs[2017]+"WWZ.root",
                basedirs[2017]+"WWW.root",
                basedirs[2017]+"TZQ.root",
                basedirs[2017]+"TTZZ.root",
                basedirs[2017]+"TTWZ.root",
                basedirs[2017]+"TTWW.root",
                basedirs[2017]+"TTWH.root",
                basedirs[2017]+"TTHH.root",
                basedirs[2017]+"TTTW.root",
                basedirs[2017]+"TTTJ.root",
                basedirs[2017]+"VHtoNonBB.root",
                ],options=options[2017]),
            "singletop": make_objs([
                basedirs[2017]+"STtop.root",
                basedirs[2017]+"STantitop.root",
                ],options=options[2017]),

            },
        2018: {

            "fakes": make_objs(basedirs[2018]+"Data*.root", options=options[2018]+" doFakes"),
            "flips": make_objs(basedirs[2018]+"Data*.root", options=options[2018]+" doFlips"),
            "data": make_objs(basedirs[2018]+"Data*.root", options=options[2018]),
            # 2017 for everything other than data for now, because...uh...there's no usable 2018 MC, even though it's almost 2019 :)
            "tt": make_objs(basedirs[2017]+"TTBAR*.root", options=options[2018]),
            "ttw": make_objs(basedirs[2017]+"TTWnlo.root", options=options[2018]),
            "tth": make_objs(basedirs[2017]+"TTHtoNonBB.root", options=options[2018]),
            "dy": make_objs([
                basedirs[2017]+"DY_high.root",
                basedirs[2017]+"DY_low.root",
                ], options=options[2018]),
            "wjets": make_objs(basedirs[2017]+"WJets.root", options=options[2018]),
            "ttfake": make_objs(basedirs[2017]+"TTBAR*.root", options=options[2018]+ "doTruthFake"),
            "ttz": make_objs([
                basedirs[2017]+"TTZnlo.root",
                basedirs[2017]+"TTZLOW.root",
                ], options=options[2018]),
            "vv": make_objs([
                basedirs[2017]+"WZ.root",
                basedirs[2017]+"QQWW.root",
                basedirs[2017]+"WW.root",
                basedirs[2017]+"WWDPS.root",
                basedirs[2017]+"ZZ.root",
                ],options=options[2018]),
            "rares": make_objs([
                basedirs[2017]+"WZG.root",
                basedirs[2017]+"WZZ.root",
                basedirs[2017]+"ZZZ.root",
                basedirs[2017]+"WWZ.root",
                basedirs[2017]+"WWW.root",
                basedirs[2017]+"TZQ.root",
                basedirs[2017]+"TTZZ.root",
                basedirs[2017]+"TTWZ.root",
                basedirs[2017]+"TTWW.root",
                basedirs[2017]+"TTWH.root",
                basedirs[2017]+"TTHH.root",
                basedirs[2017]+"TTTW.root",
                basedirs[2017]+"TTTJ.root",
                basedirs[2017]+"VHtoNonBB.root",
                ],options=options[2018]),
            "singletop": make_objs([
                basedirs[2017]+"STtop.root",
                basedirs[2017]+"STantitop.root",
                ],options=options[2018]) # FIXME,

            }
        }

# Change chain titles to proc_year so that we output the right root file name
for year in chs:
    [obj["ch"].SetTitle("{}_{}".format(proc,year)) for proc,obj in chs[year].items()]


def run_chain((index,info)):
    ch, options, outputdir = info
    ret = r.ScanChain(ch, options, outputdir)
    return index, ret

to_run = []
for year in years_to_consider:
    for proc,obj in chs[year].items():
        to_run.append([obj["ch"], obj["options"], outputdir])

os.system("mkdir -p {}".format(outputdir))

runner = pyrun.Runner(nproc=20, func=run_chain)
runner.add_args(to_run)
runner.run()
