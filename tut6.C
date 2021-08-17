void tut6()//the fuction name should be the same as the file name
{
    //Type we need for histogram is H= Histogram,1= 1D, F= Float value we can also write I for integer
    TH1F *hist = new TH1F("hist","Histogram",100,0,10);//name,title,no.of bins, start value, end value
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
    hist->GetXaxis()->SetTitle("Arbitary Distribution");
    hist->GetYaxis()->SetTitle("Entries");//Naming Axis
    

    TCanvas *c1 = new TCanvas();// Canvas names c1(Canvas is a window in which Histogram will be drawn)

    hist->Draw();
}