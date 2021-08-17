void tut27()
{
    TCanvas *c1 = new TCanvas();

    TH1F *hist = new TH1F("hist","Histogram",100,-5,5);

    gSystem->Unlink("tut27.gif");

    TRandom *r1 = new TRandom();

    for(int i; i<1e5; i++)
    {
        double val = r1->Gaus();

        hist->Fill(val);

        
        c1->Update();


        if(i%1000==0)
        {
            hist->Draw();

            hist->Fit("gaus");

            c1->Modified();

            c1->Print("tut27.gif+");
        }

        //sleep(1);
    }
}