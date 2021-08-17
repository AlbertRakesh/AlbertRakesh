void tut4()
{
    //double x[5]={1,2,3,4,5};//Array for the first value
    //double y[5]={1,8,27,64,125};// Array for the y value

    TGraph *gr = new TGraph();//if we don't know input parameters in the file


    fstream file;
    file.open("data2.txt", ios::in);//ios::in because we have to read the data
    while(1)
    {
       double x,y;//as we need to read two values in the file
       file>>x>>y;//the first column x and second column y
       gr->SetPoint(gr->GetN(),x,y);//if we don't know the number GetN() will take till the max no available in the file.
       if(file.eof()) break;

    }
    
    file.close();

    gr->SetTitle("GRAPH");
    gr->GetXaxis()->SetTitle("X Axis");
    gr->GetYaxis()->SetTitle("Y Axis");//Naming Axis
    gr->SetMarkerStyle(4);
    gr->SetMarkerStyle(kFullCircle);
    gr->SetLineWidth(2);
    gr->SetLineColor(kRed);
    gr->SetMarkerSize(1);
    TCanvas *c1 = new TCanvas();
    gr->Draw("ALP");// Here A implies all things is drawn L means all the data points are connected in line
    //AL* can be written in which case the data points will be shown as *
    //

}