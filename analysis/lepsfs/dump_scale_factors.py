import json
import pprint
import ROOT as r

def get_first_hist(f1):
    return f1.Get(f1.GetListOfKeys()[0].GetName())

def dump_bins(h2s, name, transpose=False, nofabseta=False, default1=False, do_err=False):
    buff = "float %s(float pt, float eta) {\n" % name
    if type(h2s) is not list:
        h2s = [h2s]
    for h2 in h2s:
        if transpose:
            for iy in range(1,h2.GetNbinsY()+1):
                for ix in range(1,h2.GetNbinsX()+1):
                    if do_err:
                        val = h2.GetBinError(ix,iy)
                    else:
                        val = h2.GetBinContent(ix,iy)
                    if iy != h2.GetNbinsY():
                        buff += "  if (pt >= %.0f && pt < %.0f && eta >= %.3f && eta < %.3f) return %.4f;\n" \
                                % (h2.GetYaxis().GetBinLowEdge(iy), h2.GetYaxis().GetBinUpEdge(iy), h2.GetXaxis().GetBinLowEdge(ix), h2.GetXaxis().GetBinUpEdge(ix), val)
                    else:
                        buff += "  if (pt >= %.0f  && eta >= %.3f && eta < %.3f) return %.4f;\n" \
                                % (h2.GetYaxis().GetBinLowEdge(iy), h2.GetXaxis().GetBinLowEdge(ix), h2.GetXaxis().GetBinUpEdge(ix), val)
        else:
            for ix in range(1,h2.GetNbinsX()+1):
                for iy in range(1,h2.GetNbinsY()+1):
                    if do_err:
                        val = h2.GetBinError(ix,iy)
                    else:
                        val = h2.GetBinContent(ix,iy)
                    if ix != h2.GetNbinsX():
                        buff += "  if (pt >= %.0f && pt < %.0f && fabs(eta) >= %.3f && fabs(eta) < %.3f) return %.4f;\n" \
                                % (h2.GetXaxis().GetBinLowEdge(ix), h2.GetXaxis().GetBinUpEdge(ix), h2.GetYaxis().GetBinLowEdge(iy), h2.GetYaxis().GetBinUpEdge(iy), val)
                    else:
                        buff += "  if (pt >= %.0f  && fabs(eta) >= %.3f && fabs(eta) < %.3f) return %.4f;\n" \
                                % (h2.GetXaxis().GetBinLowEdge(ix), h2.GetYaxis().GetBinLowEdge(iy), h2.GetYaxis().GetBinUpEdge(iy), val)
    if not default1:
        buff += "  return 0.;\n"
    else:
        buff += "  return 1.;\n"
    buff += "}\n"
    if nofabseta:
        buff = buff.replace("fabs(eta)", "eta")
    return buff

def dump_bins_json(jsname, name, do_err=False):
    buff = "float %s(float pt, float eta) {\n" % name

    data = json.load(open(jsname))

    d_sane = {}
    for s_aetarange,pts in data["NUM_MediumID_DEN_genTracks"]["abseta_pt"].items():
        for s_ptrange,valerr in pts.items():
            aetarange = tuple(eval(s_aetarange.split(":")[-1]))
            ptrange = tuple(eval(s_ptrange.split(":")[-1]))
            val = valerr["value"]
            err = valerr["error"]
            if ptrange not in d_sane:
                d_sane[ptrange] = {}
            d_sane[ptrange][aetarange] = (val,err)
    for ipt,ptrange in enumerate(sorted(d_sane.keys())):
        for ieta, (etarange, (val,err)) in enumerate(sorted(d_sane[ptrange].items())):
            if do_err:
                thing = err
            else:
                thing = val
            if ipt != len(d_sane.keys())-1:
                buff += "  if (pt >= %.0f && pt < %.0f && fabs(eta) >= %.3f && fabs(eta) < %.3f) return %.4f;\n" \
                        % (ptrange[0], ptrange[1], etarange[0], etarange[1], thing)
            else:
                buff += "  if (pt >= %.0f  && fabs(eta) >= %.3f && fabs(eta) < %.3f) return %.4f;\n" \
                        % (ptrange[0], etarange[0], etarange[1], thing)
    buff += "  return 0.;\n"
    buff += "}\n"
    return buff

if __name__ == "__main__":
    # from: https://twiki.cern.ch/twiki/bin/viewauth/CMS/Egamma2017DataRecommendations


    # for X in ["B","C","D","E","F","BCDEF"]:
    #     f_el_medium_runX = r.TFile("rootfiles/egammaEffi.txt_EGM2D_run{}_passingMedium94X.root".format(X))
    #     h_el_medium_runX = f_el_medium_runX.Get("EGamma_SF2D")
    #     print dump_bins(h_el_medium_runX, "electronScaleFactor_Run{}".format(X), transpose=True)
    #     print dump_bins(h_el_medium_runX, "electronScaleFactorError_Run{}".format(X), transpose=True, do_err=True)


    # f_el_reco_low = r.TFile("rootfiles/egammaEffi.txt_EGM2D_runBCDEF_passingRECO_lowEt.root")
    # h_el_reco_low = f_el_reco_low.Get("EGamma_SF2D")
    # for X in ["B","C","D","E","F","BCDEF"]:
    #     f_el_reco_high_runX = r.TFile("rootfiles/egammaEffi.txt_EGM2D_run{}_passingRECO.root".format(X))
    #     h_el_reco_high_runX = f_el_reco_high_runX.Get("EGamma_SF2D")
    #     print dump_bins([h_el_reco_low,h_el_reco_high_runX], "electronScaleFactorReco_Run{}".format(X), transpose=True)
    #     print dump_bins([h_el_reco_low,h_el_reco_high_runX], "electronScaleFactorRecoError_Run{}".format(X), transpose=True, do_err=True)


    # https://twiki.cern.ch/twiki/bin/viewauth/CMS/MuonReferenceEffs2017

    for X in ["BC","DE","F","BCDEF"]:
        print dump_bins_json("jsons/Run{}_SF_ID.json".format(X), "muonScaleFactor_Run{}".format(X))
        print dump_bins_json("jsons/Run{}_SF_ID.json".format(X), "muonScaleFactorError_Run{}".format(X), do_err=True)
