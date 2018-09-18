float isrWeight(int nisrmatch, int sample) {
    // Derive `scale` which is a factor that preserves the integral of the
    // isr-reweighted events. Done per sample.
    // t->Draw("njets>>hw(10,0,10)","weight_isr_tt * scale1fb")
    // t->Draw("njets>>hunw(10,0,10)","1 * scale1fb")
    // hunw->Integral() / hw->Integral() // sf
    float scale = 1.;
    if (sample == 1) { // ttW
        scale = 1.09063;
    } else if (sample == 2) { // ttZ
        scale = 1.10315;
    } else if (sample == 3) { // ttH
        scale = 1.10286;
    }
    if (nisrmatch == 0) { return scale*1.00; }
    else if (nisrmatch == 1) { return scale*0.86; }
    else if (nisrmatch == 2) { return scale*0.79; }
    else if (nisrmatch == 3) { return scale*0.75; }
    else if (nisrmatch == 4) { return scale*0.77; }
    else if (nisrmatch == 5) { return scale*0.74; }
    else if (nisrmatch == 6) { return scale*0.73; }
    else if (nisrmatch == 7) { return scale*0.56; }
    else { return scale; }
}
