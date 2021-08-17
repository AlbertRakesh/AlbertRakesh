void tut15()
{
    fstream file;
    file.open("data4.txt",ios::in);

    double x,y;
    double x1,y1;

    TFile *output = new TFile("data4.root","RECREATE");

    TTree *tree = new TTree("tree","tree");//name and title

    tree->Branch("x", &x , "x/D");//the data is store in tree format x, address of x and x/I denotes x is integer
    tree->Branch("y", &y, "y/D" );                                         // is x would been float it should have been x/F and for double x/D

    while(1)
    {
        file >> x1 >> y1;

        if(file.eof()) break;

        cout << x1 << " " << y1 <<endl;
        x=x1;
        y=y1;
        tree->Fill();

        

    }

    output->Write();

    output->Close();

    file.close();
}