
float electronFakeRate(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.36981;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.383718;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.362124;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.133003;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0755931;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.133186;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0315937;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0376022;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0638557;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0251877;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0372342;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0549677;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0626672;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0735429;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0931147;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.061663;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0921774;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.215701;
   return 0.;
}
float electronFakeRateError(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.111512;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.135129;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.117337;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0446089;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0300182;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.043425;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.00535719;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00487839;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00649896;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.00893708;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00881564;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00836344;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0206769;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0186938;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0152815;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0546133;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0543197;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0320851;
   return 0.;
}
float electronAlternativeFakeRate(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.382676;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.391241;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.368939;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.141314;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0824579;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.138625;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0424712;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0438981;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0701547;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0547766;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0632946;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0745759;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.103332;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.103093;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.115565;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.15574;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.162295;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.248976;
   return 0.;
}
float electronQCDMCFakeRate(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.419199;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.555941;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.401207;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.114011;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.158569;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.133304;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0314069;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0421826;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0801429;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0316121;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0632297;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0760515;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0463065;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0823888;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.089693;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.116887;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.109561;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.220749;
   return 0.;
}
float electronQCDMCFakeRateError(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0342985;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0555685;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0727932;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0205042;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0282231;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0253392;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.00515412;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00897237;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0128846;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.006374;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0146773;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0143184;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0170263;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0251064;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0198553;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0240659;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0264197;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0285809;
   return 0.;
}
float muonFakeRate(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.354006;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.621269;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.867166;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.116508;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.158848;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.234058;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0543697;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0777509;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.106282;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0327853;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0464213;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0734142;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0309721;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0790612;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.171895;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0409047;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0672507;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0748109;
   return 0.;
}
float muonFakeRateError(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.069825;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0833717;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0705844;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0251054;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0322081;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0688981;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00340569;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00685145;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0130351;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00490755;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00615822;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0156257;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0127567;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0173757;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0494435;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0456718;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0493545;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.082103;
   return 0.;
}
float muonAlternativeFakeRate(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.358923;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.623186;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.867349;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.120663;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.163093;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.237754;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0592764;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0819723;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.110947;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0471606;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.059317;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0882578;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0649026;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.110785;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.212814;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.142218;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.148892;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.140571;
   return 0.;
}
float muonQCDMCFakeRate(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.487377;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.546701;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.623436;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.180421;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.233764;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.276287;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0559866;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0855432;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0870248;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0455394;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0476693;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0605056;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0397106;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0502728;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0467293;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0416343;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0309539;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0744445;
   return 0.;
}
float muonQCDMCFakeRateError(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0285984;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.037725;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0656202;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0106149;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0135287;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0277261;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00343017;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0062241;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0105301;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00374755;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00434172;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0107851;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00430129;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00834233;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0104868;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00564941;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00596473;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0284388;
   return 0.;
}
float electronFakeRate_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.399517;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.309811;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.434438;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.134356;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0698361;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.176659;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.066665;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0726639;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.127959;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0815907;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0948904;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.118105;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.200984;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.211708;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.202369;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.179963;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.215289;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.335676;
   return 0.;
}
float electronFakeRateError_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.114154;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.156859;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.117954;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0453775;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0352535;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0566394;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0117897;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0100704;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0137485;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0263674;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0220746;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.018203;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0541642;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0440632;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0301238;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.123269;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0975551;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0479959;
   return 0.;
}
float electronAlternativeFakeRate_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.411706;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.319932;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.44013;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.145958;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0791544;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.183327;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0897719;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0851022;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.140822;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.161406;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.156382;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.160284;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.296645;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.275973;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.241973;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.358781;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.32547;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.382484;
   return 0.;
}
float electronQCDMCFakeRate_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.473083;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.567948;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.392926;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.158189;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.221255;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.158681;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0711147;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0829365;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.142449;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0724598;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.12906;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.147341;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0876978;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.158748;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.181927;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.234259;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.159783;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.279726;
   return 0.;
}
float electronQCDMCFakeRateError_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0386555;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0605446;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0831535;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0285307;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0397752;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0324968;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0123077;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0186246;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.023666;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0149396;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.030675;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0288891;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0338453;
   if (pt>=50 && pt<70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0478536;
   if (pt>=50 && pt<70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0400865;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0479921;
   if (pt>=70 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0422983;
   if (pt>=70 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0376069;
   return 0.;
}
float muonFakeRate_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.456183;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.503314;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.753577;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.13494;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.201235;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.240378;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0547237;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0825184;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.116947;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0319443;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0527539;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0976572;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0324658;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0794616;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.17036;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00820082;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.102714;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.136371;
   return 0.;
}
float muonFakeRateError_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0663737;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0774264;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.135461;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0231234;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0318881;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0621004;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00367468;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00574222;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0144314;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00529704;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00750998;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0203471;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0173555;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0193183;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0532047;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0518057;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0634912;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.124867;
   return 0.;
}
float muonAlternativeFakeRate_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.460922;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.50675;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.754475;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.139011;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.204974;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.243565;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0595995;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0870346;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.121923;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0462357;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0673314;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.11558;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0754802;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.112051;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.206762;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.119462;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.192906;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.221259;
   return 0.;
}
float muonQCDMCFakeRate_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.487586;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.546481;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.623434;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.180428;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.234253;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.277217;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0561112;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0862904;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0875979;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0459424;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0490801;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0625659;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0407351;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0527953;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.04827;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.043032;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0332423;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0814473;
   return 0.;
}
float muonQCDMCFakeRateError_IsoTrigs(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0286314;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0377409;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0656204;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0106153;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0136063;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0278149;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00343782;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00629038;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.010644;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00378464;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00447875;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0111401;
   if (pt>=50 && pt<70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00441541;
   if (pt>=50 && pt<70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00874783;
   if (pt>=50 && pt<70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0108512;
   if (pt>=70 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00585459;
   if (pt>=70 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00640964;
   if (pt>=70 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0309156;
   return 0.;
}

float fakeRate(int id, float pt, float eta, float ht) { 
    if (abs(id)==11) return electronFakeRate_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonFakeRate_IsoTrigs(pt,eta);
    else return 0.;
}

float fakeRateError(int id, float pt, float eta, float ht) { 
    if (abs(id)==11) return electronFakeRateError_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonFakeRateError_IsoTrigs(pt,eta);
    else return 0.;
}

float alternativeFakeRate(int id, float pt, float eta, float ht) { 
    if (abs(id)==11) return electronAlternativeFakeRate_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonAlternativeFakeRate_IsoTrigs(pt,eta);
    else return 0.;
}

float qcdMCFakeRate(int id, float pt, float eta, float ht) { 
    if (abs(id)==11) return electronQCDMCFakeRate_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonQCDMCFakeRate_IsoTrigs(pt,eta);
    else return 0.;
}

float qcdMCFakeRateError(int id, float pt, float eta, float ht) { 
    if (abs(id)==11) return electronQCDMCFakeRateError_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonQCDMCFakeRateError_IsoTrigs(pt,eta);
    else return 0.;
}
