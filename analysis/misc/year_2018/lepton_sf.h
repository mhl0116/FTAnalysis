#include "lepton_sfs_el.h"
#include "lepton_sfs_mu.h"

float leptonScaleFactor(int pdgId, float pt, float eta, float ht, float rand=-1.) {
    if (abs(pdgId)==13) {
        return muonScaleFactor_RunABCD(pt,eta)*muonScaleFactor_Medium(pt,eta);
    } else if (abs(pdgId)==11){
        return electronScaleFactor_RunABCD(pt,eta)*electronScaleFactorReco_RunABCD(pt,eta);
    }
    return 0.;
}

float leptonScaleFactor_err(int pdgId, float pt, float eta, float ht, float rand=-1.) {
    if (abs(pdgId)==13) {
        float e1=muonScaleFactorError_RunABCD(pt,eta);
        float e2=muonScaleFactorError_Medium(pt,eta);
        return pow(e1*e1+e2*e2,0.5);
    } else if (abs(pdgId)==11){
        float e1=electronScaleFactorError_RunABCD(pt,eta);
        float e2=electronScaleFactorRecoError_RunABCD(pt,eta);
        return pow(e1*e1+e2*e2,0.5);
    }
    return 0.;
}
