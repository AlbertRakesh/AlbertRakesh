void tut23()
{   
    THStack *hstack = new THStack("hstack","Histogram Stack; x title ; ytitle");//This function adjust the x and y axis irrespective of the entries in both hist and hist2


    TH1F *hist = new TH1F("hist", "Histogram; x title; y title", 100, -10,10);
    TH1F *hist2 = new TH1F("hist2", "Histogram 2; x title; y title", 100, -10,10);

    hstack->Add(hist);
    hstack->Add(hist2);

    
    hist->FillRandom("gaus",1e4);
    hist2->FillRandom("gaus",1e5);

    TCanvas *c1 = new TCanvas();
    
    hist->Draw();
    hist2->Draw("same");

    TCanvas *c2 = new TCanvas();
    hstack->Draw();
}