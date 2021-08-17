void plot()
{
    TFile *file = new TFile("output.root","READ");//We are reading the output.root

    TH1F *hist = (TH1F*)file->Get("hist");
     
    hist->Draw();

   // file->Close();
}