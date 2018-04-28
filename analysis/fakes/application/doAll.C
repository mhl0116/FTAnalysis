{

    gSystem->Exec("mkdir -p plots");
    gSystem->Exec("mkdir -p outputs");

    gSystem->Load("../../../common/CORE/CMS3_CORE.so");
    gROOT->ProcessLine(".L ../../../common/Software/dataMCplotMaker/PlotMaker2D.cc+");
    gROOT->ProcessLine(".L ../../../common/Software/dataMCplotMaker/dataMCplotMaker.cc+");
    // gSystem->Load("../../../common/Software/tableMaker/libSimpleTable.so");
    gROOT->ProcessLine(".L ../../misc/class_files/v8.02/SS.cc+"); 
    gROOT->ProcessLine(".L ../../misc/common_utils.h");
    gROOT->ProcessLine(".L ScanChain.C+");

    TString tag = "v1.03_os_nmiss1_dileptrig_v1";
    TString basedir = Form("/nfs-7/userdata/namin/tupler_babies/merged/FT/%s/output/",tag.Data());


    bool highhigh   = 1;
    bool highlow    = 0;
    bool lowlow     = 0;

    bool doIsoTrigs = 0;
    bool doHTTrigs  = 0;

    //These are only for not-in-situ
    bool doConeCorr   = 1; 
    bool doJetCorr    = 0;
    bool doPtRatioCor = 0;
    bool doConly      = 0;

    bool doData          = 0;

    bool doInSitu        = 0;
    bool testMVA         = 0; // use modified MVA from Lesya in 2015 AN for ISFR
    bool extrPt          = 0; // extra Ptbin for electrons
    bool inclusiveHT     = 0; // use inclusive HT FR

    bool doBonly         = 0;
    bool doLightonly     = 0;

    //For both inSitu and not-in-Situ
    bool doLooseEMVA  = 1;

    //These are only for inSitu (choose only one of these)
    bool soup         = 1;
    bool PC           = 0;   
    bool ssZ          = 0;
    bool PCssZ        = 0;

    TString option = "";

    if (doLooseEMVA) option+="_LooseEMVA";

    if (!doInSitu){
        if (doPtRatioCor) option+="_PtRatioCor";
        if (doBonly) option+="_doBonly";
        if (doConly) option+="_doConly";
        if (doLightonly) option+="_doLightonly";
        if (doIsoTrigs) option+="_IsoTrigs";
        if (doHTTrigs) option+="_HTTrigs";
    }
    else {
        if (soup) option += "_soup";
        if (PC) option += "_PC";
        if (ssZ) option += "_ssZ";
        if (PCssZ) option += "_PCssZ";
        if (doBonly) option+="_doBonly";
        if (doLightonly) option+="_doLightonly";
        if (testMVA) option+="_mva";
        if (extrPt) option+="_ept";
        if (inclusiveHT) option+="_hth";

        option += "_inSitu"; 
    }

    TString ptRegion = "";
    if (highhigh) ptRegion = "HH";
    else if (highlow)  ptRegion = "HL";
    else if (lowlow)   ptRegion = "LL";

    if (doConeCorr) option+="_coneCorr";     //option only for ScanChain
    else if (doJetCorr) option+="_jetCorr";  //option only for ScanChain

    TChain *ch = new TChain("t"); 
    if (doLooseEMVA){

        ch->Add(basedir+"WJets*.root");
        ch->Add(basedir+"W3Jets*.root");
        ch->Add(basedir+"W4Jets*.root");
        ch->Add(basedir+"TTBAR*.root");
        ch->Add(basedir+"TTSL*.root");

    }
    ScanChain(ch, option, ptRegion, doData);

}