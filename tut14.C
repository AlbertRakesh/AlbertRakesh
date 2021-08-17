void tut14()
{


    TFile *file = new TFile("output.root","RECREATE");//TFile class it will store everything that will be created after this

    TH1F *hist = new TH1F ("hist","Histogram",100,0,100);

    hist->Fill(10);
    hist->Fill(90);

    file->Write();//Everything above it will be written in the file

    file->Close();
    //hist->Draw();


}