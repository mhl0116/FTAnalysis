#pragma GCC diagnostic ignored "-Wsign-compare"

#include "TFile.h"
#include "TTree.h"
#include "TCut.h"
#include "TColor.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TH1.h"
#include "TChain.h"
#include "Math/VectorUtil.h"
#include "TROOT.h"
#include "TMVA/Reader.h"
#include "../../misc/class_files/v8.03/SS.h"
#include "../../misc/common_utils.h"
#include "../../misc/signal_regions.h"
#include "../../misc/tqdm.h"
namespace binary {
#include "../../misc/bdt.h"
}
//namespace multiclass {
//#include "func_mc.h"
//}

using namespace std;

int ScanChain(TChain *ch, TString options="", TString outputdir="outputs/"){

    TH1F * h_mbb = new TH1F("mbb", "mbb", 25, 0, 500);
    TH1F * h_mbb_fromJ = new TH1F("mbb_fromJ", "mbb_fromJ", 25, 0, 500);
    TH1F * h_mbb_2fromH = new TH1F("mbb_2fromH", "mbb_2fromH", 25, 0, 500);
    TH1F * h_mbb_1fromH_1fromT = new TH1F("mbb_1fromH_1fromT", "mbb_1fromH_1fromT", 25, 0, 500);
    TH1F * h_pTH_1fromH_1fromT = new TH1F("h_pTH_1fromH_1fromT", "h_pTH_1fromH_1fromT", 25, 0, 500);
    TH1F * h_pTt_1fromH_1fromT = new TH1F("h_pTt_1fromH_1fromT", "h_pTt_1fromH_1fromT", 25, 0, 500);
    TH1F * h_mbb_1fromH_1fromZ = new TH1F("mbb_1fromH_1fromZ", "mbb_1fromH_1fromZ", 25, 0, 500);
    TH1F * h_mbb_1fromH_1fromQ = new TH1F("mbb_1fromH_1fromQ", "mbb_1fromH_1fromQ", 25, 0, 500);
    TH1F * h_mbb_1fromH_1fromW = new TH1F("mbb_1fromH_1fromW", "mbb_1fromH_1fromW", 25, 0, 500);
    TH1F * h_mbb_1fromH_1unmatch = new TH1F("mbb_1fromH_1unmatch", "mbb_1fromH_1unmatch", 25, 0, 500);
    TH1F * h_mbb_bothNotFromH = new TH1F("mbb_bothNotFromH", "mbb", 25, 0, 500);
    TH1F * h_njet25 = new TH1F("h_njet_25", "h_njet_25", 10, 0, 10);
    TH1F * h_njet40 = new TH1F("h_njet_40", "h_njet_40", 10, 0, 10);

    TH1F * h_dr_bt_l_max = new TH1F("h_dr_bt_l_max", "h_dr_bt_l_max", 20, 0, 4);
    TH1F * h_dr_bt_l_min = new TH1F("h_dr_bt_l_min", "h_dr_bt_l_min", 20, 0, 4);
    TH1F * h_dr_bh_l_max = new TH1F("h_dr_bh_l_max", "h_dr_bh_l_max", 20, 0, 4);
    TH1F * h_dr_bh_l_min = new TH1F("h_dr_bh_l_min", "h_dr_bh_l_min", 20, 0, 4);

    TH1F * h_dr_bt_q_max = new TH1F("h_dr_bt_q_max", "h_dr_bt_q_max", 20, 0, 4);
    TH1F * h_dr_bt_q_min = new TH1F("h_dr_bt_q_min", "h_dr_bt_q_min", 20, 0, 4);
    TH1F * h_dr_bh_q_max = new TH1F("h_dr_bh_q_max", "h_dr_bh_q_max", 20, 0, 4);
    TH1F * h_dr_bh_q_min = new TH1F("h_dr_bh_q_min", "h_dr_bh_q_min", 20, 0, 4);

    TH1F * h_pT_bh = new TH1F("h_pT_bh", "h_pT_bh", 50, 0, 500);
    TH1F * h_pT_bt = new TH1F("h_pT_bt", "h_pT_bt", 50, 0, 500);

    TH1F * h_nbh_notag = new TH1F("h_nbh_notag", "h_nbh_notag", 3, 0, 3);
    TH1F * h_nbt_notag = new TH1F("h_nbt_notag", "h_nbt_notag", 3, 0, 3);
    TH1F * h_nbh_notag_2btag = new TH1F("h_nbh_notag_2btag", "h_nbh_notag_2btag", 3, 0, 3);
    TH1F * h_nbt_notag_2btag = new TH1F("h_nbt_notag_2btag", "h_nbt_notag_2btag", 3, 0, 3);
    TH2F * h_nbhtag_nbhnotag = new TH2F("h_nbhtag_nbhnotag", "h_nbhtag_nbhnotag", 3, 0, 3, 3, 0, 3);

    ana_t analysis = FTANA;

    int tree_year = -1;
    int tree_stype = -1;
    float tree_weight = -1;
    int tree_br = 0;
    int tree_SR = 0;
    int tree_class = -1;
    float tree_nbtags = -1;
    float tree_njets = -1;
    float tree_met = -1;
    float tree_ptl2 = -1;
    float tree_nlb40 = -1;
    float tree_ntb40 = -1;
    float tree_nleps = -1;
    float tree_htb = -1;
    float tree_ml1j1 = -1;
    float tree_dphil1l2 = -1;
    float tree_maxmjoverpt = -1;
    float tree_detal1l2 = -1;
    float tree_q1 = -1;
    float tree_ptj1 = -1;
    float tree_ptj6 = -1;
    float tree_ptj7 = -1;
    float tree_ptj8 = -1;
    float tree_ptl1 = -1;
    float tree_ptl3 = -1;
    float tree_disc = -1;
    float tree_disc_tmva = -1;
    // auto tree_classprobs = std::vector<float>();
    // auto tree_nnvec = std::vector<float>();

    //TMVA::Reader reader("Silent");
    //reader.AddVariable("nbtags",      &tree_nbtags);
    //reader.AddVariable("njets",       &tree_njets);
    //reader.AddVariable("met",         &tree_met);
    //reader.AddVariable("ptl2",        &tree_ptl2);
    //reader.AddVariable("nlb40",       &tree_nlb40);
    //reader.AddVariable("ntb40",       &tree_ntb40);
    //reader.AddVariable("nleps",       &tree_nleps);
    //reader.AddVariable("htb",         &tree_htb);
    //reader.AddVariable("q1",          &tree_q1);
    //reader.AddVariable("ptj1",        &tree_ptj1);
    //reader.AddVariable("ptj6",        &tree_ptj6);
    //reader.AddVariable("ptj7",        &tree_ptj7);
    //reader.AddVariable("ml1j1",       &tree_ml1j1);
    //reader.AddVariable("dphil1l2",    &tree_dphil1l2);
    //reader.AddVariable("maxmjoverpt", &tree_maxmjoverpt);
    //reader.AddVariable("ptl1",        &tree_ptl1);
    //reader.AddVariable("detal1l2",    &tree_detal1l2);
    //reader.AddVariable("ptj8",        &tree_ptj8);
    //reader.AddVariable("ptl3",        &tree_ptl3);
    //reader.AddSpectator("weight",     &tree_weight);
    //reader.AddSpectator("ptl1",       &tree_ptl1);
    //reader.AddSpectator("ptl2",       &tree_ptl2);
    //reader.AddSpectator("SR",         &tree_SR);
    //reader.AddSpectator("br",         &tree_br);
    // reader.BookMVA("BDT","../../yields/TMVAClassification_BDT_19vars.xml");
    //reader.BookMVA("BDT","TMVAClassification_BDT.weights.xml");

    TString proc(ch->GetTitle());

    if (proc == "tttt")  tree_stype = 0;
    if (proc == "ttw")   tree_stype = 1;
    if (proc == "ttz")   tree_stype = 2;
    if (proc == "tth")   tree_stype = 3;
    if (proc == "fakes") tree_stype = 4;
    if (proc == "flips") tree_stype = 5;
    if (proc == "xg")    tree_stype = 6;
    if (proc == "ttvv")  tree_stype = 7;
    if (proc == "rares") tree_stype = 8;

    bool useTTBB = (proc == "ttw") || (proc == "ttz") || (proc == "tth");

    TFile* out_file = new TFile(Form("%s/output_%s.root",outputdir.Data(),proc.Data()), "RECREATE");
    out_file->cd();
    TTree* out_tree = new TTree("t","fortraining");
    out_tree->Branch("year", &tree_year);
    out_tree->Branch("stype", &tree_stype);
    out_tree->Branch("weight", &tree_weight);
    out_tree->Branch("br", &tree_br);
    out_tree->Branch("SR", &tree_SR);
    out_tree->Branch("class", &tree_class);
    out_tree->Branch("nbtags", &tree_nbtags);
    out_tree->Branch("njets", &tree_njets);
    out_tree->Branch("met", &tree_met);
    out_tree->Branch("ptl2", &tree_ptl2);
    out_tree->Branch("nlb40", &tree_nlb40);
    out_tree->Branch("ntb40", &tree_ntb40);
    out_tree->Branch("nleps", &tree_nleps);
    out_tree->Branch("htb", &tree_htb);
    out_tree->Branch("ml1j1", &tree_ml1j1);
    out_tree->Branch("dphil1l2", &tree_dphil1l2);
    out_tree->Branch("maxmjoverpt", &tree_maxmjoverpt);
    out_tree->Branch("detal1l2", &tree_detal1l2);
    out_tree->Branch("q1", &tree_q1);
    out_tree->Branch("ptj1", &tree_ptj1);
    out_tree->Branch("ptj6", &tree_ptj6);
    out_tree->Branch("ptj7", &tree_ptj7);
    out_tree->Branch("ptj8", &tree_ptj8);
    out_tree->Branch("ptl1", &tree_ptl1);
    out_tree->Branch("ptl3", &tree_ptl3);
    out_tree->Branch("disc", &tree_disc);
    out_tree->Branch("disc_tmva", &tree_disc_tmva);
    // out_tree->Branch("classprobs", &tree_classprobs);
    // out_tree->Branch("nnvec", &tree_nnvec);

    int nEventsTotal = 0;
    int nEventsChain = ch->GetEntries();

    bool allowOSsignal = true;

    TFile *currentFile = 0;
    TObjArray *listOfFiles = ch->GetListOfFiles();
    TIter fileIter(listOfFiles);

    tqdm bar;
    // bar.set_theme_braille();
    while ( (currentFile = (TFile*)fileIter.Next()) ) { 

        // Get File Content
        TFile *file = new TFile(currentFile->GetTitle());


        TString filename = currentFile->GetTitle();
        TTree *tree = (TTree*)file->Get("t");
        samesign.Init(tree);

        if (filename.Contains("2016")) tree_year = 2016;
        else if (filename.Contains("2017")) tree_year = 2017;
        else if (filename.Contains("2018")) tree_year = 2018;

        cout << "filename: " << filename << endl;

        float min_pt_fake = -1;
        if (tree_year >= 2017) min_pt_fake = 18.;
        float lumi = getLumi(tree_year);

        for( unsigned int event = 0; event < tree->GetEntriesFast(); ++event) {

            samesign.GetEntry(event);
            nEventsTotal++;

            bar.progress(nEventsTotal, nEventsChain);


            // looser baseline
            if (ss::njets() < 2) continue;
            if (ss::nbtags() < 1) continue;
            if (ss::ht() < 250) continue;
            if (ss::met() < 30) continue;
            if (ss::lep1_coneCorrPt() < 15) continue;
            if (ss::lep2_coneCorrPt() < 15) continue;

            int njet_40 = 0;
            for (int ji = 0 ; ji < ss::njets(); ji++) {
                auto jetp4 = ss::jets()[ji]; 
                if (jetp4.pt() >= 40.0) njet_40++;
            }
            if (njet_40 < 2) continue;
            // float weight = ss::is_real_data() ? 1.0 : lumi*(ss::scale1fb())*ss::weight_btagsf();
            float weight = ss::is_real_data() ? 1.0 : lumi*(ss::scale1fb());

            if (!ss::is_real_data()) {
                weight *= getTruePUw(tree_year, ss::trueNumInt()[0]);
                if (ss::lep1_passes_id()) weight *= leptonScaleFactor(tree_year, ss::lep1_id(), ss::lep1_coneCorrPt(), ss::lep1_p4().eta(), ss::ht(), analysis);
                if (ss::lep2_passes_id()) weight *= leptonScaleFactor(tree_year, ss::lep2_id(), ss::lep2_coneCorrPt(), ss::lep2_p4().eta(), ss::ht(), analysis);
                if (ss::lep3_passes_id()) weight *= leptonScaleFactor(tree_year, ss::lep3_id(), ss::lep3_coneCorrPt(), ss::lep3_p4().eta(), ss::ht(), analysis);
                weight *= ss::weight_btagsf();
                if (tree_year == 2016) weight *= ss::prefire2016_sf();
                if (tree_year == 2017) weight *= ss::prefire2017_sf();
                if (useTTBB and (ss::extragenb() >= 2)) weight *= 1.7;
            }

            if (tree_stype == 5) {
                // Flips
                if (ss::hyp_class() != 4) continue;
                float ff = 0.;
                if (abs(ss::lep1_id()) == 11) {
                    float flr = flipRate(tree_year, ss::lep1_p4().pt(), ss::lep1_p4().eta(), analysis);
                    ff += (flr/(1-flr));
                }
                if (abs(ss::lep2_id()) == 11) {
                    float flr = flipRate(tree_year, ss::lep2_p4().pt(), ss::lep2_p4().eta(), analysis);
                    ff += (flr/(1-flr));
                }
                weight *= ff;
                if (weight == 0.0) continue; // just quit if there are no flips.
            } else if (tree_stype == 4) {
                // Fakes
                if (ss::hyp_class() != 2) continue;
                bool found_fake = false;
                if (!ss::lep1_passes_id() && ss::lep1_p4().pt()>min_pt_fake) {
                    found_fake = true;
                    float fr = fakeRate(tree_year, ss::lep1_id(), ss::lep1_coneCorrPt(), ss::lep1_p4().eta(), ss::ht(), analysis);
                    weight *= fr/(1.-fr);
                }
                if (!ss::lep2_passes_id() && ss::lep2_p4().pt()>min_pt_fake) {
                    found_fake = true;
                    float fr = fakeRate(tree_year, ss::lep2_id(), ss::lep2_coneCorrPt(), ss::lep2_p4().eta(), ss::ht(), analysis);
                    weight *= fr/(1.-fr);
                }
                if (!found_fake) continue;
            } else {
                if (tree_stype == 0 && allowOSsignal) {
                    if (!(ss::hyp_class() == 3 || ss::hyp_class() == 4)) continue;
                } else {
                    if (ss::hyp_class() != 3) continue;
                }
            }

            // // Truth fakes
            // if (tree_stype == 4) {
            //     int nbadlegs = (ss::lep1_motherID() <= 0) + (ss::lep2_motherID() <= 0);
            //     int ngoodlegs = (ss::lep1_motherID() == 1) + (ss::lep2_motherID() == 1);
            //     // skip the event if it's truth matched to be prompt prompt.
            //     // We only want reco tight-tight events that are prompt-nonprompt (or nonprompt nonprompt)
            //     if (ngoodlegs == 2) continue;
            // }

            bool br = passes_baseline_ft(
                    ss::njets(),
                    ss::nbtags(),
                    ss::met(),
                    ss::ht(),
                    ss::lep1_id(),
                    ss::lep2_id(),
                    ss::lep1_coneCorrPt(),
                    ss::lep2_coneCorrPt()
                    );
            if (tree_stype == 0 && allowOSsignal) {
                br = br && (ss::hyp_class() == 3);
            }

            int SR = signal_region_ft(ss::njets(), ss::nbtags(), ss::met(), ss::ht(), ss::mtmin(), ss::lep1_id(), ss::lep2_id(), ss::lep1_coneCorrPt(), ss::lep2_coneCorrPt(), ss::lep3_coneCorrPt(), ss::bdt_nleps(), ss::hyp_class() == 6);


            tree_nbtags = ss::bdt_nbtags();
            tree_njets = ss::bdt_njets();
            tree_met = ss::bdt_met();
            tree_ptl2 = ss::bdt_ptl2();
            tree_nlb40 = ss::bdt_nlb40();
            tree_ntb40 = ss::bdt_ntb40();
            tree_nleps = ss::bdt_nleps();
            tree_htb = ss::bdt_htb();
            tree_ml1j1 = ss::bdt_ml1j1();
            tree_dphil1l2 = ss::bdt_dphil1l2();
            tree_maxmjoverpt = ss::bdt_maxmjoverpt();
            tree_detal1l2 = ss::bdt_detal1l2();
            tree_q1 = ss::bdt_q1();
            tree_ptj1 = ss::bdt_ptj1();
            tree_ptj6 = ss::bdt_ptj6();
            tree_ptj7 = ss::bdt_ptj7();
            tree_ptj8 = ss::bdt_ptj8();
            tree_ptl1 = ss::bdt_ptl1();
            tree_ptl3 = ss::bdt_ptl3();
            // tree_ptj1 = tree_njets >= 1 ? ss::bdt_ptj1() : -1;
            // tree_ptj6 = tree_njets >= 6 ? ss::bdt_ptj6() : -1;
            // tree_ptj7 = tree_njets >= 7 ? ss::bdt_ptj7() : -1;
            // tree_ptj8 = tree_njets >= 8 ? ss::bdt_ptj8() : -1;
            // tree_ptl1 = ss::bdt_ptl1();
            // tree_ptl3 = tree_nleps >= 3 ? ss::bdt_ptl3() : -1;

            tree_weight = weight;
            tree_SR = SR;
            tree_class = ss::hyp_class();
            tree_br = br;

            // tree_disc_tmva = reader.EvaluateMVA("BDT");
            tree_disc = binary::get_prediction(tree_nbtags,tree_njets,tree_met,tree_ptl2,tree_nlb40,tree_ntb40,tree_nleps,tree_htb,tree_q1,tree_ptj1,tree_ptj6,tree_ptj7,tree_ml1j1,tree_dphil1l2,tree_maxmjoverpt,tree_ptl1,tree_detal1l2,tree_ptj8,tree_ptl3);
            // tree_classprobs = multiclass::get_prediction(tree_nbtags,tree_njets,tree_met,tree_ptl2,tree_nlb40,tree_ntb40,tree_nleps,tree_htb,tree_q1,tree_ptj1,tree_ptj6,tree_ptj7,tree_ml1j1,tree_dphil1l2,tree_maxmjoverpt,tree_ptl1,tree_detal1l2,tree_ptj8,tree_ptl3);

            // // -- 5x3 floats (nbtags, -5padded pt eta phi), 10x3 floats (njets), 3x3 floats (lep1,2,3 pt,eta,phi -5padded)
            // // -- 54 floats in total
            // tree_nnvec.clear();
            // for (int ijet = 0; ijet < 5; ijet++) {
            //     if (ijet >= ss::nbtags()) {
            //         tree_nnvec.push_back(-5);
            //         tree_nnvec.push_back(-5);
            //         tree_nnvec.push_back(-5);
            //     } else {
            //         tree_nnvec.push_back(ss::jets()[ijet].pt());
            //         tree_nnvec.push_back(ss::jets()[ijet].eta());
            //         tree_nnvec.push_back(ss::jets()[ijet].phi());
            //     }
            // }
            // for (int ijet = 0; ijet < 10; ijet++) {
            //     if (ijet >= ss::njets()) {
            //         tree_nnvec.push_back(-5);
            //         tree_nnvec.push_back(-5);
            //         tree_nnvec.push_back(-5);
            //     } else {
            //         tree_nnvec.push_back(ss::jets()[ijet].pt());
            //         tree_nnvec.push_back(ss::jets()[ijet].eta());
            //         tree_nnvec.push_back(ss::jets()[ijet].phi());
            //     }
            // }
            // tree_nnvec.push_back(ss::lep1_coneCorrPt());
            // tree_nnvec.push_back(ss::lep1_p4().eta());
            // tree_nnvec.push_back(ss::lep1_p4().phi());
            // tree_nnvec.push_back(ss::lep2_coneCorrPt());
            // tree_nnvec.push_back(ss::lep2_p4().eta());
            // tree_nnvec.push_back(ss::lep2_p4().phi());
            // if (tree_nleps >= 3) {
            //     tree_nnvec.push_back(ss::lep3_coneCorrPt());
            //     tree_nnvec.push_back(ss::lep3_p4().eta());
            //     tree_nnvec.push_back(ss::lep3_p4().phi());
            // } else {
            //     tree_nnvec.push_back(-5);
            //     tree_nnvec.push_back(-5);
            //     tree_nnvec.push_back(-5);
            // }

            out_tree->Fill();

            if (ss::hyp_class() != 3) continue;
            // make mbb
            h_mbb->Fill((ss::btags()[0]+ss::btags()[1]).M(), tree_weight);
            vector<int> bb_index; bb_index.clear();

            //cout << "got here" << endl;
            //cout << ss::njets() << ", " << ss::jets().size() << "," << ss::jet_cat().size() << endl;
            // fill bb pair index according to jet_cat defined in baby maker
            // also find number of no-btagged jet that is matched to gen-bquark
            int nbh_notag = 0;
            int nbt_notag = 0;
            int nbh_btag = 0;
            for (int ji = 0 ; ji < ss::njets(); ji++) {
                int jet_cat = ss::jet_cat()[ji];
                if (jet_cat <= 5) {
                    bb_index.push_back(ji);                    
                } 
                if (jet_cat == 0) nbh_btag++;
                if (jet_cat == 6) nbh_notag++; 
                if (jet_cat == 7) nbt_notag++; 
            }
            h_nbh_notag->Fill(nbh_notag, tree_weight);
            h_nbt_notag->Fill(nbt_notag, tree_weight);
            // this needs to be fixed, there is double counting
            if (nbh_btag + nbh_notag <=  2) h_nbhtag_nbhnotag->Fill(nbh_btag, nbh_notag, tree_weight);

            if (int(bb_index.size() == 2)) {
               h_nbh_notag_2btag->Fill(nbh_notag, tree_weight);
               h_nbt_notag_2btag->Fill(nbt_notag, tree_weight);
               int b1_index = bb_index[0]; 
               int b2_index = bb_index[1]; 
               float mbb_tmp = ( ss::jets()[b1_index] + ss::jets()[b2_index] ).M();
               int j1_cat = ss::jet_cat()[b1_index];
               int j2_cat = ss::jet_cat()[b2_index];
               h_mbb_fromJ->Fill(mbb_tmp,tree_weight);
               if (j1_cat == 0 && j2_cat == 0) h_mbb_2fromH->Fill(mbb_tmp,tree_weight);
               if (j1_cat + j2_cat == 1) {// one from top one from Higgs
                   h_mbb_1fromH_1fromT->Fill(mbb_tmp,tree_weight);
                   h_pTH_1fromH_1fromT->Fill(j1_cat == 0 ? ss::jets()[b1_index].pt() : ss::jets()[b2_index].pt());//,tree_weight);
                   h_pTt_1fromH_1fromT->Fill(j1_cat == 1 ? ss::jets()[b1_index].pt() : ss::jets()[b2_index].pt());//,tree_weight);
                   int bh_index = (j1_cat == 0) ? b1_index: b2_index;
                   int bt_index = (j1_cat == 1) ? b1_index: b2_index;
                   h_pT_bh->Fill(ss::jets()[bh_index].pt(), tree_weight);
                   h_pT_bt->Fill(ss::jets()[bt_index].pt(), tree_weight);
                   float dR_bh_l_1 = ROOT::Math::VectorUtil::DeltaR(ss::lep1_p4(),ss::jets()[bh_index]);
                   float dR_bh_l_2 = ROOT::Math::VectorUtil::DeltaR(ss::lep2_p4(),ss::jets()[bh_index]);
                   float dR_bt_l_1 = ROOT::Math::VectorUtil::DeltaR(ss::lep1_p4(),ss::jets()[bt_index]);
                   float dR_bt_l_2 = ROOT::Math::VectorUtil::DeltaR(ss::lep2_p4(),ss::jets()[bt_index]);
                   h_dr_bh_l_max->Fill(dR_bh_l_1 > dR_bh_l_2 ? dR_bh_l_1 : dR_bh_l_2 , tree_weight ) ;
                   h_dr_bh_l_min->Fill(dR_bh_l_1 < dR_bh_l_2 ? dR_bh_l_1 : dR_bh_l_2 , tree_weight ) ;
                   h_dr_bt_l_max->Fill(dR_bt_l_1 > dR_bt_l_2 ? dR_bt_l_1 : dR_bt_l_2 , tree_weight ) ;
                   h_dr_bt_l_min->Fill(dR_bt_l_1 < dR_bt_l_2 ? dR_bt_l_1 : dR_bt_l_2 , tree_weight ) ;
                   float dr_bh_q_max = -1;
                   float dr_bh_q_min = 999;
                   float dr_bt_q_max = -1;
                   float dr_bt_q_min = 999;
                   for (int j_i = 0; j_i < ss::njets(); j_i++) {
                        if (j_i == bh_index || j_i == bt_index) continue; 
                        float dR_bh_q = ROOT::Math::VectorUtil::DeltaR(ss::jets()[j_i], ss::jets()[bh_index]) ;
                        float dR_bt_q = ROOT::Math::VectorUtil::DeltaR(ss::jets()[j_i], ss::jets()[bt_index]) ;
                        if (dR_bh_q > dr_bh_q_max) dr_bh_q_max = dR_bh_q;
                        if (dR_bh_q < dr_bh_q_min) dr_bh_q_min = dR_bh_q;
                        if (dR_bt_q > dr_bt_q_max) dr_bt_q_max = dR_bt_q;
                        if (dR_bt_q < dr_bt_q_min) dr_bt_q_min = dR_bt_q;
                   }
                h_dr_bt_q_max->Fill(dr_bt_q_max, tree_weight);
                h_dr_bt_q_min->Fill(dr_bt_q_min, tree_weight);
                h_dr_bh_q_max->Fill(dr_bh_q_max, tree_weight);
                h_dr_bh_q_min->Fill(dr_bh_q_min, tree_weight);
                }
               if ( (j1_cat == 0 && j2_cat == 2) || (j1_cat == 2 && j2_cat == 0) )  h_mbb_1fromH_1fromZ->Fill(mbb_tmp,tree_weight);
               if ( (j1_cat == 0 && j2_cat == 3) || (j1_cat == 3 && j2_cat == 0) )  h_mbb_1fromH_1fromW->Fill(mbb_tmp,tree_weight);
               if ( (j1_cat == 0 && j2_cat == 4) || (j1_cat == 4 && j2_cat == 0) )  h_mbb_1fromH_1fromQ->Fill(mbb_tmp,tree_weight);
               if ( (j1_cat == 0 && j2_cat == 5) || (j1_cat == 5 && j2_cat == 0) )  h_mbb_1fromH_1unmatch->Fill(mbb_tmp,tree_weight);
               if ( j1_cat*j2_cat != 0 ) h_mbb_bothNotFromH->Fill(mbb_tmp,tree_weight);

               h_njet25->Fill(ss::njets(), tree_weight);
               h_njet40->Fill(njet_40, tree_weight);
            }

        }//event loop

        delete file;
    }//file loop
    bar.finish();



    //TFile *fout = new TFile("histos.root", "RECREATE");
    TFile *fout = new TFile("histos_v36.root", "RECREATE");
    // h_dr_vs_pt->Write();
    h_nbhtag_nbhnotag->Write();
    h_nbh_notag_2btag->Write();
    h_nbt_notag_2btag->Write();
    h_nbh_notag->Write();
    h_nbt_notag->Write();
    h_mbb->Write();
    h_pT_bt->Write();
    h_pT_bh->Write();
    h_njet25->Write();
    h_njet40->Write();
    h_mbb_fromJ->Write();
    h_mbb_2fromH->Write();
    h_mbb_1fromH_1fromT->Write();
    h_mbb_1fromH_1fromZ->Write();
    h_mbb_1fromH_1fromQ->Write();
    h_mbb_1fromH_1fromW->Write();
    h_mbb_1fromH_1unmatch->Write();
    h_mbb_bothNotFromH->Write();
    h_pTt_1fromH_1fromT->Write();
    h_pTH_1fromH_1fromT->Write();
    h_dr_bt_l_max->Write() ;
    h_dr_bt_l_min->Write() ;
    h_dr_bh_l_max->Write() ;
    h_dr_bh_l_min->Write() ;

    h_dr_bt_q_max->Write() ;
    h_dr_bt_q_min->Write() ;
    h_dr_bh_q_max->Write() ;
    h_dr_bh_q_min->Write() ;
    fout->Close();

    // Write output tree
    out_file->cd();
    out_tree->Write();
    out_file->Close();

    return 0;

}

