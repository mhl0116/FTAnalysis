#include "SS.h"
SSAG samesign;

void SSAG::Init(TTree *tree) {
  lep1_p4_branch = tree->GetBranch("lep1_p4");
  if (lep1_p4_branch) lep1_p4_branch->SetAddress(&lep1_p4_);
  lep2_p4_branch = tree->GetBranch("lep2_p4");
  if (lep2_p4_branch) lep2_p4_branch->SetAddress(&lep2_p4_);
  jets_branch = tree->GetBranch("jets");
  if (jets_branch) jets_branch->SetAddress(&jets_);
  jets_jec_up_branch = tree->GetBranch("jets_jec_up");
  if (jets_jec_up_branch) jets_jec_up_branch->SetAddress(&jets_jec_up_);
  jets_jec_dn_branch = tree->GetBranch("jets_jec_dn");
  if (jets_jec_dn_branch) jets_jec_dn_branch->SetAddress(&jets_jec_dn_);
  bjets_jec_up_branch = tree->GetBranch("bjets_jec_up");
  if (bjets_jec_up_branch) bjets_jec_up_branch->SetAddress(&bjets_jec_up_);
  bjets_jec_dn_branch = tree->GetBranch("bjets_jec_dn");
  if (bjets_jec_dn_branch) bjets_jec_dn_branch->SetAddress(&bjets_jec_dn_);
  btags_branch = tree->GetBranch("btags");
  if (btags_branch) btags_branch->SetAddress(&btags_);
  lep1_p4_gen_branch = tree->GetBranch("lep1_p4_gen");
  if (lep1_p4_gen_branch) lep1_p4_gen_branch->SetAddress(&lep1_p4_gen_);
  lep2_p4_gen_branch = tree->GetBranch("lep2_p4_gen");
  if (lep2_p4_gen_branch) lep2_p4_gen_branch->SetAddress(&lep2_p4_gen_);
  lep3_p4_branch = tree->GetBranch("lep3_p4");
  if (lep3_p4_branch) lep3_p4_branch->SetAddress(&lep3_p4_);
  lep4_p4_branch = tree->GetBranch("lep4_p4");
  if (lep4_p4_branch) lep4_p4_branch->SetAddress(&lep4_p4_);
  dilep_p4_branch = tree->GetBranch("dilep_p4");
  if (dilep_p4_branch) dilep_p4_branch->SetAddress(&dilep_p4_);
  genps_p4_branch = tree->GetBranch("genps_p4");
  if (genps_p4_branch) genps_p4_branch->SetAddress(&genps_p4_);
  genjets_p4_branch = tree->GetBranch("genjets_p4");
  if (genjets_p4_branch) genjets_p4_branch->SetAddress(&genjets_p4_);
  all_leps_p4_branch = tree->GetBranch("all_leps_p4");
  if (all_leps_p4_branch) all_leps_p4_branch->SetAddress(&all_leps_p4_);
  lep1_closeJet_branch = tree->GetBranch("lep1_closeJet");
  if (lep1_closeJet_branch) lep1_closeJet_branch->SetAddress(&lep1_closeJet_);
  lep2_closeJet_branch = tree->GetBranch("lep2_closeJet");
  if (lep2_closeJet_branch) lep2_closeJet_branch->SetAddress(&lep2_closeJet_);
  gl1_p4_branch = tree->GetBranch("gl1_p4");
  if (gl1_p4_branch) gl1_p4_branch->SetAddress(&gl1_p4_);
  gl2_p4_branch = tree->GetBranch("gl2_p4");
  if (gl2_p4_branch) gl2_p4_branch->SetAddress(&gl2_p4_);
  gammatoll1_branch = tree->GetBranch("gammatoll1");
  if (gammatoll1_branch) gammatoll1_branch->SetAddress(&gammatoll1_);
  gammatoll2_branch = tree->GetBranch("gammatoll2");
  if (gammatoll2_branch) gammatoll2_branch->SetAddress(&gammatoll2_);

  tree->SetMakeClass(1);

  lep1_isPrompt_branch = tree->GetBranch("lep1_isPrompt");
  if (lep1_isPrompt_branch) lep1_isPrompt_branch->SetAddress(&lep1_isPrompt_);
  lep1_isDirectPrompt_branch = tree->GetBranch("lep1_isDirectPrompt");
  if (lep1_isDirectPrompt_branch) lep1_isDirectPrompt_branch->SetAddress(&lep1_isDirectPrompt_);
  lep1_isStat3_branch = tree->GetBranch("lep1_isStat3");
  if (lep1_isStat3_branch) lep1_isStat3_branch->SetAddress(&lep1_isStat3_);
  lep2_isPrompt_branch = tree->GetBranch("lep2_isPrompt");
  if (lep2_isPrompt_branch) lep2_isPrompt_branch->SetAddress(&lep2_isPrompt_);
  lep2_isDirectPrompt_branch = tree->GetBranch("lep2_isDirectPrompt");
  if (lep2_isDirectPrompt_branch) lep2_isDirectPrompt_branch->SetAddress(&lep2_isDirectPrompt_);
  lep2_isStat3_branch = tree->GetBranch("lep2_isStat3");
  if (lep2_isStat3_branch) lep2_isStat3_branch->SetAddress(&lep2_isStat3_);
  met_branch = tree->GetBranch("met");
  if (met_branch) met_branch->SetAddress(&met_);
  metPhi_branch = tree->GetBranch("metPhi");
  if (metPhi_branch) metPhi_branch->SetAddress(&metPhi_);
  rawmet_branch = tree->GetBranch("rawmet");
  if (rawmet_branch) rawmet_branch->SetAddress(&rawmet_);
  rawmetPhi_branch = tree->GetBranch("rawmetPhi");
  if (rawmetPhi_branch) rawmetPhi_branch->SetAddress(&rawmetPhi_);
  calomet_branch = tree->GetBranch("calomet");
  if (calomet_branch) calomet_branch->SetAddress(&calomet_);
  calometPhi_branch = tree->GetBranch("calometPhi");
  if (calometPhi_branch) calometPhi_branch->SetAddress(&calometPhi_);
  event_branch = tree->GetBranch("event");
  if (event_branch) event_branch->SetAddress(&event_);
  lumi_branch = tree->GetBranch("lumi");
  if (lumi_branch) lumi_branch->SetAddress(&lumi_);
  run_branch = tree->GetBranch("run");
  if (run_branch) run_branch->SetAddress(&run_);
  filt_csc_branch = tree->GetBranch("filt_csc");
  if (filt_csc_branch) filt_csc_branch->SetAddress(&filt_csc_);
  filt_hbhe_branch = tree->GetBranch("filt_hbhe");
  if (filt_hbhe_branch) filt_hbhe_branch->SetAddress(&filt_hbhe_);
  filt_hcallaser_branch = tree->GetBranch("filt_hcallaser");
  if (filt_hcallaser_branch) filt_hcallaser_branch->SetAddress(&filt_hcallaser_);
  filt_ecaltp_branch = tree->GetBranch("filt_ecaltp");
  if (filt_ecaltp_branch) filt_ecaltp_branch->SetAddress(&filt_ecaltp_);
  filt_trkfail_branch = tree->GetBranch("filt_trkfail");
  if (filt_trkfail_branch) filt_trkfail_branch->SetAddress(&filt_trkfail_);
  is_real_data_branch = tree->GetBranch("is_real_data");
  if (is_real_data_branch) is_real_data_branch->SetAddress(&is_real_data_);
  scale1fb_branch = tree->GetBranch("scale1fb");
  if (scale1fb_branch) scale1fb_branch->SetAddress(&scale1fb_);
  genps_weight_branch = tree->GetBranch("genps_weight");
  if (genps_weight_branch) genps_weight_branch->SetAddress(&genps_weight_);
  xsec_branch = tree->GetBranch("xsec");
  if (xsec_branch) xsec_branch->SetAddress(&xsec_);
  neventstotal_branch = tree->GetBranch("neventstotal");
  if (neventstotal_branch) neventstotal_branch->SetAddress(&neventstotal_);
  xsec_ps_branch = tree->GetBranch("xsec_ps");
  if (xsec_ps_branch) xsec_ps_branch->SetAddress(&xsec_ps_);
  sparmNames_branch = tree->GetBranch("sparmNames");
  if (sparmNames_branch) sparmNames_branch->SetAddress(&sparmNames_);
  sparms_branch = tree->GetBranch("sparms");
  if (sparms_branch) sparms_branch->SetAddress(&sparms_);
  xsec_error_branch = tree->GetBranch("xsec_error");
  if (xsec_error_branch) xsec_error_branch->SetAddress(&xsec_error_);
  kfactor_branch = tree->GetBranch("kfactor");
  if (kfactor_branch) kfactor_branch->SetAddress(&kfactor_);
  gen_met_branch = tree->GetBranch("gen_met");
  if (gen_met_branch) gen_met_branch->SetAddress(&gen_met_);
  pdfweights_branch = tree->GetBranch("pdfweights");
  if (pdfweights_branch) pdfweights_branch->SetAddress(&pdfweights_);
  gen_met_phi_branch = tree->GetBranch("gen_met_phi");
  if (gen_met_phi_branch) gen_met_phi_branch->SetAddress(&gen_met_phi_);
  skim_branch = tree->GetBranch("skim");
  if (skim_branch) skim_branch->SetAddress(&skim_);
  skim_nomet_branch = tree->GetBranch("skim_nomet");
  if (skim_nomet_branch) skim_nomet_branch->SetAddress(&skim_nomet_);
  nleps_branch = tree->GetBranch("nleps");
  if (nleps_branch) nleps_branch->SetAddress(&nleps_);
  sr_branch = tree->GetBranch("sr");
  if (sr_branch) sr_branch->SetAddress(&sr_);
  br_branch = tree->GetBranch("br");
  if (br_branch) br_branch->SetAddress(&br_);
  ss_nleps_branch = tree->GetBranch("ss_nleps");
  if (ss_nleps_branch) ss_nleps_branch->SetAddress(&ss_nleps_);
  ss_br_branch = tree->GetBranch("ss_br");
  if (ss_br_branch) ss_br_branch->SetAddress(&ss_br_);
  ss_sr_branch = tree->GetBranch("ss_sr");
  if (ss_sr_branch) ss_sr_branch->SetAddress(&ss_sr_);
  ss_region_branch = tree->GetBranch("ss_region");
  if (ss_region_branch) ss_region_branch->SetAddress(&ss_region_);
  njets_branch = tree->GetBranch("njets");
  if (njets_branch) njets_branch->SetAddress(&njets_);
  njetsAG_branch = tree->GetBranch("njetsAG");
  if (njetsAG_branch) njetsAG_branch->SetAddress(&njetsAG_);
  nbtagsAG_branch = tree->GetBranch("nbtagsAG");
  if (nbtagsAG_branch) nbtagsAG_branch->SetAddress(&nbtagsAG_);
  njets_raw_branch = tree->GetBranch("njets_raw");
  if (njets_raw_branch) njets_raw_branch->SetAddress(&njets_raw_);
  hyp_class_branch = tree->GetBranch("hyp_class");
  if (hyp_class_branch) hyp_class_branch->SetAddress(&hyp_class_);
  lep1_pt_branch = tree->GetBranch("lep1_pt");
  if (lep1_pt_branch) lep1_pt_branch->SetAddress(&lep1_pt_);
  lep2_pt_branch = tree->GetBranch("lep2_pt");
  if (lep2_pt_branch) lep2_pt_branch->SetAddress(&lep2_pt_);
  lep3_pt_branch = tree->GetBranch("lep3_pt");
  if (lep3_pt_branch) lep3_pt_branch->SetAddress(&lep3_pt_);
  lep1_eta_branch = tree->GetBranch("lep1_eta");
  if (lep1_eta_branch) lep1_eta_branch->SetAddress(&lep1_eta_);
  lep2_eta_branch = tree->GetBranch("lep2_eta");
  if (lep2_eta_branch) lep2_eta_branch->SetAddress(&lep2_eta_);
  lep3_eta_branch = tree->GetBranch("lep3_eta");
  if (lep3_eta_branch) lep3_eta_branch->SetAddress(&lep3_eta_);
  lep1_phi_branch = tree->GetBranch("lep1_phi");
  if (lep1_phi_branch) lep1_phi_branch->SetAddress(&lep1_phi_);
  lep2_phi_branch = tree->GetBranch("lep2_phi");
  if (lep2_phi_branch) lep2_phi_branch->SetAddress(&lep2_phi_);
  lep3_phi_branch = tree->GetBranch("lep3_phi");
  if (lep3_phi_branch) lep3_phi_branch->SetAddress(&lep3_phi_);
  ht_raw_branch = tree->GetBranch("ht_raw");
  if (ht_raw_branch) ht_raw_branch->SetAddress(&ht_raw_);
  ht_branch = tree->GetBranch("ht");
  if (ht_branch) ht_branch->SetAddress(&ht_);
  lep1_motherID_branch = tree->GetBranch("lep1_motherID");
  if (lep1_motherID_branch) lep1_motherID_branch->SetAddress(&lep1_motherID_);
  lep2_motherID_branch = tree->GetBranch("lep2_motherID");
  if (lep2_motherID_branch) lep2_motherID_branch->SetAddress(&lep2_motherID_);
  lep1_mc_id_branch = tree->GetBranch("lep1_mc_id");
  if (lep1_mc_id_branch) lep1_mc_id_branch->SetAddress(&lep1_mc_id_);
  lep2_mc_id_branch = tree->GetBranch("lep2_mc_id");
  if (lep2_mc_id_branch) lep2_mc_id_branch->SetAddress(&lep2_mc_id_);
  lep1_mc_motherid_branch = tree->GetBranch("lep1_mc_motherid");
  if (lep1_mc_motherid_branch) lep1_mc_motherid_branch->SetAddress(&lep1_mc_motherid_);
  lep2_mc_motherid_branch = tree->GetBranch("lep2_mc_motherid");
  if (lep2_mc_motherid_branch) lep2_mc_motherid_branch->SetAddress(&lep2_mc_motherid_);
  lep1_id_branch = tree->GetBranch("lep1_id");
  if (lep1_id_branch) lep1_id_branch->SetAddress(&lep1_id_);
  lep2_id_branch = tree->GetBranch("lep2_id");
  if (lep2_id_branch) lep2_id_branch->SetAddress(&lep2_id_);
  lep1_coneCorrPt_branch = tree->GetBranch("lep1_coneCorrPt");
  if (lep1_coneCorrPt_branch) lep1_coneCorrPt_branch->SetAddress(&lep1_coneCorrPt_);
  lep2_coneCorrPt_branch = tree->GetBranch("lep2_coneCorrPt");
  if (lep2_coneCorrPt_branch) lep2_coneCorrPt_branch->SetAddress(&lep2_coneCorrPt_);
  lep3_coneCorrPt_branch = tree->GetBranch("lep3_coneCorrPt");
  if (lep3_coneCorrPt_branch) lep3_coneCorrPt_branch->SetAddress(&lep3_coneCorrPt_);
  lep4_coneCorrPt_branch = tree->GetBranch("lep4_coneCorrPt");
  if (lep4_coneCorrPt_branch) lep4_coneCorrPt_branch->SetAddress(&lep4_coneCorrPt_);
  lep1_idx_branch = tree->GetBranch("lep1_idx");
  if (lep1_idx_branch) lep1_idx_branch->SetAddress(&lep1_idx_);
  lep2_idx_branch = tree->GetBranch("lep2_idx");
  if (lep2_idx_branch) lep2_idx_branch->SetAddress(&lep2_idx_);
  jets_disc_up_branch = tree->GetBranch("jets_disc_up");
  if (jets_disc_up_branch) jets_disc_up_branch->SetAddress(&jets_disc_up_);
  jets_disc_dn_branch = tree->GetBranch("jets_disc_dn");
  if (jets_disc_dn_branch) jets_disc_dn_branch->SetAddress(&jets_disc_dn_);
  btags_flavor_branch = tree->GetBranch("btags_flavor");
  if (btags_flavor_branch) btags_flavor_branch->SetAddress(&btags_flavor_);
  btags_disc_branch = tree->GetBranch("btags_disc");
  if (btags_disc_branch) btags_disc_branch->SetAddress(&btags_disc_);
  btags_cdisc_branch = tree->GetBranch("btags_cdisc");
  if (btags_cdisc_branch) btags_cdisc_branch->SetAddress(&btags_cdisc_);
  jets_flavor_branch = tree->GetBranch("jets_flavor");
  if (jets_flavor_branch) jets_flavor_branch->SetAddress(&jets_flavor_);
  jets_disc_branch = tree->GetBranch("jets_disc");
  if (jets_disc_branch) jets_disc_branch->SetAddress(&jets_disc_);
  jets_bsf_branch = tree->GetBranch("jets_bsf");
  if (jets_bsf_branch) jets_bsf_branch->SetAddress(&jets_bsf_);
  jets_JEC_branch = tree->GetBranch("jets_JEC");
  if (jets_JEC_branch) jets_JEC_branch->SetAddress(&jets_JEC_);
  btags_JEC_branch = tree->GetBranch("btags_JEC");
  if (btags_JEC_branch) btags_JEC_branch->SetAddress(&btags_JEC_);
  jets_undoJEC_branch = tree->GetBranch("jets_undoJEC");
  if (jets_undoJEC_branch) jets_undoJEC_branch->SetAddress(&jets_undoJEC_);
  btags_undoJEC_branch = tree->GetBranch("btags_undoJEC");
  if (btags_undoJEC_branch) btags_undoJEC_branch->SetAddress(&btags_undoJEC_);
  btags_unc_branch = tree->GetBranch("btags_unc");
  if (btags_unc_branch) btags_unc_branch->SetAddress(&btags_unc_);
  btags_eff_branch = tree->GetBranch("btags_eff");
  if (btags_eff_branch) btags_eff_branch->SetAddress(&btags_eff_);
  btags_effpt_branch = tree->GetBranch("btags_effpt");
  if (btags_effpt_branch) btags_effpt_branch->SetAddress(&btags_effpt_);
  btags_sf_branch = tree->GetBranch("btags_sf");
  if (btags_sf_branch) btags_sf_branch->SetAddress(&btags_sf_);
  jets_unc_branch = tree->GetBranch("jets_unc");
  if (jets_unc_branch) jets_unc_branch->SetAddress(&jets_unc_);
  nbtags_branch = tree->GetBranch("nbtags");
  if (nbtags_branch) nbtags_branch->SetAddress(&nbtags_);
  nbtags_raw_branch = tree->GetBranch("nbtags_raw");
  if (nbtags_raw_branch) nbtags_raw_branch->SetAddress(&nbtags_raw_);
  sf_dilepTrig_hpt_branch = tree->GetBranch("sf_dilepTrig_hpt");
  if (sf_dilepTrig_hpt_branch) sf_dilepTrig_hpt_branch->SetAddress(&sf_dilepTrig_hpt_);
  sf_dilepTrig_lpt_branch = tree->GetBranch("sf_dilepTrig_lpt");
  if (sf_dilepTrig_lpt_branch) sf_dilepTrig_lpt_branch->SetAddress(&sf_dilepTrig_lpt_);
  sf_dilepTrig_vlpt_branch = tree->GetBranch("sf_dilepTrig_vlpt");
  if (sf_dilepTrig_vlpt_branch) sf_dilepTrig_vlpt_branch->SetAddress(&sf_dilepTrig_vlpt_);
  hyp_type_branch = tree->GetBranch("hyp_type");
  if (hyp_type_branch) hyp_type_branch->SetAddress(&hyp_type_);
  sf_dilep_eff_branch = tree->GetBranch("sf_dilep_eff");
  if (sf_dilep_eff_branch) sf_dilep_eff_branch->SetAddress(&sf_dilep_eff_);
  mt_branch = tree->GetBranch("mt");
  if (mt_branch) mt_branch->SetAddress(&mt_);
  mt_l2_branch = tree->GetBranch("mt_l2");
  if (mt_l2_branch) mt_l2_branch->SetAddress(&mt_l2_);
  mt2_branch = tree->GetBranch("mt2");
  if (mt2_branch) mt2_branch->SetAddress(&mt2_);
  mtmin_branch = tree->GetBranch("mtmin");
  if (mtmin_branch) mtmin_branch->SetAddress(&mtmin_);
  lep1_id_gen_branch = tree->GetBranch("lep1_id_gen");
  if (lep1_id_gen_branch) lep1_id_gen_branch->SetAddress(&lep1_id_gen_);
  lep2_id_gen_branch = tree->GetBranch("lep2_id_gen");
  if (lep2_id_gen_branch) lep2_id_gen_branch->SetAddress(&lep2_id_gen_);
  lep3_id_branch = tree->GetBranch("lep3_id");
  if (lep3_id_branch) lep3_id_branch->SetAddress(&lep3_id_);
  lep3_idx_branch = tree->GetBranch("lep3_idx");
  if (lep3_idx_branch) lep3_idx_branch->SetAddress(&lep3_idx_);
  lep3_quality_branch = tree->GetBranch("lep3_quality");
  if (lep3_quality_branch) lep3_quality_branch->SetAddress(&lep3_quality_);
  lep4_id_branch = tree->GetBranch("lep4_id");
  if (lep4_id_branch) lep4_id_branch->SetAddress(&lep4_id_);
  lep4_idx_branch = tree->GetBranch("lep4_idx");
  if (lep4_idx_branch) lep4_idx_branch->SetAddress(&lep4_idx_);
  lep1_iso_branch = tree->GetBranch("lep1_iso");
  if (lep1_iso_branch) lep1_iso_branch->SetAddress(&lep1_iso_);
  lep2_iso_branch = tree->GetBranch("lep2_iso");
  if (lep2_iso_branch) lep2_iso_branch->SetAddress(&lep2_iso_);
  dilep_mass_branch = tree->GetBranch("dilep_mass");
  if (dilep_mass_branch) dilep_mass_branch->SetAddress(&dilep_mass_);
  mass13_branch = tree->GetBranch("mass13");
  if (mass13_branch) mass13_branch->SetAddress(&mass13_);
  mass23_branch = tree->GetBranch("mass23");
  if (mass23_branch) mass23_branch->SetAddress(&mass23_);
  mass123_branch = tree->GetBranch("mass123");
  if (mass123_branch) mass123_branch->SetAddress(&mass123_);
  ncharginos_branch = tree->GetBranch("ncharginos");
  if (ncharginos_branch) ncharginos_branch->SetAddress(&ncharginos_);
  nhiggs_branch = tree->GetBranch("nhiggs");
  if (nhiggs_branch) nhiggs_branch->SetAddress(&nhiggs_);
  higgs_mass_branch = tree->GetBranch("higgs_mass");
  if (higgs_mass_branch) higgs_mass_branch->SetAddress(&higgs_mass_);
  genps_id_branch = tree->GetBranch("genps_id");
  if (genps_id_branch) genps_id_branch->SetAddress(&genps_id_);
  genps_id_mother_branch = tree->GetBranch("genps_id_mother");
  if (genps_id_mother_branch) genps_id_mother_branch->SetAddress(&genps_id_mother_);
  genps_idx_mother_branch = tree->GetBranch("genps_idx_mother");
  if (genps_idx_mother_branch) genps_idx_mother_branch->SetAddress(&genps_idx_mother_);
  genps_status_branch = tree->GetBranch("genps_status");
  if (genps_status_branch) genps_status_branch->SetAddress(&genps_status_);
  genps_id_grandma_branch = tree->GetBranch("genps_id_grandma");
  if (genps_id_grandma_branch) genps_id_grandma_branch->SetAddress(&genps_id_grandma_);
  all_leps_id_branch = tree->GetBranch("all_leps_id");
  if (all_leps_id_branch) all_leps_id_branch->SetAddress(&all_leps_id_);
  all_leps_veto_branch = tree->GetBranch("all_leps_veto");
  if (all_leps_veto_branch) all_leps_veto_branch->SetAddress(&all_leps_veto_);
  all_leps_mc3idx_branch = tree->GetBranch("all_leps_mc3idx");
  if (all_leps_mc3idx_branch) all_leps_mc3idx_branch->SetAddress(&all_leps_mc3idx_);
  lep1_passes_id_branch = tree->GetBranch("lep1_passes_id");
  if (lep1_passes_id_branch) lep1_passes_id_branch->SetAddress(&lep1_passes_id_);
  lep2_passes_id_branch = tree->GetBranch("lep2_passes_id");
  if (lep2_passes_id_branch) lep2_passes_id_branch->SetAddress(&lep2_passes_id_);
  lep3_passes_id_branch = tree->GetBranch("lep3_passes_id");
  if (lep3_passes_id_branch) lep3_passes_id_branch->SetAddress(&lep3_passes_id_);
  lep4_passes_id_branch = tree->GetBranch("lep4_passes_id");
  if (lep4_passes_id_branch) lep4_passes_id_branch->SetAddress(&lep4_passes_id_);
  lep1_tight_branch = tree->GetBranch("lep1_tight");
  if (lep1_tight_branch) lep1_tight_branch->SetAddress(&lep1_tight_);
  lep1_veto_branch = tree->GetBranch("lep1_veto");
  if (lep1_veto_branch) lep1_veto_branch->SetAddress(&lep1_veto_);
  lep1_fo_branch = tree->GetBranch("lep1_fo");
  if (lep1_fo_branch) lep1_fo_branch->SetAddress(&lep1_fo_);
  lep2_tight_branch = tree->GetBranch("lep2_tight");
  if (lep2_tight_branch) lep2_tight_branch->SetAddress(&lep2_tight_);
  lep2_veto_branch = tree->GetBranch("lep2_veto");
  if (lep2_veto_branch) lep2_veto_branch->SetAddress(&lep2_veto_);
  lep2_fo_branch = tree->GetBranch("lep2_fo");
  if (lep2_fo_branch) lep2_fo_branch->SetAddress(&lep2_fo_);
  lep3_tight_branch = tree->GetBranch("lep3_tight");
  if (lep3_tight_branch) lep3_tight_branch->SetAddress(&lep3_tight_);
  lep3_veto_branch = tree->GetBranch("lep3_veto");
  if (lep3_veto_branch) lep3_veto_branch->SetAddress(&lep3_veto_);
  lep3_fo_branch = tree->GetBranch("lep3_fo");
  if (lep3_fo_branch) lep3_fo_branch->SetAddress(&lep3_fo_);
  lep4_tight_branch = tree->GetBranch("lep4_tight");
  if (lep4_tight_branch) lep4_tight_branch->SetAddress(&lep4_tight_);
  lep4_veto_branch = tree->GetBranch("lep4_veto");
  if (lep4_veto_branch) lep4_veto_branch->SetAddress(&lep4_veto_);
  lep4_fo_branch = tree->GetBranch("lep4_fo");
  if (lep4_fo_branch) lep4_fo_branch->SetAddress(&lep4_fo_);
  lep1_dxyPV_branch = tree->GetBranch("lep1_dxyPV");
  if (lep1_dxyPV_branch) lep1_dxyPV_branch->SetAddress(&lep1_dxyPV_);
  lep2_dxyPV_branch = tree->GetBranch("lep2_dxyPV");
  if (lep2_dxyPV_branch) lep2_dxyPV_branch->SetAddress(&lep2_dxyPV_);
  lep1_dZ_branch = tree->GetBranch("lep1_dZ");
  if (lep1_dZ_branch) lep1_dZ_branch->SetAddress(&lep1_dZ_);
  lep2_dZ_branch = tree->GetBranch("lep2_dZ");
  if (lep2_dZ_branch) lep2_dZ_branch->SetAddress(&lep2_dZ_);
  lep1_d0_err_branch = tree->GetBranch("lep1_d0_err");
  if (lep1_d0_err_branch) lep1_d0_err_branch->SetAddress(&lep1_d0_err_);
  lep2_d0_err_branch = tree->GetBranch("lep2_d0_err");
  if (lep2_d0_err_branch) lep2_d0_err_branch->SetAddress(&lep2_d0_err_);
  lep1_ip3d_branch = tree->GetBranch("lep1_ip3d");
  if (lep1_ip3d_branch) lep1_ip3d_branch->SetAddress(&lep1_ip3d_);
  lep2_ip3d_branch = tree->GetBranch("lep2_ip3d");
  if (lep2_ip3d_branch) lep2_ip3d_branch->SetAddress(&lep2_ip3d_);
  lep1_MVA_branch = tree->GetBranch("lep1_MVA");
  if (lep1_MVA_branch) lep1_MVA_branch->SetAddress(&lep1_MVA_);
  lep2_MVA_branch = tree->GetBranch("lep2_MVA");
  if (lep2_MVA_branch) lep2_MVA_branch->SetAddress(&lep2_MVA_);
  lep1_ip3d_err_branch = tree->GetBranch("lep1_ip3d_err");
  if (lep1_ip3d_err_branch) lep1_ip3d_err_branch->SetAddress(&lep1_ip3d_err_);
  lep2_ip3d_err_branch = tree->GetBranch("lep2_ip3d_err");
  if (lep2_ip3d_err_branch) lep2_ip3d_err_branch->SetAddress(&lep2_ip3d_err_);
  nVetoElectrons7_branch = tree->GetBranch("nVetoElectrons7");
  if (nVetoElectrons7_branch) nVetoElectrons7_branch->SetAddress(&nVetoElectrons7_);
  nVetoElectrons10_branch = tree->GetBranch("nVetoElectrons10");
  if (nVetoElectrons10_branch) nVetoElectrons10_branch->SetAddress(&nVetoElectrons10_);
  nVetoElectrons25_branch = tree->GetBranch("nVetoElectrons25");
  if (nVetoElectrons25_branch) nVetoElectrons25_branch->SetAddress(&nVetoElectrons25_);
  nVetoMuons5_branch = tree->GetBranch("nVetoMuons5");
  if (nVetoMuons5_branch) nVetoMuons5_branch->SetAddress(&nVetoMuons5_);
  nVetoMuons10_branch = tree->GetBranch("nVetoMuons10");
  if (nVetoMuons10_branch) nVetoMuons10_branch->SetAddress(&nVetoMuons10_);
  nVetoMuons25_branch = tree->GetBranch("nVetoMuons25");
  if (nVetoMuons25_branch) nVetoMuons25_branch->SetAddress(&nVetoMuons25_);
  filename_branch = tree->GetBranch("filename");
  if (filename_branch) filename_branch->SetAddress(&filename_);
  lep1_ptrel_ma_branch = tree->GetBranch("lep1_ptrel_ma");
  if (lep1_ptrel_ma_branch) lep1_ptrel_ma_branch->SetAddress(&lep1_ptrel_ma_);
  lep1_ptratio_ma_branch = tree->GetBranch("lep1_ptratio_ma");
  if (lep1_ptratio_ma_branch) lep1_ptratio_ma_branch->SetAddress(&lep1_ptratio_ma_);
  lep2_ptrel_ma_branch = tree->GetBranch("lep2_ptrel_ma");
  if (lep2_ptrel_ma_branch) lep2_ptrel_ma_branch->SetAddress(&lep2_ptrel_ma_);
  lep2_ptratio_ma_branch = tree->GetBranch("lep2_ptratio_ma");
  if (lep2_ptratio_ma_branch) lep2_ptratio_ma_branch->SetAddress(&lep2_ptratio_ma_);
  lep1_ptrel_v1_branch = tree->GetBranch("lep1_ptrel_v1");
  if (lep1_ptrel_v1_branch) lep1_ptrel_v1_branch->SetAddress(&lep1_ptrel_v1_);
  lep2_ptrel_v1_branch = tree->GetBranch("lep2_ptrel_v1");
  if (lep2_ptrel_v1_branch) lep2_ptrel_v1_branch->SetAddress(&lep2_ptrel_v1_);
  lep1_ptratio_branch = tree->GetBranch("lep1_ptratio");
  if (lep1_ptratio_branch) lep1_ptratio_branch->SetAddress(&lep1_ptratio_);
  lep2_ptratio_branch = tree->GetBranch("lep2_ptratio");
  if (lep2_ptratio_branch) lep2_ptratio_branch->SetAddress(&lep2_ptratio_);
  lep1_miniIso_branch = tree->GetBranch("lep1_miniIso");
  if (lep1_miniIso_branch) lep1_miniIso_branch->SetAddress(&lep1_miniIso_);
  lep2_miniIso_branch = tree->GetBranch("lep2_miniIso");
  if (lep2_miniIso_branch) lep2_miniIso_branch->SetAddress(&lep2_miniIso_);
  trueNumInt_branch = tree->GetBranch("trueNumInt");
  if (trueNumInt_branch) trueNumInt_branch->SetAddress(&trueNumInt_);
  nGoodVertices_branch = tree->GetBranch("nGoodVertices");
  if (nGoodVertices_branch) nGoodVertices_branch->SetAddress(&nGoodVertices_);
  lep1_trigMatch_noIsoReq_branch = tree->GetBranch("lep1_trigMatch_noIsoReq");
  if (lep1_trigMatch_noIsoReq_branch) lep1_trigMatch_noIsoReq_branch->SetAddress(&lep1_trigMatch_noIsoReq_);
  lep1_trigMatch_isoReq_branch = tree->GetBranch("lep1_trigMatch_isoReq");
  if (lep1_trigMatch_isoReq_branch) lep1_trigMatch_isoReq_branch->SetAddress(&lep1_trigMatch_isoReq_);
  lep2_trigMatch_noIsoReq_branch = tree->GetBranch("lep2_trigMatch_noIsoReq");
  if (lep2_trigMatch_noIsoReq_branch) lep2_trigMatch_noIsoReq_branch->SetAddress(&lep2_trigMatch_noIsoReq_);
  lep2_trigMatch_isoReq_branch = tree->GetBranch("lep2_trigMatch_isoReq");
  if (lep2_trigMatch_isoReq_branch) lep2_trigMatch_isoReq_branch->SetAddress(&lep2_trigMatch_isoReq_);
  passes_met_filters_branch = tree->GetBranch("passes_met_filters");
  if (passes_met_filters_branch) passes_met_filters_branch->SetAddress(&passes_met_filters_);
  passes_chargedcand_filter_branch = tree->GetBranch("passes_chargedcand_filter");
  if (passes_chargedcand_filter_branch) passes_chargedcand_filter_branch->SetAddress(&passes_chargedcand_filter_);
  evt_egclean_pfmet_branch = tree->GetBranch("evt_egclean_pfmet");
  if (evt_egclean_pfmet_branch) evt_egclean_pfmet_branch->SetAddress(&evt_egclean_pfmet_);
  evt_muegclean_pfmet_branch = tree->GetBranch("evt_muegclean_pfmet");
  if (evt_muegclean_pfmet_branch) evt_muegclean_pfmet_branch->SetAddress(&evt_muegclean_pfmet_);
  evt_muegcleanfix_pfmet_branch = tree->GetBranch("evt_muegcleanfix_pfmet");
  if (evt_muegcleanfix_pfmet_branch) evt_muegcleanfix_pfmet_branch->SetAddress(&evt_muegcleanfix_pfmet_);
  evt_uncorr_pfmet_branch = tree->GetBranch("evt_uncorr_pfmet");
  if (evt_uncorr_pfmet_branch) evt_uncorr_pfmet_branch->SetAddress(&evt_uncorr_pfmet_);
  filt_noBadMuons_branch = tree->GetBranch("filt_noBadMuons");
  if (filt_noBadMuons_branch) filt_noBadMuons_branch->SetAddress(&filt_noBadMuons_);
  filt_duplicateMuons_branch = tree->GetBranch("filt_duplicateMuons");
  if (filt_duplicateMuons_branch) filt_duplicateMuons_branch->SetAddress(&filt_duplicateMuons_);
  filt_badMuons_branch = tree->GetBranch("filt_badMuons");
  if (filt_badMuons_branch) filt_badMuons_branch->SetAddress(&filt_badMuons_);
  failsRA2Filter_branch = tree->GetBranch("failsRA2Filter");
  if (failsRA2Filter_branch) failsRA2Filter_branch->SetAddress(&failsRA2Filter_);
  madeExtraZ_branch = tree->GetBranch("madeExtraZ");
  if (madeExtraZ_branch) madeExtraZ_branch->SetAddress(&madeExtraZ_);
  madeExtraG_branch = tree->GetBranch("madeExtraG");
  if (madeExtraG_branch) madeExtraG_branch->SetAddress(&madeExtraG_);
  lep3_mcid_branch = tree->GetBranch("lep3_mcid");
  if (lep3_mcid_branch) lep3_mcid_branch->SetAddress(&lep3_mcid_);
  lep3_mc_motherid_branch = tree->GetBranch("lep3_mc_motherid");
  if (lep3_mc_motherid_branch) lep3_mc_motherid_branch->SetAddress(&lep3_mc_motherid_);
  lep3_mc3idx_branch = tree->GetBranch("lep3_mc3idx");
  if (lep3_mc3idx_branch) lep3_mc3idx_branch->SetAddress(&lep3_mc3idx_);
  lep3_motherID_branch = tree->GetBranch("lep3_motherID");
  if (lep3_motherID_branch) lep3_motherID_branch->SetAddress(&lep3_motherID_);
  lep4_mcid_branch = tree->GetBranch("lep4_mcid");
  if (lep4_mcid_branch) lep4_mcid_branch->SetAddress(&lep4_mcid_);
  lep4_mcidx_branch = tree->GetBranch("lep4_mcidx");
  if (lep4_mcidx_branch) lep4_mcidx_branch->SetAddress(&lep4_mcidx_);
  njets_unc_up_branch = tree->GetBranch("njets_unc_up");
  if (njets_unc_up_branch) njets_unc_up_branch->SetAddress(&njets_unc_up_);
  njets_unc_dn_branch = tree->GetBranch("njets_unc_dn");
  if (njets_unc_dn_branch) njets_unc_dn_branch->SetAddress(&njets_unc_dn_);
  ht_unc_up_branch = tree->GetBranch("ht_unc_up");
  if (ht_unc_up_branch) ht_unc_up_branch->SetAddress(&ht_unc_up_);
  ht_unc_dn_branch = tree->GetBranch("ht_unc_dn");
  if (ht_unc_dn_branch) ht_unc_dn_branch->SetAddress(&ht_unc_dn_);
  nbtags_unc_up_branch = tree->GetBranch("nbtags_unc_up");
  if (nbtags_unc_up_branch) nbtags_unc_up_branch->SetAddress(&nbtags_unc_up_);
  nbtags_unc_dn_branch = tree->GetBranch("nbtags_unc_dn");
  if (nbtags_unc_dn_branch) nbtags_unc_dn_branch->SetAddress(&nbtags_unc_dn_);
  met_unc_up_branch = tree->GetBranch("met_unc_up");
  if (met_unc_up_branch) met_unc_up_branch->SetAddress(&met_unc_up_);
  met_unc_dn_branch = tree->GetBranch("met_unc_dn");
  if (met_unc_dn_branch) met_unc_dn_branch->SetAddress(&met_unc_dn_);
  metPhi_unc_up_branch = tree->GetBranch("metPhi_unc_up");
  if (metPhi_unc_up_branch) metPhi_unc_up_branch->SetAddress(&metPhi_unc_up_);
  metPhi_unc_dn_branch = tree->GetBranch("metPhi_unc_dn");
  if (metPhi_unc_dn_branch) metPhi_unc_dn_branch->SetAddress(&metPhi_unc_dn_);
  njets_JER_up_branch = tree->GetBranch("njets_JER_up");
  if (njets_JER_up_branch) njets_JER_up_branch->SetAddress(&njets_JER_up_);
  njets_JER_dn_branch = tree->GetBranch("njets_JER_dn");
  if (njets_JER_dn_branch) njets_JER_dn_branch->SetAddress(&njets_JER_dn_);
  ht_JER_up_branch = tree->GetBranch("ht_JER_up");
  if (ht_JER_up_branch) ht_JER_up_branch->SetAddress(&ht_JER_up_);
  ht_JER_dn_branch = tree->GetBranch("ht_JER_dn");
  if (ht_JER_dn_branch) ht_JER_dn_branch->SetAddress(&ht_JER_dn_);
  nbtags_JER_up_branch = tree->GetBranch("nbtags_JER_up");
  if (nbtags_JER_up_branch) nbtags_JER_up_branch->SetAddress(&nbtags_JER_up_);
  nbtags_JER_dn_branch = tree->GetBranch("nbtags_JER_dn");
  if (nbtags_JER_dn_branch) nbtags_JER_dn_branch->SetAddress(&nbtags_JER_dn_);
  met_JER_up_branch = tree->GetBranch("met_JER_up");
  if (met_JER_up_branch) met_JER_up_branch->SetAddress(&met_JER_up_);
  met_JER_dn_branch = tree->GetBranch("met_JER_dn");
  if (met_JER_dn_branch) met_JER_dn_branch->SetAddress(&met_JER_dn_);
  metPhi_JER_up_branch = tree->GetBranch("metPhi_JER_up");
  if (metPhi_JER_up_branch) metPhi_JER_up_branch->SetAddress(&metPhi_JER_up_);
  metPhi_JER_dn_branch = tree->GetBranch("metPhi_JER_dn");
  if (metPhi_JER_dn_branch) metPhi_JER_dn_branch->SetAddress(&metPhi_JER_dn_);
  lep2_genps_isHardProcess_branch = tree->GetBranch("lep2_genps_isHardProcess");
  if (lep2_genps_isHardProcess_branch) lep2_genps_isHardProcess_branch->SetAddress(&lep2_genps_isHardProcess_);
  lep2_genps_fromHardProcessFinalState_branch = tree->GetBranch("lep2_genps_fromHardProcessFinalState");
  if (lep2_genps_fromHardProcessFinalState_branch) lep2_genps_fromHardProcessFinalState_branch->SetAddress(&lep2_genps_fromHardProcessFinalState_);
  lep2_genps_fromHardProcessDecayed_branch = tree->GetBranch("lep2_genps_fromHardProcessDecayed");
  if (lep2_genps_fromHardProcessDecayed_branch) lep2_genps_fromHardProcessDecayed_branch->SetAddress(&lep2_genps_fromHardProcessDecayed_);
  lep2_genps_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("lep2_genps_isDirectHardProcessTauDecayProductFinalState");
  if (lep2_genps_isDirectHardProcessTauDecayProductFinalState_branch) lep2_genps_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&lep2_genps_isDirectHardProcessTauDecayProductFinalState_);
  lep2_genps_fromHardProcessBeforeFSR_branch = tree->GetBranch("lep2_genps_fromHardProcessBeforeFSR");
  if (lep2_genps_fromHardProcessBeforeFSR_branch) lep2_genps_fromHardProcessBeforeFSR_branch->SetAddress(&lep2_genps_fromHardProcessBeforeFSR_);
  lep2_genps_isLastCopy_branch = tree->GetBranch("lep2_genps_isLastCopy");
  if (lep2_genps_isLastCopy_branch) lep2_genps_isLastCopy_branch->SetAddress(&lep2_genps_isLastCopy_);
  lep2_genps_isLastCopyBeforeFSR_branch = tree->GetBranch("lep2_genps_isLastCopyBeforeFSR");
  if (lep2_genps_isLastCopyBeforeFSR_branch) lep2_genps_isLastCopyBeforeFSR_branch->SetAddress(&lep2_genps_isLastCopyBeforeFSR_);
  lep1_genps_isHardProcess_branch = tree->GetBranch("lep1_genps_isHardProcess");
  if (lep1_genps_isHardProcess_branch) lep1_genps_isHardProcess_branch->SetAddress(&lep1_genps_isHardProcess_);
  lep1_genps_fromHardProcessFinalState_branch = tree->GetBranch("lep1_genps_fromHardProcessFinalState");
  if (lep1_genps_fromHardProcessFinalState_branch) lep1_genps_fromHardProcessFinalState_branch->SetAddress(&lep1_genps_fromHardProcessFinalState_);
  lep1_genps_fromHardProcessDecayed_branch = tree->GetBranch("lep1_genps_fromHardProcessDecayed");
  if (lep1_genps_fromHardProcessDecayed_branch) lep1_genps_fromHardProcessDecayed_branch->SetAddress(&lep1_genps_fromHardProcessDecayed_);
  lep1_genps_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("lep1_genps_isDirectHardProcessTauDecayProductFinalState");
  if (lep1_genps_isDirectHardProcessTauDecayProductFinalState_branch) lep1_genps_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&lep1_genps_isDirectHardProcessTauDecayProductFinalState_);
  lep1_genps_fromHardProcessBeforeFSR_branch = tree->GetBranch("lep1_genps_fromHardProcessBeforeFSR");
  if (lep1_genps_fromHardProcessBeforeFSR_branch) lep1_genps_fromHardProcessBeforeFSR_branch->SetAddress(&lep1_genps_fromHardProcessBeforeFSR_);
  lep1_genps_isLastCopy_branch = tree->GetBranch("lep1_genps_isLastCopy");
  if (lep1_genps_isLastCopy_branch) lep1_genps_isLastCopy_branch->SetAddress(&lep1_genps_isLastCopy_);
  lep1_genps_isLastCopyBeforeFSR_branch = tree->GetBranch("lep1_genps_isLastCopyBeforeFSR");
  if (lep1_genps_isLastCopyBeforeFSR_branch) lep1_genps_isLastCopyBeforeFSR_branch->SetAddress(&lep1_genps_isLastCopyBeforeFSR_);
  lep1_mc3idx_branch = tree->GetBranch("lep1_mc3idx");
  if (lep1_mc3idx_branch) lep1_mc3idx_branch->SetAddress(&lep1_mc3idx_);
  lep2_mc3idx_branch = tree->GetBranch("lep2_mc3idx");
  if (lep2_mc3idx_branch) lep2_mc3idx_branch->SetAddress(&lep2_mc3idx_);
  lep1_el_conv_vtx_flag_branch = tree->GetBranch("lep1_el_conv_vtx_flag");
  if (lep1_el_conv_vtx_flag_branch) lep1_el_conv_vtx_flag_branch->SetAddress(&lep1_el_conv_vtx_flag_);
  lep2_el_conv_vtx_flag_branch = tree->GetBranch("lep2_el_conv_vtx_flag");
  if (lep2_el_conv_vtx_flag_branch) lep2_el_conv_vtx_flag_branch->SetAddress(&lep2_el_conv_vtx_flag_);
  lep1_el_exp_innerlayers_branch = tree->GetBranch("lep1_el_exp_innerlayers");
  if (lep1_el_exp_innerlayers_branch) lep1_el_exp_innerlayers_branch->SetAddress(&lep1_el_exp_innerlayers_);
  lep1_mu_ptErr_branch = tree->GetBranch("lep1_mu_ptErr");
  if (lep1_mu_ptErr_branch) lep1_mu_ptErr_branch->SetAddress(&lep1_mu_ptErr_);
  lep2_mu_ptErr_branch = tree->GetBranch("lep2_mu_ptErr");
  if (lep2_mu_ptErr_branch) lep2_mu_ptErr_branch->SetAddress(&lep2_mu_ptErr_);
  lep1_el_threeChargeAgree_branch = tree->GetBranch("lep1_el_threeChargeAgree");
  if (lep1_el_threeChargeAgree_branch) lep1_el_threeChargeAgree_branch->SetAddress(&lep1_el_threeChargeAgree_);
  lep2_el_threeChargeAgree_branch = tree->GetBranch("lep2_el_threeChargeAgree");
  if (lep2_el_threeChargeAgree_branch) lep2_el_threeChargeAgree_branch->SetAddress(&lep2_el_threeChargeAgree_);
  lep2_el_exp_innerlayers_branch = tree->GetBranch("lep2_el_exp_innerlayers");
  if (lep2_el_exp_innerlayers_branch) lep2_el_exp_innerlayers_branch->SetAddress(&lep2_el_exp_innerlayers_);
  lep1_el_etaSC_branch = tree->GetBranch("lep1_el_etaSC");
  if (lep1_el_etaSC_branch) lep1_el_etaSC_branch->SetAddress(&lep1_el_etaSC_);
  lep2_el_etaSC_branch = tree->GetBranch("lep2_el_etaSC");
  if (lep2_el_etaSC_branch) lep2_el_etaSC_branch->SetAddress(&lep2_el_etaSC_);
  lep1_nPixelMiss_branch = tree->GetBranch("lep1_nPixelMiss");
  if (lep1_nPixelMiss_branch) lep1_nPixelMiss_branch->SetAddress(&lep1_nPixelMiss_);
  lep2_nPixelMiss_branch = tree->GetBranch("lep2_nPixelMiss");
  if (lep2_nPixelMiss_branch) lep2_nPixelMiss_branch->SetAddress(&lep2_nPixelMiss_);
  lep1_tightCharge_branch = tree->GetBranch("lep1_tightCharge");
  if (lep1_tightCharge_branch) lep1_tightCharge_branch->SetAddress(&lep1_tightCharge_);
  lep2_tightCharge_branch = tree->GetBranch("lep2_tightCharge");
  if (lep2_tightCharge_branch) lep2_tightCharge_branch->SetAddress(&lep2_tightCharge_);
  lep1_isTrigSafeNoIsov1_branch = tree->GetBranch("lep1_isTrigSafeNoIsov1");
  if (lep1_isTrigSafeNoIsov1_branch) lep1_isTrigSafeNoIsov1_branch->SetAddress(&lep1_isTrigSafeNoIsov1_);
  lep1_isTrigSafev1_branch = tree->GetBranch("lep1_isTrigSafev1");
  if (lep1_isTrigSafev1_branch) lep1_isTrigSafev1_branch->SetAddress(&lep1_isTrigSafev1_);
  lep2_isTrigSafeNoIsov1_branch = tree->GetBranch("lep2_isTrigSafeNoIsov1");
  if (lep2_isTrigSafeNoIsov1_branch) lep2_isTrigSafeNoIsov1_branch->SetAddress(&lep2_isTrigSafeNoIsov1_);
  lep2_isTrigSafev1_branch = tree->GetBranch("lep2_isTrigSafev1");
  if (lep2_isTrigSafev1_branch) lep2_isTrigSafev1_branch->SetAddress(&lep2_isTrigSafev1_);
  lep1_tightMuonPOG_branch = tree->GetBranch("lep1_tightMuonPOG");
  if (lep1_tightMuonPOG_branch) lep1_tightMuonPOG_branch->SetAddress(&lep1_tightMuonPOG_);
  lep1_mediumMuonPOG_branch = tree->GetBranch("lep1_mediumMuonPOG");
  if (lep1_mediumMuonPOG_branch) lep1_mediumMuonPOG_branch->SetAddress(&lep1_mediumMuonPOG_);
  lep1_looseMuonPOG_branch = tree->GetBranch("lep1_looseMuonPOG");
  if (lep1_looseMuonPOG_branch) lep1_looseMuonPOG_branch->SetAddress(&lep1_looseMuonPOG_);
  lep2_tightMuonPOG_branch = tree->GetBranch("lep2_tightMuonPOG");
  if (lep2_tightMuonPOG_branch) lep2_tightMuonPOG_branch->SetAddress(&lep2_tightMuonPOG_);
  lep2_mediumMuonPOG_branch = tree->GetBranch("lep2_mediumMuonPOG");
  if (lep2_mediumMuonPOG_branch) lep2_mediumMuonPOG_branch->SetAddress(&lep2_mediumMuonPOG_);
  lep2_looseMuonPOG_branch = tree->GetBranch("lep2_looseMuonPOG");
  if (lep2_looseMuonPOG_branch) lep2_looseMuonPOG_branch->SetAddress(&lep2_looseMuonPOG_);
  lep3_mediumMuonPOG_branch = tree->GetBranch("lep3_mediumMuonPOG");
  if (lep3_mediumMuonPOG_branch) lep3_mediumMuonPOG_branch->SetAddress(&lep3_mediumMuonPOG_);
  prefire_sf_branch = tree->GetBranch("prefire_sf");
  if (prefire_sf_branch) prefire_sf_branch->SetAddress(&prefire_sf_);
  prefire_sfup_branch = tree->GetBranch("prefire_sfup");
  if (prefire_sfup_branch) prefire_sfup_branch->SetAddress(&prefire_sfup_);
  prefire_sfdown_branch = tree->GetBranch("prefire_sfdown");
  if (prefire_sfdown_branch) prefire_sfdown_branch->SetAddress(&prefire_sfdown_);
  prefire2016_sf_branch = tree->GetBranch("prefire2016_sf");
  if (prefire2016_sf_branch) prefire2016_sf_branch->SetAddress(&prefire2016_sf_);
  prefire2016_sfup_branch = tree->GetBranch("prefire2016_sfup");
  if (prefire2016_sfup_branch) prefire2016_sfup_branch->SetAddress(&prefire2016_sfup_);
  prefire2016_sfdown_branch = tree->GetBranch("prefire2016_sfdown");
  if (prefire2016_sfdown_branch) prefire2016_sfdown_branch->SetAddress(&prefire2016_sfdown_);
  prefire2017_sf_branch = tree->GetBranch("prefire2017_sf");
  if (prefire2017_sf_branch) prefire2017_sf_branch->SetAddress(&prefire2017_sf_);
  prefire2017_sfup_branch = tree->GetBranch("prefire2017_sfup");
  if (prefire2017_sfup_branch) prefire2017_sfup_branch->SetAddress(&prefire2017_sfup_);
  prefire2017_sfdown_branch = tree->GetBranch("prefire2017_sfdown");
  if (prefire2017_sfdown_branch) prefire2017_sfdown_branch->SetAddress(&prefire2017_sfdown_);
  prefire2017ele_sf_branch = tree->GetBranch("prefire2017ele_sf");
  if (prefire2017ele_sf_branch) prefire2017ele_sf_branch->SetAddress(&prefire2017ele_sf_);
  prefire2017ele_sfup_branch = tree->GetBranch("prefire2017ele_sfup");
  if (prefire2017ele_sfup_branch) prefire2017ele_sfup_branch->SetAddress(&prefire2017ele_sfup_);
  prefire2017ele_sfdown_branch = tree->GetBranch("prefire2017ele_sfdown");
  if (prefire2017ele_sfdown_branch) prefire2017ele_sfdown_branch->SetAddress(&prefire2017ele_sfdown_);
  is_fastsim_branch = tree->GetBranch("is_fastsim");
  if (is_fastsim_branch) is_fastsim_branch->SetAddress(&is_fastsim_);
  lep1_isGoodLeg_branch = tree->GetBranch("lep1_isGoodLeg");
  if (lep1_isGoodLeg_branch) lep1_isGoodLeg_branch->SetAddress(&lep1_isGoodLeg_);
  lep2_isGoodLeg_branch = tree->GetBranch("lep2_isGoodLeg");
  if (lep2_isGoodLeg_branch) lep2_isGoodLeg_branch->SetAddress(&lep2_isGoodLeg_);
  lep1_isFakeLeg_branch = tree->GetBranch("lep1_isFakeLeg");
  if (lep1_isFakeLeg_branch) lep1_isFakeLeg_branch->SetAddress(&lep1_isFakeLeg_);
  lep2_isFakeLeg_branch = tree->GetBranch("lep2_isFakeLeg");
  if (lep2_isFakeLeg_branch) lep2_isFakeLeg_branch->SetAddress(&lep2_isFakeLeg_);
  lep1_multiIso_branch = tree->GetBranch("lep1_multiIso");
  if (lep1_multiIso_branch) lep1_multiIso_branch->SetAddress(&lep1_multiIso_);
  lep2_multiIso_branch = tree->GetBranch("lep2_multiIso");
  if (lep2_multiIso_branch) lep2_multiIso_branch->SetAddress(&lep2_multiIso_);
  lep1_sip_branch = tree->GetBranch("lep1_sip");
  if (lep1_sip_branch) lep1_sip_branch->SetAddress(&lep1_sip_);
  lep2_sip_branch = tree->GetBranch("lep2_sip");
  if (lep2_sip_branch) lep2_sip_branch->SetAddress(&lep2_sip_);
  passed_id_inSituFR_lep1_branch = tree->GetBranch("passed_id_inSituFR_lep1");
  if (passed_id_inSituFR_lep1_branch) passed_id_inSituFR_lep1_branch->SetAddress(&passed_id_inSituFR_lep1_);
  passed_id_inSituFR_lep2_branch = tree->GetBranch("passed_id_inSituFR_lep2");
  if (passed_id_inSituFR_lep2_branch) passed_id_inSituFR_lep2_branch->SetAddress(&passed_id_inSituFR_lep2_);
  fired_trigger_branch = tree->GetBranch("fired_trigger");
  if (fired_trigger_branch) fired_trigger_branch->SetAddress(&fired_trigger_);
  fired_trigger_ss_branch = tree->GetBranch("fired_trigger_ss");
  if (fired_trigger_ss_branch) fired_trigger_ss_branch->SetAddress(&fired_trigger_ss_);
  triggers_branch = tree->GetBranch("triggers");
  if (triggers_branch) triggers_branch->SetAddress(&triggers_);
  weight_btagsf_branch = tree->GetBranch("weight_btagsf");
  if (weight_btagsf_branch) weight_btagsf_branch->SetAddress(&weight_btagsf_);
  weight_btagsf_light_UP_branch = tree->GetBranch("weight_btagsf_light_UP");
  if (weight_btagsf_light_UP_branch) weight_btagsf_light_UP_branch->SetAddress(&weight_btagsf_light_UP_);
  weight_btagsf_light_DN_branch = tree->GetBranch("weight_btagsf_light_DN");
  if (weight_btagsf_light_DN_branch) weight_btagsf_light_DN_branch->SetAddress(&weight_btagsf_light_DN_);
  weight_btagsf_heavy_UP_branch = tree->GetBranch("weight_btagsf_heavy_UP");
  if (weight_btagsf_heavy_UP_branch) weight_btagsf_heavy_UP_branch->SetAddress(&weight_btagsf_heavy_UP_);
  weight_btagsf_heavy_DN_branch = tree->GetBranch("weight_btagsf_heavy_DN");
  if (weight_btagsf_heavy_DN_branch) weight_btagsf_heavy_DN_branch->SetAddress(&weight_btagsf_heavy_DN_);
  weight_btagsf_iter_central_branch = tree->GetBranch("weight_btagsf_iter_central");
  if (weight_btagsf_iter_central_branch) weight_btagsf_iter_central_branch->SetAddress(&weight_btagsf_iter_central_);
  weight_btagsf_iter_down_cferr1_branch = tree->GetBranch("weight_btagsf_iter_down_cferr1");
  if (weight_btagsf_iter_down_cferr1_branch) weight_btagsf_iter_down_cferr1_branch->SetAddress(&weight_btagsf_iter_down_cferr1_);
  weight_btagsf_iter_down_cferr2_branch = tree->GetBranch("weight_btagsf_iter_down_cferr2");
  if (weight_btagsf_iter_down_cferr2_branch) weight_btagsf_iter_down_cferr2_branch->SetAddress(&weight_btagsf_iter_down_cferr2_);
  weight_btagsf_iter_down_hf_branch = tree->GetBranch("weight_btagsf_iter_down_hf");
  if (weight_btagsf_iter_down_hf_branch) weight_btagsf_iter_down_hf_branch->SetAddress(&weight_btagsf_iter_down_hf_);
  weight_btagsf_iter_down_hfstats1_branch = tree->GetBranch("weight_btagsf_iter_down_hfstats1");
  if (weight_btagsf_iter_down_hfstats1_branch) weight_btagsf_iter_down_hfstats1_branch->SetAddress(&weight_btagsf_iter_down_hfstats1_);
  weight_btagsf_iter_down_hfstats2_branch = tree->GetBranch("weight_btagsf_iter_down_hfstats2");
  if (weight_btagsf_iter_down_hfstats2_branch) weight_btagsf_iter_down_hfstats2_branch->SetAddress(&weight_btagsf_iter_down_hfstats2_);
  weight_btagsf_iter_down_jes_branch = tree->GetBranch("weight_btagsf_iter_down_jes");
  if (weight_btagsf_iter_down_jes_branch) weight_btagsf_iter_down_jes_branch->SetAddress(&weight_btagsf_iter_down_jes_);
  weight_btagsf_iter_down_lf_branch = tree->GetBranch("weight_btagsf_iter_down_lf");
  if (weight_btagsf_iter_down_lf_branch) weight_btagsf_iter_down_lf_branch->SetAddress(&weight_btagsf_iter_down_lf_);
  weight_btagsf_iter_down_lfstats1_branch = tree->GetBranch("weight_btagsf_iter_down_lfstats1");
  if (weight_btagsf_iter_down_lfstats1_branch) weight_btagsf_iter_down_lfstats1_branch->SetAddress(&weight_btagsf_iter_down_lfstats1_);
  weight_btagsf_iter_down_lfstats2_branch = tree->GetBranch("weight_btagsf_iter_down_lfstats2");
  if (weight_btagsf_iter_down_lfstats2_branch) weight_btagsf_iter_down_lfstats2_branch->SetAddress(&weight_btagsf_iter_down_lfstats2_);
  weight_btagsf_iter_up_cferr1_branch = tree->GetBranch("weight_btagsf_iter_up_cferr1");
  if (weight_btagsf_iter_up_cferr1_branch) weight_btagsf_iter_up_cferr1_branch->SetAddress(&weight_btagsf_iter_up_cferr1_);
  weight_btagsf_iter_up_cferr2_branch = tree->GetBranch("weight_btagsf_iter_up_cferr2");
  if (weight_btagsf_iter_up_cferr2_branch) weight_btagsf_iter_up_cferr2_branch->SetAddress(&weight_btagsf_iter_up_cferr2_);
  weight_btagsf_iter_up_hf_branch = tree->GetBranch("weight_btagsf_iter_up_hf");
  if (weight_btagsf_iter_up_hf_branch) weight_btagsf_iter_up_hf_branch->SetAddress(&weight_btagsf_iter_up_hf_);
  weight_btagsf_iter_up_hfstats1_branch = tree->GetBranch("weight_btagsf_iter_up_hfstats1");
  if (weight_btagsf_iter_up_hfstats1_branch) weight_btagsf_iter_up_hfstats1_branch->SetAddress(&weight_btagsf_iter_up_hfstats1_);
  weight_btagsf_iter_up_hfstats2_branch = tree->GetBranch("weight_btagsf_iter_up_hfstats2");
  if (weight_btagsf_iter_up_hfstats2_branch) weight_btagsf_iter_up_hfstats2_branch->SetAddress(&weight_btagsf_iter_up_hfstats2_);
  weight_btagsf_iter_up_jes_branch = tree->GetBranch("weight_btagsf_iter_up_jes");
  if (weight_btagsf_iter_up_jes_branch) weight_btagsf_iter_up_jes_branch->SetAddress(&weight_btagsf_iter_up_jes_);
  weight_btagsf_iter_up_lf_branch = tree->GetBranch("weight_btagsf_iter_up_lf");
  if (weight_btagsf_iter_up_lf_branch) weight_btagsf_iter_up_lf_branch->SetAddress(&weight_btagsf_iter_up_lf_);
  weight_btagsf_iter_up_lfstats1_branch = tree->GetBranch("weight_btagsf_iter_up_lfstats1");
  if (weight_btagsf_iter_up_lfstats1_branch) weight_btagsf_iter_up_lfstats1_branch->SetAddress(&weight_btagsf_iter_up_lfstats1_);
  weight_btagsf_iter_up_lfstats2_branch = tree->GetBranch("weight_btagsf_iter_up_lfstats2");
  if (weight_btagsf_iter_up_lfstats2_branch) weight_btagsf_iter_up_lfstats2_branch->SetAddress(&weight_btagsf_iter_up_lfstats2_);
  weight_branch = tree->GetBranch("weight");
  if (weight_branch) weight_branch->SetAddress(&weight_);
  weight_lepsf1_branch = tree->GetBranch("weight_lepsf1");
  if (weight_lepsf1_branch) weight_lepsf1_branch->SetAddress(&weight_lepsf1_);
  weight_lepsf2_branch = tree->GetBranch("weight_lepsf2");
  if (weight_lepsf2_branch) weight_lepsf2_branch->SetAddress(&weight_lepsf2_);
  weight_lepsf3_branch = tree->GetBranch("weight_lepsf3");
  if (weight_lepsf3_branch) weight_lepsf3_branch->SetAddress(&weight_lepsf3_);
  weight_lepsf_branch = tree->GetBranch("weight_lepsf");
  if (weight_lepsf_branch) weight_lepsf_branch->SetAddress(&weight_lepsf_);
  weight_triggersf_branch = tree->GetBranch("weight_triggersf");
  if (weight_triggersf_branch) weight_triggersf_branch->SetAddress(&weight_triggersf_);
  weight_pu_branch = tree->GetBranch("weight_pu");
  if (weight_pu_branch) weight_pu_branch->SetAddress(&weight_pu_);
  weight_isrsf_branch = tree->GetBranch("weight_isrsf");
  if (weight_isrsf_branch) weight_isrsf_branch->SetAddress(&weight_isrsf_);
  year_branch = tree->GetBranch("year");
  if (year_branch) year_branch->SetAddress(&year_);
  yearlumi_branch = tree->GetBranch("yearlumi");
  if (yearlumi_branch) yearlumi_branch->SetAddress(&yearlumi_);
  weight_scale_UP_branch = tree->GetBranch("weight_scale_UP");
  if (weight_scale_UP_branch) weight_scale_UP_branch->SetAddress(&weight_scale_UP_);
  weight_scale_DN_branch = tree->GetBranch("weight_scale_DN");
  if (weight_scale_DN_branch) weight_scale_DN_branch->SetAddress(&weight_scale_DN_);
  weight_pdf_UP_branch = tree->GetBranch("weight_pdf_UP");
  if (weight_pdf_UP_branch) weight_pdf_UP_branch->SetAddress(&weight_pdf_UP_);
  weight_pdf_DN_branch = tree->GetBranch("weight_pdf_DN");
  if (weight_pdf_DN_branch) weight_pdf_DN_branch->SetAddress(&weight_pdf_DN_);
  weight_alphas_UP_branch = tree->GetBranch("weight_alphas_UP");
  if (weight_alphas_UP_branch) weight_alphas_UP_branch->SetAddress(&weight_alphas_UP_);
  weight_alphas_DN_branch = tree->GetBranch("weight_alphas_DN");
  if (weight_alphas_DN_branch) weight_alphas_DN_branch->SetAddress(&weight_alphas_DN_);
  weight_isrvar_UP_branch = tree->GetBranch("weight_isrvar_UP");
  if (weight_isrvar_UP_branch) weight_isrvar_UP_branch->SetAddress(&weight_isrvar_UP_);
  weight_isrvar_DN_branch = tree->GetBranch("weight_isrvar_DN");
  if (weight_isrvar_DN_branch) weight_isrvar_DN_branch->SetAddress(&weight_isrvar_DN_);
  weight_fsrvar_UP_branch = tree->GetBranch("weight_fsrvar_UP");
  if (weight_fsrvar_UP_branch) weight_fsrvar_UP_branch->SetAddress(&weight_fsrvar_UP_);
  weight_fsrvar_DN_branch = tree->GetBranch("weight_fsrvar_DN");
  if (weight_fsrvar_DN_branch) weight_fsrvar_DN_branch->SetAddress(&weight_fsrvar_DN_);
  glglpt_branch = tree->GetBranch("glglpt");
  if (glglpt_branch) glglpt_branch->SetAddress(&glglpt_);
  isr_unc_branch = tree->GetBranch("isr_unc");
  if (isr_unc_branch) isr_unc_branch->SetAddress(&isr_unc_);
  nisrMatch_branch = tree->GetBranch("nisrMatch");
  if (nisrMatch_branch) nisrMatch_branch->SetAddress(&nisrMatch_);
  weight_isr_branch = tree->GetBranch("weight_isr");
  if (weight_isr_branch) weight_isr_branch->SetAddress(&weight_isr_);
  weight_isr_dy_branch = tree->GetBranch("weight_isr_dy");
  if (weight_isr_dy_branch) weight_isr_dy_branch->SetAddress(&weight_isr_dy_);
  weight_isr_tt_branch = tree->GetBranch("weight_isr_tt");
  if (weight_isr_tt_branch) weight_isr_tt_branch->SetAddress(&weight_isr_tt_);
  weight_isr_UP_branch = tree->GetBranch("weight_isr_UP");
  if (weight_isr_UP_branch) weight_isr_UP_branch->SetAddress(&weight_isr_UP_);
  weight_isr_DN_branch = tree->GetBranch("weight_isr_DN");
  if (weight_isr_DN_branch) weight_isr_DN_branch->SetAddress(&weight_isr_DN_);
  lep3_el_etaSC_branch = tree->GetBranch("lep3_el_etaSC");
  if (lep3_el_etaSC_branch) lep3_el_etaSC_branch->SetAddress(&lep3_el_etaSC_);
  lep3_el_conv_vtx_flag_branch = tree->GetBranch("lep3_el_conv_vtx_flag");
  if (lep3_el_conv_vtx_flag_branch) lep3_el_conv_vtx_flag_branch->SetAddress(&lep3_el_conv_vtx_flag_);
  lep3_el_exp_innerlayers_branch = tree->GetBranch("lep3_el_exp_innerlayers");
  if (lep3_el_exp_innerlayers_branch) lep3_el_exp_innerlayers_branch->SetAddress(&lep3_el_exp_innerlayers_);
  lep3_el_threeChargeAgree_branch = tree->GetBranch("lep3_el_threeChargeAgree");
  if (lep3_el_threeChargeAgree_branch) lep3_el_threeChargeAgree_branch->SetAddress(&lep3_el_threeChargeAgree_);
  lep3_el_dxyPV_branch = tree->GetBranch("lep3_el_dxyPV");
  if (lep3_el_dxyPV_branch) lep3_el_dxyPV_branch->SetAddress(&lep3_el_dxyPV_);
  lep3_el_ip3d_branch = tree->GetBranch("lep3_el_ip3d");
  if (lep3_el_ip3d_branch) lep3_el_ip3d_branch->SetAddress(&lep3_el_ip3d_);
  lep3_el_dzPV_branch = tree->GetBranch("lep3_el_dzPV");
  if (lep3_el_dzPV_branch) lep3_el_dzPV_branch->SetAddress(&lep3_el_dzPV_);
  lep3_el_MVA_value_branch = tree->GetBranch("lep3_el_MVA_value");
  if (lep3_el_MVA_value_branch) lep3_el_MVA_value_branch->SetAddress(&lep3_el_MVA_value_);
  lep3_el_MVA_branch = tree->GetBranch("lep3_el_MVA");
  if (lep3_el_MVA_branch) lep3_el_MVA_branch->SetAddress(&lep3_el_MVA_);
  lep3_passes_RA5_branch = tree->GetBranch("lep3_passes_RA5");
  if (lep3_passes_RA5_branch) lep3_passes_RA5_branch->SetAddress(&lep3_passes_RA5_);
  lep3_mu_dxyPV_branch = tree->GetBranch("lep3_mu_dxyPV");
  if (lep3_mu_dxyPV_branch) lep3_mu_dxyPV_branch->SetAddress(&lep3_mu_dxyPV_);
  lep3_mu_ip3d_branch = tree->GetBranch("lep3_mu_ip3d");
  if (lep3_mu_ip3d_branch) lep3_mu_ip3d_branch->SetAddress(&lep3_mu_ip3d_);
  lep3_mu_dzPV_branch = tree->GetBranch("lep3_mu_dzPV");
  if (lep3_mu_dzPV_branch) lep3_mu_dzPV_branch->SetAddress(&lep3_mu_dzPV_);
  lep3_mu_ptErr_branch = tree->GetBranch("lep3_mu_ptErr");
  if (lep3_mu_ptErr_branch) lep3_mu_ptErr_branch->SetAddress(&lep3_mu_ptErr_);
  lep4_el_etaSC_branch = tree->GetBranch("lep4_el_etaSC");
  if (lep4_el_etaSC_branch) lep4_el_etaSC_branch->SetAddress(&lep4_el_etaSC_);
  lep4_el_conv_vtx_flag_branch = tree->GetBranch("lep4_el_conv_vtx_flag");
  if (lep4_el_conv_vtx_flag_branch) lep4_el_conv_vtx_flag_branch->SetAddress(&lep4_el_conv_vtx_flag_);
  lep4_el_exp_innerlayers_branch = tree->GetBranch("lep4_el_exp_innerlayers");
  if (lep4_el_exp_innerlayers_branch) lep4_el_exp_innerlayers_branch->SetAddress(&lep4_el_exp_innerlayers_);
  lep4_el_threeChargeAgree_branch = tree->GetBranch("lep4_el_threeChargeAgree");
  if (lep4_el_threeChargeAgree_branch) lep4_el_threeChargeAgree_branch->SetAddress(&lep4_el_threeChargeAgree_);
  lep4_el_dxyPV_branch = tree->GetBranch("lep4_el_dxyPV");
  if (lep4_el_dxyPV_branch) lep4_el_dxyPV_branch->SetAddress(&lep4_el_dxyPV_);
  lep4_el_ip3d_branch = tree->GetBranch("lep4_el_ip3d");
  if (lep4_el_ip3d_branch) lep4_el_ip3d_branch->SetAddress(&lep4_el_ip3d_);
  lep4_el_dzPV_branch = tree->GetBranch("lep4_el_dzPV");
  if (lep4_el_dzPV_branch) lep4_el_dzPV_branch->SetAddress(&lep4_el_dzPV_);
  lep4_el_MVA_value_branch = tree->GetBranch("lep4_el_MVA_value");
  if (lep4_el_MVA_value_branch) lep4_el_MVA_value_branch->SetAddress(&lep4_el_MVA_value_);
  lep4_el_MVA_branch = tree->GetBranch("lep4_el_MVA");
  if (lep4_el_MVA_branch) lep4_el_MVA_branch->SetAddress(&lep4_el_MVA_);
  lep4_mu_dxyPV_branch = tree->GetBranch("lep4_mu_dxyPV");
  if (lep4_mu_dxyPV_branch) lep4_mu_dxyPV_branch->SetAddress(&lep4_mu_dxyPV_);
  lep4_mu_ip3d_branch = tree->GetBranch("lep4_mu_ip3d");
  if (lep4_mu_ip3d_branch) lep4_mu_ip3d_branch->SetAddress(&lep4_mu_ip3d_);
  lep4_mu_dzPV_branch = tree->GetBranch("lep4_mu_dzPV");
  if (lep4_mu_dzPV_branch) lep4_mu_dzPV_branch->SetAddress(&lep4_mu_dzPV_);
  lep4_mu_ptErr_branch = tree->GetBranch("lep4_mu_ptErr");
  if (lep4_mu_ptErr_branch) lep4_mu_ptErr_branch->SetAddress(&lep4_mu_ptErr_);
  lep3_isTrigSafeNoIsov1_branch = tree->GetBranch("lep3_isTrigSafeNoIsov1");
  if (lep3_isTrigSafeNoIsov1_branch) lep3_isTrigSafeNoIsov1_branch->SetAddress(&lep3_isTrigSafeNoIsov1_);
  lep3_isTrigSafev1_branch = tree->GetBranch("lep3_isTrigSafev1");
  if (lep3_isTrigSafev1_branch) lep3_isTrigSafev1_branch->SetAddress(&lep3_isTrigSafev1_);
  lep4_isTrigSafeNoIsov1_branch = tree->GetBranch("lep4_isTrigSafeNoIsov1");
  if (lep4_isTrigSafeNoIsov1_branch) lep4_isTrigSafeNoIsov1_branch->SetAddress(&lep4_isTrigSafeNoIsov1_);
  lep4_isTrigSafev1_branch = tree->GetBranch("lep4_isTrigSafev1");
  if (lep4_isTrigSafev1_branch) lep4_isTrigSafev1_branch->SetAddress(&lep4_isTrigSafev1_);
  extragenb_branch = tree->GetBranch("extragenb");
  if (extragenb_branch) extragenb_branch->SetAddress(&extragenb_);
  extragenbmoms_branch = tree->GetBranch("extragenbmoms");
  if (extragenbmoms_branch) extragenbmoms_branch->SetAddress(&extragenbmoms_);
  extragenc_branch = tree->GetBranch("extragenc");
  if (extragenc_branch) extragenc_branch->SetAddress(&extragenc_);
  extragencmoms_branch = tree->GetBranch("extragencmoms");
  if (extragencmoms_branch) extragencmoms_branch->SetAddress(&extragencmoms_);
  ngenjets_branch = tree->GetBranch("ngenjets");
  if (ngenjets_branch) ngenjets_branch->SetAddress(&ngenjets_);
  genht_branch = tree->GetBranch("genht");
  if (genht_branch) genht_branch->SetAddress(&genht_);
  ngenjets30_branch = tree->GetBranch("ngenjets30");
  if (ngenjets30_branch) ngenjets30_branch->SetAddress(&ngenjets30_);
  genht30_branch = tree->GetBranch("genht30");
  if (genht30_branch) genht30_branch->SetAddress(&genht30_);
  passfilter_branch = tree->GetBranch("passfilter");
  if (passfilter_branch) passfilter_branch->SetAddress(&passfilter_);
  hasgammatoll_branch = tree->GetBranch("hasgammatoll");
  if (hasgammatoll_branch) hasgammatoll_branch->SetAddress(&hasgammatoll_);
  gammatollmomemu_branch = tree->GetBranch("gammatollmomemu");
  if (gammatollmomemu_branch) gammatollmomemu_branch->SetAddress(&gammatollmomemu_);
  gammatolldr_branch = tree->GetBranch("gammatolldr");
  if (gammatolldr_branch) gammatolldr_branch->SetAddress(&gammatolldr_);
  bjet_type_branch = tree->GetBranch("bjet_type");
  if (bjet_type_branch) bjet_type_branch->SetAddress(&bjet_type_);
  jet_type_branch = tree->GetBranch("jet_type");
  if (jet_type_branch) jet_type_branch->SetAddress(&jet_type_);
  jet_cat_branch = tree->GetBranch("jet_cat");
  if (jet_cat_branch) jet_cat_branch->SetAddress(&jet_cat_);
  jet_matchedGenIndex_branch = tree->GetBranch("jet_matchedGenIndex");
  if (jet_matchedGenIndex_branch) jet_matchedGenIndex_branch->SetAddress(&jet_matchedGenIndex_);
  jet_matchedGenId_branch = tree->GetBranch("jet_matchedGenId");
  if (jet_matchedGenId_branch) jet_matchedGenId_branch->SetAddress(&jet_matchedGenId_);
  jet_matchedGenMId_branch = tree->GetBranch("jet_matchedGenMId");
  if (jet_matchedGenMId_branch) jet_matchedGenMId_branch->SetAddress(&jet_matchedGenMId_);
  jet_matchedDr_branch = tree->GetBranch("jet_matchedDr");
  if (jet_matchedDr_branch) jet_matchedDr_branch->SetAddress(&jet_matchedDr_);
  jet_matchedPtDiff_branch = tree->GetBranch("jet_matchedPtDiff");
  if (jet_matchedPtDiff_branch) jet_matchedPtDiff_branch->SetAddress(&jet_matchedPtDiff_);
  ndrlt0p4_branch = tree->GetBranch("ndrlt0p4");
  if (ndrlt0p4_branch) ndrlt0p4_branch->SetAddress(&ndrlt0p4_);
  gengood_branch = tree->GetBranch("gengood");
  if (gengood_branch) gengood_branch->SetAddress(&gengood_);
  nleptonic_branch = tree->GetBranch("nleptonic");
  if (nleptonic_branch) nleptonic_branch->SetAddress(&nleptonic_);
  ntau_branch = tree->GetBranch("ntau");
  if (ntau_branch) ntau_branch->SetAddress(&ntau_);
  nleptonicW_branch = tree->GetBranch("nleptonicW");
  if (nleptonicW_branch) nleptonicW_branch->SetAddress(&nleptonicW_);
  mfourtop_branch = tree->GetBranch("mfourtop");
  if (mfourtop_branch) mfourtop_branch->SetAddress(&mfourtop_);
  nhadronicW_branch = tree->GetBranch("nhadronicW");
  if (nhadronicW_branch) nhadronicW_branch->SetAddress(&nhadronicW_);
  nW_branch = tree->GetBranch("nW");
  if (nW_branch) nW_branch->SetAddress(&nW_);
  leptonicWSF_branch = tree->GetBranch("leptonicWSF");
  if (leptonicWSF_branch) leptonicWSF_branch->SetAddress(&leptonicWSF_);
  hadronicWSF_branch = tree->GetBranch("hadronicWSF");
  if (hadronicWSF_branch) hadronicWSF_branch->SetAddress(&hadronicWSF_);
  decayWSF_branch = tree->GetBranch("decayWSF");
  if (decayWSF_branch) decayWSF_branch->SetAddress(&decayWSF_);
  njincone1_branch = tree->GetBranch("njincone1");
  if (njincone1_branch) njincone1_branch->SetAddress(&njincone1_);
  njincone2_branch = tree->GetBranch("njincone2");
  if (njincone2_branch) njincone2_branch->SetAddress(&njincone2_);
  bdt_nforwardjets20_branch = tree->GetBranch("bdt_nforwardjets20");
  if (bdt_nforwardjets20_branch) bdt_nforwardjets20_branch->SetAddress(&bdt_nforwardjets20_);
  bdt_avgcdisc_branch = tree->GetBranch("bdt_avgcdisc");
  if (bdt_avgcdisc_branch) bdt_avgcdisc_branch->SetAddress(&bdt_avgcdisc_);
  bdt_nbtags_branch = tree->GetBranch("bdt_nbtags");
  if (bdt_nbtags_branch) bdt_nbtags_branch->SetAddress(&bdt_nbtags_);
  bdt_njets_branch = tree->GetBranch("bdt_njets");
  if (bdt_njets_branch) bdt_njets_branch->SetAddress(&bdt_njets_);
  bdt_met_branch = tree->GetBranch("bdt_met");
  if (bdt_met_branch) bdt_met_branch->SetAddress(&bdt_met_);
  bdt_ptl2_branch = tree->GetBranch("bdt_ptl2");
  if (bdt_ptl2_branch) bdt_ptl2_branch->SetAddress(&bdt_ptl2_);
  bdt_nlb40_branch = tree->GetBranch("bdt_nlb40");
  if (bdt_nlb40_branch) bdt_nlb40_branch->SetAddress(&bdt_nlb40_);
  bdt_ntb40_branch = tree->GetBranch("bdt_ntb40");
  if (bdt_ntb40_branch) bdt_ntb40_branch->SetAddress(&bdt_ntb40_);
  bdt_nleps_branch = tree->GetBranch("bdt_nleps");
  if (bdt_nleps_branch) bdt_nleps_branch->SetAddress(&bdt_nleps_);
  bdt_htb_branch = tree->GetBranch("bdt_htb");
  if (bdt_htb_branch) bdt_htb_branch->SetAddress(&bdt_htb_);
  bdt_ml1j1_branch = tree->GetBranch("bdt_ml1j1");
  if (bdt_ml1j1_branch) bdt_ml1j1_branch->SetAddress(&bdt_ml1j1_);
  bdt_dphil1l2_branch = tree->GetBranch("bdt_dphil1l2");
  if (bdt_dphil1l2_branch) bdt_dphil1l2_branch->SetAddress(&bdt_dphil1l2_);
  bdt_maxmjoverpt_branch = tree->GetBranch("bdt_maxmjoverpt");
  if (bdt_maxmjoverpt_branch) bdt_maxmjoverpt_branch->SetAddress(&bdt_maxmjoverpt_);
  bdt_detal1l2_branch = tree->GetBranch("bdt_detal1l2");
  if (bdt_detal1l2_branch) bdt_detal1l2_branch->SetAddress(&bdt_detal1l2_);
  bdt_q1_branch = tree->GetBranch("bdt_q1");
  if (bdt_q1_branch) bdt_q1_branch->SetAddress(&bdt_q1_);
  bdt_ptj1_branch = tree->GetBranch("bdt_ptj1");
  if (bdt_ptj1_branch) bdt_ptj1_branch->SetAddress(&bdt_ptj1_);
  bdt_ptj6_branch = tree->GetBranch("bdt_ptj6");
  if (bdt_ptj6_branch) bdt_ptj6_branch->SetAddress(&bdt_ptj6_);
  bdt_ptj7_branch = tree->GetBranch("bdt_ptj7");
  if (bdt_ptj7_branch) bdt_ptj7_branch->SetAddress(&bdt_ptj7_);
  bdt_ptj8_branch = tree->GetBranch("bdt_ptj8");
  if (bdt_ptj8_branch) bdt_ptj8_branch->SetAddress(&bdt_ptj8_);
  bdt_ptl1_branch = tree->GetBranch("bdt_ptl1");
  if (bdt_ptl1_branch) bdt_ptl1_branch->SetAddress(&bdt_ptl1_);
  bdt_ptl3_branch = tree->GetBranch("bdt_ptl3");
  if (bdt_ptl3_branch) bdt_ptl3_branch->SetAddress(&bdt_ptl3_);
  bdt_jec_up_nbtags_branch = tree->GetBranch("bdt_jec_up_nbtags");
  if (bdt_jec_up_nbtags_branch) bdt_jec_up_nbtags_branch->SetAddress(&bdt_jec_up_nbtags_);
  bdt_jec_dn_nbtags_branch = tree->GetBranch("bdt_jec_dn_nbtags");
  if (bdt_jec_dn_nbtags_branch) bdt_jec_dn_nbtags_branch->SetAddress(&bdt_jec_dn_nbtags_);
  bdt_jer_up_nbtags_branch = tree->GetBranch("bdt_jer_up_nbtags");
  if (bdt_jer_up_nbtags_branch) bdt_jer_up_nbtags_branch->SetAddress(&bdt_jer_up_nbtags_);
  bdt_jer_dn_nbtags_branch = tree->GetBranch("bdt_jer_dn_nbtags");
  if (bdt_jer_dn_nbtags_branch) bdt_jer_dn_nbtags_branch->SetAddress(&bdt_jer_dn_nbtags_);
  bdt_jec_up_njets_branch = tree->GetBranch("bdt_jec_up_njets");
  if (bdt_jec_up_njets_branch) bdt_jec_up_njets_branch->SetAddress(&bdt_jec_up_njets_);
  bdt_jec_dn_njets_branch = tree->GetBranch("bdt_jec_dn_njets");
  if (bdt_jec_dn_njets_branch) bdt_jec_dn_njets_branch->SetAddress(&bdt_jec_dn_njets_);
  bdt_jer_up_njets_branch = tree->GetBranch("bdt_jer_up_njets");
  if (bdt_jer_up_njets_branch) bdt_jer_up_njets_branch->SetAddress(&bdt_jer_up_njets_);
  bdt_jer_dn_njets_branch = tree->GetBranch("bdt_jer_dn_njets");
  if (bdt_jer_dn_njets_branch) bdt_jer_dn_njets_branch->SetAddress(&bdt_jer_dn_njets_);
  bdt_jec_up_met_branch = tree->GetBranch("bdt_jec_up_met");
  if (bdt_jec_up_met_branch) bdt_jec_up_met_branch->SetAddress(&bdt_jec_up_met_);
  bdt_jec_dn_met_branch = tree->GetBranch("bdt_jec_dn_met");
  if (bdt_jec_dn_met_branch) bdt_jec_dn_met_branch->SetAddress(&bdt_jec_dn_met_);
  bdt_jer_up_met_branch = tree->GetBranch("bdt_jer_up_met");
  if (bdt_jer_up_met_branch) bdt_jer_up_met_branch->SetAddress(&bdt_jer_up_met_);
  bdt_jer_dn_met_branch = tree->GetBranch("bdt_jer_dn_met");
  if (bdt_jer_dn_met_branch) bdt_jer_dn_met_branch->SetAddress(&bdt_jer_dn_met_);
  bdt_jec_up_htb_branch = tree->GetBranch("bdt_jec_up_htb");
  if (bdt_jec_up_htb_branch) bdt_jec_up_htb_branch->SetAddress(&bdt_jec_up_htb_);
  bdt_jec_dn_htb_branch = tree->GetBranch("bdt_jec_dn_htb");
  if (bdt_jec_dn_htb_branch) bdt_jec_dn_htb_branch->SetAddress(&bdt_jec_dn_htb_);
  bdt_jer_up_htb_branch = tree->GetBranch("bdt_jer_up_htb");
  if (bdt_jer_up_htb_branch) bdt_jer_up_htb_branch->SetAddress(&bdt_jer_up_htb_);
  bdt_jer_dn_htb_branch = tree->GetBranch("bdt_jer_dn_htb");
  if (bdt_jer_dn_htb_branch) bdt_jer_dn_htb_branch->SetAddress(&bdt_jer_dn_htb_);
  bdt_jec_up_nlb40_branch = tree->GetBranch("bdt_jec_up_nlb40");
  if (bdt_jec_up_nlb40_branch) bdt_jec_up_nlb40_branch->SetAddress(&bdt_jec_up_nlb40_);
  bdt_jec_dn_nlb40_branch = tree->GetBranch("bdt_jec_dn_nlb40");
  if (bdt_jec_dn_nlb40_branch) bdt_jec_dn_nlb40_branch->SetAddress(&bdt_jec_dn_nlb40_);
  bdt_jer_up_nlb40_branch = tree->GetBranch("bdt_jer_up_nlb40");
  if (bdt_jer_up_nlb40_branch) bdt_jer_up_nlb40_branch->SetAddress(&bdt_jer_up_nlb40_);
  bdt_jer_dn_nlb40_branch = tree->GetBranch("bdt_jer_dn_nlb40");
  if (bdt_jer_dn_nlb40_branch) bdt_jer_dn_nlb40_branch->SetAddress(&bdt_jer_dn_nlb40_);
  bdt_jec_up_ntb40_branch = tree->GetBranch("bdt_jec_up_ntb40");
  if (bdt_jec_up_ntb40_branch) bdt_jec_up_ntb40_branch->SetAddress(&bdt_jec_up_ntb40_);
  bdt_jec_dn_ntb40_branch = tree->GetBranch("bdt_jec_dn_ntb40");
  if (bdt_jec_dn_ntb40_branch) bdt_jec_dn_ntb40_branch->SetAddress(&bdt_jec_dn_ntb40_);
  bdt_jer_up_ntb40_branch = tree->GetBranch("bdt_jer_up_ntb40");
  if (bdt_jer_up_ntb40_branch) bdt_jer_up_ntb40_branch->SetAddress(&bdt_jer_up_ntb40_);
  bdt_jer_dn_ntb40_branch = tree->GetBranch("bdt_jer_dn_ntb40");
  if (bdt_jer_dn_ntb40_branch) bdt_jer_dn_ntb40_branch->SetAddress(&bdt_jer_dn_ntb40_);
  bdt_disc_branch = tree->GetBranch("bdt_disc");
  if (bdt_disc_branch) bdt_disc_branch->SetAddress(&bdt_disc_);
  bdt_disc_jec_up_branch = tree->GetBranch("bdt_disc_jec_up");
  if (bdt_disc_jec_up_branch) bdt_disc_jec_up_branch->SetAddress(&bdt_disc_jec_up_);
  bdt_disc_jer_up_branch = tree->GetBranch("bdt_disc_jer_up");
  if (bdt_disc_jer_up_branch) bdt_disc_jer_up_branch->SetAddress(&bdt_disc_jer_up_);
  bdt_disc_jec_dn_branch = tree->GetBranch("bdt_disc_jec_dn");
  if (bdt_disc_jec_dn_branch) bdt_disc_jec_dn_branch->SetAddress(&bdt_disc_jec_dn_);
  bdt_disc_jer_dn_branch = tree->GetBranch("bdt_disc_jer_dn");
  if (bdt_disc_jer_dn_branch) bdt_disc_jer_dn_branch->SetAddress(&bdt_disc_jer_dn_);
  bdt_run2_disc_branch = tree->GetBranch("bdt_run2_disc");
  if (bdt_run2_disc_branch) bdt_run2_disc_branch->SetAddress(&bdt_run2_disc_);
  bdt_run2_SRDISC_branch = tree->GetBranch("bdt_run2_SRDISC");
  if (bdt_run2_SRDISC_branch) bdt_run2_SRDISC_branch->SetAddress(&bdt_run2_SRDISC_);
  bdt_run2_disc_jec_up_branch = tree->GetBranch("bdt_run2_disc_jec_up");
  if (bdt_run2_disc_jec_up_branch) bdt_run2_disc_jec_up_branch->SetAddress(&bdt_run2_disc_jec_up_);
  bdt_run2_disc_jer_up_branch = tree->GetBranch("bdt_run2_disc_jer_up");
  if (bdt_run2_disc_jer_up_branch) bdt_run2_disc_jer_up_branch->SetAddress(&bdt_run2_disc_jer_up_);
  bdt_run2_disc_jec_dn_branch = tree->GetBranch("bdt_run2_disc_jec_dn");
  if (bdt_run2_disc_jec_dn_branch) bdt_run2_disc_jec_dn_branch->SetAddress(&bdt_run2_disc_jec_dn_);
  bdt_run2_disc_jer_dn_branch = tree->GetBranch("bdt_run2_disc_jer_dn");
  if (bdt_run2_disc_jer_dn_branch) bdt_run2_disc_jer_dn_branch->SetAddress(&bdt_run2_disc_jer_dn_);

  tree->SetMakeClass(0);
}

void SSAG::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  lep1_isPrompt_isLoaded = false;
  lep1_isDirectPrompt_isLoaded = false;
  lep1_isStat3_isLoaded = false;
  lep2_isPrompt_isLoaded = false;
  lep2_isDirectPrompt_isLoaded = false;
  lep2_isStat3_isLoaded = false;
  met_isLoaded = false;
  metPhi_isLoaded = false;
  rawmet_isLoaded = false;
  rawmetPhi_isLoaded = false;
  calomet_isLoaded = false;
  calometPhi_isLoaded = false;
  event_isLoaded = false;
  lumi_isLoaded = false;
  run_isLoaded = false;
  filt_csc_isLoaded = false;
  filt_hbhe_isLoaded = false;
  filt_hcallaser_isLoaded = false;
  filt_ecaltp_isLoaded = false;
  filt_trkfail_isLoaded = false;
  is_real_data_isLoaded = false;
  scale1fb_isLoaded = false;
  genps_weight_isLoaded = false;
  xsec_isLoaded = false;
  neventstotal_isLoaded = false;
  xsec_ps_isLoaded = false;
  sparmNames_isLoaded = false;
  sparms_isLoaded = false;
  xsec_error_isLoaded = false;
  kfactor_isLoaded = false;
  gen_met_isLoaded = false;
  pdfweights_isLoaded = false;
  gen_met_phi_isLoaded = false;
  skim_isLoaded = false;
  skim_nomet_isLoaded = false;
  nleps_isLoaded = false;
  sr_isLoaded = false;
  br_isLoaded = false;
  ss_nleps_isLoaded = false;
  ss_br_isLoaded = false;
  ss_sr_isLoaded = false;
  ss_region_isLoaded = false;
  njets_isLoaded = false;
  njetsAG_isLoaded = false;
  nbtagsAG_isLoaded = false;
  njets_raw_isLoaded = false;
  hyp_class_isLoaded = false;
  lep1_p4_isLoaded = false;
  lep2_p4_isLoaded = false;
  lep1_pt_isLoaded = false;
  lep2_pt_isLoaded = false;
  lep3_pt_isLoaded = false;
  lep1_eta_isLoaded = false;
  lep2_eta_isLoaded = false;
  lep3_eta_isLoaded = false;
  lep1_phi_isLoaded = false;
  lep2_phi_isLoaded = false;
  lep3_phi_isLoaded = false;
  ht_raw_isLoaded = false;
  ht_isLoaded = false;
  lep1_motherID_isLoaded = false;
  lep2_motherID_isLoaded = false;
  lep1_mc_id_isLoaded = false;
  lep2_mc_id_isLoaded = false;
  lep1_mc_motherid_isLoaded = false;
  lep2_mc_motherid_isLoaded = false;
  lep1_id_isLoaded = false;
  lep2_id_isLoaded = false;
  lep1_coneCorrPt_isLoaded = false;
  lep2_coneCorrPt_isLoaded = false;
  lep3_coneCorrPt_isLoaded = false;
  lep4_coneCorrPt_isLoaded = false;
  lep1_idx_isLoaded = false;
  lep2_idx_isLoaded = false;
  jets_isLoaded = false;
  jets_jec_up_isLoaded = false;
  jets_jec_dn_isLoaded = false;
  jets_disc_up_isLoaded = false;
  jets_disc_dn_isLoaded = false;
  bjets_jec_up_isLoaded = false;
  bjets_jec_dn_isLoaded = false;
  btags_flavor_isLoaded = false;
  btags_disc_isLoaded = false;
  btags_cdisc_isLoaded = false;
  jets_flavor_isLoaded = false;
  jets_disc_isLoaded = false;
  jets_bsf_isLoaded = false;
  jets_JEC_isLoaded = false;
  btags_JEC_isLoaded = false;
  jets_undoJEC_isLoaded = false;
  btags_undoJEC_isLoaded = false;
  btags_unc_isLoaded = false;
  btags_eff_isLoaded = false;
  btags_effpt_isLoaded = false;
  btags_sf_isLoaded = false;
  jets_unc_isLoaded = false;
  btags_isLoaded = false;
  nbtags_isLoaded = false;
  nbtags_raw_isLoaded = false;
  sf_dilepTrig_hpt_isLoaded = false;
  sf_dilepTrig_lpt_isLoaded = false;
  sf_dilepTrig_vlpt_isLoaded = false;
  hyp_type_isLoaded = false;
  sf_dilep_eff_isLoaded = false;
  mt_isLoaded = false;
  mt_l2_isLoaded = false;
  mt2_isLoaded = false;
  mtmin_isLoaded = false;
  lep1_id_gen_isLoaded = false;
  lep2_id_gen_isLoaded = false;
  lep1_p4_gen_isLoaded = false;
  lep2_p4_gen_isLoaded = false;
  lep3_id_isLoaded = false;
  lep3_idx_isLoaded = false;
  lep3_p4_isLoaded = false;
  lep3_quality_isLoaded = false;
  lep4_id_isLoaded = false;
  lep4_idx_isLoaded = false;
  lep4_p4_isLoaded = false;
  lep1_iso_isLoaded = false;
  lep2_iso_isLoaded = false;
  dilep_p4_isLoaded = false;
  dilep_mass_isLoaded = false;
  mass13_isLoaded = false;
  mass23_isLoaded = false;
  mass123_isLoaded = false;
  ncharginos_isLoaded = false;
  nhiggs_isLoaded = false;
  higgs_mass_isLoaded = false;
  genps_p4_isLoaded = false;
  genjets_p4_isLoaded = false;
  genps_id_isLoaded = false;
  genps_id_mother_isLoaded = false;
  genps_idx_mother_isLoaded = false;
  genps_status_isLoaded = false;
  genps_id_grandma_isLoaded = false;
  all_leps_p4_isLoaded = false;
  all_leps_id_isLoaded = false;
  all_leps_veto_isLoaded = false;
  all_leps_mc3idx_isLoaded = false;
  lep1_passes_id_isLoaded = false;
  lep2_passes_id_isLoaded = false;
  lep3_passes_id_isLoaded = false;
  lep4_passes_id_isLoaded = false;
  lep1_tight_isLoaded = false;
  lep1_veto_isLoaded = false;
  lep1_fo_isLoaded = false;
  lep2_tight_isLoaded = false;
  lep2_veto_isLoaded = false;
  lep2_fo_isLoaded = false;
  lep3_tight_isLoaded = false;
  lep3_veto_isLoaded = false;
  lep3_fo_isLoaded = false;
  lep4_tight_isLoaded = false;
  lep4_veto_isLoaded = false;
  lep4_fo_isLoaded = false;
  lep1_dxyPV_isLoaded = false;
  lep2_dxyPV_isLoaded = false;
  lep1_dZ_isLoaded = false;
  lep2_dZ_isLoaded = false;
  lep1_d0_err_isLoaded = false;
  lep2_d0_err_isLoaded = false;
  lep1_ip3d_isLoaded = false;
  lep2_ip3d_isLoaded = false;
  lep1_MVA_isLoaded = false;
  lep2_MVA_isLoaded = false;
  lep1_ip3d_err_isLoaded = false;
  lep2_ip3d_err_isLoaded = false;
  nVetoElectrons7_isLoaded = false;
  nVetoElectrons10_isLoaded = false;
  nVetoElectrons25_isLoaded = false;
  nVetoMuons5_isLoaded = false;
  nVetoMuons10_isLoaded = false;
  nVetoMuons25_isLoaded = false;
  filename_isLoaded = false;
  lep1_ptrel_ma_isLoaded = false;
  lep1_ptratio_ma_isLoaded = false;
  lep2_ptrel_ma_isLoaded = false;
  lep2_ptratio_ma_isLoaded = false;
  lep1_ptrel_v1_isLoaded = false;
  lep2_ptrel_v1_isLoaded = false;
  lep1_ptratio_isLoaded = false;
  lep2_ptratio_isLoaded = false;
  lep1_miniIso_isLoaded = false;
  lep2_miniIso_isLoaded = false;
  trueNumInt_isLoaded = false;
  nGoodVertices_isLoaded = false;
  lep1_trigMatch_noIsoReq_isLoaded = false;
  lep1_trigMatch_isoReq_isLoaded = false;
  lep2_trigMatch_noIsoReq_isLoaded = false;
  lep2_trigMatch_isoReq_isLoaded = false;
  passes_met_filters_isLoaded = false;
  passes_chargedcand_filter_isLoaded = false;
  evt_egclean_pfmet_isLoaded = false;
  evt_muegclean_pfmet_isLoaded = false;
  evt_muegcleanfix_pfmet_isLoaded = false;
  evt_uncorr_pfmet_isLoaded = false;
  filt_noBadMuons_isLoaded = false;
  filt_duplicateMuons_isLoaded = false;
  filt_badMuons_isLoaded = false;
  failsRA2Filter_isLoaded = false;
  madeExtraZ_isLoaded = false;
  madeExtraG_isLoaded = false;
  lep3_mcid_isLoaded = false;
  lep3_mc_motherid_isLoaded = false;
  lep3_mc3idx_isLoaded = false;
  lep3_motherID_isLoaded = false;
  lep4_mcid_isLoaded = false;
  lep4_mcidx_isLoaded = false;
  njets_unc_up_isLoaded = false;
  njets_unc_dn_isLoaded = false;
  ht_unc_up_isLoaded = false;
  ht_unc_dn_isLoaded = false;
  nbtags_unc_up_isLoaded = false;
  nbtags_unc_dn_isLoaded = false;
  met_unc_up_isLoaded = false;
  met_unc_dn_isLoaded = false;
  metPhi_unc_up_isLoaded = false;
  metPhi_unc_dn_isLoaded = false;
  njets_JER_up_isLoaded = false;
  njets_JER_dn_isLoaded = false;
  ht_JER_up_isLoaded = false;
  ht_JER_dn_isLoaded = false;
  nbtags_JER_up_isLoaded = false;
  nbtags_JER_dn_isLoaded = false;
  met_JER_up_isLoaded = false;
  met_JER_dn_isLoaded = false;
  metPhi_JER_up_isLoaded = false;
  metPhi_JER_dn_isLoaded = false;
  lep2_genps_isHardProcess_isLoaded = false;
  lep2_genps_fromHardProcessFinalState_isLoaded = false;
  lep2_genps_fromHardProcessDecayed_isLoaded = false;
  lep2_genps_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
  lep2_genps_fromHardProcessBeforeFSR_isLoaded = false;
  lep2_genps_isLastCopy_isLoaded = false;
  lep2_genps_isLastCopyBeforeFSR_isLoaded = false;
  lep1_genps_isHardProcess_isLoaded = false;
  lep1_genps_fromHardProcessFinalState_isLoaded = false;
  lep1_genps_fromHardProcessDecayed_isLoaded = false;
  lep1_genps_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
  lep1_genps_fromHardProcessBeforeFSR_isLoaded = false;
  lep1_genps_isLastCopy_isLoaded = false;
  lep1_genps_isLastCopyBeforeFSR_isLoaded = false;
  lep1_mc3idx_isLoaded = false;
  lep2_mc3idx_isLoaded = false;
  lep1_el_conv_vtx_flag_isLoaded = false;
  lep2_el_conv_vtx_flag_isLoaded = false;
  lep1_el_exp_innerlayers_isLoaded = false;
  lep1_mu_ptErr_isLoaded = false;
  lep2_mu_ptErr_isLoaded = false;
  lep1_el_threeChargeAgree_isLoaded = false;
  lep2_el_threeChargeAgree_isLoaded = false;
  lep2_el_exp_innerlayers_isLoaded = false;
  lep1_el_etaSC_isLoaded = false;
  lep2_el_etaSC_isLoaded = false;
  lep1_nPixelMiss_isLoaded = false;
  lep2_nPixelMiss_isLoaded = false;
  lep1_tightCharge_isLoaded = false;
  lep2_tightCharge_isLoaded = false;
  lep1_isTrigSafeNoIsov1_isLoaded = false;
  lep1_isTrigSafev1_isLoaded = false;
  lep2_isTrigSafeNoIsov1_isLoaded = false;
  lep2_isTrigSafev1_isLoaded = false;
  lep1_tightMuonPOG_isLoaded = false;
  lep1_mediumMuonPOG_isLoaded = false;
  lep1_looseMuonPOG_isLoaded = false;
  lep2_tightMuonPOG_isLoaded = false;
  lep2_mediumMuonPOG_isLoaded = false;
  lep2_looseMuonPOG_isLoaded = false;
  lep3_mediumMuonPOG_isLoaded = false;
  prefire_sf_isLoaded = false;
  prefire_sfup_isLoaded = false;
  prefire_sfdown_isLoaded = false;
  prefire2016_sf_isLoaded = false;
  prefire2016_sfup_isLoaded = false;
  prefire2016_sfdown_isLoaded = false;
  prefire2017_sf_isLoaded = false;
  prefire2017_sfup_isLoaded = false;
  prefire2017_sfdown_isLoaded = false;
  prefire2017ele_sf_isLoaded = false;
  prefire2017ele_sfup_isLoaded = false;
  prefire2017ele_sfdown_isLoaded = false;
  is_fastsim_isLoaded = false;
  lep1_isGoodLeg_isLoaded = false;
  lep2_isGoodLeg_isLoaded = false;
  lep1_isFakeLeg_isLoaded = false;
  lep2_isFakeLeg_isLoaded = false;
  lep1_multiIso_isLoaded = false;
  lep2_multiIso_isLoaded = false;
  lep1_sip_isLoaded = false;
  lep2_sip_isLoaded = false;
  lep1_closeJet_isLoaded = false;
  lep2_closeJet_isLoaded = false;
  passed_id_inSituFR_lep1_isLoaded = false;
  passed_id_inSituFR_lep2_isLoaded = false;
  fired_trigger_isLoaded = false;
  fired_trigger_ss_isLoaded = false;
  triggers_isLoaded = false;
  weight_btagsf_isLoaded = false;
  weight_btagsf_light_UP_isLoaded = false;
  weight_btagsf_light_DN_isLoaded = false;
  weight_btagsf_heavy_UP_isLoaded = false;
  weight_btagsf_heavy_DN_isLoaded = false;
  weight_btagsf_iter_central_isLoaded = false;
  weight_btagsf_iter_down_cferr1_isLoaded = false;
  weight_btagsf_iter_down_cferr2_isLoaded = false;
  weight_btagsf_iter_down_hf_isLoaded = false;
  weight_btagsf_iter_down_hfstats1_isLoaded = false;
  weight_btagsf_iter_down_hfstats2_isLoaded = false;
  weight_btagsf_iter_down_jes_isLoaded = false;
  weight_btagsf_iter_down_lf_isLoaded = false;
  weight_btagsf_iter_down_lfstats1_isLoaded = false;
  weight_btagsf_iter_down_lfstats2_isLoaded = false;
  weight_btagsf_iter_up_cferr1_isLoaded = false;
  weight_btagsf_iter_up_cferr2_isLoaded = false;
  weight_btagsf_iter_up_hf_isLoaded = false;
  weight_btagsf_iter_up_hfstats1_isLoaded = false;
  weight_btagsf_iter_up_hfstats2_isLoaded = false;
  weight_btagsf_iter_up_jes_isLoaded = false;
  weight_btagsf_iter_up_lf_isLoaded = false;
  weight_btagsf_iter_up_lfstats1_isLoaded = false;
  weight_btagsf_iter_up_lfstats2_isLoaded = false;
  weight_isLoaded = false;
  weight_lepsf1_isLoaded = false;
  weight_lepsf2_isLoaded = false;
  weight_lepsf3_isLoaded = false;
  weight_lepsf_isLoaded = false;
  weight_triggersf_isLoaded = false;
  weight_pu_isLoaded = false;
  weight_isrsf_isLoaded = false;
  year_isLoaded = false;
  yearlumi_isLoaded = false;
  weight_scale_UP_isLoaded = false;
  weight_scale_DN_isLoaded = false;
  weight_pdf_UP_isLoaded = false;
  weight_pdf_DN_isLoaded = false;
  weight_alphas_UP_isLoaded = false;
  weight_alphas_DN_isLoaded = false;
  weight_isrvar_UP_isLoaded = false;
  weight_isrvar_DN_isLoaded = false;
  weight_fsrvar_UP_isLoaded = false;
  weight_fsrvar_DN_isLoaded = false;
  gl1_p4_isLoaded = false;
  gl2_p4_isLoaded = false;
  glglpt_isLoaded = false;
  isr_unc_isLoaded = false;
  nisrMatch_isLoaded = false;
  weight_isr_isLoaded = false;
  weight_isr_dy_isLoaded = false;
  weight_isr_tt_isLoaded = false;
  weight_isr_UP_isLoaded = false;
  weight_isr_DN_isLoaded = false;
  lep3_el_etaSC_isLoaded = false;
  lep3_el_conv_vtx_flag_isLoaded = false;
  lep3_el_exp_innerlayers_isLoaded = false;
  lep3_el_threeChargeAgree_isLoaded = false;
  lep3_el_dxyPV_isLoaded = false;
  lep3_el_ip3d_isLoaded = false;
  lep3_el_dzPV_isLoaded = false;
  lep3_el_MVA_value_isLoaded = false;
  lep3_el_MVA_isLoaded = false;
  lep3_passes_RA5_isLoaded = false;
  lep3_mu_dxyPV_isLoaded = false;
  lep3_mu_ip3d_isLoaded = false;
  lep3_mu_dzPV_isLoaded = false;
  lep3_mu_ptErr_isLoaded = false;
  lep4_el_etaSC_isLoaded = false;
  lep4_el_conv_vtx_flag_isLoaded = false;
  lep4_el_exp_innerlayers_isLoaded = false;
  lep4_el_threeChargeAgree_isLoaded = false;
  lep4_el_dxyPV_isLoaded = false;
  lep4_el_ip3d_isLoaded = false;
  lep4_el_dzPV_isLoaded = false;
  lep4_el_MVA_value_isLoaded = false;
  lep4_el_MVA_isLoaded = false;
  lep4_mu_dxyPV_isLoaded = false;
  lep4_mu_ip3d_isLoaded = false;
  lep4_mu_dzPV_isLoaded = false;
  lep4_mu_ptErr_isLoaded = false;
  lep3_isTrigSafeNoIsov1_isLoaded = false;
  lep3_isTrigSafev1_isLoaded = false;
  lep4_isTrigSafeNoIsov1_isLoaded = false;
  lep4_isTrigSafev1_isLoaded = false;
  extragenb_isLoaded = false;
  extragenbmoms_isLoaded = false;
  extragenc_isLoaded = false;
  extragencmoms_isLoaded = false;
  ngenjets_isLoaded = false;
  genht_isLoaded = false;
  ngenjets30_isLoaded = false;
  genht30_isLoaded = false;
  passfilter_isLoaded = false;
  hasgammatoll_isLoaded = false;
  gammatollmomemu_isLoaded = false;
  gammatolldr_isLoaded = false;
  gammatoll1_isLoaded = false;
  gammatoll2_isLoaded = false;
  bjet_type_isLoaded = false;
  jet_type_isLoaded = false;
  jet_cat_isLoaded = false;
  jet_matchedGenIndex_isLoaded = false;
  jet_matchedGenId_isLoaded = false;
  jet_matchedGenMId_isLoaded = false;
  jet_matchedDr_isLoaded = false;
  jet_matchedPtDiff_isLoaded = false;
  ndrlt0p4_isLoaded = false;
  gengood_isLoaded = false;
  nleptonic_isLoaded = false;
  ntau_isLoaded = false;
  nleptonicW_isLoaded = false;
  mfourtop_isLoaded = false;
  nhadronicW_isLoaded = false;
  nW_isLoaded = false;
  leptonicWSF_isLoaded = false;
  hadronicWSF_isLoaded = false;
  decayWSF_isLoaded = false;
  njincone1_isLoaded = false;
  njincone2_isLoaded = false;
  bdt_nforwardjets20_isLoaded = false;
  bdt_avgcdisc_isLoaded = false;
  bdt_nbtags_isLoaded = false;
  bdt_njets_isLoaded = false;
  bdt_met_isLoaded = false;
  bdt_ptl2_isLoaded = false;
  bdt_nlb40_isLoaded = false;
  bdt_ntb40_isLoaded = false;
  bdt_nleps_isLoaded = false;
  bdt_htb_isLoaded = false;
  bdt_ml1j1_isLoaded = false;
  bdt_dphil1l2_isLoaded = false;
  bdt_maxmjoverpt_isLoaded = false;
  bdt_detal1l2_isLoaded = false;
  bdt_q1_isLoaded = false;
  bdt_ptj1_isLoaded = false;
  bdt_ptj6_isLoaded = false;
  bdt_ptj7_isLoaded = false;
  bdt_ptj8_isLoaded = false;
  bdt_ptl1_isLoaded = false;
  bdt_ptl3_isLoaded = false;
  bdt_jec_up_nbtags_isLoaded = false;
  bdt_jec_dn_nbtags_isLoaded = false;
  bdt_jer_up_nbtags_isLoaded = false;
  bdt_jer_dn_nbtags_isLoaded = false;
  bdt_jec_up_njets_isLoaded = false;
  bdt_jec_dn_njets_isLoaded = false;
  bdt_jer_up_njets_isLoaded = false;
  bdt_jer_dn_njets_isLoaded = false;
  bdt_jec_up_met_isLoaded = false;
  bdt_jec_dn_met_isLoaded = false;
  bdt_jer_up_met_isLoaded = false;
  bdt_jer_dn_met_isLoaded = false;
  bdt_jec_up_htb_isLoaded = false;
  bdt_jec_dn_htb_isLoaded = false;
  bdt_jer_up_htb_isLoaded = false;
  bdt_jer_dn_htb_isLoaded = false;
  bdt_jec_up_nlb40_isLoaded = false;
  bdt_jec_dn_nlb40_isLoaded = false;
  bdt_jer_up_nlb40_isLoaded = false;
  bdt_jer_dn_nlb40_isLoaded = false;
  bdt_jec_up_ntb40_isLoaded = false;
  bdt_jec_dn_ntb40_isLoaded = false;
  bdt_jer_up_ntb40_isLoaded = false;
  bdt_jer_dn_ntb40_isLoaded = false;
  bdt_disc_isLoaded = false;
  bdt_disc_jec_up_isLoaded = false;
  bdt_disc_jer_up_isLoaded = false;
  bdt_disc_jec_dn_isLoaded = false;
  bdt_disc_jer_dn_isLoaded = false;
  bdt_run2_disc_isLoaded = false;
  bdt_run2_SRDISC_isLoaded = false;
  bdt_run2_disc_jec_up_isLoaded = false;
  bdt_run2_disc_jer_up_isLoaded = false;
  bdt_run2_disc_jec_dn_isLoaded = false;
  bdt_run2_disc_jer_dn_isLoaded = false;
}

void SSAG::LoadAllBranches() {
  // load all branches
  if (lep1_isPrompt_branch != 0) lep1_isPrompt();
  if (lep1_isDirectPrompt_branch != 0) lep1_isDirectPrompt();
  if (lep1_isStat3_branch != 0) lep1_isStat3();
  if (lep2_isPrompt_branch != 0) lep2_isPrompt();
  if (lep2_isDirectPrompt_branch != 0) lep2_isDirectPrompt();
  if (lep2_isStat3_branch != 0) lep2_isStat3();
  if (met_branch != 0) met();
  if (metPhi_branch != 0) metPhi();
  if (rawmet_branch != 0) rawmet();
  if (rawmetPhi_branch != 0) rawmetPhi();
  if (calomet_branch != 0) calomet();
  if (calometPhi_branch != 0) calometPhi();
  if (event_branch != 0) event();
  if (lumi_branch != 0) lumi();
  if (run_branch != 0) run();
  if (filt_csc_branch != 0) filt_csc();
  if (filt_hbhe_branch != 0) filt_hbhe();
  if (filt_hcallaser_branch != 0) filt_hcallaser();
  if (filt_ecaltp_branch != 0) filt_ecaltp();
  if (filt_trkfail_branch != 0) filt_trkfail();
  if (is_real_data_branch != 0) is_real_data();
  if (scale1fb_branch != 0) scale1fb();
  if (genps_weight_branch != 0) genps_weight();
  if (xsec_branch != 0) xsec();
  if (neventstotal_branch != 0) neventstotal();
  if (xsec_ps_branch != 0) xsec_ps();
  if (sparmNames_branch != 0) sparmNames();
  if (sparms_branch != 0) sparms();
  if (xsec_error_branch != 0) xsec_error();
  if (kfactor_branch != 0) kfactor();
  if (gen_met_branch != 0) gen_met();
  if (pdfweights_branch != 0) pdfweights();
  if (gen_met_phi_branch != 0) gen_met_phi();
  if (skim_branch != 0) skim();
  if (skim_nomet_branch != 0) skim_nomet();
  if (nleps_branch != 0) nleps();
  if (sr_branch != 0) sr();
  if (br_branch != 0) br();
  if (ss_nleps_branch != 0) ss_nleps();
  if (ss_br_branch != 0) ss_br();
  if (ss_sr_branch != 0) ss_sr();
  if (ss_region_branch != 0) ss_region();
  if (njets_branch != 0) njets();
  if (njetsAG_branch != 0) njetsAG();
  if (nbtagsAG_branch != 0) nbtagsAG();
  if (njets_raw_branch != 0) njets_raw();
  if (hyp_class_branch != 0) hyp_class();
  if (lep1_p4_branch != 0) lep1_p4();
  if (lep2_p4_branch != 0) lep2_p4();
  if (lep1_pt_branch != 0) lep1_pt();
  if (lep2_pt_branch != 0) lep2_pt();
  if (lep3_pt_branch != 0) lep3_pt();
  if (lep1_eta_branch != 0) lep1_eta();
  if (lep2_eta_branch != 0) lep2_eta();
  if (lep3_eta_branch != 0) lep3_eta();
  if (lep1_phi_branch != 0) lep1_phi();
  if (lep2_phi_branch != 0) lep2_phi();
  if (lep3_phi_branch != 0) lep3_phi();
  if (ht_raw_branch != 0) ht_raw();
  if (ht_branch != 0) ht();
  if (lep1_motherID_branch != 0) lep1_motherID();
  if (lep2_motherID_branch != 0) lep2_motherID();
  if (lep1_mc_id_branch != 0) lep1_mc_id();
  if (lep2_mc_id_branch != 0) lep2_mc_id();
  if (lep1_mc_motherid_branch != 0) lep1_mc_motherid();
  if (lep2_mc_motherid_branch != 0) lep2_mc_motherid();
  if (lep1_id_branch != 0) lep1_id();
  if (lep2_id_branch != 0) lep2_id();
  if (lep1_coneCorrPt_branch != 0) lep1_coneCorrPt();
  if (lep2_coneCorrPt_branch != 0) lep2_coneCorrPt();
  if (lep3_coneCorrPt_branch != 0) lep3_coneCorrPt();
  if (lep4_coneCorrPt_branch != 0) lep4_coneCorrPt();
  if (lep1_idx_branch != 0) lep1_idx();
  if (lep2_idx_branch != 0) lep2_idx();
  if (jets_branch != 0) jets();
  if (jets_jec_up_branch != 0) jets_jec_up();
  if (jets_jec_dn_branch != 0) jets_jec_dn();
  if (jets_disc_up_branch != 0) jets_disc_up();
  if (jets_disc_dn_branch != 0) jets_disc_dn();
  if (bjets_jec_up_branch != 0) bjets_jec_up();
  if (bjets_jec_dn_branch != 0) bjets_jec_dn();
  if (btags_flavor_branch != 0) btags_flavor();
  if (btags_disc_branch != 0) btags_disc();
  if (btags_cdisc_branch != 0) btags_cdisc();
  if (jets_flavor_branch != 0) jets_flavor();
  if (jets_disc_branch != 0) jets_disc();
  if (jets_bsf_branch != 0) jets_bsf();
  if (jets_JEC_branch != 0) jets_JEC();
  if (btags_JEC_branch != 0) btags_JEC();
  if (jets_undoJEC_branch != 0) jets_undoJEC();
  if (btags_undoJEC_branch != 0) btags_undoJEC();
  if (btags_unc_branch != 0) btags_unc();
  if (btags_eff_branch != 0) btags_eff();
  if (btags_effpt_branch != 0) btags_effpt();
  if (btags_sf_branch != 0) btags_sf();
  if (jets_unc_branch != 0) jets_unc();
  if (btags_branch != 0) btags();
  if (nbtags_branch != 0) nbtags();
  if (nbtags_raw_branch != 0) nbtags_raw();
  if (sf_dilepTrig_hpt_branch != 0) sf_dilepTrig_hpt();
  if (sf_dilepTrig_lpt_branch != 0) sf_dilepTrig_lpt();
  if (sf_dilepTrig_vlpt_branch != 0) sf_dilepTrig_vlpt();
  if (hyp_type_branch != 0) hyp_type();
  if (sf_dilep_eff_branch != 0) sf_dilep_eff();
  if (mt_branch != 0) mt();
  if (mt_l2_branch != 0) mt_l2();
  if (mt2_branch != 0) mt2();
  if (mtmin_branch != 0) mtmin();
  if (lep1_id_gen_branch != 0) lep1_id_gen();
  if (lep2_id_gen_branch != 0) lep2_id_gen();
  if (lep1_p4_gen_branch != 0) lep1_p4_gen();
  if (lep2_p4_gen_branch != 0) lep2_p4_gen();
  if (lep3_id_branch != 0) lep3_id();
  if (lep3_idx_branch != 0) lep3_idx();
  if (lep3_p4_branch != 0) lep3_p4();
  if (lep3_quality_branch != 0) lep3_quality();
  if (lep4_id_branch != 0) lep4_id();
  if (lep4_idx_branch != 0) lep4_idx();
  if (lep4_p4_branch != 0) lep4_p4();
  if (lep1_iso_branch != 0) lep1_iso();
  if (lep2_iso_branch != 0) lep2_iso();
  if (dilep_p4_branch != 0) dilep_p4();
  if (dilep_mass_branch != 0) dilep_mass();
  if (mass13_branch != 0) mass13();
  if (mass23_branch != 0) mass23();
  if (mass123_branch != 0) mass123();
  if (ncharginos_branch != 0) ncharginos();
  if (nhiggs_branch != 0) nhiggs();
  if (higgs_mass_branch != 0) higgs_mass();
  if (genps_p4_branch != 0) genps_p4();
  if (genjets_p4_branch != 0) genjets_p4();
  if (genps_id_branch != 0) genps_id();
  if (genps_id_mother_branch != 0) genps_id_mother();
  if (genps_idx_mother_branch != 0) genps_idx_mother();
  if (genps_status_branch != 0) genps_status();
  if (genps_id_grandma_branch != 0) genps_id_grandma();
  if (all_leps_p4_branch != 0) all_leps_p4();
  if (all_leps_id_branch != 0) all_leps_id();
  if (all_leps_veto_branch != 0) all_leps_veto();
  if (all_leps_mc3idx_branch != 0) all_leps_mc3idx();
  if (lep1_passes_id_branch != 0) lep1_passes_id();
  if (lep2_passes_id_branch != 0) lep2_passes_id();
  if (lep3_passes_id_branch != 0) lep3_passes_id();
  if (lep4_passes_id_branch != 0) lep4_passes_id();
  if (lep1_tight_branch != 0) lep1_tight();
  if (lep1_veto_branch != 0) lep1_veto();
  if (lep1_fo_branch != 0) lep1_fo();
  if (lep2_tight_branch != 0) lep2_tight();
  if (lep2_veto_branch != 0) lep2_veto();
  if (lep2_fo_branch != 0) lep2_fo();
  if (lep3_tight_branch != 0) lep3_tight();
  if (lep3_veto_branch != 0) lep3_veto();
  if (lep3_fo_branch != 0) lep3_fo();
  if (lep4_tight_branch != 0) lep4_tight();
  if (lep4_veto_branch != 0) lep4_veto();
  if (lep4_fo_branch != 0) lep4_fo();
  if (lep1_dxyPV_branch != 0) lep1_dxyPV();
  if (lep2_dxyPV_branch != 0) lep2_dxyPV();
  if (lep1_dZ_branch != 0) lep1_dZ();
  if (lep2_dZ_branch != 0) lep2_dZ();
  if (lep1_d0_err_branch != 0) lep1_d0_err();
  if (lep2_d0_err_branch != 0) lep2_d0_err();
  if (lep1_ip3d_branch != 0) lep1_ip3d();
  if (lep2_ip3d_branch != 0) lep2_ip3d();
  if (lep1_MVA_branch != 0) lep1_MVA();
  if (lep2_MVA_branch != 0) lep2_MVA();
  if (lep1_ip3d_err_branch != 0) lep1_ip3d_err();
  if (lep2_ip3d_err_branch != 0) lep2_ip3d_err();
  if (nVetoElectrons7_branch != 0) nVetoElectrons7();
  if (nVetoElectrons10_branch != 0) nVetoElectrons10();
  if (nVetoElectrons25_branch != 0) nVetoElectrons25();
  if (nVetoMuons5_branch != 0) nVetoMuons5();
  if (nVetoMuons10_branch != 0) nVetoMuons10();
  if (nVetoMuons25_branch != 0) nVetoMuons25();
  if (filename_branch != 0) filename();
  if (lep1_ptrel_ma_branch != 0) lep1_ptrel_ma();
  if (lep1_ptratio_ma_branch != 0) lep1_ptratio_ma();
  if (lep2_ptrel_ma_branch != 0) lep2_ptrel_ma();
  if (lep2_ptratio_ma_branch != 0) lep2_ptratio_ma();
  if (lep1_ptrel_v1_branch != 0) lep1_ptrel_v1();
  if (lep2_ptrel_v1_branch != 0) lep2_ptrel_v1();
  if (lep1_ptratio_branch != 0) lep1_ptratio();
  if (lep2_ptratio_branch != 0) lep2_ptratio();
  if (lep1_miniIso_branch != 0) lep1_miniIso();
  if (lep2_miniIso_branch != 0) lep2_miniIso();
  if (trueNumInt_branch != 0) trueNumInt();
  if (nGoodVertices_branch != 0) nGoodVertices();
  if (lep1_trigMatch_noIsoReq_branch != 0) lep1_trigMatch_noIsoReq();
  if (lep1_trigMatch_isoReq_branch != 0) lep1_trigMatch_isoReq();
  if (lep2_trigMatch_noIsoReq_branch != 0) lep2_trigMatch_noIsoReq();
  if (lep2_trigMatch_isoReq_branch != 0) lep2_trigMatch_isoReq();
  if (passes_met_filters_branch != 0) passes_met_filters();
  if (passes_chargedcand_filter_branch != 0) passes_chargedcand_filter();
  if (evt_egclean_pfmet_branch != 0) evt_egclean_pfmet();
  if (evt_muegclean_pfmet_branch != 0) evt_muegclean_pfmet();
  if (evt_muegcleanfix_pfmet_branch != 0) evt_muegcleanfix_pfmet();
  if (evt_uncorr_pfmet_branch != 0) evt_uncorr_pfmet();
  if (filt_noBadMuons_branch != 0) filt_noBadMuons();
  if (filt_duplicateMuons_branch != 0) filt_duplicateMuons();
  if (filt_badMuons_branch != 0) filt_badMuons();
  if (failsRA2Filter_branch != 0) failsRA2Filter();
  if (madeExtraZ_branch != 0) madeExtraZ();
  if (madeExtraG_branch != 0) madeExtraG();
  if (lep3_mcid_branch != 0) lep3_mcid();
  if (lep3_mc_motherid_branch != 0) lep3_mc_motherid();
  if (lep3_mc3idx_branch != 0) lep3_mc3idx();
  if (lep3_motherID_branch != 0) lep3_motherID();
  if (lep4_mcid_branch != 0) lep4_mcid();
  if (lep4_mcidx_branch != 0) lep4_mcidx();
  if (njets_unc_up_branch != 0) njets_unc_up();
  if (njets_unc_dn_branch != 0) njets_unc_dn();
  if (ht_unc_up_branch != 0) ht_unc_up();
  if (ht_unc_dn_branch != 0) ht_unc_dn();
  if (nbtags_unc_up_branch != 0) nbtags_unc_up();
  if (nbtags_unc_dn_branch != 0) nbtags_unc_dn();
  if (met_unc_up_branch != 0) met_unc_up();
  if (met_unc_dn_branch != 0) met_unc_dn();
  if (metPhi_unc_up_branch != 0) metPhi_unc_up();
  if (metPhi_unc_dn_branch != 0) metPhi_unc_dn();
  if (njets_JER_up_branch != 0) njets_JER_up();
  if (njets_JER_dn_branch != 0) njets_JER_dn();
  if (ht_JER_up_branch != 0) ht_JER_up();
  if (ht_JER_dn_branch != 0) ht_JER_dn();
  if (nbtags_JER_up_branch != 0) nbtags_JER_up();
  if (nbtags_JER_dn_branch != 0) nbtags_JER_dn();
  if (met_JER_up_branch != 0) met_JER_up();
  if (met_JER_dn_branch != 0) met_JER_dn();
  if (metPhi_JER_up_branch != 0) metPhi_JER_up();
  if (metPhi_JER_dn_branch != 0) metPhi_JER_dn();
  if (lep2_genps_isHardProcess_branch != 0) lep2_genps_isHardProcess();
  if (lep2_genps_fromHardProcessFinalState_branch != 0) lep2_genps_fromHardProcessFinalState();
  if (lep2_genps_fromHardProcessDecayed_branch != 0) lep2_genps_fromHardProcessDecayed();
  if (lep2_genps_isDirectHardProcessTauDecayProductFinalState_branch != 0) lep2_genps_isDirectHardProcessTauDecayProductFinalState();
  if (lep2_genps_fromHardProcessBeforeFSR_branch != 0) lep2_genps_fromHardProcessBeforeFSR();
  if (lep2_genps_isLastCopy_branch != 0) lep2_genps_isLastCopy();
  if (lep2_genps_isLastCopyBeforeFSR_branch != 0) lep2_genps_isLastCopyBeforeFSR();
  if (lep1_genps_isHardProcess_branch != 0) lep1_genps_isHardProcess();
  if (lep1_genps_fromHardProcessFinalState_branch != 0) lep1_genps_fromHardProcessFinalState();
  if (lep1_genps_fromHardProcessDecayed_branch != 0) lep1_genps_fromHardProcessDecayed();
  if (lep1_genps_isDirectHardProcessTauDecayProductFinalState_branch != 0) lep1_genps_isDirectHardProcessTauDecayProductFinalState();
  if (lep1_genps_fromHardProcessBeforeFSR_branch != 0) lep1_genps_fromHardProcessBeforeFSR();
  if (lep1_genps_isLastCopy_branch != 0) lep1_genps_isLastCopy();
  if (lep1_genps_isLastCopyBeforeFSR_branch != 0) lep1_genps_isLastCopyBeforeFSR();
  if (lep1_mc3idx_branch != 0) lep1_mc3idx();
  if (lep2_mc3idx_branch != 0) lep2_mc3idx();
  if (lep1_el_conv_vtx_flag_branch != 0) lep1_el_conv_vtx_flag();
  if (lep2_el_conv_vtx_flag_branch != 0) lep2_el_conv_vtx_flag();
  if (lep1_el_exp_innerlayers_branch != 0) lep1_el_exp_innerlayers();
  if (lep1_mu_ptErr_branch != 0) lep1_mu_ptErr();
  if (lep2_mu_ptErr_branch != 0) lep2_mu_ptErr();
  if (lep1_el_threeChargeAgree_branch != 0) lep1_el_threeChargeAgree();
  if (lep2_el_threeChargeAgree_branch != 0) lep2_el_threeChargeAgree();
  if (lep2_el_exp_innerlayers_branch != 0) lep2_el_exp_innerlayers();
  if (lep1_el_etaSC_branch != 0) lep1_el_etaSC();
  if (lep2_el_etaSC_branch != 0) lep2_el_etaSC();
  if (lep1_nPixelMiss_branch != 0) lep1_nPixelMiss();
  if (lep2_nPixelMiss_branch != 0) lep2_nPixelMiss();
  if (lep1_tightCharge_branch != 0) lep1_tightCharge();
  if (lep2_tightCharge_branch != 0) lep2_tightCharge();
  if (lep1_isTrigSafeNoIsov1_branch != 0) lep1_isTrigSafeNoIsov1();
  if (lep1_isTrigSafev1_branch != 0) lep1_isTrigSafev1();
  if (lep2_isTrigSafeNoIsov1_branch != 0) lep2_isTrigSafeNoIsov1();
  if (lep2_isTrigSafev1_branch != 0) lep2_isTrigSafev1();
  if (lep1_tightMuonPOG_branch != 0) lep1_tightMuonPOG();
  if (lep1_mediumMuonPOG_branch != 0) lep1_mediumMuonPOG();
  if (lep1_looseMuonPOG_branch != 0) lep1_looseMuonPOG();
  if (lep2_tightMuonPOG_branch != 0) lep2_tightMuonPOG();
  if (lep2_mediumMuonPOG_branch != 0) lep2_mediumMuonPOG();
  if (lep2_looseMuonPOG_branch != 0) lep2_looseMuonPOG();
  if (lep3_mediumMuonPOG_branch != 0) lep3_mediumMuonPOG();
  if (prefire_sf_branch != 0) prefire_sf();
  if (prefire_sfup_branch != 0) prefire_sfup();
  if (prefire_sfdown_branch != 0) prefire_sfdown();
  if (prefire2016_sf_branch != 0) prefire2016_sf();
  if (prefire2016_sfup_branch != 0) prefire2016_sfup();
  if (prefire2016_sfdown_branch != 0) prefire2016_sfdown();
  if (prefire2017_sf_branch != 0) prefire2017_sf();
  if (prefire2017_sfup_branch != 0) prefire2017_sfup();
  if (prefire2017_sfdown_branch != 0) prefire2017_sfdown();
  if (prefire2017ele_sf_branch != 0) prefire2017ele_sf();
  if (prefire2017ele_sfup_branch != 0) prefire2017ele_sfup();
  if (prefire2017ele_sfdown_branch != 0) prefire2017ele_sfdown();
  if (is_fastsim_branch != 0) is_fastsim();
  if (lep1_isGoodLeg_branch != 0) lep1_isGoodLeg();
  if (lep2_isGoodLeg_branch != 0) lep2_isGoodLeg();
  if (lep1_isFakeLeg_branch != 0) lep1_isFakeLeg();
  if (lep2_isFakeLeg_branch != 0) lep2_isFakeLeg();
  if (lep1_multiIso_branch != 0) lep1_multiIso();
  if (lep2_multiIso_branch != 0) lep2_multiIso();
  if (lep1_sip_branch != 0) lep1_sip();
  if (lep2_sip_branch != 0) lep2_sip();
  if (lep1_closeJet_branch != 0) lep1_closeJet();
  if (lep2_closeJet_branch != 0) lep2_closeJet();
  if (passed_id_inSituFR_lep1_branch != 0) passed_id_inSituFR_lep1();
  if (passed_id_inSituFR_lep2_branch != 0) passed_id_inSituFR_lep2();
  if (fired_trigger_branch != 0) fired_trigger();
  if (fired_trigger_ss_branch != 0) fired_trigger_ss();
  if (triggers_branch != 0) triggers();
  if (weight_btagsf_branch != 0) weight_btagsf();
  if (weight_btagsf_light_UP_branch != 0) weight_btagsf_light_UP();
  if (weight_btagsf_light_DN_branch != 0) weight_btagsf_light_DN();
  if (weight_btagsf_heavy_UP_branch != 0) weight_btagsf_heavy_UP();
  if (weight_btagsf_heavy_DN_branch != 0) weight_btagsf_heavy_DN();
  if (weight_btagsf_iter_central_branch != 0) weight_btagsf_iter_central();
  if (weight_btagsf_iter_down_cferr1_branch != 0) weight_btagsf_iter_down_cferr1();
  if (weight_btagsf_iter_down_cferr2_branch != 0) weight_btagsf_iter_down_cferr2();
  if (weight_btagsf_iter_down_hf_branch != 0) weight_btagsf_iter_down_hf();
  if (weight_btagsf_iter_down_hfstats1_branch != 0) weight_btagsf_iter_down_hfstats1();
  if (weight_btagsf_iter_down_hfstats2_branch != 0) weight_btagsf_iter_down_hfstats2();
  if (weight_btagsf_iter_down_jes_branch != 0) weight_btagsf_iter_down_jes();
  if (weight_btagsf_iter_down_lf_branch != 0) weight_btagsf_iter_down_lf();
  if (weight_btagsf_iter_down_lfstats1_branch != 0) weight_btagsf_iter_down_lfstats1();
  if (weight_btagsf_iter_down_lfstats2_branch != 0) weight_btagsf_iter_down_lfstats2();
  if (weight_btagsf_iter_up_cferr1_branch != 0) weight_btagsf_iter_up_cferr1();
  if (weight_btagsf_iter_up_cferr2_branch != 0) weight_btagsf_iter_up_cferr2();
  if (weight_btagsf_iter_up_hf_branch != 0) weight_btagsf_iter_up_hf();
  if (weight_btagsf_iter_up_hfstats1_branch != 0) weight_btagsf_iter_up_hfstats1();
  if (weight_btagsf_iter_up_hfstats2_branch != 0) weight_btagsf_iter_up_hfstats2();
  if (weight_btagsf_iter_up_jes_branch != 0) weight_btagsf_iter_up_jes();
  if (weight_btagsf_iter_up_lf_branch != 0) weight_btagsf_iter_up_lf();
  if (weight_btagsf_iter_up_lfstats1_branch != 0) weight_btagsf_iter_up_lfstats1();
  if (weight_btagsf_iter_up_lfstats2_branch != 0) weight_btagsf_iter_up_lfstats2();
  if (weight_branch != 0) weight();
  if (weight_lepsf1_branch != 0) weight_lepsf1();
  if (weight_lepsf2_branch != 0) weight_lepsf2();
  if (weight_lepsf3_branch != 0) weight_lepsf3();
  if (weight_lepsf_branch != 0) weight_lepsf();
  if (weight_triggersf_branch != 0) weight_triggersf();
  if (weight_pu_branch != 0) weight_pu();
  if (weight_isrsf_branch != 0) weight_isrsf();
  if (year_branch != 0) year();
  if (yearlumi_branch != 0) yearlumi();
  if (weight_scale_UP_branch != 0) weight_scale_UP();
  if (weight_scale_DN_branch != 0) weight_scale_DN();
  if (weight_pdf_UP_branch != 0) weight_pdf_UP();
  if (weight_pdf_DN_branch != 0) weight_pdf_DN();
  if (weight_alphas_UP_branch != 0) weight_alphas_UP();
  if (weight_alphas_DN_branch != 0) weight_alphas_DN();
  if (weight_isrvar_UP_branch != 0) weight_isrvar_UP();
  if (weight_isrvar_DN_branch != 0) weight_isrvar_DN();
  if (weight_fsrvar_UP_branch != 0) weight_fsrvar_UP();
  if (weight_fsrvar_DN_branch != 0) weight_fsrvar_DN();
  if (gl1_p4_branch != 0) gl1_p4();
  if (gl2_p4_branch != 0) gl2_p4();
  if (glglpt_branch != 0) glglpt();
  if (isr_unc_branch != 0) isr_unc();
  if (nisrMatch_branch != 0) nisrMatch();
  if (weight_isr_branch != 0) weight_isr();
  if (weight_isr_dy_branch != 0) weight_isr_dy();
  if (weight_isr_tt_branch != 0) weight_isr_tt();
  if (weight_isr_UP_branch != 0) weight_isr_UP();
  if (weight_isr_DN_branch != 0) weight_isr_DN();
  if (lep3_el_etaSC_branch != 0) lep3_el_etaSC();
  if (lep3_el_conv_vtx_flag_branch != 0) lep3_el_conv_vtx_flag();
  if (lep3_el_exp_innerlayers_branch != 0) lep3_el_exp_innerlayers();
  if (lep3_el_threeChargeAgree_branch != 0) lep3_el_threeChargeAgree();
  if (lep3_el_dxyPV_branch != 0) lep3_el_dxyPV();
  if (lep3_el_ip3d_branch != 0) lep3_el_ip3d();
  if (lep3_el_dzPV_branch != 0) lep3_el_dzPV();
  if (lep3_el_MVA_value_branch != 0) lep3_el_MVA_value();
  if (lep3_el_MVA_branch != 0) lep3_el_MVA();
  if (lep3_passes_RA5_branch != 0) lep3_passes_RA5();
  if (lep3_mu_dxyPV_branch != 0) lep3_mu_dxyPV();
  if (lep3_mu_ip3d_branch != 0) lep3_mu_ip3d();
  if (lep3_mu_dzPV_branch != 0) lep3_mu_dzPV();
  if (lep3_mu_ptErr_branch != 0) lep3_mu_ptErr();
  if (lep4_el_etaSC_branch != 0) lep4_el_etaSC();
  if (lep4_el_conv_vtx_flag_branch != 0) lep4_el_conv_vtx_flag();
  if (lep4_el_exp_innerlayers_branch != 0) lep4_el_exp_innerlayers();
  if (lep4_el_threeChargeAgree_branch != 0) lep4_el_threeChargeAgree();
  if (lep4_el_dxyPV_branch != 0) lep4_el_dxyPV();
  if (lep4_el_ip3d_branch != 0) lep4_el_ip3d();
  if (lep4_el_dzPV_branch != 0) lep4_el_dzPV();
  if (lep4_el_MVA_value_branch != 0) lep4_el_MVA_value();
  if (lep4_el_MVA_branch != 0) lep4_el_MVA();
  if (lep4_mu_dxyPV_branch != 0) lep4_mu_dxyPV();
  if (lep4_mu_ip3d_branch != 0) lep4_mu_ip3d();
  if (lep4_mu_dzPV_branch != 0) lep4_mu_dzPV();
  if (lep4_mu_ptErr_branch != 0) lep4_mu_ptErr();
  if (lep3_isTrigSafeNoIsov1_branch != 0) lep3_isTrigSafeNoIsov1();
  if (lep3_isTrigSafev1_branch != 0) lep3_isTrigSafev1();
  if (lep4_isTrigSafeNoIsov1_branch != 0) lep4_isTrigSafeNoIsov1();
  if (lep4_isTrigSafev1_branch != 0) lep4_isTrigSafev1();
  if (extragenb_branch != 0) extragenb();
  if (extragenbmoms_branch != 0) extragenbmoms();
  if (extragenc_branch != 0) extragenc();
  if (extragencmoms_branch != 0) extragencmoms();
  if (ngenjets_branch != 0) ngenjets();
  if (genht_branch != 0) genht();
  if (ngenjets30_branch != 0) ngenjets30();
  if (genht30_branch != 0) genht30();
  if (passfilter_branch != 0) passfilter();
  if (hasgammatoll_branch != 0) hasgammatoll();
  if (gammatollmomemu_branch != 0) gammatollmomemu();
  if (gammatolldr_branch != 0) gammatolldr();
  if (gammatoll1_branch != 0) gammatoll1();
  if (gammatoll2_branch != 0) gammatoll2();
  if (bjet_type_branch != 0) bjet_type();
  if (jet_type_branch != 0) jet_type();
  if (jet_cat_branch != 0) jet_cat();
  if (jet_matchedGenIndex_branch != 0) jet_matchedGenIndex();
  if (jet_matchedGenId_branch != 0) jet_matchedGenId();
  if (jet_matchedGenMId_branch != 0) jet_matchedGenMId();
  if (jet_matchedDr_branch != 0) jet_matchedDr();
  if (jet_matchedPtDiff_branch != 0) jet_matchedPtDiff();
  if (ndrlt0p4_branch != 0) ndrlt0p4();
  if (gengood_branch != 0) gengood();
  if (nleptonic_branch != 0) nleptonic();
  if (ntau_branch != 0) ntau();
  if (nleptonicW_branch != 0) nleptonicW();
  if (mfourtop_branch != 0) mfourtop();
  if (nhadronicW_branch != 0) nhadronicW();
  if (nW_branch != 0) nW();
  if (leptonicWSF_branch != 0) leptonicWSF();
  if (hadronicWSF_branch != 0) hadronicWSF();
  if (decayWSF_branch != 0) decayWSF();
  if (njincone1_branch != 0) njincone1();
  if (njincone2_branch != 0) njincone2();
  if (bdt_nforwardjets20_branch != 0) bdt_nforwardjets20();
  if (bdt_avgcdisc_branch != 0) bdt_avgcdisc();
  if (bdt_nbtags_branch != 0) bdt_nbtags();
  if (bdt_njets_branch != 0) bdt_njets();
  if (bdt_met_branch != 0) bdt_met();
  if (bdt_ptl2_branch != 0) bdt_ptl2();
  if (bdt_nlb40_branch != 0) bdt_nlb40();
  if (bdt_ntb40_branch != 0) bdt_ntb40();
  if (bdt_nleps_branch != 0) bdt_nleps();
  if (bdt_htb_branch != 0) bdt_htb();
  if (bdt_ml1j1_branch != 0) bdt_ml1j1();
  if (bdt_dphil1l2_branch != 0) bdt_dphil1l2();
  if (bdt_maxmjoverpt_branch != 0) bdt_maxmjoverpt();
  if (bdt_detal1l2_branch != 0) bdt_detal1l2();
  if (bdt_q1_branch != 0) bdt_q1();
  if (bdt_ptj1_branch != 0) bdt_ptj1();
  if (bdt_ptj6_branch != 0) bdt_ptj6();
  if (bdt_ptj7_branch != 0) bdt_ptj7();
  if (bdt_ptj8_branch != 0) bdt_ptj8();
  if (bdt_ptl1_branch != 0) bdt_ptl1();
  if (bdt_ptl3_branch != 0) bdt_ptl3();
  if (bdt_jec_up_nbtags_branch != 0) bdt_jec_up_nbtags();
  if (bdt_jec_dn_nbtags_branch != 0) bdt_jec_dn_nbtags();
  if (bdt_jer_up_nbtags_branch != 0) bdt_jer_up_nbtags();
  if (bdt_jer_dn_nbtags_branch != 0) bdt_jer_dn_nbtags();
  if (bdt_jec_up_njets_branch != 0) bdt_jec_up_njets();
  if (bdt_jec_dn_njets_branch != 0) bdt_jec_dn_njets();
  if (bdt_jer_up_njets_branch != 0) bdt_jer_up_njets();
  if (bdt_jer_dn_njets_branch != 0) bdt_jer_dn_njets();
  if (bdt_jec_up_met_branch != 0) bdt_jec_up_met();
  if (bdt_jec_dn_met_branch != 0) bdt_jec_dn_met();
  if (bdt_jer_up_met_branch != 0) bdt_jer_up_met();
  if (bdt_jer_dn_met_branch != 0) bdt_jer_dn_met();
  if (bdt_jec_up_htb_branch != 0) bdt_jec_up_htb();
  if (bdt_jec_dn_htb_branch != 0) bdt_jec_dn_htb();
  if (bdt_jer_up_htb_branch != 0) bdt_jer_up_htb();
  if (bdt_jer_dn_htb_branch != 0) bdt_jer_dn_htb();
  if (bdt_jec_up_nlb40_branch != 0) bdt_jec_up_nlb40();
  if (bdt_jec_dn_nlb40_branch != 0) bdt_jec_dn_nlb40();
  if (bdt_jer_up_nlb40_branch != 0) bdt_jer_up_nlb40();
  if (bdt_jer_dn_nlb40_branch != 0) bdt_jer_dn_nlb40();
  if (bdt_jec_up_ntb40_branch != 0) bdt_jec_up_ntb40();
  if (bdt_jec_dn_ntb40_branch != 0) bdt_jec_dn_ntb40();
  if (bdt_jer_up_ntb40_branch != 0) bdt_jer_up_ntb40();
  if (bdt_jer_dn_ntb40_branch != 0) bdt_jer_dn_ntb40();
  if (bdt_disc_branch != 0) bdt_disc();
  if (bdt_disc_jec_up_branch != 0) bdt_disc_jec_up();
  if (bdt_disc_jer_up_branch != 0) bdt_disc_jer_up();
  if (bdt_disc_jec_dn_branch != 0) bdt_disc_jec_dn();
  if (bdt_disc_jer_dn_branch != 0) bdt_disc_jer_dn();
  if (bdt_run2_disc_branch != 0) bdt_run2_disc();
  if (bdt_run2_SRDISC_branch != 0) bdt_run2_SRDISC();
  if (bdt_run2_disc_jec_up_branch != 0) bdt_run2_disc_jec_up();
  if (bdt_run2_disc_jer_up_branch != 0) bdt_run2_disc_jer_up();
  if (bdt_run2_disc_jec_dn_branch != 0) bdt_run2_disc_jec_dn();
  if (bdt_run2_disc_jer_dn_branch != 0) bdt_run2_disc_jer_dn();
}

const bool &SSAG::lep1_isPrompt() {
  if (not lep1_isPrompt_isLoaded) {
    if (lep1_isPrompt_branch != 0) {
      lep1_isPrompt_branch->GetEntry(index);
    } else {
      printf("branch lep1_isPrompt_branch does not exist!\n");
      exit(1);
    }
    lep1_isPrompt_isLoaded = true;
  }
  return lep1_isPrompt_;
}

const bool &SSAG::lep1_isDirectPrompt() {
  if (not lep1_isDirectPrompt_isLoaded) {
    if (lep1_isDirectPrompt_branch != 0) {
      lep1_isDirectPrompt_branch->GetEntry(index);
    } else {
      printf("branch lep1_isDirectPrompt_branch does not exist!\n");
      exit(1);
    }
    lep1_isDirectPrompt_isLoaded = true;
  }
  return lep1_isDirectPrompt_;
}

const bool &SSAG::lep1_isStat3() {
  if (not lep1_isStat3_isLoaded) {
    if (lep1_isStat3_branch != 0) {
      lep1_isStat3_branch->GetEntry(index);
    } else {
      printf("branch lep1_isStat3_branch does not exist!\n");
      exit(1);
    }
    lep1_isStat3_isLoaded = true;
  }
  return lep1_isStat3_;
}

const bool &SSAG::lep2_isPrompt() {
  if (not lep2_isPrompt_isLoaded) {
    if (lep2_isPrompt_branch != 0) {
      lep2_isPrompt_branch->GetEntry(index);
    } else {
      printf("branch lep2_isPrompt_branch does not exist!\n");
      exit(1);
    }
    lep2_isPrompt_isLoaded = true;
  }
  return lep2_isPrompt_;
}

const bool &SSAG::lep2_isDirectPrompt() {
  if (not lep2_isDirectPrompt_isLoaded) {
    if (lep2_isDirectPrompt_branch != 0) {
      lep2_isDirectPrompt_branch->GetEntry(index);
    } else {
      printf("branch lep2_isDirectPrompt_branch does not exist!\n");
      exit(1);
    }
    lep2_isDirectPrompt_isLoaded = true;
  }
  return lep2_isDirectPrompt_;
}

const bool &SSAG::lep2_isStat3() {
  if (not lep2_isStat3_isLoaded) {
    if (lep2_isStat3_branch != 0) {
      lep2_isStat3_branch->GetEntry(index);
    } else {
      printf("branch lep2_isStat3_branch does not exist!\n");
      exit(1);
    }
    lep2_isStat3_isLoaded = true;
  }
  return lep2_isStat3_;
}

const float &SSAG::met() {
  if (not met_isLoaded) {
    if (met_branch != 0) {
      met_branch->GetEntry(index);
    } else {
      printf("branch met_branch does not exist!\n");
      exit(1);
    }
    met_isLoaded = true;
  }
  return met_;
}

const float &SSAG::metPhi() {
  if (not metPhi_isLoaded) {
    if (metPhi_branch != 0) {
      metPhi_branch->GetEntry(index);
    } else {
      printf("branch metPhi_branch does not exist!\n");
      exit(1);
    }
    metPhi_isLoaded = true;
  }
  return metPhi_;
}

const float &SSAG::rawmet() {
  if (not rawmet_isLoaded) {
    if (rawmet_branch != 0) {
      rawmet_branch->GetEntry(index);
    } else {
      printf("branch rawmet_branch does not exist!\n");
      exit(1);
    }
    rawmet_isLoaded = true;
  }
  return rawmet_;
}

const float &SSAG::rawmetPhi() {
  if (not rawmetPhi_isLoaded) {
    if (rawmetPhi_branch != 0) {
      rawmetPhi_branch->GetEntry(index);
    } else {
      printf("branch rawmetPhi_branch does not exist!\n");
      exit(1);
    }
    rawmetPhi_isLoaded = true;
  }
  return rawmetPhi_;
}

const float &SSAG::calomet() {
  if (not calomet_isLoaded) {
    if (calomet_branch != 0) {
      calomet_branch->GetEntry(index);
    } else {
      printf("branch calomet_branch does not exist!\n");
      exit(1);
    }
    calomet_isLoaded = true;
  }
  return calomet_;
}

const float &SSAG::calometPhi() {
  if (not calometPhi_isLoaded) {
    if (calometPhi_branch != 0) {
      calometPhi_branch->GetEntry(index);
    } else {
      printf("branch calometPhi_branch does not exist!\n");
      exit(1);
    }
    calometPhi_isLoaded = true;
  }
  return calometPhi_;
}

const unsigned long long &SSAG::event() {
  if (not event_isLoaded) {
    if (event_branch != 0) {
      event_branch->GetEntry(index);
    } else {
      printf("branch event_branch does not exist!\n");
      exit(1);
    }
    event_isLoaded = true;
  }
  return event_;
}

const int &SSAG::lumi() {
  if (not lumi_isLoaded) {
    if (lumi_branch != 0) {
      lumi_branch->GetEntry(index);
    } else {
      printf("branch lumi_branch does not exist!\n");
      exit(1);
    }
    lumi_isLoaded = true;
  }
  return lumi_;
}

const int &SSAG::run() {
  if (not run_isLoaded) {
    if (run_branch != 0) {
      run_branch->GetEntry(index);
    } else {
      printf("branch run_branch does not exist!\n");
      exit(1);
    }
    run_isLoaded = true;
  }
  return run_;
}

const bool &SSAG::filt_csc() {
  if (not filt_csc_isLoaded) {
    if (filt_csc_branch != 0) {
      filt_csc_branch->GetEntry(index);
    } else {
      printf("branch filt_csc_branch does not exist!\n");
      exit(1);
    }
    filt_csc_isLoaded = true;
  }
  return filt_csc_;
}

const bool &SSAG::filt_hbhe() {
  if (not filt_hbhe_isLoaded) {
    if (filt_hbhe_branch != 0) {
      filt_hbhe_branch->GetEntry(index);
    } else {
      printf("branch filt_hbhe_branch does not exist!\n");
      exit(1);
    }
    filt_hbhe_isLoaded = true;
  }
  return filt_hbhe_;
}

const bool &SSAG::filt_hcallaser() {
  if (not filt_hcallaser_isLoaded) {
    if (filt_hcallaser_branch != 0) {
      filt_hcallaser_branch->GetEntry(index);
    } else {
      printf("branch filt_hcallaser_branch does not exist!\n");
      exit(1);
    }
    filt_hcallaser_isLoaded = true;
  }
  return filt_hcallaser_;
}

const bool &SSAG::filt_ecaltp() {
  if (not filt_ecaltp_isLoaded) {
    if (filt_ecaltp_branch != 0) {
      filt_ecaltp_branch->GetEntry(index);
    } else {
      printf("branch filt_ecaltp_branch does not exist!\n");
      exit(1);
    }
    filt_ecaltp_isLoaded = true;
  }
  return filt_ecaltp_;
}

const bool &SSAG::filt_trkfail() {
  if (not filt_trkfail_isLoaded) {
    if (filt_trkfail_branch != 0) {
      filt_trkfail_branch->GetEntry(index);
    } else {
      printf("branch filt_trkfail_branch does not exist!\n");
      exit(1);
    }
    filt_trkfail_isLoaded = true;
  }
  return filt_trkfail_;
}

const bool &SSAG::is_real_data() {
  if (not is_real_data_isLoaded) {
    if (is_real_data_branch != 0) {
      is_real_data_branch->GetEntry(index);
    } else {
      printf("branch is_real_data_branch does not exist!\n");
      exit(1);
    }
    is_real_data_isLoaded = true;
  }
  return is_real_data_;
}

const float &SSAG::scale1fb() {
  if (not scale1fb_isLoaded) {
    if (scale1fb_branch != 0) {
      scale1fb_branch->GetEntry(index);
    } else {
      printf("branch scale1fb_branch does not exist!\n");
      exit(1);
    }
    scale1fb_isLoaded = true;
  }
  return scale1fb_;
}

const float &SSAG::genps_weight() {
  if (not genps_weight_isLoaded) {
    if (genps_weight_branch != 0) {
      genps_weight_branch->GetEntry(index);
    } else {
      printf("branch genps_weight_branch does not exist!\n");
      exit(1);
    }
    genps_weight_isLoaded = true;
  }
  return genps_weight_;
}

const float &SSAG::xsec() {
  if (not xsec_isLoaded) {
    if (xsec_branch != 0) {
      xsec_branch->GetEntry(index);
    } else {
      printf("branch xsec_branch does not exist!\n");
      exit(1);
    }
    xsec_isLoaded = true;
  }
  return xsec_;
}

const int &SSAG::neventstotal() {
  if (not neventstotal_isLoaded) {
    if (neventstotal_branch != 0) {
      neventstotal_branch->GetEntry(index);
    } else {
      printf("branch neventstotal_branch does not exist!\n");
      exit(1);
    }
    neventstotal_isLoaded = true;
  }
  return neventstotal_;
}

const float &SSAG::xsec_ps() {
  if (not xsec_ps_isLoaded) {
    if (xsec_ps_branch != 0) {
      xsec_ps_branch->GetEntry(index);
    } else {
      printf("branch xsec_ps_branch does not exist!\n");
      exit(1);
    }
    xsec_ps_isLoaded = true;
  }
  return xsec_ps_;
}

const vector<TString> &SSAG::sparmNames() {
  if (not sparmNames_isLoaded) {
    if (sparmNames_branch != 0) {
      sparmNames_branch->GetEntry(index);
    } else {
      printf("branch sparmNames_branch does not exist!\n");
      exit(1);
    }
    sparmNames_isLoaded = true;
  }
  return *sparmNames_;
}

const vector<float> &SSAG::sparms() {
  if (not sparms_isLoaded) {
    if (sparms_branch != 0) {
      sparms_branch->GetEntry(index);
    } else {
      printf("branch sparms_branch does not exist!\n");
      exit(1);
    }
    sparms_isLoaded = true;
  }
  return *sparms_;
}

const float &SSAG::xsec_error() {
  if (not xsec_error_isLoaded) {
    if (xsec_error_branch != 0) {
      xsec_error_branch->GetEntry(index);
    } else {
      printf("branch xsec_error_branch does not exist!\n");
      exit(1);
    }
    xsec_error_isLoaded = true;
  }
  return xsec_error_;
}

const float &SSAG::kfactor() {
  if (not kfactor_isLoaded) {
    if (kfactor_branch != 0) {
      kfactor_branch->GetEntry(index);
    } else {
      printf("branch kfactor_branch does not exist!\n");
      exit(1);
    }
    kfactor_isLoaded = true;
  }
  return kfactor_;
}

const float &SSAG::gen_met() {
  if (not gen_met_isLoaded) {
    if (gen_met_branch != 0) {
      gen_met_branch->GetEntry(index);
    } else {
      printf("branch gen_met_branch does not exist!\n");
      exit(1);
    }
    gen_met_isLoaded = true;
  }
  return gen_met_;
}

const vector<float> &SSAG::pdfweights() {
  if (not pdfweights_isLoaded) {
    if (pdfweights_branch != 0) {
      pdfweights_branch->GetEntry(index);
    } else {
      printf("branch pdfweights_branch does not exist!\n");
      exit(1);
    }
    pdfweights_isLoaded = true;
  }
  return *pdfweights_;
}

const float &SSAG::gen_met_phi() {
  if (not gen_met_phi_isLoaded) {
    if (gen_met_phi_branch != 0) {
      gen_met_phi_branch->GetEntry(index);
    } else {
      printf("branch gen_met_phi_branch does not exist!\n");
      exit(1);
    }
    gen_met_phi_isLoaded = true;
  }
  return gen_met_phi_;
}

const bool &SSAG::skim() {
  if (not skim_isLoaded) {
    if (skim_branch != 0) {
      skim_branch->GetEntry(index);
    } else {
      printf("branch skim_branch does not exist!\n");
      exit(1);
    }
    skim_isLoaded = true;
  }
  return skim_;
}

const bool &SSAG::skim_nomet() {
  if (not skim_nomet_isLoaded) {
    if (skim_nomet_branch != 0) {
      skim_nomet_branch->GetEntry(index);
    } else {
      printf("branch skim_nomet_branch does not exist!\n");
      exit(1);
    }
    skim_nomet_isLoaded = true;
  }
  return skim_nomet_;
}

const int &SSAG::nleps() {
  if (not nleps_isLoaded) {
    if (nleps_branch != 0) {
      nleps_branch->GetEntry(index);
    } else {
      printf("branch nleps_branch does not exist!\n");
      exit(1);
    }
    nleps_isLoaded = true;
  }
  return nleps_;
}

const int &SSAG::sr() {
  if (not sr_isLoaded) {
    if (sr_branch != 0) {
      sr_branch->GetEntry(index);
    } else {
      printf("branch sr_branch does not exist!\n");
      exit(1);
    }
    sr_isLoaded = true;
  }
  return sr_;
}

const bool &SSAG::br() {
  if (not br_isLoaded) {
    if (br_branch != 0) {
      br_branch->GetEntry(index);
    } else {
      printf("branch br_branch does not exist!\n");
      exit(1);
    }
    br_isLoaded = true;
  }
  return br_;
}

const int &SSAG::ss_nleps() {
  if (not ss_nleps_isLoaded) {
    if (ss_nleps_branch != 0) {
      ss_nleps_branch->GetEntry(index);
    } else {
      printf("branch ss_nleps_branch does not exist!\n");
      exit(1);
    }
    ss_nleps_isLoaded = true;
  }
  return ss_nleps_;
}

const bool &SSAG::ss_br() {
  if (not ss_br_isLoaded) {
    if (ss_br_branch != 0) {
      ss_br_branch->GetEntry(index);
    } else {
      printf("branch ss_br_branch does not exist!\n");
      exit(1);
    }
    ss_br_isLoaded = true;
  }
  return ss_br_;
}

const int &SSAG::ss_sr() {
  if (not ss_sr_isLoaded) {
    if (ss_sr_branch != 0) {
      ss_sr_branch->GetEntry(index);
    } else {
      printf("branch ss_sr_branch does not exist!\n");
      exit(1);
    }
    ss_sr_isLoaded = true;
  }
  return ss_sr_;
}

const int &SSAG::ss_region() {
  if (not ss_region_isLoaded) {
    if (ss_region_branch != 0) {
      ss_region_branch->GetEntry(index);
    } else {
      printf("branch ss_region_branch does not exist!\n");
      exit(1);
    }
    ss_region_isLoaded = true;
  }
  return ss_region_;
}

const int &SSAG::njets() {
  if (not njets_isLoaded) {
    if (njets_branch != 0) {
      njets_branch->GetEntry(index);
    } else {
      printf("branch njets_branch does not exist!\n");
      exit(1);
    }
    njets_isLoaded = true;
  }
  return njets_;
}

const int &SSAG::njetsAG() {
  if (not njetsAG_isLoaded) {
    if (njetsAG_branch != 0) {
      njetsAG_branch->GetEntry(index);
    } else {
      printf("branch njetsAG_branch does not exist!\n");
      exit(1);
    }
    njetsAG_isLoaded = true;
  }
  return njetsAG_;
}

const int &SSAG::nbtagsAG() {
  if (not nbtagsAG_isLoaded) {
    if (nbtagsAG_branch != 0) {
      nbtagsAG_branch->GetEntry(index);
    } else {
      printf("branch nbtagsAG_branch does not exist!\n");
      exit(1);
    }
    nbtagsAG_isLoaded = true;
  }
  return nbtagsAG_;
}

const int &SSAG::njets_raw() {
  if (not njets_raw_isLoaded) {
    if (njets_raw_branch != 0) {
      njets_raw_branch->GetEntry(index);
    } else {
      printf("branch njets_raw_branch does not exist!\n");
      exit(1);
    }
    njets_raw_isLoaded = true;
  }
  return njets_raw_;
}

const int &SSAG::hyp_class() {
  if (not hyp_class_isLoaded) {
    if (hyp_class_branch != 0) {
      hyp_class_branch->GetEntry(index);
    } else {
      printf("branch hyp_class_branch does not exist!\n");
      exit(1);
    }
    hyp_class_isLoaded = true;
  }
  return hyp_class_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::lep1_p4() {
  if (not lep1_p4_isLoaded) {
    if (lep1_p4_branch != 0) {
      lep1_p4_branch->GetEntry(index);
    } else {
      printf("branch lep1_p4_branch does not exist!\n");
      exit(1);
    }
    lep1_p4_isLoaded = true;
  }
  return *lep1_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::lep2_p4() {
  if (not lep2_p4_isLoaded) {
    if (lep2_p4_branch != 0) {
      lep2_p4_branch->GetEntry(index);
    } else {
      printf("branch lep2_p4_branch does not exist!\n");
      exit(1);
    }
    lep2_p4_isLoaded = true;
  }
  return *lep2_p4_;
}

const float &SSAG::lep1_pt() {
  if (not lep1_pt_isLoaded) {
    if (lep1_pt_branch != 0) {
      lep1_pt_branch->GetEntry(index);
    } else {
      printf("branch lep1_pt_branch does not exist!\n");
      exit(1);
    }
    lep1_pt_isLoaded = true;
  }
  return lep1_pt_;
}

const float &SSAG::lep2_pt() {
  if (not lep2_pt_isLoaded) {
    if (lep2_pt_branch != 0) {
      lep2_pt_branch->GetEntry(index);
    } else {
      printf("branch lep2_pt_branch does not exist!\n");
      exit(1);
    }
    lep2_pt_isLoaded = true;
  }
  return lep2_pt_;
}

const float &SSAG::lep3_pt() {
  if (not lep3_pt_isLoaded) {
    if (lep3_pt_branch != 0) {
      lep3_pt_branch->GetEntry(index);
    } else {
      printf("branch lep3_pt_branch does not exist!\n");
      exit(1);
    }
    lep3_pt_isLoaded = true;
  }
  return lep3_pt_;
}

const float &SSAG::lep1_eta() {
  if (not lep1_eta_isLoaded) {
    if (lep1_eta_branch != 0) {
      lep1_eta_branch->GetEntry(index);
    } else {
      printf("branch lep1_eta_branch does not exist!\n");
      exit(1);
    }
    lep1_eta_isLoaded = true;
  }
  return lep1_eta_;
}

const float &SSAG::lep2_eta() {
  if (not lep2_eta_isLoaded) {
    if (lep2_eta_branch != 0) {
      lep2_eta_branch->GetEntry(index);
    } else {
      printf("branch lep2_eta_branch does not exist!\n");
      exit(1);
    }
    lep2_eta_isLoaded = true;
  }
  return lep2_eta_;
}

const float &SSAG::lep3_eta() {
  if (not lep3_eta_isLoaded) {
    if (lep3_eta_branch != 0) {
      lep3_eta_branch->GetEntry(index);
    } else {
      printf("branch lep3_eta_branch does not exist!\n");
      exit(1);
    }
    lep3_eta_isLoaded = true;
  }
  return lep3_eta_;
}

const float &SSAG::lep1_phi() {
  if (not lep1_phi_isLoaded) {
    if (lep1_phi_branch != 0) {
      lep1_phi_branch->GetEntry(index);
    } else {
      printf("branch lep1_phi_branch does not exist!\n");
      exit(1);
    }
    lep1_phi_isLoaded = true;
  }
  return lep1_phi_;
}

const float &SSAG::lep2_phi() {
  if (not lep2_phi_isLoaded) {
    if (lep2_phi_branch != 0) {
      lep2_phi_branch->GetEntry(index);
    } else {
      printf("branch lep2_phi_branch does not exist!\n");
      exit(1);
    }
    lep2_phi_isLoaded = true;
  }
  return lep2_phi_;
}

const float &SSAG::lep3_phi() {
  if (not lep3_phi_isLoaded) {
    if (lep3_phi_branch != 0) {
      lep3_phi_branch->GetEntry(index);
    } else {
      printf("branch lep3_phi_branch does not exist!\n");
      exit(1);
    }
    lep3_phi_isLoaded = true;
  }
  return lep3_phi_;
}

const float &SSAG::ht_raw() {
  if (not ht_raw_isLoaded) {
    if (ht_raw_branch != 0) {
      ht_raw_branch->GetEntry(index);
    } else {
      printf("branch ht_raw_branch does not exist!\n");
      exit(1);
    }
    ht_raw_isLoaded = true;
  }
  return ht_raw_;
}

const float &SSAG::ht() {
  if (not ht_isLoaded) {
    if (ht_branch != 0) {
      ht_branch->GetEntry(index);
    } else {
      printf("branch ht_branch does not exist!\n");
      exit(1);
    }
    ht_isLoaded = true;
  }
  return ht_;
}

const int &SSAG::lep1_motherID() {
  if (not lep1_motherID_isLoaded) {
    if (lep1_motherID_branch != 0) {
      lep1_motherID_branch->GetEntry(index);
    } else {
      printf("branch lep1_motherID_branch does not exist!\n");
      exit(1);
    }
    lep1_motherID_isLoaded = true;
  }
  return lep1_motherID_;
}

const int &SSAG::lep2_motherID() {
  if (not lep2_motherID_isLoaded) {
    if (lep2_motherID_branch != 0) {
      lep2_motherID_branch->GetEntry(index);
    } else {
      printf("branch lep2_motherID_branch does not exist!\n");
      exit(1);
    }
    lep2_motherID_isLoaded = true;
  }
  return lep2_motherID_;
}

const int &SSAG::lep1_mc_id() {
  if (not lep1_mc_id_isLoaded) {
    if (lep1_mc_id_branch != 0) {
      lep1_mc_id_branch->GetEntry(index);
    } else {
      printf("branch lep1_mc_id_branch does not exist!\n");
      exit(1);
    }
    lep1_mc_id_isLoaded = true;
  }
  return lep1_mc_id_;
}

const int &SSAG::lep2_mc_id() {
  if (not lep2_mc_id_isLoaded) {
    if (lep2_mc_id_branch != 0) {
      lep2_mc_id_branch->GetEntry(index);
    } else {
      printf("branch lep2_mc_id_branch does not exist!\n");
      exit(1);
    }
    lep2_mc_id_isLoaded = true;
  }
  return lep2_mc_id_;
}

const int &SSAG::lep1_mc_motherid() {
  if (not lep1_mc_motherid_isLoaded) {
    if (lep1_mc_motherid_branch != 0) {
      lep1_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch lep1_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    lep1_mc_motherid_isLoaded = true;
  }
  return lep1_mc_motherid_;
}

const int &SSAG::lep2_mc_motherid() {
  if (not lep2_mc_motherid_isLoaded) {
    if (lep2_mc_motherid_branch != 0) {
      lep2_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch lep2_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    lep2_mc_motherid_isLoaded = true;
  }
  return lep2_mc_motherid_;
}

const int &SSAG::lep1_id() {
  if (not lep1_id_isLoaded) {
    if (lep1_id_branch != 0) {
      lep1_id_branch->GetEntry(index);
    } else {
      printf("branch lep1_id_branch does not exist!\n");
      exit(1);
    }
    lep1_id_isLoaded = true;
  }
  return lep1_id_;
}

const int &SSAG::lep2_id() {
  if (not lep2_id_isLoaded) {
    if (lep2_id_branch != 0) {
      lep2_id_branch->GetEntry(index);
    } else {
      printf("branch lep2_id_branch does not exist!\n");
      exit(1);
    }
    lep2_id_isLoaded = true;
  }
  return lep2_id_;
}

const float &SSAG::lep1_coneCorrPt() {
  if (not lep1_coneCorrPt_isLoaded) {
    if (lep1_coneCorrPt_branch != 0) {
      lep1_coneCorrPt_branch->GetEntry(index);
    } else {
      printf("branch lep1_coneCorrPt_branch does not exist!\n");
      exit(1);
    }
    lep1_coneCorrPt_isLoaded = true;
  }
  return lep1_coneCorrPt_;
}

const float &SSAG::lep2_coneCorrPt() {
  if (not lep2_coneCorrPt_isLoaded) {
    if (lep2_coneCorrPt_branch != 0) {
      lep2_coneCorrPt_branch->GetEntry(index);
    } else {
      printf("branch lep2_coneCorrPt_branch does not exist!\n");
      exit(1);
    }
    lep2_coneCorrPt_isLoaded = true;
  }
  return lep2_coneCorrPt_;
}

const float &SSAG::lep3_coneCorrPt() {
  if (not lep3_coneCorrPt_isLoaded) {
    if (lep3_coneCorrPt_branch != 0) {
      lep3_coneCorrPt_branch->GetEntry(index);
    } else {
      printf("branch lep3_coneCorrPt_branch does not exist!\n");
      exit(1);
    }
    lep3_coneCorrPt_isLoaded = true;
  }
  return lep3_coneCorrPt_;
}

const float &SSAG::lep4_coneCorrPt() {
  if (not lep4_coneCorrPt_isLoaded) {
    if (lep4_coneCorrPt_branch != 0) {
      lep4_coneCorrPt_branch->GetEntry(index);
    } else {
      printf("branch lep4_coneCorrPt_branch does not exist!\n");
      exit(1);
    }
    lep4_coneCorrPt_isLoaded = true;
  }
  return lep4_coneCorrPt_;
}

const int &SSAG::lep1_idx() {
  if (not lep1_idx_isLoaded) {
    if (lep1_idx_branch != 0) {
      lep1_idx_branch->GetEntry(index);
    } else {
      printf("branch lep1_idx_branch does not exist!\n");
      exit(1);
    }
    lep1_idx_isLoaded = true;
  }
  return lep1_idx_;
}

const int &SSAG::lep2_idx() {
  if (not lep2_idx_isLoaded) {
    if (lep2_idx_branch != 0) {
      lep2_idx_branch->GetEntry(index);
    } else {
      printf("branch lep2_idx_branch does not exist!\n");
      exit(1);
    }
    lep2_idx_isLoaded = true;
  }
  return lep2_idx_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::jets() {
  if (not jets_isLoaded) {
    if (jets_branch != 0) {
      jets_branch->GetEntry(index);
    } else {
      printf("branch jets_branch does not exist!\n");
      exit(1);
    }
    jets_isLoaded = true;
  }
  return *jets_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::jets_jec_up() {
  if (not jets_jec_up_isLoaded) {
    if (jets_jec_up_branch != 0) {
      jets_jec_up_branch->GetEntry(index);
    } else {
      printf("branch jets_jec_up_branch does not exist!\n");
      exit(1);
    }
    jets_jec_up_isLoaded = true;
  }
  return *jets_jec_up_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::jets_jec_dn() {
  if (not jets_jec_dn_isLoaded) {
    if (jets_jec_dn_branch != 0) {
      jets_jec_dn_branch->GetEntry(index);
    } else {
      printf("branch jets_jec_dn_branch does not exist!\n");
      exit(1);
    }
    jets_jec_dn_isLoaded = true;
  }
  return *jets_jec_dn_;
}

const vector<float> &SSAG::jets_disc_up() {
  if (not jets_disc_up_isLoaded) {
    if (jets_disc_up_branch != 0) {
      jets_disc_up_branch->GetEntry(index);
    } else {
      printf("branch jets_disc_up_branch does not exist!\n");
      exit(1);
    }
    jets_disc_up_isLoaded = true;
  }
  return *jets_disc_up_;
}

const vector<float> &SSAG::jets_disc_dn() {
  if (not jets_disc_dn_isLoaded) {
    if (jets_disc_dn_branch != 0) {
      jets_disc_dn_branch->GetEntry(index);
    } else {
      printf("branch jets_disc_dn_branch does not exist!\n");
      exit(1);
    }
    jets_disc_dn_isLoaded = true;
  }
  return *jets_disc_dn_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::bjets_jec_up() {
  if (not bjets_jec_up_isLoaded) {
    if (bjets_jec_up_branch != 0) {
      bjets_jec_up_branch->GetEntry(index);
    } else {
      printf("branch bjets_jec_up_branch does not exist!\n");
      exit(1);
    }
    bjets_jec_up_isLoaded = true;
  }
  return *bjets_jec_up_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::bjets_jec_dn() {
  if (not bjets_jec_dn_isLoaded) {
    if (bjets_jec_dn_branch != 0) {
      bjets_jec_dn_branch->GetEntry(index);
    } else {
      printf("branch bjets_jec_dn_branch does not exist!\n");
      exit(1);
    }
    bjets_jec_dn_isLoaded = true;
  }
  return *bjets_jec_dn_;
}

const vector<int> &SSAG::btags_flavor() {
  if (not btags_flavor_isLoaded) {
    if (btags_flavor_branch != 0) {
      btags_flavor_branch->GetEntry(index);
    } else {
      printf("branch btags_flavor_branch does not exist!\n");
      exit(1);
    }
    btags_flavor_isLoaded = true;
  }
  return *btags_flavor_;
}

const vector<float> &SSAG::btags_disc() {
  if (not btags_disc_isLoaded) {
    if (btags_disc_branch != 0) {
      btags_disc_branch->GetEntry(index);
    } else {
      printf("branch btags_disc_branch does not exist!\n");
      exit(1);
    }
    btags_disc_isLoaded = true;
  }
  return *btags_disc_;
}

const vector<float> &SSAG::btags_cdisc() {
  if (not btags_cdisc_isLoaded) {
    if (btags_cdisc_branch != 0) {
      btags_cdisc_branch->GetEntry(index);
    } else {
      printf("branch btags_cdisc_branch does not exist!\n");
      exit(1);
    }
    btags_cdisc_isLoaded = true;
  }
  return *btags_cdisc_;
}

const vector<int> &SSAG::jets_flavor() {
  if (not jets_flavor_isLoaded) {
    if (jets_flavor_branch != 0) {
      jets_flavor_branch->GetEntry(index);
    } else {
      printf("branch jets_flavor_branch does not exist!\n");
      exit(1);
    }
    jets_flavor_isLoaded = true;
  }
  return *jets_flavor_;
}

const vector<float> &SSAG::jets_disc() {
  if (not jets_disc_isLoaded) {
    if (jets_disc_branch != 0) {
      jets_disc_branch->GetEntry(index);
    } else {
      printf("branch jets_disc_branch does not exist!\n");
      exit(1);
    }
    jets_disc_isLoaded = true;
  }
  return *jets_disc_;
}

const vector<float> &SSAG::jets_bsf() {
  if (not jets_bsf_isLoaded) {
    if (jets_bsf_branch != 0) {
      jets_bsf_branch->GetEntry(index);
    } else {
      printf("branch jets_bsf_branch does not exist!\n");
      exit(1);
    }
    jets_bsf_isLoaded = true;
  }
  return *jets_bsf_;
}

const vector<float> &SSAG::jets_JEC() {
  if (not jets_JEC_isLoaded) {
    if (jets_JEC_branch != 0) {
      jets_JEC_branch->GetEntry(index);
    } else {
      printf("branch jets_JEC_branch does not exist!\n");
      exit(1);
    }
    jets_JEC_isLoaded = true;
  }
  return *jets_JEC_;
}

const vector<float> &SSAG::btags_JEC() {
  if (not btags_JEC_isLoaded) {
    if (btags_JEC_branch != 0) {
      btags_JEC_branch->GetEntry(index);
    } else {
      printf("branch btags_JEC_branch does not exist!\n");
      exit(1);
    }
    btags_JEC_isLoaded = true;
  }
  return *btags_JEC_;
}

const vector<float> &SSAG::jets_undoJEC() {
  if (not jets_undoJEC_isLoaded) {
    if (jets_undoJEC_branch != 0) {
      jets_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch jets_undoJEC_branch does not exist!\n");
      exit(1);
    }
    jets_undoJEC_isLoaded = true;
  }
  return *jets_undoJEC_;
}

const vector<float> &SSAG::btags_undoJEC() {
  if (not btags_undoJEC_isLoaded) {
    if (btags_undoJEC_branch != 0) {
      btags_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch btags_undoJEC_branch does not exist!\n");
      exit(1);
    }
    btags_undoJEC_isLoaded = true;
  }
  return *btags_undoJEC_;
}

const vector<float> &SSAG::btags_unc() {
  if (not btags_unc_isLoaded) {
    if (btags_unc_branch != 0) {
      btags_unc_branch->GetEntry(index);
    } else {
      printf("branch btags_unc_branch does not exist!\n");
      exit(1);
    }
    btags_unc_isLoaded = true;
  }
  return *btags_unc_;
}

const vector<float> &SSAG::btags_eff() {
  if (not btags_eff_isLoaded) {
    if (btags_eff_branch != 0) {
      btags_eff_branch->GetEntry(index);
    } else {
      printf("branch btags_eff_branch does not exist!\n");
      exit(1);
    }
    btags_eff_isLoaded = true;
  }
  return *btags_eff_;
}

const vector<float> &SSAG::btags_effpt() {
  if (not btags_effpt_isLoaded) {
    if (btags_effpt_branch != 0) {
      btags_effpt_branch->GetEntry(index);
    } else {
      printf("branch btags_effpt_branch does not exist!\n");
      exit(1);
    }
    btags_effpt_isLoaded = true;
  }
  return *btags_effpt_;
}

const vector<float> &SSAG::btags_sf() {
  if (not btags_sf_isLoaded) {
    if (btags_sf_branch != 0) {
      btags_sf_branch->GetEntry(index);
    } else {
      printf("branch btags_sf_branch does not exist!\n");
      exit(1);
    }
    btags_sf_isLoaded = true;
  }
  return *btags_sf_;
}

const vector<float> &SSAG::jets_unc() {
  if (not jets_unc_isLoaded) {
    if (jets_unc_branch != 0) {
      jets_unc_branch->GetEntry(index);
    } else {
      printf("branch jets_unc_branch does not exist!\n");
      exit(1);
    }
    jets_unc_isLoaded = true;
  }
  return *jets_unc_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::btags() {
  if (not btags_isLoaded) {
    if (btags_branch != 0) {
      btags_branch->GetEntry(index);
    } else {
      printf("branch btags_branch does not exist!\n");
      exit(1);
    }
    btags_isLoaded = true;
  }
  return *btags_;
}

const int &SSAG::nbtags() {
  if (not nbtags_isLoaded) {
    if (nbtags_branch != 0) {
      nbtags_branch->GetEntry(index);
    } else {
      printf("branch nbtags_branch does not exist!\n");
      exit(1);
    }
    nbtags_isLoaded = true;
  }
  return nbtags_;
}

const int &SSAG::nbtags_raw() {
  if (not nbtags_raw_isLoaded) {
    if (nbtags_raw_branch != 0) {
      nbtags_raw_branch->GetEntry(index);
    } else {
      printf("branch nbtags_raw_branch does not exist!\n");
      exit(1);
    }
    nbtags_raw_isLoaded = true;
  }
  return nbtags_raw_;
}

const float &SSAG::sf_dilepTrig_hpt() {
  if (not sf_dilepTrig_hpt_isLoaded) {
    if (sf_dilepTrig_hpt_branch != 0) {
      sf_dilepTrig_hpt_branch->GetEntry(index);
    } else {
      printf("branch sf_dilepTrig_hpt_branch does not exist!\n");
      exit(1);
    }
    sf_dilepTrig_hpt_isLoaded = true;
  }
  return sf_dilepTrig_hpt_;
}

const float &SSAG::sf_dilepTrig_lpt() {
  if (not sf_dilepTrig_lpt_isLoaded) {
    if (sf_dilepTrig_lpt_branch != 0) {
      sf_dilepTrig_lpt_branch->GetEntry(index);
    } else {
      printf("branch sf_dilepTrig_lpt_branch does not exist!\n");
      exit(1);
    }
    sf_dilepTrig_lpt_isLoaded = true;
  }
  return sf_dilepTrig_lpt_;
}

const float &SSAG::sf_dilepTrig_vlpt() {
  if (not sf_dilepTrig_vlpt_isLoaded) {
    if (sf_dilepTrig_vlpt_branch != 0) {
      sf_dilepTrig_vlpt_branch->GetEntry(index);
    } else {
      printf("branch sf_dilepTrig_vlpt_branch does not exist!\n");
      exit(1);
    }
    sf_dilepTrig_vlpt_isLoaded = true;
  }
  return sf_dilepTrig_vlpt_;
}

const int &SSAG::hyp_type() {
  if (not hyp_type_isLoaded) {
    if (hyp_type_branch != 0) {
      hyp_type_branch->GetEntry(index);
    } else {
      printf("branch hyp_type_branch does not exist!\n");
      exit(1);
    }
    hyp_type_isLoaded = true;
  }
  return hyp_type_;
}

const float &SSAG::sf_dilep_eff() {
  if (not sf_dilep_eff_isLoaded) {
    if (sf_dilep_eff_branch != 0) {
      sf_dilep_eff_branch->GetEntry(index);
    } else {
      printf("branch sf_dilep_eff_branch does not exist!\n");
      exit(1);
    }
    sf_dilep_eff_isLoaded = true;
  }
  return sf_dilep_eff_;
}

const float &SSAG::mt() {
  if (not mt_isLoaded) {
    if (mt_branch != 0) {
      mt_branch->GetEntry(index);
    } else {
      printf("branch mt_branch does not exist!\n");
      exit(1);
    }
    mt_isLoaded = true;
  }
  return mt_;
}

const float &SSAG::mt_l2() {
  if (not mt_l2_isLoaded) {
    if (mt_l2_branch != 0) {
      mt_l2_branch->GetEntry(index);
    } else {
      printf("branch mt_l2_branch does not exist!\n");
      exit(1);
    }
    mt_l2_isLoaded = true;
  }
  return mt_l2_;
}

const float &SSAG::mt2() {
  if (not mt2_isLoaded) {
    if (mt2_branch != 0) {
      mt2_branch->GetEntry(index);
    } else {
      printf("branch mt2_branch does not exist!\n");
      exit(1);
    }
    mt2_isLoaded = true;
  }
  return mt2_;
}

const float &SSAG::mtmin() {
  if (not mtmin_isLoaded) {
    if (mtmin_branch != 0) {
      mtmin_branch->GetEntry(index);
    } else {
      printf("branch mtmin_branch does not exist!\n");
      exit(1);
    }
    mtmin_isLoaded = true;
  }
  return mtmin_;
}

const int &SSAG::lep1_id_gen() {
  if (not lep1_id_gen_isLoaded) {
    if (lep1_id_gen_branch != 0) {
      lep1_id_gen_branch->GetEntry(index);
    } else {
      printf("branch lep1_id_gen_branch does not exist!\n");
      exit(1);
    }
    lep1_id_gen_isLoaded = true;
  }
  return lep1_id_gen_;
}

const int &SSAG::lep2_id_gen() {
  if (not lep2_id_gen_isLoaded) {
    if (lep2_id_gen_branch != 0) {
      lep2_id_gen_branch->GetEntry(index);
    } else {
      printf("branch lep2_id_gen_branch does not exist!\n");
      exit(1);
    }
    lep2_id_gen_isLoaded = true;
  }
  return lep2_id_gen_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::lep1_p4_gen() {
  if (not lep1_p4_gen_isLoaded) {
    if (lep1_p4_gen_branch != 0) {
      lep1_p4_gen_branch->GetEntry(index);
    } else {
      printf("branch lep1_p4_gen_branch does not exist!\n");
      exit(1);
    }
    lep1_p4_gen_isLoaded = true;
  }
  return *lep1_p4_gen_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::lep2_p4_gen() {
  if (not lep2_p4_gen_isLoaded) {
    if (lep2_p4_gen_branch != 0) {
      lep2_p4_gen_branch->GetEntry(index);
    } else {
      printf("branch lep2_p4_gen_branch does not exist!\n");
      exit(1);
    }
    lep2_p4_gen_isLoaded = true;
  }
  return *lep2_p4_gen_;
}

const int &SSAG::lep3_id() {
  if (not lep3_id_isLoaded) {
    if (lep3_id_branch != 0) {
      lep3_id_branch->GetEntry(index);
    } else {
      printf("branch lep3_id_branch does not exist!\n");
      exit(1);
    }
    lep3_id_isLoaded = true;
  }
  return lep3_id_;
}

const int &SSAG::lep3_idx() {
  if (not lep3_idx_isLoaded) {
    if (lep3_idx_branch != 0) {
      lep3_idx_branch->GetEntry(index);
    } else {
      printf("branch lep3_idx_branch does not exist!\n");
      exit(1);
    }
    lep3_idx_isLoaded = true;
  }
  return lep3_idx_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::lep3_p4() {
  if (not lep3_p4_isLoaded) {
    if (lep3_p4_branch != 0) {
      lep3_p4_branch->GetEntry(index);
    } else {
      printf("branch lep3_p4_branch does not exist!\n");
      exit(1);
    }
    lep3_p4_isLoaded = true;
  }
  return *lep3_p4_;
}

const int &SSAG::lep3_quality() {
  if (not lep3_quality_isLoaded) {
    if (lep3_quality_branch != 0) {
      lep3_quality_branch->GetEntry(index);
    } else {
      printf("branch lep3_quality_branch does not exist!\n");
      exit(1);
    }
    lep3_quality_isLoaded = true;
  }
  return lep3_quality_;
}

const int &SSAG::lep4_id() {
  if (not lep4_id_isLoaded) {
    if (lep4_id_branch != 0) {
      lep4_id_branch->GetEntry(index);
    } else {
      printf("branch lep4_id_branch does not exist!\n");
      exit(1);
    }
    lep4_id_isLoaded = true;
  }
  return lep4_id_;
}

const int &SSAG::lep4_idx() {
  if (not lep4_idx_isLoaded) {
    if (lep4_idx_branch != 0) {
      lep4_idx_branch->GetEntry(index);
    } else {
      printf("branch lep4_idx_branch does not exist!\n");
      exit(1);
    }
    lep4_idx_isLoaded = true;
  }
  return lep4_idx_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::lep4_p4() {
  if (not lep4_p4_isLoaded) {
    if (lep4_p4_branch != 0) {
      lep4_p4_branch->GetEntry(index);
    } else {
      printf("branch lep4_p4_branch does not exist!\n");
      exit(1);
    }
    lep4_p4_isLoaded = true;
  }
  return *lep4_p4_;
}

const float &SSAG::lep1_iso() {
  if (not lep1_iso_isLoaded) {
    if (lep1_iso_branch != 0) {
      lep1_iso_branch->GetEntry(index);
    } else {
      printf("branch lep1_iso_branch does not exist!\n");
      exit(1);
    }
    lep1_iso_isLoaded = true;
  }
  return lep1_iso_;
}

const float &SSAG::lep2_iso() {
  if (not lep2_iso_isLoaded) {
    if (lep2_iso_branch != 0) {
      lep2_iso_branch->GetEntry(index);
    } else {
      printf("branch lep2_iso_branch does not exist!\n");
      exit(1);
    }
    lep2_iso_isLoaded = true;
  }
  return lep2_iso_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::dilep_p4() {
  if (not dilep_p4_isLoaded) {
    if (dilep_p4_branch != 0) {
      dilep_p4_branch->GetEntry(index);
    } else {
      printf("branch dilep_p4_branch does not exist!\n");
      exit(1);
    }
    dilep_p4_isLoaded = true;
  }
  return *dilep_p4_;
}

const float &SSAG::dilep_mass() {
  if (not dilep_mass_isLoaded) {
    if (dilep_mass_branch != 0) {
      dilep_mass_branch->GetEntry(index);
    } else {
      printf("branch dilep_mass_branch does not exist!\n");
      exit(1);
    }
    dilep_mass_isLoaded = true;
  }
  return dilep_mass_;
}

const float &SSAG::mass13() {
  if (not mass13_isLoaded) {
    if (mass13_branch != 0) {
      mass13_branch->GetEntry(index);
    } else {
      printf("branch mass13_branch does not exist!\n");
      exit(1);
    }
    mass13_isLoaded = true;
  }
  return mass13_;
}

const float &SSAG::mass23() {
  if (not mass23_isLoaded) {
    if (mass23_branch != 0) {
      mass23_branch->GetEntry(index);
    } else {
      printf("branch mass23_branch does not exist!\n");
      exit(1);
    }
    mass23_isLoaded = true;
  }
  return mass23_;
}

const float &SSAG::mass123() {
  if (not mass123_isLoaded) {
    if (mass123_branch != 0) {
      mass123_branch->GetEntry(index);
    } else {
      printf("branch mass123_branch does not exist!\n");
      exit(1);
    }
    mass123_isLoaded = true;
  }
  return mass123_;
}

const int &SSAG::ncharginos() {
  if (not ncharginos_isLoaded) {
    if (ncharginos_branch != 0) {
      ncharginos_branch->GetEntry(index);
    } else {
      printf("branch ncharginos_branch does not exist!\n");
      exit(1);
    }
    ncharginos_isLoaded = true;
  }
  return ncharginos_;
}

const int &SSAG::nhiggs() {
  if (not nhiggs_isLoaded) {
    if (nhiggs_branch != 0) {
      nhiggs_branch->GetEntry(index);
    } else {
      printf("branch nhiggs_branch does not exist!\n");
      exit(1);
    }
    nhiggs_isLoaded = true;
  }
  return nhiggs_;
}

const int &SSAG::higgs_mass() {
  if (not higgs_mass_isLoaded) {
    if (higgs_mass_branch != 0) {
      higgs_mass_branch->GetEntry(index);
    } else {
      printf("branch higgs_mass_branch does not exist!\n");
      exit(1);
    }
    higgs_mass_isLoaded = true;
  }
  return higgs_mass_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::genps_p4() {
  if (not genps_p4_isLoaded) {
    if (genps_p4_branch != 0) {
      genps_p4_branch->GetEntry(index);
    } else {
      printf("branch genps_p4_branch does not exist!\n");
      exit(1);
    }
    genps_p4_isLoaded = true;
  }
  return *genps_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::genjets_p4() {
  if (not genjets_p4_isLoaded) {
    if (genjets_p4_branch != 0) {
      genjets_p4_branch->GetEntry(index);
    } else {
      printf("branch genjets_p4_branch does not exist!\n");
      exit(1);
    }
    genjets_p4_isLoaded = true;
  }
  return *genjets_p4_;
}

const vector<int> &SSAG::genps_id() {
  if (not genps_id_isLoaded) {
    if (genps_id_branch != 0) {
      genps_id_branch->GetEntry(index);
    } else {
      printf("branch genps_id_branch does not exist!\n");
      exit(1);
    }
    genps_id_isLoaded = true;
  }
  return *genps_id_;
}

const vector<int> &SSAG::genps_id_mother() {
  if (not genps_id_mother_isLoaded) {
    if (genps_id_mother_branch != 0) {
      genps_id_mother_branch->GetEntry(index);
    } else {
      printf("branch genps_id_mother_branch does not exist!\n");
      exit(1);
    }
    genps_id_mother_isLoaded = true;
  }
  return *genps_id_mother_;
}

const vector<int> &SSAG::genps_idx_mother() {
  if (not genps_idx_mother_isLoaded) {
    if (genps_idx_mother_branch != 0) {
      genps_idx_mother_branch->GetEntry(index);
    } else {
      printf("branch genps_idx_mother_branch does not exist!\n");
      exit(1);
    }
    genps_idx_mother_isLoaded = true;
  }
  return *genps_idx_mother_;
}

const vector<int> &SSAG::genps_status() {
  if (not genps_status_isLoaded) {
    if (genps_status_branch != 0) {
      genps_status_branch->GetEntry(index);
    } else {
      printf("branch genps_status_branch does not exist!\n");
      exit(1);
    }
    genps_status_isLoaded = true;
  }
  return *genps_status_;
}

const vector<int> &SSAG::genps_id_grandma() {
  if (not genps_id_grandma_isLoaded) {
    if (genps_id_grandma_branch != 0) {
      genps_id_grandma_branch->GetEntry(index);
    } else {
      printf("branch genps_id_grandma_branch does not exist!\n");
      exit(1);
    }
    genps_id_grandma_isLoaded = true;
  }
  return *genps_id_grandma_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &SSAG::all_leps_p4() {
  if (not all_leps_p4_isLoaded) {
    if (all_leps_p4_branch != 0) {
      all_leps_p4_branch->GetEntry(index);
    } else {
      printf("branch all_leps_p4_branch does not exist!\n");
      exit(1);
    }
    all_leps_p4_isLoaded = true;
  }
  return *all_leps_p4_;
}

const vector<int> &SSAG::all_leps_id() {
  if (not all_leps_id_isLoaded) {
    if (all_leps_id_branch != 0) {
      all_leps_id_branch->GetEntry(index);
    } else {
      printf("branch all_leps_id_branch does not exist!\n");
      exit(1);
    }
    all_leps_id_isLoaded = true;
  }
  return *all_leps_id_;
}

const vector<bool> &SSAG::all_leps_veto() {
  if (not all_leps_veto_isLoaded) {
    if (all_leps_veto_branch != 0) {
      all_leps_veto_branch->GetEntry(index);
    } else {
      printf("branch all_leps_veto_branch does not exist!\n");
      exit(1);
    }
    all_leps_veto_isLoaded = true;
  }
  return *all_leps_veto_;
}

const vector<int> &SSAG::all_leps_mc3idx() {
  if (not all_leps_mc3idx_isLoaded) {
    if (all_leps_mc3idx_branch != 0) {
      all_leps_mc3idx_branch->GetEntry(index);
    } else {
      printf("branch all_leps_mc3idx_branch does not exist!\n");
      exit(1);
    }
    all_leps_mc3idx_isLoaded = true;
  }
  return *all_leps_mc3idx_;
}

const bool &SSAG::lep1_passes_id() {
  if (not lep1_passes_id_isLoaded) {
    if (lep1_passes_id_branch != 0) {
      lep1_passes_id_branch->GetEntry(index);
    } else {
      printf("branch lep1_passes_id_branch does not exist!\n");
      exit(1);
    }
    lep1_passes_id_isLoaded = true;
  }
  return lep1_passes_id_;
}

const bool &SSAG::lep2_passes_id() {
  if (not lep2_passes_id_isLoaded) {
    if (lep2_passes_id_branch != 0) {
      lep2_passes_id_branch->GetEntry(index);
    } else {
      printf("branch lep2_passes_id_branch does not exist!\n");
      exit(1);
    }
    lep2_passes_id_isLoaded = true;
  }
  return lep2_passes_id_;
}

const bool &SSAG::lep3_passes_id() {
  if (not lep3_passes_id_isLoaded) {
    if (lep3_passes_id_branch != 0) {
      lep3_passes_id_branch->GetEntry(index);
    } else {
      printf("branch lep3_passes_id_branch does not exist!\n");
      exit(1);
    }
    lep3_passes_id_isLoaded = true;
  }
  return lep3_passes_id_;
}

const bool &SSAG::lep4_passes_id() {
  if (not lep4_passes_id_isLoaded) {
    if (lep4_passes_id_branch != 0) {
      lep4_passes_id_branch->GetEntry(index);
    } else {
      printf("branch lep4_passes_id_branch does not exist!\n");
      exit(1);
    }
    lep4_passes_id_isLoaded = true;
  }
  return lep4_passes_id_;
}

const bool &SSAG::lep1_tight() {
  if (not lep1_tight_isLoaded) {
    if (lep1_tight_branch != 0) {
      lep1_tight_branch->GetEntry(index);
    } else {
      printf("branch lep1_tight_branch does not exist!\n");
      exit(1);
    }
    lep1_tight_isLoaded = true;
  }
  return lep1_tight_;
}

const bool &SSAG::lep1_veto() {
  if (not lep1_veto_isLoaded) {
    if (lep1_veto_branch != 0) {
      lep1_veto_branch->GetEntry(index);
    } else {
      printf("branch lep1_veto_branch does not exist!\n");
      exit(1);
    }
    lep1_veto_isLoaded = true;
  }
  return lep1_veto_;
}

const bool &SSAG::lep1_fo() {
  if (not lep1_fo_isLoaded) {
    if (lep1_fo_branch != 0) {
      lep1_fo_branch->GetEntry(index);
    } else {
      printf("branch lep1_fo_branch does not exist!\n");
      exit(1);
    }
    lep1_fo_isLoaded = true;
  }
  return lep1_fo_;
}

const bool &SSAG::lep2_tight() {
  if (not lep2_tight_isLoaded) {
    if (lep2_tight_branch != 0) {
      lep2_tight_branch->GetEntry(index);
    } else {
      printf("branch lep2_tight_branch does not exist!\n");
      exit(1);
    }
    lep2_tight_isLoaded = true;
  }
  return lep2_tight_;
}

const bool &SSAG::lep2_veto() {
  if (not lep2_veto_isLoaded) {
    if (lep2_veto_branch != 0) {
      lep2_veto_branch->GetEntry(index);
    } else {
      printf("branch lep2_veto_branch does not exist!\n");
      exit(1);
    }
    lep2_veto_isLoaded = true;
  }
  return lep2_veto_;
}

const bool &SSAG::lep2_fo() {
  if (not lep2_fo_isLoaded) {
    if (lep2_fo_branch != 0) {
      lep2_fo_branch->GetEntry(index);
    } else {
      printf("branch lep2_fo_branch does not exist!\n");
      exit(1);
    }
    lep2_fo_isLoaded = true;
  }
  return lep2_fo_;
}

const bool &SSAG::lep3_tight() {
  if (not lep3_tight_isLoaded) {
    if (lep3_tight_branch != 0) {
      lep3_tight_branch->GetEntry(index);
    } else {
      printf("branch lep3_tight_branch does not exist!\n");
      exit(1);
    }
    lep3_tight_isLoaded = true;
  }
  return lep3_tight_;
}

const bool &SSAG::lep3_veto() {
  if (not lep3_veto_isLoaded) {
    if (lep3_veto_branch != 0) {
      lep3_veto_branch->GetEntry(index);
    } else {
      printf("branch lep3_veto_branch does not exist!\n");
      exit(1);
    }
    lep3_veto_isLoaded = true;
  }
  return lep3_veto_;
}

const bool &SSAG::lep3_fo() {
  if (not lep3_fo_isLoaded) {
    if (lep3_fo_branch != 0) {
      lep3_fo_branch->GetEntry(index);
    } else {
      printf("branch lep3_fo_branch does not exist!\n");
      exit(1);
    }
    lep3_fo_isLoaded = true;
  }
  return lep3_fo_;
}

const bool &SSAG::lep4_tight() {
  if (not lep4_tight_isLoaded) {
    if (lep4_tight_branch != 0) {
      lep4_tight_branch->GetEntry(index);
    } else {
      printf("branch lep4_tight_branch does not exist!\n");
      exit(1);
    }
    lep4_tight_isLoaded = true;
  }
  return lep4_tight_;
}

const bool &SSAG::lep4_veto() {
  if (not lep4_veto_isLoaded) {
    if (lep4_veto_branch != 0) {
      lep4_veto_branch->GetEntry(index);
    } else {
      printf("branch lep4_veto_branch does not exist!\n");
      exit(1);
    }
    lep4_veto_isLoaded = true;
  }
  return lep4_veto_;
}

const bool &SSAG::lep4_fo() {
  if (not lep4_fo_isLoaded) {
    if (lep4_fo_branch != 0) {
      lep4_fo_branch->GetEntry(index);
    } else {
      printf("branch lep4_fo_branch does not exist!\n");
      exit(1);
    }
    lep4_fo_isLoaded = true;
  }
  return lep4_fo_;
}

const float &SSAG::lep1_dxyPV() {
  if (not lep1_dxyPV_isLoaded) {
    if (lep1_dxyPV_branch != 0) {
      lep1_dxyPV_branch->GetEntry(index);
    } else {
      printf("branch lep1_dxyPV_branch does not exist!\n");
      exit(1);
    }
    lep1_dxyPV_isLoaded = true;
  }
  return lep1_dxyPV_;
}

const float &SSAG::lep2_dxyPV() {
  if (not lep2_dxyPV_isLoaded) {
    if (lep2_dxyPV_branch != 0) {
      lep2_dxyPV_branch->GetEntry(index);
    } else {
      printf("branch lep2_dxyPV_branch does not exist!\n");
      exit(1);
    }
    lep2_dxyPV_isLoaded = true;
  }
  return lep2_dxyPV_;
}

const float &SSAG::lep1_dZ() {
  if (not lep1_dZ_isLoaded) {
    if (lep1_dZ_branch != 0) {
      lep1_dZ_branch->GetEntry(index);
    } else {
      printf("branch lep1_dZ_branch does not exist!\n");
      exit(1);
    }
    lep1_dZ_isLoaded = true;
  }
  return lep1_dZ_;
}

const float &SSAG::lep2_dZ() {
  if (not lep2_dZ_isLoaded) {
    if (lep2_dZ_branch != 0) {
      lep2_dZ_branch->GetEntry(index);
    } else {
      printf("branch lep2_dZ_branch does not exist!\n");
      exit(1);
    }
    lep2_dZ_isLoaded = true;
  }
  return lep2_dZ_;
}

const float &SSAG::lep1_d0_err() {
  if (not lep1_d0_err_isLoaded) {
    if (lep1_d0_err_branch != 0) {
      lep1_d0_err_branch->GetEntry(index);
    } else {
      printf("branch lep1_d0_err_branch does not exist!\n");
      exit(1);
    }
    lep1_d0_err_isLoaded = true;
  }
  return lep1_d0_err_;
}

const float &SSAG::lep2_d0_err() {
  if (not lep2_d0_err_isLoaded) {
    if (lep2_d0_err_branch != 0) {
      lep2_d0_err_branch->GetEntry(index);
    } else {
      printf("branch lep2_d0_err_branch does not exist!\n");
      exit(1);
    }
    lep2_d0_err_isLoaded = true;
  }
  return lep2_d0_err_;
}

const float &SSAG::lep1_ip3d() {
  if (not lep1_ip3d_isLoaded) {
    if (lep1_ip3d_branch != 0) {
      lep1_ip3d_branch->GetEntry(index);
    } else {
      printf("branch lep1_ip3d_branch does not exist!\n");
      exit(1);
    }
    lep1_ip3d_isLoaded = true;
  }
  return lep1_ip3d_;
}

const float &SSAG::lep2_ip3d() {
  if (not lep2_ip3d_isLoaded) {
    if (lep2_ip3d_branch != 0) {
      lep2_ip3d_branch->GetEntry(index);
    } else {
      printf("branch lep2_ip3d_branch does not exist!\n");
      exit(1);
    }
    lep2_ip3d_isLoaded = true;
  }
  return lep2_ip3d_;
}

const float &SSAG::lep1_MVA() {
  if (not lep1_MVA_isLoaded) {
    if (lep1_MVA_branch != 0) {
      lep1_MVA_branch->GetEntry(index);
    } else {
      printf("branch lep1_MVA_branch does not exist!\n");
      exit(1);
    }
    lep1_MVA_isLoaded = true;
  }
  return lep1_MVA_;
}

const float &SSAG::lep2_MVA() {
  if (not lep2_MVA_isLoaded) {
    if (lep2_MVA_branch != 0) {
      lep2_MVA_branch->GetEntry(index);
    } else {
      printf("branch lep2_MVA_branch does not exist!\n");
      exit(1);
    }
    lep2_MVA_isLoaded = true;
  }
  return lep2_MVA_;
}

const float &SSAG::lep1_ip3d_err() {
  if (not lep1_ip3d_err_isLoaded) {
    if (lep1_ip3d_err_branch != 0) {
      lep1_ip3d_err_branch->GetEntry(index);
    } else {
      printf("branch lep1_ip3d_err_branch does not exist!\n");
      exit(1);
    }
    lep1_ip3d_err_isLoaded = true;
  }
  return lep1_ip3d_err_;
}

const float &SSAG::lep2_ip3d_err() {
  if (not lep2_ip3d_err_isLoaded) {
    if (lep2_ip3d_err_branch != 0) {
      lep2_ip3d_err_branch->GetEntry(index);
    } else {
      printf("branch lep2_ip3d_err_branch does not exist!\n");
      exit(1);
    }
    lep2_ip3d_err_isLoaded = true;
  }
  return lep2_ip3d_err_;
}

const int &SSAG::nVetoElectrons7() {
  if (not nVetoElectrons7_isLoaded) {
    if (nVetoElectrons7_branch != 0) {
      nVetoElectrons7_branch->GetEntry(index);
    } else {
      printf("branch nVetoElectrons7_branch does not exist!\n");
      exit(1);
    }
    nVetoElectrons7_isLoaded = true;
  }
  return nVetoElectrons7_;
}

const int &SSAG::nVetoElectrons10() {
  if (not nVetoElectrons10_isLoaded) {
    if (nVetoElectrons10_branch != 0) {
      nVetoElectrons10_branch->GetEntry(index);
    } else {
      printf("branch nVetoElectrons10_branch does not exist!\n");
      exit(1);
    }
    nVetoElectrons10_isLoaded = true;
  }
  return nVetoElectrons10_;
}

const int &SSAG::nVetoElectrons25() {
  if (not nVetoElectrons25_isLoaded) {
    if (nVetoElectrons25_branch != 0) {
      nVetoElectrons25_branch->GetEntry(index);
    } else {
      printf("branch nVetoElectrons25_branch does not exist!\n");
      exit(1);
    }
    nVetoElectrons25_isLoaded = true;
  }
  return nVetoElectrons25_;
}

const int &SSAG::nVetoMuons5() {
  if (not nVetoMuons5_isLoaded) {
    if (nVetoMuons5_branch != 0) {
      nVetoMuons5_branch->GetEntry(index);
    } else {
      printf("branch nVetoMuons5_branch does not exist!\n");
      exit(1);
    }
    nVetoMuons5_isLoaded = true;
  }
  return nVetoMuons5_;
}

const int &SSAG::nVetoMuons10() {
  if (not nVetoMuons10_isLoaded) {
    if (nVetoMuons10_branch != 0) {
      nVetoMuons10_branch->GetEntry(index);
    } else {
      printf("branch nVetoMuons10_branch does not exist!\n");
      exit(1);
    }
    nVetoMuons10_isLoaded = true;
  }
  return nVetoMuons10_;
}

const int &SSAG::nVetoMuons25() {
  if (not nVetoMuons25_isLoaded) {
    if (nVetoMuons25_branch != 0) {
      nVetoMuons25_branch->GetEntry(index);
    } else {
      printf("branch nVetoMuons25_branch does not exist!\n");
      exit(1);
    }
    nVetoMuons25_isLoaded = true;
  }
  return nVetoMuons25_;
}

const string &SSAG::filename() {
  if (not filename_isLoaded) {
    if (filename_branch != 0) {
      filename_branch->GetEntry(index);
    } else {
      printf("branch filename_branch does not exist!\n");
      exit(1);
    }
    filename_isLoaded = true;
  }
  return *filename_;
}

const float &SSAG::lep1_ptrel_ma() {
  if (not lep1_ptrel_ma_isLoaded) {
    if (lep1_ptrel_ma_branch != 0) {
      lep1_ptrel_ma_branch->GetEntry(index);
    } else {
      printf("branch lep1_ptrel_ma_branch does not exist!\n");
      exit(1);
    }
    lep1_ptrel_ma_isLoaded = true;
  }
  return lep1_ptrel_ma_;
}

const float &SSAG::lep1_ptratio_ma() {
  if (not lep1_ptratio_ma_isLoaded) {
    if (lep1_ptratio_ma_branch != 0) {
      lep1_ptratio_ma_branch->GetEntry(index);
    } else {
      printf("branch lep1_ptratio_ma_branch does not exist!\n");
      exit(1);
    }
    lep1_ptratio_ma_isLoaded = true;
  }
  return lep1_ptratio_ma_;
}

const float &SSAG::lep2_ptrel_ma() {
  if (not lep2_ptrel_ma_isLoaded) {
    if (lep2_ptrel_ma_branch != 0) {
      lep2_ptrel_ma_branch->GetEntry(index);
    } else {
      printf("branch lep2_ptrel_ma_branch does not exist!\n");
      exit(1);
    }
    lep2_ptrel_ma_isLoaded = true;
  }
  return lep2_ptrel_ma_;
}

const float &SSAG::lep2_ptratio_ma() {
  if (not lep2_ptratio_ma_isLoaded) {
    if (lep2_ptratio_ma_branch != 0) {
      lep2_ptratio_ma_branch->GetEntry(index);
    } else {
      printf("branch lep2_ptratio_ma_branch does not exist!\n");
      exit(1);
    }
    lep2_ptratio_ma_isLoaded = true;
  }
  return lep2_ptratio_ma_;
}

const float &SSAG::lep1_ptrel_v1() {
  if (not lep1_ptrel_v1_isLoaded) {
    if (lep1_ptrel_v1_branch != 0) {
      lep1_ptrel_v1_branch->GetEntry(index);
    } else {
      printf("branch lep1_ptrel_v1_branch does not exist!\n");
      exit(1);
    }
    lep1_ptrel_v1_isLoaded = true;
  }
  return lep1_ptrel_v1_;
}

const float &SSAG::lep2_ptrel_v1() {
  if (not lep2_ptrel_v1_isLoaded) {
    if (lep2_ptrel_v1_branch != 0) {
      lep2_ptrel_v1_branch->GetEntry(index);
    } else {
      printf("branch lep2_ptrel_v1_branch does not exist!\n");
      exit(1);
    }
    lep2_ptrel_v1_isLoaded = true;
  }
  return lep2_ptrel_v1_;
}

const float &SSAG::lep1_ptratio() {
  if (not lep1_ptratio_isLoaded) {
    if (lep1_ptratio_branch != 0) {
      lep1_ptratio_branch->GetEntry(index);
    } else {
      printf("branch lep1_ptratio_branch does not exist!\n");
      exit(1);
    }
    lep1_ptratio_isLoaded = true;
  }
  return lep1_ptratio_;
}

const float &SSAG::lep2_ptratio() {
  if (not lep2_ptratio_isLoaded) {
    if (lep2_ptratio_branch != 0) {
      lep2_ptratio_branch->GetEntry(index);
    } else {
      printf("branch lep2_ptratio_branch does not exist!\n");
      exit(1);
    }
    lep2_ptratio_isLoaded = true;
  }
  return lep2_ptratio_;
}

const float &SSAG::lep1_miniIso() {
  if (not lep1_miniIso_isLoaded) {
    if (lep1_miniIso_branch != 0) {
      lep1_miniIso_branch->GetEntry(index);
    } else {
      printf("branch lep1_miniIso_branch does not exist!\n");
      exit(1);
    }
    lep1_miniIso_isLoaded = true;
  }
  return lep1_miniIso_;
}

const float &SSAG::lep2_miniIso() {
  if (not lep2_miniIso_isLoaded) {
    if (lep2_miniIso_branch != 0) {
      lep2_miniIso_branch->GetEntry(index);
    } else {
      printf("branch lep2_miniIso_branch does not exist!\n");
      exit(1);
    }
    lep2_miniIso_isLoaded = true;
  }
  return lep2_miniIso_;
}

const vector<float> &SSAG::trueNumInt() {
  if (not trueNumInt_isLoaded) {
    if (trueNumInt_branch != 0) {
      trueNumInt_branch->GetEntry(index);
    } else {
      printf("branch trueNumInt_branch does not exist!\n");
      exit(1);
    }
    trueNumInt_isLoaded = true;
  }
  return *trueNumInt_;
}

const int &SSAG::nGoodVertices() {
  if (not nGoodVertices_isLoaded) {
    if (nGoodVertices_branch != 0) {
      nGoodVertices_branch->GetEntry(index);
    } else {
      printf("branch nGoodVertices_branch does not exist!\n");
      exit(1);
    }
    nGoodVertices_isLoaded = true;
  }
  return nGoodVertices_;
}

const bool &SSAG::lep1_trigMatch_noIsoReq() {
  if (not lep1_trigMatch_noIsoReq_isLoaded) {
    if (lep1_trigMatch_noIsoReq_branch != 0) {
      lep1_trigMatch_noIsoReq_branch->GetEntry(index);
    } else {
      printf("branch lep1_trigMatch_noIsoReq_branch does not exist!\n");
      exit(1);
    }
    lep1_trigMatch_noIsoReq_isLoaded = true;
  }
  return lep1_trigMatch_noIsoReq_;
}

const bool &SSAG::lep1_trigMatch_isoReq() {
  if (not lep1_trigMatch_isoReq_isLoaded) {
    if (lep1_trigMatch_isoReq_branch != 0) {
      lep1_trigMatch_isoReq_branch->GetEntry(index);
    } else {
      printf("branch lep1_trigMatch_isoReq_branch does not exist!\n");
      exit(1);
    }
    lep1_trigMatch_isoReq_isLoaded = true;
  }
  return lep1_trigMatch_isoReq_;
}

const bool &SSAG::lep2_trigMatch_noIsoReq() {
  if (not lep2_trigMatch_noIsoReq_isLoaded) {
    if (lep2_trigMatch_noIsoReq_branch != 0) {
      lep2_trigMatch_noIsoReq_branch->GetEntry(index);
    } else {
      printf("branch lep2_trigMatch_noIsoReq_branch does not exist!\n");
      exit(1);
    }
    lep2_trigMatch_noIsoReq_isLoaded = true;
  }
  return lep2_trigMatch_noIsoReq_;
}

const bool &SSAG::lep2_trigMatch_isoReq() {
  if (not lep2_trigMatch_isoReq_isLoaded) {
    if (lep2_trigMatch_isoReq_branch != 0) {
      lep2_trigMatch_isoReq_branch->GetEntry(index);
    } else {
      printf("branch lep2_trigMatch_isoReq_branch does not exist!\n");
      exit(1);
    }
    lep2_trigMatch_isoReq_isLoaded = true;
  }
  return lep2_trigMatch_isoReq_;
}

const bool &SSAG::passes_met_filters() {
  if (not passes_met_filters_isLoaded) {
    if (passes_met_filters_branch != 0) {
      passes_met_filters_branch->GetEntry(index);
    } else {
      printf("branch passes_met_filters_branch does not exist!\n");
      exit(1);
    }
    passes_met_filters_isLoaded = true;
  }
  return passes_met_filters_;
}

const bool &SSAG::passes_chargedcand_filter() {
  if (not passes_chargedcand_filter_isLoaded) {
    if (passes_chargedcand_filter_branch != 0) {
      passes_chargedcand_filter_branch->GetEntry(index);
    } else {
      printf("branch passes_chargedcand_filter_branch does not exist!\n");
      exit(1);
    }
    passes_chargedcand_filter_isLoaded = true;
  }
  return passes_chargedcand_filter_;
}

const float &SSAG::evt_egclean_pfmet() {
  if (not evt_egclean_pfmet_isLoaded) {
    if (evt_egclean_pfmet_branch != 0) {
      evt_egclean_pfmet_branch->GetEntry(index);
    } else {
      printf("branch evt_egclean_pfmet_branch does not exist!\n");
      exit(1);
    }
    evt_egclean_pfmet_isLoaded = true;
  }
  return evt_egclean_pfmet_;
}

const float &SSAG::evt_muegclean_pfmet() {
  if (not evt_muegclean_pfmet_isLoaded) {
    if (evt_muegclean_pfmet_branch != 0) {
      evt_muegclean_pfmet_branch->GetEntry(index);
    } else {
      printf("branch evt_muegclean_pfmet_branch does not exist!\n");
      exit(1);
    }
    evt_muegclean_pfmet_isLoaded = true;
  }
  return evt_muegclean_pfmet_;
}

const float &SSAG::evt_muegcleanfix_pfmet() {
  if (not evt_muegcleanfix_pfmet_isLoaded) {
    if (evt_muegcleanfix_pfmet_branch != 0) {
      evt_muegcleanfix_pfmet_branch->GetEntry(index);
    } else {
      printf("branch evt_muegcleanfix_pfmet_branch does not exist!\n");
      exit(1);
    }
    evt_muegcleanfix_pfmet_isLoaded = true;
  }
  return evt_muegcleanfix_pfmet_;
}

const float &SSAG::evt_uncorr_pfmet() {
  if (not evt_uncorr_pfmet_isLoaded) {
    if (evt_uncorr_pfmet_branch != 0) {
      evt_uncorr_pfmet_branch->GetEntry(index);
    } else {
      printf("branch evt_uncorr_pfmet_branch does not exist!\n");
      exit(1);
    }
    evt_uncorr_pfmet_isLoaded = true;
  }
  return evt_uncorr_pfmet_;
}

const bool &SSAG::filt_noBadMuons() {
  if (not filt_noBadMuons_isLoaded) {
    if (filt_noBadMuons_branch != 0) {
      filt_noBadMuons_branch->GetEntry(index);
    } else {
      printf("branch filt_noBadMuons_branch does not exist!\n");
      exit(1);
    }
    filt_noBadMuons_isLoaded = true;
  }
  return filt_noBadMuons_;
}

const bool &SSAG::filt_duplicateMuons() {
  if (not filt_duplicateMuons_isLoaded) {
    if (filt_duplicateMuons_branch != 0) {
      filt_duplicateMuons_branch->GetEntry(index);
    } else {
      printf("branch filt_duplicateMuons_branch does not exist!\n");
      exit(1);
    }
    filt_duplicateMuons_isLoaded = true;
  }
  return filt_duplicateMuons_;
}

const bool &SSAG::filt_badMuons() {
  if (not filt_badMuons_isLoaded) {
    if (filt_badMuons_branch != 0) {
      filt_badMuons_branch->GetEntry(index);
    } else {
      printf("branch filt_badMuons_branch does not exist!\n");
      exit(1);
    }
    filt_badMuons_isLoaded = true;
  }
  return filt_badMuons_;
}

const bool &SSAG::failsRA2Filter() {
  if (not failsRA2Filter_isLoaded) {
    if (failsRA2Filter_branch != 0) {
      failsRA2Filter_branch->GetEntry(index);
    } else {
      printf("branch failsRA2Filter_branch does not exist!\n");
      exit(1);
    }
    failsRA2Filter_isLoaded = true;
  }
  return failsRA2Filter_;
}

const bool &SSAG::madeExtraZ() {
  if (not madeExtraZ_isLoaded) {
    if (madeExtraZ_branch != 0) {
      madeExtraZ_branch->GetEntry(index);
    } else {
      printf("branch madeExtraZ_branch does not exist!\n");
      exit(1);
    }
    madeExtraZ_isLoaded = true;
  }
  return madeExtraZ_;
}

const bool &SSAG::madeExtraG() {
  if (not madeExtraG_isLoaded) {
    if (madeExtraG_branch != 0) {
      madeExtraG_branch->GetEntry(index);
    } else {
      printf("branch madeExtraG_branch does not exist!\n");
      exit(1);
    }
    madeExtraG_isLoaded = true;
  }
  return madeExtraG_;
}

const int &SSAG::lep3_mcid() {
  if (not lep3_mcid_isLoaded) {
    if (lep3_mcid_branch != 0) {
      lep3_mcid_branch->GetEntry(index);
    } else {
      printf("branch lep3_mcid_branch does not exist!\n");
      exit(1);
    }
    lep3_mcid_isLoaded = true;
  }
  return lep3_mcid_;
}

const int &SSAG::lep3_mc_motherid() {
  if (not lep3_mc_motherid_isLoaded) {
    if (lep3_mc_motherid_branch != 0) {
      lep3_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch lep3_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    lep3_mc_motherid_isLoaded = true;
  }
  return lep3_mc_motherid_;
}

const int &SSAG::lep3_mc3idx() {
  if (not lep3_mc3idx_isLoaded) {
    if (lep3_mc3idx_branch != 0) {
      lep3_mc3idx_branch->GetEntry(index);
    } else {
      printf("branch lep3_mc3idx_branch does not exist!\n");
      exit(1);
    }
    lep3_mc3idx_isLoaded = true;
  }
  return lep3_mc3idx_;
}

const int &SSAG::lep3_motherID() {
  if (not lep3_motherID_isLoaded) {
    if (lep3_motherID_branch != 0) {
      lep3_motherID_branch->GetEntry(index);
    } else {
      printf("branch lep3_motherID_branch does not exist!\n");
      exit(1);
    }
    lep3_motherID_isLoaded = true;
  }
  return lep3_motherID_;
}

const int &SSAG::lep4_mcid() {
  if (not lep4_mcid_isLoaded) {
    if (lep4_mcid_branch != 0) {
      lep4_mcid_branch->GetEntry(index);
    } else {
      printf("branch lep4_mcid_branch does not exist!\n");
      exit(1);
    }
    lep4_mcid_isLoaded = true;
  }
  return lep4_mcid_;
}

const int &SSAG::lep4_mcidx() {
  if (not lep4_mcidx_isLoaded) {
    if (lep4_mcidx_branch != 0) {
      lep4_mcidx_branch->GetEntry(index);
    } else {
      printf("branch lep4_mcidx_branch does not exist!\n");
      exit(1);
    }
    lep4_mcidx_isLoaded = true;
  }
  return lep4_mcidx_;
}

const int &SSAG::njets_unc_up() {
  if (not njets_unc_up_isLoaded) {
    if (njets_unc_up_branch != 0) {
      njets_unc_up_branch->GetEntry(index);
    } else {
      printf("branch njets_unc_up_branch does not exist!\n");
      exit(1);
    }
    njets_unc_up_isLoaded = true;
  }
  return njets_unc_up_;
}

const int &SSAG::njets_unc_dn() {
  if (not njets_unc_dn_isLoaded) {
    if (njets_unc_dn_branch != 0) {
      njets_unc_dn_branch->GetEntry(index);
    } else {
      printf("branch njets_unc_dn_branch does not exist!\n");
      exit(1);
    }
    njets_unc_dn_isLoaded = true;
  }
  return njets_unc_dn_;
}

const float &SSAG::ht_unc_up() {
  if (not ht_unc_up_isLoaded) {
    if (ht_unc_up_branch != 0) {
      ht_unc_up_branch->GetEntry(index);
    } else {
      printf("branch ht_unc_up_branch does not exist!\n");
      exit(1);
    }
    ht_unc_up_isLoaded = true;
  }
  return ht_unc_up_;
}

const float &SSAG::ht_unc_dn() {
  if (not ht_unc_dn_isLoaded) {
    if (ht_unc_dn_branch != 0) {
      ht_unc_dn_branch->GetEntry(index);
    } else {
      printf("branch ht_unc_dn_branch does not exist!\n");
      exit(1);
    }
    ht_unc_dn_isLoaded = true;
  }
  return ht_unc_dn_;
}

const int &SSAG::nbtags_unc_up() {
  if (not nbtags_unc_up_isLoaded) {
    if (nbtags_unc_up_branch != 0) {
      nbtags_unc_up_branch->GetEntry(index);
    } else {
      printf("branch nbtags_unc_up_branch does not exist!\n");
      exit(1);
    }
    nbtags_unc_up_isLoaded = true;
  }
  return nbtags_unc_up_;
}

const int &SSAG::nbtags_unc_dn() {
  if (not nbtags_unc_dn_isLoaded) {
    if (nbtags_unc_dn_branch != 0) {
      nbtags_unc_dn_branch->GetEntry(index);
    } else {
      printf("branch nbtags_unc_dn_branch does not exist!\n");
      exit(1);
    }
    nbtags_unc_dn_isLoaded = true;
  }
  return nbtags_unc_dn_;
}

const float &SSAG::met_unc_up() {
  if (not met_unc_up_isLoaded) {
    if (met_unc_up_branch != 0) {
      met_unc_up_branch->GetEntry(index);
    } else {
      printf("branch met_unc_up_branch does not exist!\n");
      exit(1);
    }
    met_unc_up_isLoaded = true;
  }
  return met_unc_up_;
}

const float &SSAG::met_unc_dn() {
  if (not met_unc_dn_isLoaded) {
    if (met_unc_dn_branch != 0) {
      met_unc_dn_branch->GetEntry(index);
    } else {
      printf("branch met_unc_dn_branch does not exist!\n");
      exit(1);
    }
    met_unc_dn_isLoaded = true;
  }
  return met_unc_dn_;
}

const float &SSAG::metPhi_unc_up() {
  if (not metPhi_unc_up_isLoaded) {
    if (metPhi_unc_up_branch != 0) {
      metPhi_unc_up_branch->GetEntry(index);
    } else {
      printf("branch metPhi_unc_up_branch does not exist!\n");
      exit(1);
    }
    metPhi_unc_up_isLoaded = true;
  }
  return metPhi_unc_up_;
}

const float &SSAG::metPhi_unc_dn() {
  if (not metPhi_unc_dn_isLoaded) {
    if (metPhi_unc_dn_branch != 0) {
      metPhi_unc_dn_branch->GetEntry(index);
    } else {
      printf("branch metPhi_unc_dn_branch does not exist!\n");
      exit(1);
    }
    metPhi_unc_dn_isLoaded = true;
  }
  return metPhi_unc_dn_;
}

const int &SSAG::njets_JER_up() {
  if (not njets_JER_up_isLoaded) {
    if (njets_JER_up_branch != 0) {
      njets_JER_up_branch->GetEntry(index);
    } else {
      printf("branch njets_JER_up_branch does not exist!\n");
      exit(1);
    }
    njets_JER_up_isLoaded = true;
  }
  return njets_JER_up_;
}

const int &SSAG::njets_JER_dn() {
  if (not njets_JER_dn_isLoaded) {
    if (njets_JER_dn_branch != 0) {
      njets_JER_dn_branch->GetEntry(index);
    } else {
      printf("branch njets_JER_dn_branch does not exist!\n");
      exit(1);
    }
    njets_JER_dn_isLoaded = true;
  }
  return njets_JER_dn_;
}

const float &SSAG::ht_JER_up() {
  if (not ht_JER_up_isLoaded) {
    if (ht_JER_up_branch != 0) {
      ht_JER_up_branch->GetEntry(index);
    } else {
      printf("branch ht_JER_up_branch does not exist!\n");
      exit(1);
    }
    ht_JER_up_isLoaded = true;
  }
  return ht_JER_up_;
}

const float &SSAG::ht_JER_dn() {
  if (not ht_JER_dn_isLoaded) {
    if (ht_JER_dn_branch != 0) {
      ht_JER_dn_branch->GetEntry(index);
    } else {
      printf("branch ht_JER_dn_branch does not exist!\n");
      exit(1);
    }
    ht_JER_dn_isLoaded = true;
  }
  return ht_JER_dn_;
}

const int &SSAG::nbtags_JER_up() {
  if (not nbtags_JER_up_isLoaded) {
    if (nbtags_JER_up_branch != 0) {
      nbtags_JER_up_branch->GetEntry(index);
    } else {
      printf("branch nbtags_JER_up_branch does not exist!\n");
      exit(1);
    }
    nbtags_JER_up_isLoaded = true;
  }
  return nbtags_JER_up_;
}

const int &SSAG::nbtags_JER_dn() {
  if (not nbtags_JER_dn_isLoaded) {
    if (nbtags_JER_dn_branch != 0) {
      nbtags_JER_dn_branch->GetEntry(index);
    } else {
      printf("branch nbtags_JER_dn_branch does not exist!\n");
      exit(1);
    }
    nbtags_JER_dn_isLoaded = true;
  }
  return nbtags_JER_dn_;
}

const float &SSAG::met_JER_up() {
  if (not met_JER_up_isLoaded) {
    if (met_JER_up_branch != 0) {
      met_JER_up_branch->GetEntry(index);
    } else {
      printf("branch met_JER_up_branch does not exist!\n");
      exit(1);
    }
    met_JER_up_isLoaded = true;
  }
  return met_JER_up_;
}

const float &SSAG::met_JER_dn() {
  if (not met_JER_dn_isLoaded) {
    if (met_JER_dn_branch != 0) {
      met_JER_dn_branch->GetEntry(index);
    } else {
      printf("branch met_JER_dn_branch does not exist!\n");
      exit(1);
    }
    met_JER_dn_isLoaded = true;
  }
  return met_JER_dn_;
}

const float &SSAG::metPhi_JER_up() {
  if (not metPhi_JER_up_isLoaded) {
    if (metPhi_JER_up_branch != 0) {
      metPhi_JER_up_branch->GetEntry(index);
    } else {
      printf("branch metPhi_JER_up_branch does not exist!\n");
      exit(1);
    }
    metPhi_JER_up_isLoaded = true;
  }
  return metPhi_JER_up_;
}

const float &SSAG::metPhi_JER_dn() {
  if (not metPhi_JER_dn_isLoaded) {
    if (metPhi_JER_dn_branch != 0) {
      metPhi_JER_dn_branch->GetEntry(index);
    } else {
      printf("branch metPhi_JER_dn_branch does not exist!\n");
      exit(1);
    }
    metPhi_JER_dn_isLoaded = true;
  }
  return metPhi_JER_dn_;
}

const bool &SSAG::lep2_genps_isHardProcess() {
  if (not lep2_genps_isHardProcess_isLoaded) {
    if (lep2_genps_isHardProcess_branch != 0) {
      lep2_genps_isHardProcess_branch->GetEntry(index);
    } else {
      printf("branch lep2_genps_isHardProcess_branch does not exist!\n");
      exit(1);
    }
    lep2_genps_isHardProcess_isLoaded = true;
  }
  return lep2_genps_isHardProcess_;
}

const bool &SSAG::lep2_genps_fromHardProcessFinalState() {
  if (not lep2_genps_fromHardProcessFinalState_isLoaded) {
    if (lep2_genps_fromHardProcessFinalState_branch != 0) {
      lep2_genps_fromHardProcessFinalState_branch->GetEntry(index);
    } else {
      printf("branch lep2_genps_fromHardProcessFinalState_branch does not exist!\n");
      exit(1);
    }
    lep2_genps_fromHardProcessFinalState_isLoaded = true;
  }
  return lep2_genps_fromHardProcessFinalState_;
}

const bool &SSAG::lep2_genps_fromHardProcessDecayed() {
  if (not lep2_genps_fromHardProcessDecayed_isLoaded) {
    if (lep2_genps_fromHardProcessDecayed_branch != 0) {
      lep2_genps_fromHardProcessDecayed_branch->GetEntry(index);
    } else {
      printf("branch lep2_genps_fromHardProcessDecayed_branch does not exist!\n");
      exit(1);
    }
    lep2_genps_fromHardProcessDecayed_isLoaded = true;
  }
  return lep2_genps_fromHardProcessDecayed_;
}

const bool &SSAG::lep2_genps_isDirectHardProcessTauDecayProductFinalState() {
  if (not lep2_genps_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
    if (lep2_genps_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
      lep2_genps_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
    } else {
      printf("branch lep2_genps_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
      exit(1);
    }
    lep2_genps_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
  }
  return lep2_genps_isDirectHardProcessTauDecayProductFinalState_;
}

const bool &SSAG::lep2_genps_fromHardProcessBeforeFSR() {
  if (not lep2_genps_fromHardProcessBeforeFSR_isLoaded) {
    if (lep2_genps_fromHardProcessBeforeFSR_branch != 0) {
      lep2_genps_fromHardProcessBeforeFSR_branch->GetEntry(index);
    } else {
      printf("branch lep2_genps_fromHardProcessBeforeFSR_branch does not exist!\n");
      exit(1);
    }
    lep2_genps_fromHardProcessBeforeFSR_isLoaded = true;
  }
  return lep2_genps_fromHardProcessBeforeFSR_;
}

const bool &SSAG::lep2_genps_isLastCopy() {
  if (not lep2_genps_isLastCopy_isLoaded) {
    if (lep2_genps_isLastCopy_branch != 0) {
      lep2_genps_isLastCopy_branch->GetEntry(index);
    } else {
      printf("branch lep2_genps_isLastCopy_branch does not exist!\n");
      exit(1);
    }
    lep2_genps_isLastCopy_isLoaded = true;
  }
  return lep2_genps_isLastCopy_;
}

const bool &SSAG::lep2_genps_isLastCopyBeforeFSR() {
  if (not lep2_genps_isLastCopyBeforeFSR_isLoaded) {
    if (lep2_genps_isLastCopyBeforeFSR_branch != 0) {
      lep2_genps_isLastCopyBeforeFSR_branch->GetEntry(index);
    } else {
      printf("branch lep2_genps_isLastCopyBeforeFSR_branch does not exist!\n");
      exit(1);
    }
    lep2_genps_isLastCopyBeforeFSR_isLoaded = true;
  }
  return lep2_genps_isLastCopyBeforeFSR_;
}

const bool &SSAG::lep1_genps_isHardProcess() {
  if (not lep1_genps_isHardProcess_isLoaded) {
    if (lep1_genps_isHardProcess_branch != 0) {
      lep1_genps_isHardProcess_branch->GetEntry(index);
    } else {
      printf("branch lep1_genps_isHardProcess_branch does not exist!\n");
      exit(1);
    }
    lep1_genps_isHardProcess_isLoaded = true;
  }
  return lep1_genps_isHardProcess_;
}

const bool &SSAG::lep1_genps_fromHardProcessFinalState() {
  if (not lep1_genps_fromHardProcessFinalState_isLoaded) {
    if (lep1_genps_fromHardProcessFinalState_branch != 0) {
      lep1_genps_fromHardProcessFinalState_branch->GetEntry(index);
    } else {
      printf("branch lep1_genps_fromHardProcessFinalState_branch does not exist!\n");
      exit(1);
    }
    lep1_genps_fromHardProcessFinalState_isLoaded = true;
  }
  return lep1_genps_fromHardProcessFinalState_;
}

const bool &SSAG::lep1_genps_fromHardProcessDecayed() {
  if (not lep1_genps_fromHardProcessDecayed_isLoaded) {
    if (lep1_genps_fromHardProcessDecayed_branch != 0) {
      lep1_genps_fromHardProcessDecayed_branch->GetEntry(index);
    } else {
      printf("branch lep1_genps_fromHardProcessDecayed_branch does not exist!\n");
      exit(1);
    }
    lep1_genps_fromHardProcessDecayed_isLoaded = true;
  }
  return lep1_genps_fromHardProcessDecayed_;
}

const bool &SSAG::lep1_genps_isDirectHardProcessTauDecayProductFinalState() {
  if (not lep1_genps_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
    if (lep1_genps_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
      lep1_genps_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
    } else {
      printf("branch lep1_genps_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
      exit(1);
    }
    lep1_genps_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
  }
  return lep1_genps_isDirectHardProcessTauDecayProductFinalState_;
}

const bool &SSAG::lep1_genps_fromHardProcessBeforeFSR() {
  if (not lep1_genps_fromHardProcessBeforeFSR_isLoaded) {
    if (lep1_genps_fromHardProcessBeforeFSR_branch != 0) {
      lep1_genps_fromHardProcessBeforeFSR_branch->GetEntry(index);
    } else {
      printf("branch lep1_genps_fromHardProcessBeforeFSR_branch does not exist!\n");
      exit(1);
    }
    lep1_genps_fromHardProcessBeforeFSR_isLoaded = true;
  }
  return lep1_genps_fromHardProcessBeforeFSR_;
}

const bool &SSAG::lep1_genps_isLastCopy() {
  if (not lep1_genps_isLastCopy_isLoaded) {
    if (lep1_genps_isLastCopy_branch != 0) {
      lep1_genps_isLastCopy_branch->GetEntry(index);
    } else {
      printf("branch lep1_genps_isLastCopy_branch does not exist!\n");
      exit(1);
    }
    lep1_genps_isLastCopy_isLoaded = true;
  }
  return lep1_genps_isLastCopy_;
}

const bool &SSAG::lep1_genps_isLastCopyBeforeFSR() {
  if (not lep1_genps_isLastCopyBeforeFSR_isLoaded) {
    if (lep1_genps_isLastCopyBeforeFSR_branch != 0) {
      lep1_genps_isLastCopyBeforeFSR_branch->GetEntry(index);
    } else {
      printf("branch lep1_genps_isLastCopyBeforeFSR_branch does not exist!\n");
      exit(1);
    }
    lep1_genps_isLastCopyBeforeFSR_isLoaded = true;
  }
  return lep1_genps_isLastCopyBeforeFSR_;
}

const int &SSAG::lep1_mc3idx() {
  if (not lep1_mc3idx_isLoaded) {
    if (lep1_mc3idx_branch != 0) {
      lep1_mc3idx_branch->GetEntry(index);
    } else {
      printf("branch lep1_mc3idx_branch does not exist!\n");
      exit(1);
    }
    lep1_mc3idx_isLoaded = true;
  }
  return lep1_mc3idx_;
}

const int &SSAG::lep2_mc3idx() {
  if (not lep2_mc3idx_isLoaded) {
    if (lep2_mc3idx_branch != 0) {
      lep2_mc3idx_branch->GetEntry(index);
    } else {
      printf("branch lep2_mc3idx_branch does not exist!\n");
      exit(1);
    }
    lep2_mc3idx_isLoaded = true;
  }
  return lep2_mc3idx_;
}

const bool &SSAG::lep1_el_conv_vtx_flag() {
  if (not lep1_el_conv_vtx_flag_isLoaded) {
    if (lep1_el_conv_vtx_flag_branch != 0) {
      lep1_el_conv_vtx_flag_branch->GetEntry(index);
    } else {
      printf("branch lep1_el_conv_vtx_flag_branch does not exist!\n");
      exit(1);
    }
    lep1_el_conv_vtx_flag_isLoaded = true;
  }
  return lep1_el_conv_vtx_flag_;
}

const bool &SSAG::lep2_el_conv_vtx_flag() {
  if (not lep2_el_conv_vtx_flag_isLoaded) {
    if (lep2_el_conv_vtx_flag_branch != 0) {
      lep2_el_conv_vtx_flag_branch->GetEntry(index);
    } else {
      printf("branch lep2_el_conv_vtx_flag_branch does not exist!\n");
      exit(1);
    }
    lep2_el_conv_vtx_flag_isLoaded = true;
  }
  return lep2_el_conv_vtx_flag_;
}

const int &SSAG::lep1_el_exp_innerlayers() {
  if (not lep1_el_exp_innerlayers_isLoaded) {
    if (lep1_el_exp_innerlayers_branch != 0) {
      lep1_el_exp_innerlayers_branch->GetEntry(index);
    } else {
      printf("branch lep1_el_exp_innerlayers_branch does not exist!\n");
      exit(1);
    }
    lep1_el_exp_innerlayers_isLoaded = true;
  }
  return lep1_el_exp_innerlayers_;
}

const bool &SSAG::lep1_mu_ptErr() {
  if (not lep1_mu_ptErr_isLoaded) {
    if (lep1_mu_ptErr_branch != 0) {
      lep1_mu_ptErr_branch->GetEntry(index);
    } else {
      printf("branch lep1_mu_ptErr_branch does not exist!\n");
      exit(1);
    }
    lep1_mu_ptErr_isLoaded = true;
  }
  return lep1_mu_ptErr_;
}

const bool &SSAG::lep2_mu_ptErr() {
  if (not lep2_mu_ptErr_isLoaded) {
    if (lep2_mu_ptErr_branch != 0) {
      lep2_mu_ptErr_branch->GetEntry(index);
    } else {
      printf("branch lep2_mu_ptErr_branch does not exist!\n");
      exit(1);
    }
    lep2_mu_ptErr_isLoaded = true;
  }
  return lep2_mu_ptErr_;
}

const bool &SSAG::lep1_el_threeChargeAgree() {
  if (not lep1_el_threeChargeAgree_isLoaded) {
    if (lep1_el_threeChargeAgree_branch != 0) {
      lep1_el_threeChargeAgree_branch->GetEntry(index);
    } else {
      printf("branch lep1_el_threeChargeAgree_branch does not exist!\n");
      exit(1);
    }
    lep1_el_threeChargeAgree_isLoaded = true;
  }
  return lep1_el_threeChargeAgree_;
}

const bool &SSAG::lep2_el_threeChargeAgree() {
  if (not lep2_el_threeChargeAgree_isLoaded) {
    if (lep2_el_threeChargeAgree_branch != 0) {
      lep2_el_threeChargeAgree_branch->GetEntry(index);
    } else {
      printf("branch lep2_el_threeChargeAgree_branch does not exist!\n");
      exit(1);
    }
    lep2_el_threeChargeAgree_isLoaded = true;
  }
  return lep2_el_threeChargeAgree_;
}

const int &SSAG::lep2_el_exp_innerlayers() {
  if (not lep2_el_exp_innerlayers_isLoaded) {
    if (lep2_el_exp_innerlayers_branch != 0) {
      lep2_el_exp_innerlayers_branch->GetEntry(index);
    } else {
      printf("branch lep2_el_exp_innerlayers_branch does not exist!\n");
      exit(1);
    }
    lep2_el_exp_innerlayers_isLoaded = true;
  }
  return lep2_el_exp_innerlayers_;
}

const float &SSAG::lep1_el_etaSC() {
  if (not lep1_el_etaSC_isLoaded) {
    if (lep1_el_etaSC_branch != 0) {
      lep1_el_etaSC_branch->GetEntry(index);
    } else {
      printf("branch lep1_el_etaSC_branch does not exist!\n");
      exit(1);
    }
    lep1_el_etaSC_isLoaded = true;
  }
  return lep1_el_etaSC_;
}

const float &SSAG::lep2_el_etaSC() {
  if (not lep2_el_etaSC_isLoaded) {
    if (lep2_el_etaSC_branch != 0) {
      lep2_el_etaSC_branch->GetEntry(index);
    } else {
      printf("branch lep2_el_etaSC_branch does not exist!\n");
      exit(1);
    }
    lep2_el_etaSC_isLoaded = true;
  }
  return lep2_el_etaSC_;
}

const bool &SSAG::lep1_nPixelMiss() {
  if (not lep1_nPixelMiss_isLoaded) {
    if (lep1_nPixelMiss_branch != 0) {
      lep1_nPixelMiss_branch->GetEntry(index);
    } else {
      printf("branch lep1_nPixelMiss_branch does not exist!\n");
      exit(1);
    }
    lep1_nPixelMiss_isLoaded = true;
  }
  return lep1_nPixelMiss_;
}

const bool &SSAG::lep2_nPixelMiss() {
  if (not lep2_nPixelMiss_isLoaded) {
    if (lep2_nPixelMiss_branch != 0) {
      lep2_nPixelMiss_branch->GetEntry(index);
    } else {
      printf("branch lep2_nPixelMiss_branch does not exist!\n");
      exit(1);
    }
    lep2_nPixelMiss_isLoaded = true;
  }
  return lep2_nPixelMiss_;
}

const bool &SSAG::lep1_tightCharge() {
  if (not lep1_tightCharge_isLoaded) {
    if (lep1_tightCharge_branch != 0) {
      lep1_tightCharge_branch->GetEntry(index);
    } else {
      printf("branch lep1_tightCharge_branch does not exist!\n");
      exit(1);
    }
    lep1_tightCharge_isLoaded = true;
  }
  return lep1_tightCharge_;
}

const bool &SSAG::lep2_tightCharge() {
  if (not lep2_tightCharge_isLoaded) {
    if (lep2_tightCharge_branch != 0) {
      lep2_tightCharge_branch->GetEntry(index);
    } else {
      printf("branch lep2_tightCharge_branch does not exist!\n");
      exit(1);
    }
    lep2_tightCharge_isLoaded = true;
  }
  return lep2_tightCharge_;
}

const bool &SSAG::lep1_isTrigSafeNoIsov1() {
  if (not lep1_isTrigSafeNoIsov1_isLoaded) {
    if (lep1_isTrigSafeNoIsov1_branch != 0) {
      lep1_isTrigSafeNoIsov1_branch->GetEntry(index);
    } else {
      printf("branch lep1_isTrigSafeNoIsov1_branch does not exist!\n");
      exit(1);
    }
    lep1_isTrigSafeNoIsov1_isLoaded = true;
  }
  return lep1_isTrigSafeNoIsov1_;
}

const bool &SSAG::lep1_isTrigSafev1() {
  if (not lep1_isTrigSafev1_isLoaded) {
    if (lep1_isTrigSafev1_branch != 0) {
      lep1_isTrigSafev1_branch->GetEntry(index);
    } else {
      printf("branch lep1_isTrigSafev1_branch does not exist!\n");
      exit(1);
    }
    lep1_isTrigSafev1_isLoaded = true;
  }
  return lep1_isTrigSafev1_;
}

const bool &SSAG::lep2_isTrigSafeNoIsov1() {
  if (not lep2_isTrigSafeNoIsov1_isLoaded) {
    if (lep2_isTrigSafeNoIsov1_branch != 0) {
      lep2_isTrigSafeNoIsov1_branch->GetEntry(index);
    } else {
      printf("branch lep2_isTrigSafeNoIsov1_branch does not exist!\n");
      exit(1);
    }
    lep2_isTrigSafeNoIsov1_isLoaded = true;
  }
  return lep2_isTrigSafeNoIsov1_;
}

const bool &SSAG::lep2_isTrigSafev1() {
  if (not lep2_isTrigSafev1_isLoaded) {
    if (lep2_isTrigSafev1_branch != 0) {
      lep2_isTrigSafev1_branch->GetEntry(index);
    } else {
      printf("branch lep2_isTrigSafev1_branch does not exist!\n");
      exit(1);
    }
    lep2_isTrigSafev1_isLoaded = true;
  }
  return lep2_isTrigSafev1_;
}

const bool &SSAG::lep1_tightMuonPOG() {
  if (not lep1_tightMuonPOG_isLoaded) {
    if (lep1_tightMuonPOG_branch != 0) {
      lep1_tightMuonPOG_branch->GetEntry(index);
    } else {
      printf("branch lep1_tightMuonPOG_branch does not exist!\n");
      exit(1);
    }
    lep1_tightMuonPOG_isLoaded = true;
  }
  return lep1_tightMuonPOG_;
}

const bool &SSAG::lep1_mediumMuonPOG() {
  if (not lep1_mediumMuonPOG_isLoaded) {
    if (lep1_mediumMuonPOG_branch != 0) {
      lep1_mediumMuonPOG_branch->GetEntry(index);
    } else {
      printf("branch lep1_mediumMuonPOG_branch does not exist!\n");
      exit(1);
    }
    lep1_mediumMuonPOG_isLoaded = true;
  }
  return lep1_mediumMuonPOG_;
}

const bool &SSAG::lep1_looseMuonPOG() {
  if (not lep1_looseMuonPOG_isLoaded) {
    if (lep1_looseMuonPOG_branch != 0) {
      lep1_looseMuonPOG_branch->GetEntry(index);
    } else {
      printf("branch lep1_looseMuonPOG_branch does not exist!\n");
      exit(1);
    }
    lep1_looseMuonPOG_isLoaded = true;
  }
  return lep1_looseMuonPOG_;
}

const bool &SSAG::lep2_tightMuonPOG() {
  if (not lep2_tightMuonPOG_isLoaded) {
    if (lep2_tightMuonPOG_branch != 0) {
      lep2_tightMuonPOG_branch->GetEntry(index);
    } else {
      printf("branch lep2_tightMuonPOG_branch does not exist!\n");
      exit(1);
    }
    lep2_tightMuonPOG_isLoaded = true;
  }
  return lep2_tightMuonPOG_;
}

const bool &SSAG::lep2_mediumMuonPOG() {
  if (not lep2_mediumMuonPOG_isLoaded) {
    if (lep2_mediumMuonPOG_branch != 0) {
      lep2_mediumMuonPOG_branch->GetEntry(index);
    } else {
      printf("branch lep2_mediumMuonPOG_branch does not exist!\n");
      exit(1);
    }
    lep2_mediumMuonPOG_isLoaded = true;
  }
  return lep2_mediumMuonPOG_;
}

const bool &SSAG::lep2_looseMuonPOG() {
  if (not lep2_looseMuonPOG_isLoaded) {
    if (lep2_looseMuonPOG_branch != 0) {
      lep2_looseMuonPOG_branch->GetEntry(index);
    } else {
      printf("branch lep2_looseMuonPOG_branch does not exist!\n");
      exit(1);
    }
    lep2_looseMuonPOG_isLoaded = true;
  }
  return lep2_looseMuonPOG_;
}

const bool &SSAG::lep3_mediumMuonPOG() {
  if (not lep3_mediumMuonPOG_isLoaded) {
    if (lep3_mediumMuonPOG_branch != 0) {
      lep3_mediumMuonPOG_branch->GetEntry(index);
    } else {
      printf("branch lep3_mediumMuonPOG_branch does not exist!\n");
      exit(1);
    }
    lep3_mediumMuonPOG_isLoaded = true;
  }
  return lep3_mediumMuonPOG_;
}

const float &SSAG::prefire_sf() {
  if (not prefire_sf_isLoaded) {
    if (prefire_sf_branch != 0) {
      prefire_sf_branch->GetEntry(index);
    } else {
      printf("branch prefire_sf_branch does not exist!\n");
      exit(1);
    }
    prefire_sf_isLoaded = true;
  }
  return prefire_sf_;
}

const float &SSAG::prefire_sfup() {
  if (not prefire_sfup_isLoaded) {
    if (prefire_sfup_branch != 0) {
      prefire_sfup_branch->GetEntry(index);
    } else {
      printf("branch prefire_sfup_branch does not exist!\n");
      exit(1);
    }
    prefire_sfup_isLoaded = true;
  }
  return prefire_sfup_;
}

const float &SSAG::prefire_sfdown() {
  if (not prefire_sfdown_isLoaded) {
    if (prefire_sfdown_branch != 0) {
      prefire_sfdown_branch->GetEntry(index);
    } else {
      printf("branch prefire_sfdown_branch does not exist!\n");
      exit(1);
    }
    prefire_sfdown_isLoaded = true;
  }
  return prefire_sfdown_;
}

const float &SSAG::prefire2016_sf() {
  if (not prefire2016_sf_isLoaded) {
    if (prefire2016_sf_branch != 0) {
      prefire2016_sf_branch->GetEntry(index);
    } else {
      printf("branch prefire2016_sf_branch does not exist!\n");
      exit(1);
    }
    prefire2016_sf_isLoaded = true;
  }
  return prefire2016_sf_;
}

const float &SSAG::prefire2016_sfup() {
  if (not prefire2016_sfup_isLoaded) {
    if (prefire2016_sfup_branch != 0) {
      prefire2016_sfup_branch->GetEntry(index);
    } else {
      printf("branch prefire2016_sfup_branch does not exist!\n");
      exit(1);
    }
    prefire2016_sfup_isLoaded = true;
  }
  return prefire2016_sfup_;
}

const float &SSAG::prefire2016_sfdown() {
  if (not prefire2016_sfdown_isLoaded) {
    if (prefire2016_sfdown_branch != 0) {
      prefire2016_sfdown_branch->GetEntry(index);
    } else {
      printf("branch prefire2016_sfdown_branch does not exist!\n");
      exit(1);
    }
    prefire2016_sfdown_isLoaded = true;
  }
  return prefire2016_sfdown_;
}

const float &SSAG::prefire2017_sf() {
  if (not prefire2017_sf_isLoaded) {
    if (prefire2017_sf_branch != 0) {
      prefire2017_sf_branch->GetEntry(index);
    } else {
      printf("branch prefire2017_sf_branch does not exist!\n");
      exit(1);
    }
    prefire2017_sf_isLoaded = true;
  }
  return prefire2017_sf_;
}

const float &SSAG::prefire2017_sfup() {
  if (not prefire2017_sfup_isLoaded) {
    if (prefire2017_sfup_branch != 0) {
      prefire2017_sfup_branch->GetEntry(index);
    } else {
      printf("branch prefire2017_sfup_branch does not exist!\n");
      exit(1);
    }
    prefire2017_sfup_isLoaded = true;
  }
  return prefire2017_sfup_;
}

const float &SSAG::prefire2017_sfdown() {
  if (not prefire2017_sfdown_isLoaded) {
    if (prefire2017_sfdown_branch != 0) {
      prefire2017_sfdown_branch->GetEntry(index);
    } else {
      printf("branch prefire2017_sfdown_branch does not exist!\n");
      exit(1);
    }
    prefire2017_sfdown_isLoaded = true;
  }
  return prefire2017_sfdown_;
}

const float &SSAG::prefire2017ele_sf() {
  if (not prefire2017ele_sf_isLoaded) {
    if (prefire2017ele_sf_branch != 0) {
      prefire2017ele_sf_branch->GetEntry(index);
    } else {
      printf("branch prefire2017ele_sf_branch does not exist!\n");
      exit(1);
    }
    prefire2017ele_sf_isLoaded = true;
  }
  return prefire2017ele_sf_;
}

const float &SSAG::prefire2017ele_sfup() {
  if (not prefire2017ele_sfup_isLoaded) {
    if (prefire2017ele_sfup_branch != 0) {
      prefire2017ele_sfup_branch->GetEntry(index);
    } else {
      printf("branch prefire2017ele_sfup_branch does not exist!\n");
      exit(1);
    }
    prefire2017ele_sfup_isLoaded = true;
  }
  return prefire2017ele_sfup_;
}

const float &SSAG::prefire2017ele_sfdown() {
  if (not prefire2017ele_sfdown_isLoaded) {
    if (prefire2017ele_sfdown_branch != 0) {
      prefire2017ele_sfdown_branch->GetEntry(index);
    } else {
      printf("branch prefire2017ele_sfdown_branch does not exist!\n");
      exit(1);
    }
    prefire2017ele_sfdown_isLoaded = true;
  }
  return prefire2017ele_sfdown_;
}

const bool &SSAG::is_fastsim() {
  if (not is_fastsim_isLoaded) {
    if (is_fastsim_branch != 0) {
      is_fastsim_branch->GetEntry(index);
    } else {
      printf("branch is_fastsim_branch does not exist!\n");
      exit(1);
    }
    is_fastsim_isLoaded = true;
  }
  return is_fastsim_;
}

const bool &SSAG::lep1_isGoodLeg() {
  if (not lep1_isGoodLeg_isLoaded) {
    if (lep1_isGoodLeg_branch != 0) {
      lep1_isGoodLeg_branch->GetEntry(index);
    } else {
      printf("branch lep1_isGoodLeg_branch does not exist!\n");
      exit(1);
    }
    lep1_isGoodLeg_isLoaded = true;
  }
  return lep1_isGoodLeg_;
}

const bool &SSAG::lep2_isGoodLeg() {
  if (not lep2_isGoodLeg_isLoaded) {
    if (lep2_isGoodLeg_branch != 0) {
      lep2_isGoodLeg_branch->GetEntry(index);
    } else {
      printf("branch lep2_isGoodLeg_branch does not exist!\n");
      exit(1);
    }
    lep2_isGoodLeg_isLoaded = true;
  }
  return lep2_isGoodLeg_;
}

const bool &SSAG::lep1_isFakeLeg() {
  if (not lep1_isFakeLeg_isLoaded) {
    if (lep1_isFakeLeg_branch != 0) {
      lep1_isFakeLeg_branch->GetEntry(index);
    } else {
      printf("branch lep1_isFakeLeg_branch does not exist!\n");
      exit(1);
    }
    lep1_isFakeLeg_isLoaded = true;
  }
  return lep1_isFakeLeg_;
}

const bool &SSAG::lep2_isFakeLeg() {
  if (not lep2_isFakeLeg_isLoaded) {
    if (lep2_isFakeLeg_branch != 0) {
      lep2_isFakeLeg_branch->GetEntry(index);
    } else {
      printf("branch lep2_isFakeLeg_branch does not exist!\n");
      exit(1);
    }
    lep2_isFakeLeg_isLoaded = true;
  }
  return lep2_isFakeLeg_;
}

const bool &SSAG::lep1_multiIso() {
  if (not lep1_multiIso_isLoaded) {
    if (lep1_multiIso_branch != 0) {
      lep1_multiIso_branch->GetEntry(index);
    } else {
      printf("branch lep1_multiIso_branch does not exist!\n");
      exit(1);
    }
    lep1_multiIso_isLoaded = true;
  }
  return lep1_multiIso_;
}

const bool &SSAG::lep2_multiIso() {
  if (not lep2_multiIso_isLoaded) {
    if (lep2_multiIso_branch != 0) {
      lep2_multiIso_branch->GetEntry(index);
    } else {
      printf("branch lep2_multiIso_branch does not exist!\n");
      exit(1);
    }
    lep2_multiIso_isLoaded = true;
  }
  return lep2_multiIso_;
}

const float &SSAG::lep1_sip() {
  if (not lep1_sip_isLoaded) {
    if (lep1_sip_branch != 0) {
      lep1_sip_branch->GetEntry(index);
    } else {
      printf("branch lep1_sip_branch does not exist!\n");
      exit(1);
    }
    lep1_sip_isLoaded = true;
  }
  return lep1_sip_;
}

const float &SSAG::lep2_sip() {
  if (not lep2_sip_isLoaded) {
    if (lep2_sip_branch != 0) {
      lep2_sip_branch->GetEntry(index);
    } else {
      printf("branch lep2_sip_branch does not exist!\n");
      exit(1);
    }
    lep2_sip_isLoaded = true;
  }
  return lep2_sip_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::lep1_closeJet() {
  if (not lep1_closeJet_isLoaded) {
    if (lep1_closeJet_branch != 0) {
      lep1_closeJet_branch->GetEntry(index);
    } else {
      printf("branch lep1_closeJet_branch does not exist!\n");
      exit(1);
    }
    lep1_closeJet_isLoaded = true;
  }
  return *lep1_closeJet_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::lep2_closeJet() {
  if (not lep2_closeJet_isLoaded) {
    if (lep2_closeJet_branch != 0) {
      lep2_closeJet_branch->GetEntry(index);
    } else {
      printf("branch lep2_closeJet_branch does not exist!\n");
      exit(1);
    }
    lep2_closeJet_isLoaded = true;
  }
  return *lep2_closeJet_;
}

const bool &SSAG::passed_id_inSituFR_lep1() {
  if (not passed_id_inSituFR_lep1_isLoaded) {
    if (passed_id_inSituFR_lep1_branch != 0) {
      passed_id_inSituFR_lep1_branch->GetEntry(index);
    } else {
      printf("branch passed_id_inSituFR_lep1_branch does not exist!\n");
      exit(1);
    }
    passed_id_inSituFR_lep1_isLoaded = true;
  }
  return passed_id_inSituFR_lep1_;
}

const bool &SSAG::passed_id_inSituFR_lep2() {
  if (not passed_id_inSituFR_lep2_isLoaded) {
    if (passed_id_inSituFR_lep2_branch != 0) {
      passed_id_inSituFR_lep2_branch->GetEntry(index);
    } else {
      printf("branch passed_id_inSituFR_lep2_branch does not exist!\n");
      exit(1);
    }
    passed_id_inSituFR_lep2_isLoaded = true;
  }
  return passed_id_inSituFR_lep2_;
}

const bool &SSAG::fired_trigger() {
  if (not fired_trigger_isLoaded) {
    if (fired_trigger_branch != 0) {
      fired_trigger_branch->GetEntry(index);
    } else {
      printf("branch fired_trigger_branch does not exist!\n");
      exit(1);
    }
    fired_trigger_isLoaded = true;
  }
  return fired_trigger_;
}

const bool &SSAG::fired_trigger_ss() {
  if (not fired_trigger_ss_isLoaded) {
    if (fired_trigger_ss_branch != 0) {
      fired_trigger_ss_branch->GetEntry(index);
    } else {
      printf("branch fired_trigger_ss_branch does not exist!\n");
      exit(1);
    }
    fired_trigger_ss_isLoaded = true;
  }
  return fired_trigger_ss_;
}

const unsigned int &SSAG::triggers() {
  if (not triggers_isLoaded) {
    if (triggers_branch != 0) {
      triggers_branch->GetEntry(index);
    } else {
      printf("branch triggers_branch does not exist!\n");
      exit(1);
    }
    triggers_isLoaded = true;
  }
  return triggers_;
}

const float &SSAG::weight_btagsf() {
  if (not weight_btagsf_isLoaded) {
    if (weight_btagsf_branch != 0) {
      weight_btagsf_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_isLoaded = true;
  }
  return weight_btagsf_;
}

const float &SSAG::weight_btagsf_light_UP() {
  if (not weight_btagsf_light_UP_isLoaded) {
    if (weight_btagsf_light_UP_branch != 0) {
      weight_btagsf_light_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_light_UP_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_light_UP_isLoaded = true;
  }
  return weight_btagsf_light_UP_;
}

const float &SSAG::weight_btagsf_light_DN() {
  if (not weight_btagsf_light_DN_isLoaded) {
    if (weight_btagsf_light_DN_branch != 0) {
      weight_btagsf_light_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_light_DN_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_light_DN_isLoaded = true;
  }
  return weight_btagsf_light_DN_;
}

const float &SSAG::weight_btagsf_heavy_UP() {
  if (not weight_btagsf_heavy_UP_isLoaded) {
    if (weight_btagsf_heavy_UP_branch != 0) {
      weight_btagsf_heavy_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_heavy_UP_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_heavy_UP_isLoaded = true;
  }
  return weight_btagsf_heavy_UP_;
}

const float &SSAG::weight_btagsf_heavy_DN() {
  if (not weight_btagsf_heavy_DN_isLoaded) {
    if (weight_btagsf_heavy_DN_branch != 0) {
      weight_btagsf_heavy_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_heavy_DN_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_heavy_DN_isLoaded = true;
  }
  return weight_btagsf_heavy_DN_;
}

const float &SSAG::weight_btagsf_iter_central() {
  if (not weight_btagsf_iter_central_isLoaded) {
    if (weight_btagsf_iter_central_branch != 0) {
      weight_btagsf_iter_central_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_central_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_central_isLoaded = true;
  }
  return weight_btagsf_iter_central_;
}

const float &SSAG::weight_btagsf_iter_down_cferr1() {
  if (not weight_btagsf_iter_down_cferr1_isLoaded) {
    if (weight_btagsf_iter_down_cferr1_branch != 0) {
      weight_btagsf_iter_down_cferr1_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_cferr1_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_cferr1_isLoaded = true;
  }
  return weight_btagsf_iter_down_cferr1_;
}

const float &SSAG::weight_btagsf_iter_down_cferr2() {
  if (not weight_btagsf_iter_down_cferr2_isLoaded) {
    if (weight_btagsf_iter_down_cferr2_branch != 0) {
      weight_btagsf_iter_down_cferr2_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_cferr2_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_cferr2_isLoaded = true;
  }
  return weight_btagsf_iter_down_cferr2_;
}

const float &SSAG::weight_btagsf_iter_down_hf() {
  if (not weight_btagsf_iter_down_hf_isLoaded) {
    if (weight_btagsf_iter_down_hf_branch != 0) {
      weight_btagsf_iter_down_hf_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_hf_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_hf_isLoaded = true;
  }
  return weight_btagsf_iter_down_hf_;
}

const float &SSAG::weight_btagsf_iter_down_hfstats1() {
  if (not weight_btagsf_iter_down_hfstats1_isLoaded) {
    if (weight_btagsf_iter_down_hfstats1_branch != 0) {
      weight_btagsf_iter_down_hfstats1_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_hfstats1_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_hfstats1_isLoaded = true;
  }
  return weight_btagsf_iter_down_hfstats1_;
}

const float &SSAG::weight_btagsf_iter_down_hfstats2() {
  if (not weight_btagsf_iter_down_hfstats2_isLoaded) {
    if (weight_btagsf_iter_down_hfstats2_branch != 0) {
      weight_btagsf_iter_down_hfstats2_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_hfstats2_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_hfstats2_isLoaded = true;
  }
  return weight_btagsf_iter_down_hfstats2_;
}

const float &SSAG::weight_btagsf_iter_down_jes() {
  if (not weight_btagsf_iter_down_jes_isLoaded) {
    if (weight_btagsf_iter_down_jes_branch != 0) {
      weight_btagsf_iter_down_jes_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_jes_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_jes_isLoaded = true;
  }
  return weight_btagsf_iter_down_jes_;
}

const float &SSAG::weight_btagsf_iter_down_lf() {
  if (not weight_btagsf_iter_down_lf_isLoaded) {
    if (weight_btagsf_iter_down_lf_branch != 0) {
      weight_btagsf_iter_down_lf_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_lf_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_lf_isLoaded = true;
  }
  return weight_btagsf_iter_down_lf_;
}

const float &SSAG::weight_btagsf_iter_down_lfstats1() {
  if (not weight_btagsf_iter_down_lfstats1_isLoaded) {
    if (weight_btagsf_iter_down_lfstats1_branch != 0) {
      weight_btagsf_iter_down_lfstats1_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_lfstats1_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_lfstats1_isLoaded = true;
  }
  return weight_btagsf_iter_down_lfstats1_;
}

const float &SSAG::weight_btagsf_iter_down_lfstats2() {
  if (not weight_btagsf_iter_down_lfstats2_isLoaded) {
    if (weight_btagsf_iter_down_lfstats2_branch != 0) {
      weight_btagsf_iter_down_lfstats2_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_down_lfstats2_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_down_lfstats2_isLoaded = true;
  }
  return weight_btagsf_iter_down_lfstats2_;
}

const float &SSAG::weight_btagsf_iter_up_cferr1() {
  if (not weight_btagsf_iter_up_cferr1_isLoaded) {
    if (weight_btagsf_iter_up_cferr1_branch != 0) {
      weight_btagsf_iter_up_cferr1_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_cferr1_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_cferr1_isLoaded = true;
  }
  return weight_btagsf_iter_up_cferr1_;
}

const float &SSAG::weight_btagsf_iter_up_cferr2() {
  if (not weight_btagsf_iter_up_cferr2_isLoaded) {
    if (weight_btagsf_iter_up_cferr2_branch != 0) {
      weight_btagsf_iter_up_cferr2_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_cferr2_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_cferr2_isLoaded = true;
  }
  return weight_btagsf_iter_up_cferr2_;
}

const float &SSAG::weight_btagsf_iter_up_hf() {
  if (not weight_btagsf_iter_up_hf_isLoaded) {
    if (weight_btagsf_iter_up_hf_branch != 0) {
      weight_btagsf_iter_up_hf_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_hf_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_hf_isLoaded = true;
  }
  return weight_btagsf_iter_up_hf_;
}

const float &SSAG::weight_btagsf_iter_up_hfstats1() {
  if (not weight_btagsf_iter_up_hfstats1_isLoaded) {
    if (weight_btagsf_iter_up_hfstats1_branch != 0) {
      weight_btagsf_iter_up_hfstats1_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_hfstats1_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_hfstats1_isLoaded = true;
  }
  return weight_btagsf_iter_up_hfstats1_;
}

const float &SSAG::weight_btagsf_iter_up_hfstats2() {
  if (not weight_btagsf_iter_up_hfstats2_isLoaded) {
    if (weight_btagsf_iter_up_hfstats2_branch != 0) {
      weight_btagsf_iter_up_hfstats2_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_hfstats2_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_hfstats2_isLoaded = true;
  }
  return weight_btagsf_iter_up_hfstats2_;
}

const float &SSAG::weight_btagsf_iter_up_jes() {
  if (not weight_btagsf_iter_up_jes_isLoaded) {
    if (weight_btagsf_iter_up_jes_branch != 0) {
      weight_btagsf_iter_up_jes_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_jes_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_jes_isLoaded = true;
  }
  return weight_btagsf_iter_up_jes_;
}

const float &SSAG::weight_btagsf_iter_up_lf() {
  if (not weight_btagsf_iter_up_lf_isLoaded) {
    if (weight_btagsf_iter_up_lf_branch != 0) {
      weight_btagsf_iter_up_lf_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_lf_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_lf_isLoaded = true;
  }
  return weight_btagsf_iter_up_lf_;
}

const float &SSAG::weight_btagsf_iter_up_lfstats1() {
  if (not weight_btagsf_iter_up_lfstats1_isLoaded) {
    if (weight_btagsf_iter_up_lfstats1_branch != 0) {
      weight_btagsf_iter_up_lfstats1_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_lfstats1_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_lfstats1_isLoaded = true;
  }
  return weight_btagsf_iter_up_lfstats1_;
}

const float &SSAG::weight_btagsf_iter_up_lfstats2() {
  if (not weight_btagsf_iter_up_lfstats2_isLoaded) {
    if (weight_btagsf_iter_up_lfstats2_branch != 0) {
      weight_btagsf_iter_up_lfstats2_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_iter_up_lfstats2_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_iter_up_lfstats2_isLoaded = true;
  }
  return weight_btagsf_iter_up_lfstats2_;
}

const float &SSAG::weight() {
  if (not weight_isLoaded) {
    if (weight_branch != 0) {
      weight_branch->GetEntry(index);
    } else {
      printf("branch weight_branch does not exist!\n");
      exit(1);
    }
    weight_isLoaded = true;
  }
  return weight_;
}

const float &SSAG::weight_lepsf1() {
  if (not weight_lepsf1_isLoaded) {
    if (weight_lepsf1_branch != 0) {
      weight_lepsf1_branch->GetEntry(index);
    } else {
      printf("branch weight_lepsf1_branch does not exist!\n");
      exit(1);
    }
    weight_lepsf1_isLoaded = true;
  }
  return weight_lepsf1_;
}

const float &SSAG::weight_lepsf2() {
  if (not weight_lepsf2_isLoaded) {
    if (weight_lepsf2_branch != 0) {
      weight_lepsf2_branch->GetEntry(index);
    } else {
      printf("branch weight_lepsf2_branch does not exist!\n");
      exit(1);
    }
    weight_lepsf2_isLoaded = true;
  }
  return weight_lepsf2_;
}

const float &SSAG::weight_lepsf3() {
  if (not weight_lepsf3_isLoaded) {
    if (weight_lepsf3_branch != 0) {
      weight_lepsf3_branch->GetEntry(index);
    } else {
      printf("branch weight_lepsf3_branch does not exist!\n");
      exit(1);
    }
    weight_lepsf3_isLoaded = true;
  }
  return weight_lepsf3_;
}

const float &SSAG::weight_lepsf() {
  if (not weight_lepsf_isLoaded) {
    if (weight_lepsf_branch != 0) {
      weight_lepsf_branch->GetEntry(index);
    } else {
      printf("branch weight_lepsf_branch does not exist!\n");
      exit(1);
    }
    weight_lepsf_isLoaded = true;
  }
  return weight_lepsf_;
}

const float &SSAG::weight_triggersf() {
  if (not weight_triggersf_isLoaded) {
    if (weight_triggersf_branch != 0) {
      weight_triggersf_branch->GetEntry(index);
    } else {
      printf("branch weight_triggersf_branch does not exist!\n");
      exit(1);
    }
    weight_triggersf_isLoaded = true;
  }
  return weight_triggersf_;
}

const float &SSAG::weight_pu() {
  if (not weight_pu_isLoaded) {
    if (weight_pu_branch != 0) {
      weight_pu_branch->GetEntry(index);
    } else {
      printf("branch weight_pu_branch does not exist!\n");
      exit(1);
    }
    weight_pu_isLoaded = true;
  }
  return weight_pu_;
}

const float &SSAG::weight_isrsf() {
  if (not weight_isrsf_isLoaded) {
    if (weight_isrsf_branch != 0) {
      weight_isrsf_branch->GetEntry(index);
    } else {
      printf("branch weight_isrsf_branch does not exist!\n");
      exit(1);
    }
    weight_isrsf_isLoaded = true;
  }
  return weight_isrsf_;
}

const int &SSAG::year() {
  if (not year_isLoaded) {
    if (year_branch != 0) {
      year_branch->GetEntry(index);
    } else {
      printf("branch year_branch does not exist!\n");
      exit(1);
    }
    year_isLoaded = true;
  }
  return year_;
}

const float &SSAG::yearlumi() {
  if (not yearlumi_isLoaded) {
    if (yearlumi_branch != 0) {
      yearlumi_branch->GetEntry(index);
    } else {
      printf("branch yearlumi_branch does not exist!\n");
      exit(1);
    }
    yearlumi_isLoaded = true;
  }
  return yearlumi_;
}

const float &SSAG::weight_scale_UP() {
  if (not weight_scale_UP_isLoaded) {
    if (weight_scale_UP_branch != 0) {
      weight_scale_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_scale_UP_branch does not exist!\n");
      exit(1);
    }
    weight_scale_UP_isLoaded = true;
  }
  return weight_scale_UP_;
}

const float &SSAG::weight_scale_DN() {
  if (not weight_scale_DN_isLoaded) {
    if (weight_scale_DN_branch != 0) {
      weight_scale_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_scale_DN_branch does not exist!\n");
      exit(1);
    }
    weight_scale_DN_isLoaded = true;
  }
  return weight_scale_DN_;
}

const float &SSAG::weight_pdf_UP() {
  if (not weight_pdf_UP_isLoaded) {
    if (weight_pdf_UP_branch != 0) {
      weight_pdf_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_pdf_UP_branch does not exist!\n");
      exit(1);
    }
    weight_pdf_UP_isLoaded = true;
  }
  return weight_pdf_UP_;
}

const float &SSAG::weight_pdf_DN() {
  if (not weight_pdf_DN_isLoaded) {
    if (weight_pdf_DN_branch != 0) {
      weight_pdf_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_pdf_DN_branch does not exist!\n");
      exit(1);
    }
    weight_pdf_DN_isLoaded = true;
  }
  return weight_pdf_DN_;
}

const float &SSAG::weight_alphas_UP() {
  if (not weight_alphas_UP_isLoaded) {
    if (weight_alphas_UP_branch != 0) {
      weight_alphas_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_alphas_UP_branch does not exist!\n");
      exit(1);
    }
    weight_alphas_UP_isLoaded = true;
  }
  return weight_alphas_UP_;
}

const float &SSAG::weight_alphas_DN() {
  if (not weight_alphas_DN_isLoaded) {
    if (weight_alphas_DN_branch != 0) {
      weight_alphas_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_alphas_DN_branch does not exist!\n");
      exit(1);
    }
    weight_alphas_DN_isLoaded = true;
  }
  return weight_alphas_DN_;
}

const float &SSAG::weight_isrvar_UP() {
  if (not weight_isrvar_UP_isLoaded) {
    if (weight_isrvar_UP_branch != 0) {
      weight_isrvar_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_isrvar_UP_branch does not exist!\n");
      exit(1);
    }
    weight_isrvar_UP_isLoaded = true;
  }
  return weight_isrvar_UP_;
}

const float &SSAG::weight_isrvar_DN() {
  if (not weight_isrvar_DN_isLoaded) {
    if (weight_isrvar_DN_branch != 0) {
      weight_isrvar_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_isrvar_DN_branch does not exist!\n");
      exit(1);
    }
    weight_isrvar_DN_isLoaded = true;
  }
  return weight_isrvar_DN_;
}

const float &SSAG::weight_fsrvar_UP() {
  if (not weight_fsrvar_UP_isLoaded) {
    if (weight_fsrvar_UP_branch != 0) {
      weight_fsrvar_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_fsrvar_UP_branch does not exist!\n");
      exit(1);
    }
    weight_fsrvar_UP_isLoaded = true;
  }
  return weight_fsrvar_UP_;
}

const float &SSAG::weight_fsrvar_DN() {
  if (not weight_fsrvar_DN_isLoaded) {
    if (weight_fsrvar_DN_branch != 0) {
      weight_fsrvar_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_fsrvar_DN_branch does not exist!\n");
      exit(1);
    }
    weight_fsrvar_DN_isLoaded = true;
  }
  return weight_fsrvar_DN_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::gl1_p4() {
  if (not gl1_p4_isLoaded) {
    if (gl1_p4_branch != 0) {
      gl1_p4_branch->GetEntry(index);
    } else {
      printf("branch gl1_p4_branch does not exist!\n");
      exit(1);
    }
    gl1_p4_isLoaded = true;
  }
  return *gl1_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::gl2_p4() {
  if (not gl2_p4_isLoaded) {
    if (gl2_p4_branch != 0) {
      gl2_p4_branch->GetEntry(index);
    } else {
      printf("branch gl2_p4_branch does not exist!\n");
      exit(1);
    }
    gl2_p4_isLoaded = true;
  }
  return *gl2_p4_;
}

const float &SSAG::glglpt() {
  if (not glglpt_isLoaded) {
    if (glglpt_branch != 0) {
      glglpt_branch->GetEntry(index);
    } else {
      printf("branch glglpt_branch does not exist!\n");
      exit(1);
    }
    glglpt_isLoaded = true;
  }
  return glglpt_;
}

const float &SSAG::isr_unc() {
  if (not isr_unc_isLoaded) {
    if (isr_unc_branch != 0) {
      isr_unc_branch->GetEntry(index);
    } else {
      printf("branch isr_unc_branch does not exist!\n");
      exit(1);
    }
    isr_unc_isLoaded = true;
  }
  return isr_unc_;
}

const int &SSAG::nisrMatch() {
  if (not nisrMatch_isLoaded) {
    if (nisrMatch_branch != 0) {
      nisrMatch_branch->GetEntry(index);
    } else {
      printf("branch nisrMatch_branch does not exist!\n");
      exit(1);
    }
    nisrMatch_isLoaded = true;
  }
  return nisrMatch_;
}

const float &SSAG::weight_isr() {
  if (not weight_isr_isLoaded) {
    if (weight_isr_branch != 0) {
      weight_isr_branch->GetEntry(index);
    } else {
      printf("branch weight_isr_branch does not exist!\n");
      exit(1);
    }
    weight_isr_isLoaded = true;
  }
  return weight_isr_;
}

const float &SSAG::weight_isr_dy() {
  if (not weight_isr_dy_isLoaded) {
    if (weight_isr_dy_branch != 0) {
      weight_isr_dy_branch->GetEntry(index);
    } else {
      printf("branch weight_isr_dy_branch does not exist!\n");
      exit(1);
    }
    weight_isr_dy_isLoaded = true;
  }
  return weight_isr_dy_;
}

const float &SSAG::weight_isr_tt() {
  if (not weight_isr_tt_isLoaded) {
    if (weight_isr_tt_branch != 0) {
      weight_isr_tt_branch->GetEntry(index);
    } else {
      printf("branch weight_isr_tt_branch does not exist!\n");
      exit(1);
    }
    weight_isr_tt_isLoaded = true;
  }
  return weight_isr_tt_;
}

const float &SSAG::weight_isr_UP() {
  if (not weight_isr_UP_isLoaded) {
    if (weight_isr_UP_branch != 0) {
      weight_isr_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_isr_UP_branch does not exist!\n");
      exit(1);
    }
    weight_isr_UP_isLoaded = true;
  }
  return weight_isr_UP_;
}

const float &SSAG::weight_isr_DN() {
  if (not weight_isr_DN_isLoaded) {
    if (weight_isr_DN_branch != 0) {
      weight_isr_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_isr_DN_branch does not exist!\n");
      exit(1);
    }
    weight_isr_DN_isLoaded = true;
  }
  return weight_isr_DN_;
}

const bool &SSAG::lep3_el_etaSC() {
  if (not lep3_el_etaSC_isLoaded) {
    if (lep3_el_etaSC_branch != 0) {
      lep3_el_etaSC_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_etaSC_branch does not exist!\n");
      exit(1);
    }
    lep3_el_etaSC_isLoaded = true;
  }
  return lep3_el_etaSC_;
}

const bool &SSAG::lep3_el_conv_vtx_flag() {
  if (not lep3_el_conv_vtx_flag_isLoaded) {
    if (lep3_el_conv_vtx_flag_branch != 0) {
      lep3_el_conv_vtx_flag_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_conv_vtx_flag_branch does not exist!\n");
      exit(1);
    }
    lep3_el_conv_vtx_flag_isLoaded = true;
  }
  return lep3_el_conv_vtx_flag_;
}

const bool &SSAG::lep3_el_exp_innerlayers() {
  if (not lep3_el_exp_innerlayers_isLoaded) {
    if (lep3_el_exp_innerlayers_branch != 0) {
      lep3_el_exp_innerlayers_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_exp_innerlayers_branch does not exist!\n");
      exit(1);
    }
    lep3_el_exp_innerlayers_isLoaded = true;
  }
  return lep3_el_exp_innerlayers_;
}

const bool &SSAG::lep3_el_threeChargeAgree() {
  if (not lep3_el_threeChargeAgree_isLoaded) {
    if (lep3_el_threeChargeAgree_branch != 0) {
      lep3_el_threeChargeAgree_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_threeChargeAgree_branch does not exist!\n");
      exit(1);
    }
    lep3_el_threeChargeAgree_isLoaded = true;
  }
  return lep3_el_threeChargeAgree_;
}

const bool &SSAG::lep3_el_dxyPV() {
  if (not lep3_el_dxyPV_isLoaded) {
    if (lep3_el_dxyPV_branch != 0) {
      lep3_el_dxyPV_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_dxyPV_branch does not exist!\n");
      exit(1);
    }
    lep3_el_dxyPV_isLoaded = true;
  }
  return lep3_el_dxyPV_;
}

const bool &SSAG::lep3_el_ip3d() {
  if (not lep3_el_ip3d_isLoaded) {
    if (lep3_el_ip3d_branch != 0) {
      lep3_el_ip3d_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_ip3d_branch does not exist!\n");
      exit(1);
    }
    lep3_el_ip3d_isLoaded = true;
  }
  return lep3_el_ip3d_;
}

const bool &SSAG::lep3_el_dzPV() {
  if (not lep3_el_dzPV_isLoaded) {
    if (lep3_el_dzPV_branch != 0) {
      lep3_el_dzPV_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_dzPV_branch does not exist!\n");
      exit(1);
    }
    lep3_el_dzPV_isLoaded = true;
  }
  return lep3_el_dzPV_;
}

const float &SSAG::lep3_el_MVA_value() {
  if (not lep3_el_MVA_value_isLoaded) {
    if (lep3_el_MVA_value_branch != 0) {
      lep3_el_MVA_value_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_MVA_value_branch does not exist!\n");
      exit(1);
    }
    lep3_el_MVA_value_isLoaded = true;
  }
  return lep3_el_MVA_value_;
}

const bool &SSAG::lep3_el_MVA() {
  if (not lep3_el_MVA_isLoaded) {
    if (lep3_el_MVA_branch != 0) {
      lep3_el_MVA_branch->GetEntry(index);
    } else {
      printf("branch lep3_el_MVA_branch does not exist!\n");
      exit(1);
    }
    lep3_el_MVA_isLoaded = true;
  }
  return lep3_el_MVA_;
}

const bool &SSAG::lep3_passes_RA5() {
  if (not lep3_passes_RA5_isLoaded) {
    if (lep3_passes_RA5_branch != 0) {
      lep3_passes_RA5_branch->GetEntry(index);
    } else {
      printf("branch lep3_passes_RA5_branch does not exist!\n");
      exit(1);
    }
    lep3_passes_RA5_isLoaded = true;
  }
  return lep3_passes_RA5_;
}

const bool &SSAG::lep3_mu_dxyPV() {
  if (not lep3_mu_dxyPV_isLoaded) {
    if (lep3_mu_dxyPV_branch != 0) {
      lep3_mu_dxyPV_branch->GetEntry(index);
    } else {
      printf("branch lep3_mu_dxyPV_branch does not exist!\n");
      exit(1);
    }
    lep3_mu_dxyPV_isLoaded = true;
  }
  return lep3_mu_dxyPV_;
}

const bool &SSAG::lep3_mu_ip3d() {
  if (not lep3_mu_ip3d_isLoaded) {
    if (lep3_mu_ip3d_branch != 0) {
      lep3_mu_ip3d_branch->GetEntry(index);
    } else {
      printf("branch lep3_mu_ip3d_branch does not exist!\n");
      exit(1);
    }
    lep3_mu_ip3d_isLoaded = true;
  }
  return lep3_mu_ip3d_;
}

const bool &SSAG::lep3_mu_dzPV() {
  if (not lep3_mu_dzPV_isLoaded) {
    if (lep3_mu_dzPV_branch != 0) {
      lep3_mu_dzPV_branch->GetEntry(index);
    } else {
      printf("branch lep3_mu_dzPV_branch does not exist!\n");
      exit(1);
    }
    lep3_mu_dzPV_isLoaded = true;
  }
  return lep3_mu_dzPV_;
}

const bool &SSAG::lep3_mu_ptErr() {
  if (not lep3_mu_ptErr_isLoaded) {
    if (lep3_mu_ptErr_branch != 0) {
      lep3_mu_ptErr_branch->GetEntry(index);
    } else {
      printf("branch lep3_mu_ptErr_branch does not exist!\n");
      exit(1);
    }
    lep3_mu_ptErr_isLoaded = true;
  }
  return lep3_mu_ptErr_;
}

const bool &SSAG::lep4_el_etaSC() {
  if (not lep4_el_etaSC_isLoaded) {
    if (lep4_el_etaSC_branch != 0) {
      lep4_el_etaSC_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_etaSC_branch does not exist!\n");
      exit(1);
    }
    lep4_el_etaSC_isLoaded = true;
  }
  return lep4_el_etaSC_;
}

const bool &SSAG::lep4_el_conv_vtx_flag() {
  if (not lep4_el_conv_vtx_flag_isLoaded) {
    if (lep4_el_conv_vtx_flag_branch != 0) {
      lep4_el_conv_vtx_flag_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_conv_vtx_flag_branch does not exist!\n");
      exit(1);
    }
    lep4_el_conv_vtx_flag_isLoaded = true;
  }
  return lep4_el_conv_vtx_flag_;
}

const bool &SSAG::lep4_el_exp_innerlayers() {
  if (not lep4_el_exp_innerlayers_isLoaded) {
    if (lep4_el_exp_innerlayers_branch != 0) {
      lep4_el_exp_innerlayers_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_exp_innerlayers_branch does not exist!\n");
      exit(1);
    }
    lep4_el_exp_innerlayers_isLoaded = true;
  }
  return lep4_el_exp_innerlayers_;
}

const bool &SSAG::lep4_el_threeChargeAgree() {
  if (not lep4_el_threeChargeAgree_isLoaded) {
    if (lep4_el_threeChargeAgree_branch != 0) {
      lep4_el_threeChargeAgree_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_threeChargeAgree_branch does not exist!\n");
      exit(1);
    }
    lep4_el_threeChargeAgree_isLoaded = true;
  }
  return lep4_el_threeChargeAgree_;
}

const bool &SSAG::lep4_el_dxyPV() {
  if (not lep4_el_dxyPV_isLoaded) {
    if (lep4_el_dxyPV_branch != 0) {
      lep4_el_dxyPV_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_dxyPV_branch does not exist!\n");
      exit(1);
    }
    lep4_el_dxyPV_isLoaded = true;
  }
  return lep4_el_dxyPV_;
}

const bool &SSAG::lep4_el_ip3d() {
  if (not lep4_el_ip3d_isLoaded) {
    if (lep4_el_ip3d_branch != 0) {
      lep4_el_ip3d_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_ip3d_branch does not exist!\n");
      exit(1);
    }
    lep4_el_ip3d_isLoaded = true;
  }
  return lep4_el_ip3d_;
}

const bool &SSAG::lep4_el_dzPV() {
  if (not lep4_el_dzPV_isLoaded) {
    if (lep4_el_dzPV_branch != 0) {
      lep4_el_dzPV_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_dzPV_branch does not exist!\n");
      exit(1);
    }
    lep4_el_dzPV_isLoaded = true;
  }
  return lep4_el_dzPV_;
}

const float &SSAG::lep4_el_MVA_value() {
  if (not lep4_el_MVA_value_isLoaded) {
    if (lep4_el_MVA_value_branch != 0) {
      lep4_el_MVA_value_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_MVA_value_branch does not exist!\n");
      exit(1);
    }
    lep4_el_MVA_value_isLoaded = true;
  }
  return lep4_el_MVA_value_;
}

const bool &SSAG::lep4_el_MVA() {
  if (not lep4_el_MVA_isLoaded) {
    if (lep4_el_MVA_branch != 0) {
      lep4_el_MVA_branch->GetEntry(index);
    } else {
      printf("branch lep4_el_MVA_branch does not exist!\n");
      exit(1);
    }
    lep4_el_MVA_isLoaded = true;
  }
  return lep4_el_MVA_;
}

const bool &SSAG::lep4_mu_dxyPV() {
  if (not lep4_mu_dxyPV_isLoaded) {
    if (lep4_mu_dxyPV_branch != 0) {
      lep4_mu_dxyPV_branch->GetEntry(index);
    } else {
      printf("branch lep4_mu_dxyPV_branch does not exist!\n");
      exit(1);
    }
    lep4_mu_dxyPV_isLoaded = true;
  }
  return lep4_mu_dxyPV_;
}

const bool &SSAG::lep4_mu_ip3d() {
  if (not lep4_mu_ip3d_isLoaded) {
    if (lep4_mu_ip3d_branch != 0) {
      lep4_mu_ip3d_branch->GetEntry(index);
    } else {
      printf("branch lep4_mu_ip3d_branch does not exist!\n");
      exit(1);
    }
    lep4_mu_ip3d_isLoaded = true;
  }
  return lep4_mu_ip3d_;
}

const bool &SSAG::lep4_mu_dzPV() {
  if (not lep4_mu_dzPV_isLoaded) {
    if (lep4_mu_dzPV_branch != 0) {
      lep4_mu_dzPV_branch->GetEntry(index);
    } else {
      printf("branch lep4_mu_dzPV_branch does not exist!\n");
      exit(1);
    }
    lep4_mu_dzPV_isLoaded = true;
  }
  return lep4_mu_dzPV_;
}

const bool &SSAG::lep4_mu_ptErr() {
  if (not lep4_mu_ptErr_isLoaded) {
    if (lep4_mu_ptErr_branch != 0) {
      lep4_mu_ptErr_branch->GetEntry(index);
    } else {
      printf("branch lep4_mu_ptErr_branch does not exist!\n");
      exit(1);
    }
    lep4_mu_ptErr_isLoaded = true;
  }
  return lep4_mu_ptErr_;
}

const bool &SSAG::lep3_isTrigSafeNoIsov1() {
  if (not lep3_isTrigSafeNoIsov1_isLoaded) {
    if (lep3_isTrigSafeNoIsov1_branch != 0) {
      lep3_isTrigSafeNoIsov1_branch->GetEntry(index);
    } else {
      printf("branch lep3_isTrigSafeNoIsov1_branch does not exist!\n");
      exit(1);
    }
    lep3_isTrigSafeNoIsov1_isLoaded = true;
  }
  return lep3_isTrigSafeNoIsov1_;
}

const bool &SSAG::lep3_isTrigSafev1() {
  if (not lep3_isTrigSafev1_isLoaded) {
    if (lep3_isTrigSafev1_branch != 0) {
      lep3_isTrigSafev1_branch->GetEntry(index);
    } else {
      printf("branch lep3_isTrigSafev1_branch does not exist!\n");
      exit(1);
    }
    lep3_isTrigSafev1_isLoaded = true;
  }
  return lep3_isTrigSafev1_;
}

const bool &SSAG::lep4_isTrigSafeNoIsov1() {
  if (not lep4_isTrigSafeNoIsov1_isLoaded) {
    if (lep4_isTrigSafeNoIsov1_branch != 0) {
      lep4_isTrigSafeNoIsov1_branch->GetEntry(index);
    } else {
      printf("branch lep4_isTrigSafeNoIsov1_branch does not exist!\n");
      exit(1);
    }
    lep4_isTrigSafeNoIsov1_isLoaded = true;
  }
  return lep4_isTrigSafeNoIsov1_;
}

const bool &SSAG::lep4_isTrigSafev1() {
  if (not lep4_isTrigSafev1_isLoaded) {
    if (lep4_isTrigSafev1_branch != 0) {
      lep4_isTrigSafev1_branch->GetEntry(index);
    } else {
      printf("branch lep4_isTrigSafev1_branch does not exist!\n");
      exit(1);
    }
    lep4_isTrigSafev1_isLoaded = true;
  }
  return lep4_isTrigSafev1_;
}

const int &SSAG::extragenb() {
  if (not extragenb_isLoaded) {
    if (extragenb_branch != 0) {
      extragenb_branch->GetEntry(index);
    } else {
      printf("branch extragenb_branch does not exist!\n");
      exit(1);
    }
    extragenb_isLoaded = true;
  }
  return extragenb_;
}

const vector<int> &SSAG::extragenbmoms() {
  if (not extragenbmoms_isLoaded) {
    if (extragenbmoms_branch != 0) {
      extragenbmoms_branch->GetEntry(index);
    } else {
      printf("branch extragenbmoms_branch does not exist!\n");
      exit(1);
    }
    extragenbmoms_isLoaded = true;
  }
  return *extragenbmoms_;
}

const int &SSAG::extragenc() {
  if (not extragenc_isLoaded) {
    if (extragenc_branch != 0) {
      extragenc_branch->GetEntry(index);
    } else {
      printf("branch extragenc_branch does not exist!\n");
      exit(1);
    }
    extragenc_isLoaded = true;
  }
  return extragenc_;
}

const vector<int> &SSAG::extragencmoms() {
  if (not extragencmoms_isLoaded) {
    if (extragencmoms_branch != 0) {
      extragencmoms_branch->GetEntry(index);
    } else {
      printf("branch extragencmoms_branch does not exist!\n");
      exit(1);
    }
    extragencmoms_isLoaded = true;
  }
  return *extragencmoms_;
}

const int &SSAG::ngenjets() {
  if (not ngenjets_isLoaded) {
    if (ngenjets_branch != 0) {
      ngenjets_branch->GetEntry(index);
    } else {
      printf("branch ngenjets_branch does not exist!\n");
      exit(1);
    }
    ngenjets_isLoaded = true;
  }
  return ngenjets_;
}

const float &SSAG::genht() {
  if (not genht_isLoaded) {
    if (genht_branch != 0) {
      genht_branch->GetEntry(index);
    } else {
      printf("branch genht_branch does not exist!\n");
      exit(1);
    }
    genht_isLoaded = true;
  }
  return genht_;
}

const int &SSAG::ngenjets30() {
  if (not ngenjets30_isLoaded) {
    if (ngenjets30_branch != 0) {
      ngenjets30_branch->GetEntry(index);
    } else {
      printf("branch ngenjets30_branch does not exist!\n");
      exit(1);
    }
    ngenjets30_isLoaded = true;
  }
  return ngenjets30_;
}

const float &SSAG::genht30() {
  if (not genht30_isLoaded) {
    if (genht30_branch != 0) {
      genht30_branch->GetEntry(index);
    } else {
      printf("branch genht30_branch does not exist!\n");
      exit(1);
    }
    genht30_isLoaded = true;
  }
  return genht30_;
}

const bool &SSAG::passfilter() {
  if (not passfilter_isLoaded) {
    if (passfilter_branch != 0) {
      passfilter_branch->GetEntry(index);
    } else {
      printf("branch passfilter_branch does not exist!\n");
      exit(1);
    }
    passfilter_isLoaded = true;
  }
  return passfilter_;
}

const bool &SSAG::hasgammatoll() {
  if (not hasgammatoll_isLoaded) {
    if (hasgammatoll_branch != 0) {
      hasgammatoll_branch->GetEntry(index);
    } else {
      printf("branch hasgammatoll_branch does not exist!\n");
      exit(1);
    }
    hasgammatoll_isLoaded = true;
  }
  return hasgammatoll_;
}

const bool &SSAG::gammatollmomemu() {
  if (not gammatollmomemu_isLoaded) {
    if (gammatollmomemu_branch != 0) {
      gammatollmomemu_branch->GetEntry(index);
    } else {
      printf("branch gammatollmomemu_branch does not exist!\n");
      exit(1);
    }
    gammatollmomemu_isLoaded = true;
  }
  return gammatollmomemu_;
}

const float &SSAG::gammatolldr() {
  if (not gammatolldr_isLoaded) {
    if (gammatolldr_branch != 0) {
      gammatolldr_branch->GetEntry(index);
    } else {
      printf("branch gammatolldr_branch does not exist!\n");
      exit(1);
    }
    gammatolldr_isLoaded = true;
  }
  return gammatolldr_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::gammatoll1() {
  if (not gammatoll1_isLoaded) {
    if (gammatoll1_branch != 0) {
      gammatoll1_branch->GetEntry(index);
    } else {
      printf("branch gammatoll1_branch does not exist!\n");
      exit(1);
    }
    gammatoll1_isLoaded = true;
  }
  return *gammatoll1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &SSAG::gammatoll2() {
  if (not gammatoll2_isLoaded) {
    if (gammatoll2_branch != 0) {
      gammatoll2_branch->GetEntry(index);
    } else {
      printf("branch gammatoll2_branch does not exist!\n");
      exit(1);
    }
    gammatoll2_isLoaded = true;
  }
  return *gammatoll2_;
}

const vector<int> &SSAG::bjet_type() {
  if (not bjet_type_isLoaded) {
    if (bjet_type_branch != 0) {
      bjet_type_branch->GetEntry(index);
    } else {
      printf("branch bjet_type_branch does not exist!\n");
      exit(1);
    }
    bjet_type_isLoaded = true;
  }
  return *bjet_type_;
}

const vector<int> &SSAG::jet_type() {
  if (not jet_type_isLoaded) {
    if (jet_type_branch != 0) {
      jet_type_branch->GetEntry(index);
    } else {
      printf("branch jet_type_branch does not exist!\n");
      exit(1);
    }
    jet_type_isLoaded = true;
  }
  return *jet_type_;
}

const vector<int> &SSAG::jet_cat() {
  if (not jet_cat_isLoaded) {
    if (jet_cat_branch != 0) {
      jet_cat_branch->GetEntry(index);
    } else {
      printf("branch jet_cat_branch does not exist!\n");
      exit(1);
    }
    jet_cat_isLoaded = true;
  }
  return *jet_cat_;
}

const vector<int> &SSAG::jet_matchedGenIndex() {
  if (not jet_matchedGenIndex_isLoaded) {
    if (jet_matchedGenIndex_branch != 0) {
      jet_matchedGenIndex_branch->GetEntry(index);
    } else {
      printf("branch jet_matchedGenIndex_branch does not exist!\n");
      exit(1);
    }
    jet_matchedGenIndex_isLoaded = true;
  }
  return *jet_matchedGenIndex_;
}

const vector<int> &SSAG::jet_matchedGenId() {
  if (not jet_matchedGenId_isLoaded) {
    if (jet_matchedGenId_branch != 0) {
      jet_matchedGenId_branch->GetEntry(index);
    } else {
      printf("branch jet_matchedGenId_branch does not exist!\n");
      exit(1);
    }
    jet_matchedGenId_isLoaded = true;
  }
  return *jet_matchedGenId_;
}

const vector<int> &SSAG::jet_matchedGenMId() {
  if (not jet_matchedGenMId_isLoaded) {
    if (jet_matchedGenMId_branch != 0) {
      jet_matchedGenMId_branch->GetEntry(index);
    } else {
      printf("branch jet_matchedGenMId_branch does not exist!\n");
      exit(1);
    }
    jet_matchedGenMId_isLoaded = true;
  }
  return *jet_matchedGenMId_;
}

const vector<float> &SSAG::jet_matchedDr() {
  if (not jet_matchedDr_isLoaded) {
    if (jet_matchedDr_branch != 0) {
      jet_matchedDr_branch->GetEntry(index);
    } else {
      printf("branch jet_matchedDr_branch does not exist!\n");
      exit(1);
    }
    jet_matchedDr_isLoaded = true;
  }
  return *jet_matchedDr_;
}

const vector<float> &SSAG::jet_matchedPtDiff() {
  if (not jet_matchedPtDiff_isLoaded) {
    if (jet_matchedPtDiff_branch != 0) {
      jet_matchedPtDiff_branch->GetEntry(index);
    } else {
      printf("branch jet_matchedPtDiff_branch does not exist!\n");
      exit(1);
    }
    jet_matchedPtDiff_isLoaded = true;
  }
  return *jet_matchedPtDiff_;
}

const int &SSAG::ndrlt0p4() {
  if (not ndrlt0p4_isLoaded) {
    if (ndrlt0p4_branch != 0) {
      ndrlt0p4_branch->GetEntry(index);
    } else {
      printf("branch ndrlt0p4_branch does not exist!\n");
      exit(1);
    }
    ndrlt0p4_isLoaded = true;
  }
  return ndrlt0p4_;
}

const bool &SSAG::gengood() {
  if (not gengood_isLoaded) {
    if (gengood_branch != 0) {
      gengood_branch->GetEntry(index);
    } else {
      printf("branch gengood_branch does not exist!\n");
      exit(1);
    }
    gengood_isLoaded = true;
  }
  return gengood_;
}

const int &SSAG::nleptonic() {
  if (not nleptonic_isLoaded) {
    if (nleptonic_branch != 0) {
      nleptonic_branch->GetEntry(index);
    } else {
      printf("branch nleptonic_branch does not exist!\n");
      exit(1);
    }
    nleptonic_isLoaded = true;
  }
  return nleptonic_;
}

const int &SSAG::ntau() {
  if (not ntau_isLoaded) {
    if (ntau_branch != 0) {
      ntau_branch->GetEntry(index);
    } else {
      printf("branch ntau_branch does not exist!\n");
      exit(1);
    }
    ntau_isLoaded = true;
  }
  return ntau_;
}

const int &SSAG::nleptonicW() {
  if (not nleptonicW_isLoaded) {
    if (nleptonicW_branch != 0) {
      nleptonicW_branch->GetEntry(index);
    } else {
      printf("branch nleptonicW_branch does not exist!\n");
      exit(1);
    }
    nleptonicW_isLoaded = true;
  }
  return nleptonicW_;
}

const float &SSAG::mfourtop() {
  if (not mfourtop_isLoaded) {
    if (mfourtop_branch != 0) {
      mfourtop_branch->GetEntry(index);
    } else {
      printf("branch mfourtop_branch does not exist!\n");
      exit(1);
    }
    mfourtop_isLoaded = true;
  }
  return mfourtop_;
}

const int &SSAG::nhadronicW() {
  if (not nhadronicW_isLoaded) {
    if (nhadronicW_branch != 0) {
      nhadronicW_branch->GetEntry(index);
    } else {
      printf("branch nhadronicW_branch does not exist!\n");
      exit(1);
    }
    nhadronicW_isLoaded = true;
  }
  return nhadronicW_;
}

const int &SSAG::nW() {
  if (not nW_isLoaded) {
    if (nW_branch != 0) {
      nW_branch->GetEntry(index);
    } else {
      printf("branch nW_branch does not exist!\n");
      exit(1);
    }
    nW_isLoaded = true;
  }
  return nW_;
}

const float &SSAG::leptonicWSF() {
  if (not leptonicWSF_isLoaded) {
    if (leptonicWSF_branch != 0) {
      leptonicWSF_branch->GetEntry(index);
    } else {
      printf("branch leptonicWSF_branch does not exist!\n");
      exit(1);
    }
    leptonicWSF_isLoaded = true;
  }
  return leptonicWSF_;
}

const float &SSAG::hadronicWSF() {
  if (not hadronicWSF_isLoaded) {
    if (hadronicWSF_branch != 0) {
      hadronicWSF_branch->GetEntry(index);
    } else {
      printf("branch hadronicWSF_branch does not exist!\n");
      exit(1);
    }
    hadronicWSF_isLoaded = true;
  }
  return hadronicWSF_;
}

const float &SSAG::decayWSF() {
  if (not decayWSF_isLoaded) {
    if (decayWSF_branch != 0) {
      decayWSF_branch->GetEntry(index);
    } else {
      printf("branch decayWSF_branch does not exist!\n");
      exit(1);
    }
    decayWSF_isLoaded = true;
  }
  return decayWSF_;
}

const int &SSAG::njincone1() {
  if (not njincone1_isLoaded) {
    if (njincone1_branch != 0) {
      njincone1_branch->GetEntry(index);
    } else {
      printf("branch njincone1_branch does not exist!\n");
      exit(1);
    }
    njincone1_isLoaded = true;
  }
  return njincone1_;
}

const int &SSAG::njincone2() {
  if (not njincone2_isLoaded) {
    if (njincone2_branch != 0) {
      njincone2_branch->GetEntry(index);
    } else {
      printf("branch njincone2_branch does not exist!\n");
      exit(1);
    }
    njincone2_isLoaded = true;
  }
  return njincone2_;
}

const int &SSAG::bdt_nforwardjets20() {
  if (not bdt_nforwardjets20_isLoaded) {
    if (bdt_nforwardjets20_branch != 0) {
      bdt_nforwardjets20_branch->GetEntry(index);
    } else {
      printf("branch bdt_nforwardjets20_branch does not exist!\n");
      exit(1);
    }
    bdt_nforwardjets20_isLoaded = true;
  }
  return bdt_nforwardjets20_;
}

const float &SSAG::bdt_avgcdisc() {
  if (not bdt_avgcdisc_isLoaded) {
    if (bdt_avgcdisc_branch != 0) {
      bdt_avgcdisc_branch->GetEntry(index);
    } else {
      printf("branch bdt_avgcdisc_branch does not exist!\n");
      exit(1);
    }
    bdt_avgcdisc_isLoaded = true;
  }
  return bdt_avgcdisc_;
}

const float &SSAG::bdt_nbtags() {
  if (not bdt_nbtags_isLoaded) {
    if (bdt_nbtags_branch != 0) {
      bdt_nbtags_branch->GetEntry(index);
    } else {
      printf("branch bdt_nbtags_branch does not exist!\n");
      exit(1);
    }
    bdt_nbtags_isLoaded = true;
  }
  return bdt_nbtags_;
}

const float &SSAG::bdt_njets() {
  if (not bdt_njets_isLoaded) {
    if (bdt_njets_branch != 0) {
      bdt_njets_branch->GetEntry(index);
    } else {
      printf("branch bdt_njets_branch does not exist!\n");
      exit(1);
    }
    bdt_njets_isLoaded = true;
  }
  return bdt_njets_;
}

const float &SSAG::bdt_met() {
  if (not bdt_met_isLoaded) {
    if (bdt_met_branch != 0) {
      bdt_met_branch->GetEntry(index);
    } else {
      printf("branch bdt_met_branch does not exist!\n");
      exit(1);
    }
    bdt_met_isLoaded = true;
  }
  return bdt_met_;
}

const float &SSAG::bdt_ptl2() {
  if (not bdt_ptl2_isLoaded) {
    if (bdt_ptl2_branch != 0) {
      bdt_ptl2_branch->GetEntry(index);
    } else {
      printf("branch bdt_ptl2_branch does not exist!\n");
      exit(1);
    }
    bdt_ptl2_isLoaded = true;
  }
  return bdt_ptl2_;
}

const float &SSAG::bdt_nlb40() {
  if (not bdt_nlb40_isLoaded) {
    if (bdt_nlb40_branch != 0) {
      bdt_nlb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_nlb40_branch does not exist!\n");
      exit(1);
    }
    bdt_nlb40_isLoaded = true;
  }
  return bdt_nlb40_;
}

const float &SSAG::bdt_ntb40() {
  if (not bdt_ntb40_isLoaded) {
    if (bdt_ntb40_branch != 0) {
      bdt_ntb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_ntb40_branch does not exist!\n");
      exit(1);
    }
    bdt_ntb40_isLoaded = true;
  }
  return bdt_ntb40_;
}

const float &SSAG::bdt_nleps() {
  if (not bdt_nleps_isLoaded) {
    if (bdt_nleps_branch != 0) {
      bdt_nleps_branch->GetEntry(index);
    } else {
      printf("branch bdt_nleps_branch does not exist!\n");
      exit(1);
    }
    bdt_nleps_isLoaded = true;
  }
  return bdt_nleps_;
}

const float &SSAG::bdt_htb() {
  if (not bdt_htb_isLoaded) {
    if (bdt_htb_branch != 0) {
      bdt_htb_branch->GetEntry(index);
    } else {
      printf("branch bdt_htb_branch does not exist!\n");
      exit(1);
    }
    bdt_htb_isLoaded = true;
  }
  return bdt_htb_;
}

const float &SSAG::bdt_ml1j1() {
  if (not bdt_ml1j1_isLoaded) {
    if (bdt_ml1j1_branch != 0) {
      bdt_ml1j1_branch->GetEntry(index);
    } else {
      printf("branch bdt_ml1j1_branch does not exist!\n");
      exit(1);
    }
    bdt_ml1j1_isLoaded = true;
  }
  return bdt_ml1j1_;
}

const float &SSAG::bdt_dphil1l2() {
  if (not bdt_dphil1l2_isLoaded) {
    if (bdt_dphil1l2_branch != 0) {
      bdt_dphil1l2_branch->GetEntry(index);
    } else {
      printf("branch bdt_dphil1l2_branch does not exist!\n");
      exit(1);
    }
    bdt_dphil1l2_isLoaded = true;
  }
  return bdt_dphil1l2_;
}

const float &SSAG::bdt_maxmjoverpt() {
  if (not bdt_maxmjoverpt_isLoaded) {
    if (bdt_maxmjoverpt_branch != 0) {
      bdt_maxmjoverpt_branch->GetEntry(index);
    } else {
      printf("branch bdt_maxmjoverpt_branch does not exist!\n");
      exit(1);
    }
    bdt_maxmjoverpt_isLoaded = true;
  }
  return bdt_maxmjoverpt_;
}

const float &SSAG::bdt_detal1l2() {
  if (not bdt_detal1l2_isLoaded) {
    if (bdt_detal1l2_branch != 0) {
      bdt_detal1l2_branch->GetEntry(index);
    } else {
      printf("branch bdt_detal1l2_branch does not exist!\n");
      exit(1);
    }
    bdt_detal1l2_isLoaded = true;
  }
  return bdt_detal1l2_;
}

const float &SSAG::bdt_q1() {
  if (not bdt_q1_isLoaded) {
    if (bdt_q1_branch != 0) {
      bdt_q1_branch->GetEntry(index);
    } else {
      printf("branch bdt_q1_branch does not exist!\n");
      exit(1);
    }
    bdt_q1_isLoaded = true;
  }
  return bdt_q1_;
}

const float &SSAG::bdt_ptj1() {
  if (not bdt_ptj1_isLoaded) {
    if (bdt_ptj1_branch != 0) {
      bdt_ptj1_branch->GetEntry(index);
    } else {
      printf("branch bdt_ptj1_branch does not exist!\n");
      exit(1);
    }
    bdt_ptj1_isLoaded = true;
  }
  return bdt_ptj1_;
}

const float &SSAG::bdt_ptj6() {
  if (not bdt_ptj6_isLoaded) {
    if (bdt_ptj6_branch != 0) {
      bdt_ptj6_branch->GetEntry(index);
    } else {
      printf("branch bdt_ptj6_branch does not exist!\n");
      exit(1);
    }
    bdt_ptj6_isLoaded = true;
  }
  return bdt_ptj6_;
}

const float &SSAG::bdt_ptj7() {
  if (not bdt_ptj7_isLoaded) {
    if (bdt_ptj7_branch != 0) {
      bdt_ptj7_branch->GetEntry(index);
    } else {
      printf("branch bdt_ptj7_branch does not exist!\n");
      exit(1);
    }
    bdt_ptj7_isLoaded = true;
  }
  return bdt_ptj7_;
}

const float &SSAG::bdt_ptj8() {
  if (not bdt_ptj8_isLoaded) {
    if (bdt_ptj8_branch != 0) {
      bdt_ptj8_branch->GetEntry(index);
    } else {
      printf("branch bdt_ptj8_branch does not exist!\n");
      exit(1);
    }
    bdt_ptj8_isLoaded = true;
  }
  return bdt_ptj8_;
}

const float &SSAG::bdt_ptl1() {
  if (not bdt_ptl1_isLoaded) {
    if (bdt_ptl1_branch != 0) {
      bdt_ptl1_branch->GetEntry(index);
    } else {
      printf("branch bdt_ptl1_branch does not exist!\n");
      exit(1);
    }
    bdt_ptl1_isLoaded = true;
  }
  return bdt_ptl1_;
}

const float &SSAG::bdt_ptl3() {
  if (not bdt_ptl3_isLoaded) {
    if (bdt_ptl3_branch != 0) {
      bdt_ptl3_branch->GetEntry(index);
    } else {
      printf("branch bdt_ptl3_branch does not exist!\n");
      exit(1);
    }
    bdt_ptl3_isLoaded = true;
  }
  return bdt_ptl3_;
}

const float &SSAG::bdt_jec_up_nbtags() {
  if (not bdt_jec_up_nbtags_isLoaded) {
    if (bdt_jec_up_nbtags_branch != 0) {
      bdt_jec_up_nbtags_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_up_nbtags_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_up_nbtags_isLoaded = true;
  }
  return bdt_jec_up_nbtags_;
}

const float &SSAG::bdt_jec_dn_nbtags() {
  if (not bdt_jec_dn_nbtags_isLoaded) {
    if (bdt_jec_dn_nbtags_branch != 0) {
      bdt_jec_dn_nbtags_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_dn_nbtags_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_dn_nbtags_isLoaded = true;
  }
  return bdt_jec_dn_nbtags_;
}

const float &SSAG::bdt_jer_up_nbtags() {
  if (not bdt_jer_up_nbtags_isLoaded) {
    if (bdt_jer_up_nbtags_branch != 0) {
      bdt_jer_up_nbtags_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_up_nbtags_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_up_nbtags_isLoaded = true;
  }
  return bdt_jer_up_nbtags_;
}

const float &SSAG::bdt_jer_dn_nbtags() {
  if (not bdt_jer_dn_nbtags_isLoaded) {
    if (bdt_jer_dn_nbtags_branch != 0) {
      bdt_jer_dn_nbtags_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_dn_nbtags_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_dn_nbtags_isLoaded = true;
  }
  return bdt_jer_dn_nbtags_;
}

const float &SSAG::bdt_jec_up_njets() {
  if (not bdt_jec_up_njets_isLoaded) {
    if (bdt_jec_up_njets_branch != 0) {
      bdt_jec_up_njets_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_up_njets_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_up_njets_isLoaded = true;
  }
  return bdt_jec_up_njets_;
}

const float &SSAG::bdt_jec_dn_njets() {
  if (not bdt_jec_dn_njets_isLoaded) {
    if (bdt_jec_dn_njets_branch != 0) {
      bdt_jec_dn_njets_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_dn_njets_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_dn_njets_isLoaded = true;
  }
  return bdt_jec_dn_njets_;
}

const float &SSAG::bdt_jer_up_njets() {
  if (not bdt_jer_up_njets_isLoaded) {
    if (bdt_jer_up_njets_branch != 0) {
      bdt_jer_up_njets_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_up_njets_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_up_njets_isLoaded = true;
  }
  return bdt_jer_up_njets_;
}

const float &SSAG::bdt_jer_dn_njets() {
  if (not bdt_jer_dn_njets_isLoaded) {
    if (bdt_jer_dn_njets_branch != 0) {
      bdt_jer_dn_njets_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_dn_njets_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_dn_njets_isLoaded = true;
  }
  return bdt_jer_dn_njets_;
}

const float &SSAG::bdt_jec_up_met() {
  if (not bdt_jec_up_met_isLoaded) {
    if (bdt_jec_up_met_branch != 0) {
      bdt_jec_up_met_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_up_met_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_up_met_isLoaded = true;
  }
  return bdt_jec_up_met_;
}

const float &SSAG::bdt_jec_dn_met() {
  if (not bdt_jec_dn_met_isLoaded) {
    if (bdt_jec_dn_met_branch != 0) {
      bdt_jec_dn_met_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_dn_met_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_dn_met_isLoaded = true;
  }
  return bdt_jec_dn_met_;
}

const float &SSAG::bdt_jer_up_met() {
  if (not bdt_jer_up_met_isLoaded) {
    if (bdt_jer_up_met_branch != 0) {
      bdt_jer_up_met_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_up_met_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_up_met_isLoaded = true;
  }
  return bdt_jer_up_met_;
}

const float &SSAG::bdt_jer_dn_met() {
  if (not bdt_jer_dn_met_isLoaded) {
    if (bdt_jer_dn_met_branch != 0) {
      bdt_jer_dn_met_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_dn_met_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_dn_met_isLoaded = true;
  }
  return bdt_jer_dn_met_;
}

const float &SSAG::bdt_jec_up_htb() {
  if (not bdt_jec_up_htb_isLoaded) {
    if (bdt_jec_up_htb_branch != 0) {
      bdt_jec_up_htb_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_up_htb_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_up_htb_isLoaded = true;
  }
  return bdt_jec_up_htb_;
}

const float &SSAG::bdt_jec_dn_htb() {
  if (not bdt_jec_dn_htb_isLoaded) {
    if (bdt_jec_dn_htb_branch != 0) {
      bdt_jec_dn_htb_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_dn_htb_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_dn_htb_isLoaded = true;
  }
  return bdt_jec_dn_htb_;
}

const float &SSAG::bdt_jer_up_htb() {
  if (not bdt_jer_up_htb_isLoaded) {
    if (bdt_jer_up_htb_branch != 0) {
      bdt_jer_up_htb_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_up_htb_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_up_htb_isLoaded = true;
  }
  return bdt_jer_up_htb_;
}

const float &SSAG::bdt_jer_dn_htb() {
  if (not bdt_jer_dn_htb_isLoaded) {
    if (bdt_jer_dn_htb_branch != 0) {
      bdt_jer_dn_htb_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_dn_htb_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_dn_htb_isLoaded = true;
  }
  return bdt_jer_dn_htb_;
}

const float &SSAG::bdt_jec_up_nlb40() {
  if (not bdt_jec_up_nlb40_isLoaded) {
    if (bdt_jec_up_nlb40_branch != 0) {
      bdt_jec_up_nlb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_up_nlb40_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_up_nlb40_isLoaded = true;
  }
  return bdt_jec_up_nlb40_;
}

const float &SSAG::bdt_jec_dn_nlb40() {
  if (not bdt_jec_dn_nlb40_isLoaded) {
    if (bdt_jec_dn_nlb40_branch != 0) {
      bdt_jec_dn_nlb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_dn_nlb40_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_dn_nlb40_isLoaded = true;
  }
  return bdt_jec_dn_nlb40_;
}

const float &SSAG::bdt_jer_up_nlb40() {
  if (not bdt_jer_up_nlb40_isLoaded) {
    if (bdt_jer_up_nlb40_branch != 0) {
      bdt_jer_up_nlb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_up_nlb40_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_up_nlb40_isLoaded = true;
  }
  return bdt_jer_up_nlb40_;
}

const float &SSAG::bdt_jer_dn_nlb40() {
  if (not bdt_jer_dn_nlb40_isLoaded) {
    if (bdt_jer_dn_nlb40_branch != 0) {
      bdt_jer_dn_nlb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_dn_nlb40_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_dn_nlb40_isLoaded = true;
  }
  return bdt_jer_dn_nlb40_;
}

const float &SSAG::bdt_jec_up_ntb40() {
  if (not bdt_jec_up_ntb40_isLoaded) {
    if (bdt_jec_up_ntb40_branch != 0) {
      bdt_jec_up_ntb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_up_ntb40_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_up_ntb40_isLoaded = true;
  }
  return bdt_jec_up_ntb40_;
}

const float &SSAG::bdt_jec_dn_ntb40() {
  if (not bdt_jec_dn_ntb40_isLoaded) {
    if (bdt_jec_dn_ntb40_branch != 0) {
      bdt_jec_dn_ntb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_jec_dn_ntb40_branch does not exist!\n");
      exit(1);
    }
    bdt_jec_dn_ntb40_isLoaded = true;
  }
  return bdt_jec_dn_ntb40_;
}

const float &SSAG::bdt_jer_up_ntb40() {
  if (not bdt_jer_up_ntb40_isLoaded) {
    if (bdt_jer_up_ntb40_branch != 0) {
      bdt_jer_up_ntb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_up_ntb40_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_up_ntb40_isLoaded = true;
  }
  return bdt_jer_up_ntb40_;
}

const float &SSAG::bdt_jer_dn_ntb40() {
  if (not bdt_jer_dn_ntb40_isLoaded) {
    if (bdt_jer_dn_ntb40_branch != 0) {
      bdt_jer_dn_ntb40_branch->GetEntry(index);
    } else {
      printf("branch bdt_jer_dn_ntb40_branch does not exist!\n");
      exit(1);
    }
    bdt_jer_dn_ntb40_isLoaded = true;
  }
  return bdt_jer_dn_ntb40_;
}

const float &SSAG::bdt_disc() {
  if (not bdt_disc_isLoaded) {
    if (bdt_disc_branch != 0) {
      bdt_disc_branch->GetEntry(index);
    } else {
      printf("branch bdt_disc_branch does not exist!\n");
      exit(1);
    }
    bdt_disc_isLoaded = true;
  }
  return bdt_disc_;
}

const float &SSAG::bdt_disc_jec_up() {
  if (not bdt_disc_jec_up_isLoaded) {
    if (bdt_disc_jec_up_branch != 0) {
      bdt_disc_jec_up_branch->GetEntry(index);
    } else {
      printf("branch bdt_disc_jec_up_branch does not exist!\n");
      exit(1);
    }
    bdt_disc_jec_up_isLoaded = true;
  }
  return bdt_disc_jec_up_;
}

const float &SSAG::bdt_disc_jer_up() {
  if (not bdt_disc_jer_up_isLoaded) {
    if (bdt_disc_jer_up_branch != 0) {
      bdt_disc_jer_up_branch->GetEntry(index);
    } else {
      printf("branch bdt_disc_jer_up_branch does not exist!\n");
      exit(1);
    }
    bdt_disc_jer_up_isLoaded = true;
  }
  return bdt_disc_jer_up_;
}

const float &SSAG::bdt_disc_jec_dn() {
  if (not bdt_disc_jec_dn_isLoaded) {
    if (bdt_disc_jec_dn_branch != 0) {
      bdt_disc_jec_dn_branch->GetEntry(index);
    } else {
      printf("branch bdt_disc_jec_dn_branch does not exist!\n");
      exit(1);
    }
    bdt_disc_jec_dn_isLoaded = true;
  }
  return bdt_disc_jec_dn_;
}

const float &SSAG::bdt_disc_jer_dn() {
  if (not bdt_disc_jer_dn_isLoaded) {
    if (bdt_disc_jer_dn_branch != 0) {
      bdt_disc_jer_dn_branch->GetEntry(index);
    } else {
      printf("branch bdt_disc_jer_dn_branch does not exist!\n");
      exit(1);
    }
    bdt_disc_jer_dn_isLoaded = true;
  }
  return bdt_disc_jer_dn_;
}

const float &SSAG::bdt_run2_disc() {
  if (not bdt_run2_disc_isLoaded) {
    if (bdt_run2_disc_branch != 0) {
      bdt_run2_disc_branch->GetEntry(index);
    } else {
      printf("branch bdt_run2_disc_branch does not exist!\n");
      exit(1);
    }
    bdt_run2_disc_isLoaded = true;
  }
  return bdt_run2_disc_;
}

const int &SSAG::bdt_run2_SRDISC() {
  if (not bdt_run2_SRDISC_isLoaded) {
    if (bdt_run2_SRDISC_branch != 0) {
      bdt_run2_SRDISC_branch->GetEntry(index);
    } else {
      printf("branch bdt_run2_SRDISC_branch does not exist!\n");
      exit(1);
    }
    bdt_run2_SRDISC_isLoaded = true;
  }
  return bdt_run2_SRDISC_;
}

const float &SSAG::bdt_run2_disc_jec_up() {
  if (not bdt_run2_disc_jec_up_isLoaded) {
    if (bdt_run2_disc_jec_up_branch != 0) {
      bdt_run2_disc_jec_up_branch->GetEntry(index);
    } else {
      printf("branch bdt_run2_disc_jec_up_branch does not exist!\n");
      exit(1);
    }
    bdt_run2_disc_jec_up_isLoaded = true;
  }
  return bdt_run2_disc_jec_up_;
}

const float &SSAG::bdt_run2_disc_jer_up() {
  if (not bdt_run2_disc_jer_up_isLoaded) {
    if (bdt_run2_disc_jer_up_branch != 0) {
      bdt_run2_disc_jer_up_branch->GetEntry(index);
    } else {
      printf("branch bdt_run2_disc_jer_up_branch does not exist!\n");
      exit(1);
    }
    bdt_run2_disc_jer_up_isLoaded = true;
  }
  return bdt_run2_disc_jer_up_;
}

const float &SSAG::bdt_run2_disc_jec_dn() {
  if (not bdt_run2_disc_jec_dn_isLoaded) {
    if (bdt_run2_disc_jec_dn_branch != 0) {
      bdt_run2_disc_jec_dn_branch->GetEntry(index);
    } else {
      printf("branch bdt_run2_disc_jec_dn_branch does not exist!\n");
      exit(1);
    }
    bdt_run2_disc_jec_dn_isLoaded = true;
  }
  return bdt_run2_disc_jec_dn_;
}

const float &SSAG::bdt_run2_disc_jer_dn() {
  if (not bdt_run2_disc_jer_dn_isLoaded) {
    if (bdt_run2_disc_jer_dn_branch != 0) {
      bdt_run2_disc_jer_dn_branch->GetEntry(index);
    } else {
      printf("branch bdt_run2_disc_jer_dn_branch does not exist!\n");
      exit(1);
    }
    bdt_run2_disc_jer_dn_isLoaded = true;
  }
  return bdt_run2_disc_jer_dn_;
}


void SSAG::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace ss {

const bool &lep1_isPrompt() { return samesign.lep1_isPrompt(); }
const bool &lep1_isDirectPrompt() { return samesign.lep1_isDirectPrompt(); }
const bool &lep1_isStat3() { return samesign.lep1_isStat3(); }
const bool &lep2_isPrompt() { return samesign.lep2_isPrompt(); }
const bool &lep2_isDirectPrompt() { return samesign.lep2_isDirectPrompt(); }
const bool &lep2_isStat3() { return samesign.lep2_isStat3(); }
const float &met() { return samesign.met(); }
const float &metPhi() { return samesign.metPhi(); }
const float &rawmet() { return samesign.rawmet(); }
const float &rawmetPhi() { return samesign.rawmetPhi(); }
const float &calomet() { return samesign.calomet(); }
const float &calometPhi() { return samesign.calometPhi(); }
const unsigned long long &event() { return samesign.event(); }
const int &lumi() { return samesign.lumi(); }
const int &run() { return samesign.run(); }
const bool &filt_csc() { return samesign.filt_csc(); }
const bool &filt_hbhe() { return samesign.filt_hbhe(); }
const bool &filt_hcallaser() { return samesign.filt_hcallaser(); }
const bool &filt_ecaltp() { return samesign.filt_ecaltp(); }
const bool &filt_trkfail() { return samesign.filt_trkfail(); }
const bool &is_real_data() { return samesign.is_real_data(); }
const float &scale1fb() { return samesign.scale1fb(); }
const float &genps_weight() { return samesign.genps_weight(); }
const float &xsec() { return samesign.xsec(); }
const int &neventstotal() { return samesign.neventstotal(); }
const float &xsec_ps() { return samesign.xsec_ps(); }
const vector<TString> &sparmNames() { return samesign.sparmNames(); }
const vector<float> &sparms() { return samesign.sparms(); }
const float &xsec_error() { return samesign.xsec_error(); }
const float &kfactor() { return samesign.kfactor(); }
const float &gen_met() { return samesign.gen_met(); }
const vector<float> &pdfweights() { return samesign.pdfweights(); }
const float &gen_met_phi() { return samesign.gen_met_phi(); }
const bool &skim() { return samesign.skim(); }
const bool &skim_nomet() { return samesign.skim_nomet(); }
const int &nleps() { return samesign.nleps(); }
const int &sr() { return samesign.sr(); }
const bool &br() { return samesign.br(); }
const int &ss_nleps() { return samesign.ss_nleps(); }
const bool &ss_br() { return samesign.ss_br(); }
const int &ss_sr() { return samesign.ss_sr(); }
const int &ss_region() { return samesign.ss_region(); }
const int &njets() { return samesign.njets(); }
const int &njetsAG() { return samesign.njetsAG(); }
const int &nbtagsAG() { return samesign.nbtagsAG(); }
const int &njets_raw() { return samesign.njets_raw(); }
const int &hyp_class() { return samesign.hyp_class(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return samesign.lep1_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return samesign.lep2_p4(); }
const float &lep1_pt() { return samesign.lep1_pt(); }
const float &lep2_pt() { return samesign.lep2_pt(); }
const float &lep3_pt() { return samesign.lep3_pt(); }
const float &lep1_eta() { return samesign.lep1_eta(); }
const float &lep2_eta() { return samesign.lep2_eta(); }
const float &lep3_eta() { return samesign.lep3_eta(); }
const float &lep1_phi() { return samesign.lep1_phi(); }
const float &lep2_phi() { return samesign.lep2_phi(); }
const float &lep3_phi() { return samesign.lep3_phi(); }
const float &ht_raw() { return samesign.ht_raw(); }
const float &ht() { return samesign.ht(); }
const int &lep1_motherID() { return samesign.lep1_motherID(); }
const int &lep2_motherID() { return samesign.lep2_motherID(); }
const int &lep1_mc_id() { return samesign.lep1_mc_id(); }
const int &lep2_mc_id() { return samesign.lep2_mc_id(); }
const int &lep1_mc_motherid() { return samesign.lep1_mc_motherid(); }
const int &lep2_mc_motherid() { return samesign.lep2_mc_motherid(); }
const int &lep1_id() { return samesign.lep1_id(); }
const int &lep2_id() { return samesign.lep2_id(); }
const float &lep1_coneCorrPt() { return samesign.lep1_coneCorrPt(); }
const float &lep2_coneCorrPt() { return samesign.lep2_coneCorrPt(); }
const float &lep3_coneCorrPt() { return samesign.lep3_coneCorrPt(); }
const float &lep4_coneCorrPt() { return samesign.lep4_coneCorrPt(); }
const int &lep1_idx() { return samesign.lep1_idx(); }
const int &lep2_idx() { return samesign.lep2_idx(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets() { return samesign.jets(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_jec_up() { return samesign.jets_jec_up(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_jec_dn() { return samesign.jets_jec_dn(); }
const vector<float> &jets_disc_up() { return samesign.jets_disc_up(); }
const vector<float> &jets_disc_dn() { return samesign.jets_disc_dn(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &bjets_jec_up() { return samesign.bjets_jec_up(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &bjets_jec_dn() { return samesign.bjets_jec_dn(); }
const vector<int> &btags_flavor() { return samesign.btags_flavor(); }
const vector<float> &btags_disc() { return samesign.btags_disc(); }
const vector<float> &btags_cdisc() { return samesign.btags_cdisc(); }
const vector<int> &jets_flavor() { return samesign.jets_flavor(); }
const vector<float> &jets_disc() { return samesign.jets_disc(); }
const vector<float> &jets_bsf() { return samesign.jets_bsf(); }
const vector<float> &jets_JEC() { return samesign.jets_JEC(); }
const vector<float> &btags_JEC() { return samesign.btags_JEC(); }
const vector<float> &jets_undoJEC() { return samesign.jets_undoJEC(); }
const vector<float> &btags_undoJEC() { return samesign.btags_undoJEC(); }
const vector<float> &btags_unc() { return samesign.btags_unc(); }
const vector<float> &btags_eff() { return samesign.btags_eff(); }
const vector<float> &btags_effpt() { return samesign.btags_effpt(); }
const vector<float> &btags_sf() { return samesign.btags_sf(); }
const vector<float> &jets_unc() { return samesign.jets_unc(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &btags() { return samesign.btags(); }
const int &nbtags() { return samesign.nbtags(); }
const int &nbtags_raw() { return samesign.nbtags_raw(); }
const float &sf_dilepTrig_hpt() { return samesign.sf_dilepTrig_hpt(); }
const float &sf_dilepTrig_lpt() { return samesign.sf_dilepTrig_lpt(); }
const float &sf_dilepTrig_vlpt() { return samesign.sf_dilepTrig_vlpt(); }
const int &hyp_type() { return samesign.hyp_type(); }
const float &sf_dilep_eff() { return samesign.sf_dilep_eff(); }
const float &mt() { return samesign.mt(); }
const float &mt_l2() { return samesign.mt_l2(); }
const float &mt2() { return samesign.mt2(); }
const float &mtmin() { return samesign.mtmin(); }
const int &lep1_id_gen() { return samesign.lep1_id_gen(); }
const int &lep2_id_gen() { return samesign.lep2_id_gen(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4_gen() { return samesign.lep1_p4_gen(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4_gen() { return samesign.lep2_p4_gen(); }
const int &lep3_id() { return samesign.lep3_id(); }
const int &lep3_idx() { return samesign.lep3_idx(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep3_p4() { return samesign.lep3_p4(); }
const int &lep3_quality() { return samesign.lep3_quality(); }
const int &lep4_id() { return samesign.lep4_id(); }
const int &lep4_idx() { return samesign.lep4_idx(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep4_p4() { return samesign.lep4_p4(); }
const float &lep1_iso() { return samesign.lep1_iso(); }
const float &lep2_iso() { return samesign.lep2_iso(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &dilep_p4() { return samesign.dilep_p4(); }
const float &dilep_mass() { return samesign.dilep_mass(); }
const float &mass13() { return samesign.mass13(); }
const float &mass23() { return samesign.mass23(); }
const float &mass123() { return samesign.mass123(); }
const int &ncharginos() { return samesign.ncharginos(); }
const int &nhiggs() { return samesign.nhiggs(); }
const int &higgs_mass() { return samesign.higgs_mass(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return samesign.genps_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genjets_p4() { return samesign.genjets_p4(); }
const vector<int> &genps_id() { return samesign.genps_id(); }
const vector<int> &genps_id_mother() { return samesign.genps_id_mother(); }
const vector<int> &genps_idx_mother() { return samesign.genps_idx_mother(); }
const vector<int> &genps_status() { return samesign.genps_status(); }
const vector<int> &genps_id_grandma() { return samesign.genps_id_grandma(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &all_leps_p4() { return samesign.all_leps_p4(); }
const vector<int> &all_leps_id() { return samesign.all_leps_id(); }
const vector<bool> &all_leps_veto() { return samesign.all_leps_veto(); }
const vector<int> &all_leps_mc3idx() { return samesign.all_leps_mc3idx(); }
const bool &lep1_passes_id() { return samesign.lep1_passes_id(); }
const bool &lep2_passes_id() { return samesign.lep2_passes_id(); }
const bool &lep3_passes_id() { return samesign.lep3_passes_id(); }
const bool &lep4_passes_id() { return samesign.lep4_passes_id(); }
const bool &lep1_tight() { return samesign.lep1_tight(); }
const bool &lep1_veto() { return samesign.lep1_veto(); }
const bool &lep1_fo() { return samesign.lep1_fo(); }
const bool &lep2_tight() { return samesign.lep2_tight(); }
const bool &lep2_veto() { return samesign.lep2_veto(); }
const bool &lep2_fo() { return samesign.lep2_fo(); }
const bool &lep3_tight() { return samesign.lep3_tight(); }
const bool &lep3_veto() { return samesign.lep3_veto(); }
const bool &lep3_fo() { return samesign.lep3_fo(); }
const bool &lep4_tight() { return samesign.lep4_tight(); }
const bool &lep4_veto() { return samesign.lep4_veto(); }
const bool &lep4_fo() { return samesign.lep4_fo(); }
const float &lep1_dxyPV() { return samesign.lep1_dxyPV(); }
const float &lep2_dxyPV() { return samesign.lep2_dxyPV(); }
const float &lep1_dZ() { return samesign.lep1_dZ(); }
const float &lep2_dZ() { return samesign.lep2_dZ(); }
const float &lep1_d0_err() { return samesign.lep1_d0_err(); }
const float &lep2_d0_err() { return samesign.lep2_d0_err(); }
const float &lep1_ip3d() { return samesign.lep1_ip3d(); }
const float &lep2_ip3d() { return samesign.lep2_ip3d(); }
const float &lep1_MVA() { return samesign.lep1_MVA(); }
const float &lep2_MVA() { return samesign.lep2_MVA(); }
const float &lep1_ip3d_err() { return samesign.lep1_ip3d_err(); }
const float &lep2_ip3d_err() { return samesign.lep2_ip3d_err(); }
const int &nVetoElectrons7() { return samesign.nVetoElectrons7(); }
const int &nVetoElectrons10() { return samesign.nVetoElectrons10(); }
const int &nVetoElectrons25() { return samesign.nVetoElectrons25(); }
const int &nVetoMuons5() { return samesign.nVetoMuons5(); }
const int &nVetoMuons10() { return samesign.nVetoMuons10(); }
const int &nVetoMuons25() { return samesign.nVetoMuons25(); }
const string &filename() { return samesign.filename(); }
const float &lep1_ptrel_ma() { return samesign.lep1_ptrel_ma(); }
const float &lep1_ptratio_ma() { return samesign.lep1_ptratio_ma(); }
const float &lep2_ptrel_ma() { return samesign.lep2_ptrel_ma(); }
const float &lep2_ptratio_ma() { return samesign.lep2_ptratio_ma(); }
const float &lep1_ptrel_v1() { return samesign.lep1_ptrel_v1(); }
const float &lep2_ptrel_v1() { return samesign.lep2_ptrel_v1(); }
const float &lep1_ptratio() { return samesign.lep1_ptratio(); }
const float &lep2_ptratio() { return samesign.lep2_ptratio(); }
const float &lep1_miniIso() { return samesign.lep1_miniIso(); }
const float &lep2_miniIso() { return samesign.lep2_miniIso(); }
const vector<float> &trueNumInt() { return samesign.trueNumInt(); }
const int &nGoodVertices() { return samesign.nGoodVertices(); }
const bool &lep1_trigMatch_noIsoReq() { return samesign.lep1_trigMatch_noIsoReq(); }
const bool &lep1_trigMatch_isoReq() { return samesign.lep1_trigMatch_isoReq(); }
const bool &lep2_trigMatch_noIsoReq() { return samesign.lep2_trigMatch_noIsoReq(); }
const bool &lep2_trigMatch_isoReq() { return samesign.lep2_trigMatch_isoReq(); }
const bool &passes_met_filters() { return samesign.passes_met_filters(); }
const bool &passes_chargedcand_filter() { return samesign.passes_chargedcand_filter(); }
const float &evt_egclean_pfmet() { return samesign.evt_egclean_pfmet(); }
const float &evt_muegclean_pfmet() { return samesign.evt_muegclean_pfmet(); }
const float &evt_muegcleanfix_pfmet() { return samesign.evt_muegcleanfix_pfmet(); }
const float &evt_uncorr_pfmet() { return samesign.evt_uncorr_pfmet(); }
const bool &filt_noBadMuons() { return samesign.filt_noBadMuons(); }
const bool &filt_duplicateMuons() { return samesign.filt_duplicateMuons(); }
const bool &filt_badMuons() { return samesign.filt_badMuons(); }
const bool &failsRA2Filter() { return samesign.failsRA2Filter(); }
const bool &madeExtraZ() { return samesign.madeExtraZ(); }
const bool &madeExtraG() { return samesign.madeExtraG(); }
const int &lep3_mcid() { return samesign.lep3_mcid(); }
const int &lep3_mc_motherid() { return samesign.lep3_mc_motherid(); }
const int &lep3_mc3idx() { return samesign.lep3_mc3idx(); }
const int &lep3_motherID() { return samesign.lep3_motherID(); }
const int &lep4_mcid() { return samesign.lep4_mcid(); }
const int &lep4_mcidx() { return samesign.lep4_mcidx(); }
const int &njets_unc_up() { return samesign.njets_unc_up(); }
const int &njets_unc_dn() { return samesign.njets_unc_dn(); }
const float &ht_unc_up() { return samesign.ht_unc_up(); }
const float &ht_unc_dn() { return samesign.ht_unc_dn(); }
const int &nbtags_unc_up() { return samesign.nbtags_unc_up(); }
const int &nbtags_unc_dn() { return samesign.nbtags_unc_dn(); }
const float &met_unc_up() { return samesign.met_unc_up(); }
const float &met_unc_dn() { return samesign.met_unc_dn(); }
const float &metPhi_unc_up() { return samesign.metPhi_unc_up(); }
const float &metPhi_unc_dn() { return samesign.metPhi_unc_dn(); }
const int &njets_JER_up() { return samesign.njets_JER_up(); }
const int &njets_JER_dn() { return samesign.njets_JER_dn(); }
const float &ht_JER_up() { return samesign.ht_JER_up(); }
const float &ht_JER_dn() { return samesign.ht_JER_dn(); }
const int &nbtags_JER_up() { return samesign.nbtags_JER_up(); }
const int &nbtags_JER_dn() { return samesign.nbtags_JER_dn(); }
const float &met_JER_up() { return samesign.met_JER_up(); }
const float &met_JER_dn() { return samesign.met_JER_dn(); }
const float &metPhi_JER_up() { return samesign.metPhi_JER_up(); }
const float &metPhi_JER_dn() { return samesign.metPhi_JER_dn(); }
const bool &lep2_genps_isHardProcess() { return samesign.lep2_genps_isHardProcess(); }
const bool &lep2_genps_fromHardProcessFinalState() { return samesign.lep2_genps_fromHardProcessFinalState(); }
const bool &lep2_genps_fromHardProcessDecayed() { return samesign.lep2_genps_fromHardProcessDecayed(); }
const bool &lep2_genps_isDirectHardProcessTauDecayProductFinalState() { return samesign.lep2_genps_isDirectHardProcessTauDecayProductFinalState(); }
const bool &lep2_genps_fromHardProcessBeforeFSR() { return samesign.lep2_genps_fromHardProcessBeforeFSR(); }
const bool &lep2_genps_isLastCopy() { return samesign.lep2_genps_isLastCopy(); }
const bool &lep2_genps_isLastCopyBeforeFSR() { return samesign.lep2_genps_isLastCopyBeforeFSR(); }
const bool &lep1_genps_isHardProcess() { return samesign.lep1_genps_isHardProcess(); }
const bool &lep1_genps_fromHardProcessFinalState() { return samesign.lep1_genps_fromHardProcessFinalState(); }
const bool &lep1_genps_fromHardProcessDecayed() { return samesign.lep1_genps_fromHardProcessDecayed(); }
const bool &lep1_genps_isDirectHardProcessTauDecayProductFinalState() { return samesign.lep1_genps_isDirectHardProcessTauDecayProductFinalState(); }
const bool &lep1_genps_fromHardProcessBeforeFSR() { return samesign.lep1_genps_fromHardProcessBeforeFSR(); }
const bool &lep1_genps_isLastCopy() { return samesign.lep1_genps_isLastCopy(); }
const bool &lep1_genps_isLastCopyBeforeFSR() { return samesign.lep1_genps_isLastCopyBeforeFSR(); }
const int &lep1_mc3idx() { return samesign.lep1_mc3idx(); }
const int &lep2_mc3idx() { return samesign.lep2_mc3idx(); }
const bool &lep1_el_conv_vtx_flag() { return samesign.lep1_el_conv_vtx_flag(); }
const bool &lep2_el_conv_vtx_flag() { return samesign.lep2_el_conv_vtx_flag(); }
const int &lep1_el_exp_innerlayers() { return samesign.lep1_el_exp_innerlayers(); }
const bool &lep1_mu_ptErr() { return samesign.lep1_mu_ptErr(); }
const bool &lep2_mu_ptErr() { return samesign.lep2_mu_ptErr(); }
const bool &lep1_el_threeChargeAgree() { return samesign.lep1_el_threeChargeAgree(); }
const bool &lep2_el_threeChargeAgree() { return samesign.lep2_el_threeChargeAgree(); }
const int &lep2_el_exp_innerlayers() { return samesign.lep2_el_exp_innerlayers(); }
const float &lep1_el_etaSC() { return samesign.lep1_el_etaSC(); }
const float &lep2_el_etaSC() { return samesign.lep2_el_etaSC(); }
const bool &lep1_nPixelMiss() { return samesign.lep1_nPixelMiss(); }
const bool &lep2_nPixelMiss() { return samesign.lep2_nPixelMiss(); }
const bool &lep1_tightCharge() { return samesign.lep1_tightCharge(); }
const bool &lep2_tightCharge() { return samesign.lep2_tightCharge(); }
const bool &lep1_isTrigSafeNoIsov1() { return samesign.lep1_isTrigSafeNoIsov1(); }
const bool &lep1_isTrigSafev1() { return samesign.lep1_isTrigSafev1(); }
const bool &lep2_isTrigSafeNoIsov1() { return samesign.lep2_isTrigSafeNoIsov1(); }
const bool &lep2_isTrigSafev1() { return samesign.lep2_isTrigSafev1(); }
const bool &lep1_tightMuonPOG() { return samesign.lep1_tightMuonPOG(); }
const bool &lep1_mediumMuonPOG() { return samesign.lep1_mediumMuonPOG(); }
const bool &lep1_looseMuonPOG() { return samesign.lep1_looseMuonPOG(); }
const bool &lep2_tightMuonPOG() { return samesign.lep2_tightMuonPOG(); }
const bool &lep2_mediumMuonPOG() { return samesign.lep2_mediumMuonPOG(); }
const bool &lep2_looseMuonPOG() { return samesign.lep2_looseMuonPOG(); }
const bool &lep3_mediumMuonPOG() { return samesign.lep3_mediumMuonPOG(); }
const float &prefire_sf() { return samesign.prefire_sf(); }
const float &prefire_sfup() { return samesign.prefire_sfup(); }
const float &prefire_sfdown() { return samesign.prefire_sfdown(); }
const float &prefire2016_sf() { return samesign.prefire2016_sf(); }
const float &prefire2016_sfup() { return samesign.prefire2016_sfup(); }
const float &prefire2016_sfdown() { return samesign.prefire2016_sfdown(); }
const float &prefire2017_sf() { return samesign.prefire2017_sf(); }
const float &prefire2017_sfup() { return samesign.prefire2017_sfup(); }
const float &prefire2017_sfdown() { return samesign.prefire2017_sfdown(); }
const float &prefire2017ele_sf() { return samesign.prefire2017ele_sf(); }
const float &prefire2017ele_sfup() { return samesign.prefire2017ele_sfup(); }
const float &prefire2017ele_sfdown() { return samesign.prefire2017ele_sfdown(); }
const bool &is_fastsim() { return samesign.is_fastsim(); }
const bool &lep1_isGoodLeg() { return samesign.lep1_isGoodLeg(); }
const bool &lep2_isGoodLeg() { return samesign.lep2_isGoodLeg(); }
const bool &lep1_isFakeLeg() { return samesign.lep1_isFakeLeg(); }
const bool &lep2_isFakeLeg() { return samesign.lep2_isFakeLeg(); }
const bool &lep1_multiIso() { return samesign.lep1_multiIso(); }
const bool &lep2_multiIso() { return samesign.lep2_multiIso(); }
const float &lep1_sip() { return samesign.lep1_sip(); }
const float &lep2_sip() { return samesign.lep2_sip(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_closeJet() { return samesign.lep1_closeJet(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_closeJet() { return samesign.lep2_closeJet(); }
const bool &passed_id_inSituFR_lep1() { return samesign.passed_id_inSituFR_lep1(); }
const bool &passed_id_inSituFR_lep2() { return samesign.passed_id_inSituFR_lep2(); }
const bool &fired_trigger() { return samesign.fired_trigger(); }
const bool &fired_trigger_ss() { return samesign.fired_trigger_ss(); }
const unsigned int &triggers() { return samesign.triggers(); }
const float &weight_btagsf() { return samesign.weight_btagsf(); }
const float &weight_btagsf_light_UP() { return samesign.weight_btagsf_light_UP(); }
const float &weight_btagsf_light_DN() { return samesign.weight_btagsf_light_DN(); }
const float &weight_btagsf_heavy_UP() { return samesign.weight_btagsf_heavy_UP(); }
const float &weight_btagsf_heavy_DN() { return samesign.weight_btagsf_heavy_DN(); }
const float &weight_btagsf_iter_central() { return samesign.weight_btagsf_iter_central(); }
const float &weight_btagsf_iter_down_cferr1() { return samesign.weight_btagsf_iter_down_cferr1(); }
const float &weight_btagsf_iter_down_cferr2() { return samesign.weight_btagsf_iter_down_cferr2(); }
const float &weight_btagsf_iter_down_hf() { return samesign.weight_btagsf_iter_down_hf(); }
const float &weight_btagsf_iter_down_hfstats1() { return samesign.weight_btagsf_iter_down_hfstats1(); }
const float &weight_btagsf_iter_down_hfstats2() { return samesign.weight_btagsf_iter_down_hfstats2(); }
const float &weight_btagsf_iter_down_jes() { return samesign.weight_btagsf_iter_down_jes(); }
const float &weight_btagsf_iter_down_lf() { return samesign.weight_btagsf_iter_down_lf(); }
const float &weight_btagsf_iter_down_lfstats1() { return samesign.weight_btagsf_iter_down_lfstats1(); }
const float &weight_btagsf_iter_down_lfstats2() { return samesign.weight_btagsf_iter_down_lfstats2(); }
const float &weight_btagsf_iter_up_cferr1() { return samesign.weight_btagsf_iter_up_cferr1(); }
const float &weight_btagsf_iter_up_cferr2() { return samesign.weight_btagsf_iter_up_cferr2(); }
const float &weight_btagsf_iter_up_hf() { return samesign.weight_btagsf_iter_up_hf(); }
const float &weight_btagsf_iter_up_hfstats1() { return samesign.weight_btagsf_iter_up_hfstats1(); }
const float &weight_btagsf_iter_up_hfstats2() { return samesign.weight_btagsf_iter_up_hfstats2(); }
const float &weight_btagsf_iter_up_jes() { return samesign.weight_btagsf_iter_up_jes(); }
const float &weight_btagsf_iter_up_lf() { return samesign.weight_btagsf_iter_up_lf(); }
const float &weight_btagsf_iter_up_lfstats1() { return samesign.weight_btagsf_iter_up_lfstats1(); }
const float &weight_btagsf_iter_up_lfstats2() { return samesign.weight_btagsf_iter_up_lfstats2(); }
const float &weight() { return samesign.weight(); }
const float &weight_lepsf1() { return samesign.weight_lepsf1(); }
const float &weight_lepsf2() { return samesign.weight_lepsf2(); }
const float &weight_lepsf3() { return samesign.weight_lepsf3(); }
const float &weight_lepsf() { return samesign.weight_lepsf(); }
const float &weight_triggersf() { return samesign.weight_triggersf(); }
const float &weight_pu() { return samesign.weight_pu(); }
const float &weight_isrsf() { return samesign.weight_isrsf(); }
const int &year() { return samesign.year(); }
const float &yearlumi() { return samesign.yearlumi(); }
const float &weight_scale_UP() { return samesign.weight_scale_UP(); }
const float &weight_scale_DN() { return samesign.weight_scale_DN(); }
const float &weight_pdf_UP() { return samesign.weight_pdf_UP(); }
const float &weight_pdf_DN() { return samesign.weight_pdf_DN(); }
const float &weight_alphas_UP() { return samesign.weight_alphas_UP(); }
const float &weight_alphas_DN() { return samesign.weight_alphas_DN(); }
const float &weight_isrvar_UP() { return samesign.weight_isrvar_UP(); }
const float &weight_isrvar_DN() { return samesign.weight_isrvar_DN(); }
const float &weight_fsrvar_UP() { return samesign.weight_fsrvar_UP(); }
const float &weight_fsrvar_DN() { return samesign.weight_fsrvar_DN(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gl1_p4() { return samesign.gl1_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gl2_p4() { return samesign.gl2_p4(); }
const float &glglpt() { return samesign.glglpt(); }
const float &isr_unc() { return samesign.isr_unc(); }
const int &nisrMatch() { return samesign.nisrMatch(); }
const float &weight_isr() { return samesign.weight_isr(); }
const float &weight_isr_dy() { return samesign.weight_isr_dy(); }
const float &weight_isr_tt() { return samesign.weight_isr_tt(); }
const float &weight_isr_UP() { return samesign.weight_isr_UP(); }
const float &weight_isr_DN() { return samesign.weight_isr_DN(); }
const bool &lep3_el_etaSC() { return samesign.lep3_el_etaSC(); }
const bool &lep3_el_conv_vtx_flag() { return samesign.lep3_el_conv_vtx_flag(); }
const bool &lep3_el_exp_innerlayers() { return samesign.lep3_el_exp_innerlayers(); }
const bool &lep3_el_threeChargeAgree() { return samesign.lep3_el_threeChargeAgree(); }
const bool &lep3_el_dxyPV() { return samesign.lep3_el_dxyPV(); }
const bool &lep3_el_ip3d() { return samesign.lep3_el_ip3d(); }
const bool &lep3_el_dzPV() { return samesign.lep3_el_dzPV(); }
const float &lep3_el_MVA_value() { return samesign.lep3_el_MVA_value(); }
const bool &lep3_el_MVA() { return samesign.lep3_el_MVA(); }
const bool &lep3_passes_RA5() { return samesign.lep3_passes_RA5(); }
const bool &lep3_mu_dxyPV() { return samesign.lep3_mu_dxyPV(); }
const bool &lep3_mu_ip3d() { return samesign.lep3_mu_ip3d(); }
const bool &lep3_mu_dzPV() { return samesign.lep3_mu_dzPV(); }
const bool &lep3_mu_ptErr() { return samesign.lep3_mu_ptErr(); }
const bool &lep4_el_etaSC() { return samesign.lep4_el_etaSC(); }
const bool &lep4_el_conv_vtx_flag() { return samesign.lep4_el_conv_vtx_flag(); }
const bool &lep4_el_exp_innerlayers() { return samesign.lep4_el_exp_innerlayers(); }
const bool &lep4_el_threeChargeAgree() { return samesign.lep4_el_threeChargeAgree(); }
const bool &lep4_el_dxyPV() { return samesign.lep4_el_dxyPV(); }
const bool &lep4_el_ip3d() { return samesign.lep4_el_ip3d(); }
const bool &lep4_el_dzPV() { return samesign.lep4_el_dzPV(); }
const float &lep4_el_MVA_value() { return samesign.lep4_el_MVA_value(); }
const bool &lep4_el_MVA() { return samesign.lep4_el_MVA(); }
const bool &lep4_mu_dxyPV() { return samesign.lep4_mu_dxyPV(); }
const bool &lep4_mu_ip3d() { return samesign.lep4_mu_ip3d(); }
const bool &lep4_mu_dzPV() { return samesign.lep4_mu_dzPV(); }
const bool &lep4_mu_ptErr() { return samesign.lep4_mu_ptErr(); }
const bool &lep3_isTrigSafeNoIsov1() { return samesign.lep3_isTrigSafeNoIsov1(); }
const bool &lep3_isTrigSafev1() { return samesign.lep3_isTrigSafev1(); }
const bool &lep4_isTrigSafeNoIsov1() { return samesign.lep4_isTrigSafeNoIsov1(); }
const bool &lep4_isTrigSafev1() { return samesign.lep4_isTrigSafev1(); }
const int &extragenb() { return samesign.extragenb(); }
const vector<int> &extragenbmoms() { return samesign.extragenbmoms(); }
const int &extragenc() { return samesign.extragenc(); }
const vector<int> &extragencmoms() { return samesign.extragencmoms(); }
const int &ngenjets() { return samesign.ngenjets(); }
const float &genht() { return samesign.genht(); }
const int &ngenjets30() { return samesign.ngenjets30(); }
const float &genht30() { return samesign.genht30(); }
const bool &passfilter() { return samesign.passfilter(); }
const bool &hasgammatoll() { return samesign.hasgammatoll(); }
const bool &gammatollmomemu() { return samesign.gammatollmomemu(); }
const float &gammatolldr() { return samesign.gammatolldr(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gammatoll1() { return samesign.gammatoll1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gammatoll2() { return samesign.gammatoll2(); }
const vector<int> &bjet_type() { return samesign.bjet_type(); }
const vector<int> &jet_type() { return samesign.jet_type(); }
const vector<int> &jet_cat() { return samesign.jet_cat(); }
const vector<int> &jet_matchedGenIndex() { return samesign.jet_matchedGenIndex(); }
const vector<int> &jet_matchedGenId() { return samesign.jet_matchedGenId(); }
const vector<int> &jet_matchedGenMId() { return samesign.jet_matchedGenMId(); }
const vector<float> &jet_matchedDr() { return samesign.jet_matchedDr(); }
const vector<float> &jet_matchedPtDiff() { return samesign.jet_matchedPtDiff(); }
const int &ndrlt0p4() { return samesign.ndrlt0p4(); }
const bool &gengood() { return samesign.gengood(); }
const int &nleptonic() { return samesign.nleptonic(); }
const int &ntau() { return samesign.ntau(); }
const int &nleptonicW() { return samesign.nleptonicW(); }
const float &mfourtop() { return samesign.mfourtop(); }
const int &nhadronicW() { return samesign.nhadronicW(); }
const int &nW() { return samesign.nW(); }
const float &leptonicWSF() { return samesign.leptonicWSF(); }
const float &hadronicWSF() { return samesign.hadronicWSF(); }
const float &decayWSF() { return samesign.decayWSF(); }
const int &njincone1() { return samesign.njincone1(); }
const int &njincone2() { return samesign.njincone2(); }
const int &bdt_nforwardjets20() { return samesign.bdt_nforwardjets20(); }
const float &bdt_avgcdisc() { return samesign.bdt_avgcdisc(); }
const float &bdt_nbtags() { return samesign.bdt_nbtags(); }
const float &bdt_njets() { return samesign.bdt_njets(); }
const float &bdt_met() { return samesign.bdt_met(); }
const float &bdt_ptl2() { return samesign.bdt_ptl2(); }
const float &bdt_nlb40() { return samesign.bdt_nlb40(); }
const float &bdt_ntb40() { return samesign.bdt_ntb40(); }
const float &bdt_nleps() { return samesign.bdt_nleps(); }
const float &bdt_htb() { return samesign.bdt_htb(); }
const float &bdt_ml1j1() { return samesign.bdt_ml1j1(); }
const float &bdt_dphil1l2() { return samesign.bdt_dphil1l2(); }
const float &bdt_maxmjoverpt() { return samesign.bdt_maxmjoverpt(); }
const float &bdt_detal1l2() { return samesign.bdt_detal1l2(); }
const float &bdt_q1() { return samesign.bdt_q1(); }
const float &bdt_ptj1() { return samesign.bdt_ptj1(); }
const float &bdt_ptj6() { return samesign.bdt_ptj6(); }
const float &bdt_ptj7() { return samesign.bdt_ptj7(); }
const float &bdt_ptj8() { return samesign.bdt_ptj8(); }
const float &bdt_ptl1() { return samesign.bdt_ptl1(); }
const float &bdt_ptl3() { return samesign.bdt_ptl3(); }
const float &bdt_jec_up_nbtags() { return samesign.bdt_jec_up_nbtags(); }
const float &bdt_jec_dn_nbtags() { return samesign.bdt_jec_dn_nbtags(); }
const float &bdt_jer_up_nbtags() { return samesign.bdt_jer_up_nbtags(); }
const float &bdt_jer_dn_nbtags() { return samesign.bdt_jer_dn_nbtags(); }
const float &bdt_jec_up_njets() { return samesign.bdt_jec_up_njets(); }
const float &bdt_jec_dn_njets() { return samesign.bdt_jec_dn_njets(); }
const float &bdt_jer_up_njets() { return samesign.bdt_jer_up_njets(); }
const float &bdt_jer_dn_njets() { return samesign.bdt_jer_dn_njets(); }
const float &bdt_jec_up_met() { return samesign.bdt_jec_up_met(); }
const float &bdt_jec_dn_met() { return samesign.bdt_jec_dn_met(); }
const float &bdt_jer_up_met() { return samesign.bdt_jer_up_met(); }
const float &bdt_jer_dn_met() { return samesign.bdt_jer_dn_met(); }
const float &bdt_jec_up_htb() { return samesign.bdt_jec_up_htb(); }
const float &bdt_jec_dn_htb() { return samesign.bdt_jec_dn_htb(); }
const float &bdt_jer_up_htb() { return samesign.bdt_jer_up_htb(); }
const float &bdt_jer_dn_htb() { return samesign.bdt_jer_dn_htb(); }
const float &bdt_jec_up_nlb40() { return samesign.bdt_jec_up_nlb40(); }
const float &bdt_jec_dn_nlb40() { return samesign.bdt_jec_dn_nlb40(); }
const float &bdt_jer_up_nlb40() { return samesign.bdt_jer_up_nlb40(); }
const float &bdt_jer_dn_nlb40() { return samesign.bdt_jer_dn_nlb40(); }
const float &bdt_jec_up_ntb40() { return samesign.bdt_jec_up_ntb40(); }
const float &bdt_jec_dn_ntb40() { return samesign.bdt_jec_dn_ntb40(); }
const float &bdt_jer_up_ntb40() { return samesign.bdt_jer_up_ntb40(); }
const float &bdt_jer_dn_ntb40() { return samesign.bdt_jer_dn_ntb40(); }
const float &bdt_disc() { return samesign.bdt_disc(); }
const float &bdt_disc_jec_up() { return samesign.bdt_disc_jec_up(); }
const float &bdt_disc_jer_up() { return samesign.bdt_disc_jer_up(); }
const float &bdt_disc_jec_dn() { return samesign.bdt_disc_jec_dn(); }
const float &bdt_disc_jer_dn() { return samesign.bdt_disc_jer_dn(); }
const float &bdt_run2_disc() { return samesign.bdt_run2_disc(); }
const int &bdt_run2_SRDISC() { return samesign.bdt_run2_SRDISC(); }
const float &bdt_run2_disc_jec_up() { return samesign.bdt_run2_disc_jec_up(); }
const float &bdt_run2_disc_jer_up() { return samesign.bdt_run2_disc_jer_up(); }
const float &bdt_run2_disc_jec_dn() { return samesign.bdt_run2_disc_jec_dn(); }
const float &bdt_run2_disc_jer_dn() { return samesign.bdt_run2_disc_jer_dn(); }

}
