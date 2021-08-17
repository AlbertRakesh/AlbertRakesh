void Hist()//the fuction name should be the same as the file name
{
    //Type we need for histogram is H= Histogram,1= 1D , F= Float value we can also write I for integer
    TH1F *hist = new TH1F("hist","Histogram",100,0,100);//name,title,no.of pin, start value, end value
    hist->Fill(10);//the histogram will be filled with the value 10
    hist->Fill(90);//Filled with 90

    hist->GetXaxis()->SetTitle("X Axis");
    hist->GetYaxis()->SetTitle("Y Axis");//Naming Axis
    

    TCanvas *c1 = new TCanvas();// Canvas names c1(Canvas is a window in which Histogram will be drawn)

    hist->Draw();
}