void Graph()
{
    double x[5]={1,2,3,4,5};//Array for the first value
    double y[5]={1,8,27,64,125};// Array for the y value

    TGraph *gr = new TGraph(5,x,y);//entries, array for x, array for y

    gr->GetXaxis()->SetTitle("X Axis");
    gr->GetYaxis()->SetTitle("Y Axis");//Naming Axis
    gr->SetMarkerStyle(4);
    gr->SetMarkerStyle(kFullCircle);
    gr->SetMarkerSize(1);
    TCanvas *c1 = new TCanvas();
    gr->Draw("ALP");// Here A implies all things is drawn L means all the data points are connected in line
    //AL* can be written in which case the data points will be shown as *
    //

}