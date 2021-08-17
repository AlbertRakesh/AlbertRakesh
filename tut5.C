void tut5()
{
    TRandom2 *rand= new TRandom2();//TRandom2() creat the same random again and again by running the code multiple times
    //TRandom2 *rand= new TRandom2();//Trandom2(0) creates diffrent random number again and again

    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 100);

    for(int i=0; i<1000; i++)
    {
        double r = rand->Rndm()*100;
        cout<< r <<endl;
        hist->Fill(r);
    }

    TCanvas *c1 = new TCanvas();
    hist->GetYaxis()->SetRangeUser(0,200);//This will set the Y axis range from 0 to 200.
    hist->Draw();
}