void tut9()//the fuction name should be the same as the file name
{
    //Type we need for histogram is H= Histogram,1= 1D, F= Float value we can also write I for integer
    TH1F *hist = new TH1F("hist","",100,0,15);//name,title,no.of bins, start value, end value
    //hist->Fill(10);//the histogram will be filled with the value 10
    //hist->Fill(90);//Filled with 90

    TRandom2 *rand =new TRandom2(3);//taking seed 3

    // First we write the data in the file

    fstream file;//fstream class fom C++ help us to open the file


    file.open("data.txt", ios::out);// OPEN THE FILE(Here we'll read out the data meaning we'll write the data)
    

    for(int i=0; i<1000; i++)
    {
       double r= rand->Gaus(5,1);// Gaussian distribution (mean, std deviation)
       file << r << endl;//write every value we get from gaussian distribution
    }
    
    file.close();


    //fstream//fstream class fom C++ help us to open the file


// We read the data that we wrote


    file.open("data.txt", ios::in);// OPEN THE FILE

    double value;//value is the data type that is in our file we want to read

    while(1)
    {
       file>>value;
       hist->Fill(value);
       if(file.eof()) break;//eof=end of file that mean if file reaches to the end stop it i.e break the while loop
    }

    file.close();//close the file
    
    hist->SetFillColor(kGreen-9);//Filling color to the histogram(kGreen-number represents the intenity change)

    hist->GetXaxis()->SetTitle("Arbitary Distribution");
    hist->GetYaxis()->SetTitle("Entries");//Naming Axis
    
    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);

    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);


    TF1 *fit = new TF1("fit","gaus",0,15);//fit the gaussian fit from 0 to 10;
    fit->SetLineWidth(3);
    //fit->SetLineColor(kBlue);
    fit->SetLineStyle(2);//Line style can be change by changing 1,2,3 etc.

    //fit->SetParameter(0,40);
    //fit->SetParameter(5);
   // fit->SetParameter(1);

    TCanvas *c1 = new TCanvas();// Canvas names c1(Canvas is a window in which Histogram will be drawn)
    c1->SetTickx();//additional ticks in the x axis
    c1->SetTicky();//additional ticks in the y axis


    hist->SetStats(0);//This will remove the statistics box
   
    hist->Draw();
    //hist->Fit("gaus");
    //hist->Fit("fit");
    hist->Fit("fit","R");//here R refers to the region in which we want to fit our plot
    // Introducing Legend
    
    TLegend *leg = new TLegend(0.5,0.6,0.8,0.8);//TLegend(xmin,ymin,xmax,ymax)
    leg->SetBorderSize(0);//To set no border(box) to the legend
    leg->AddEntry(hist, "Measure Data","f");//variable hist , name , f=filling
    leg->AddEntry(fit,"Fit Function","l");// varaibale fit, name , l=line
    leg->Draw();


    double mean = fit->GetParameter(1);
    double sigma= fit->GetParameter(2);

    cout << mean/sigma << endl;
}