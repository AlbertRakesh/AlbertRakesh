void tut26()
{
    TCanvas *c1= new TCanvas("c1","c1",300,300);

    TEllipse *el = new TEllipse (0.5, 0.5, 0.1, 0.1);//center_x,center_y,radi1,radi2

    el->SetFillColor(kBlue);

    for(int i; i<50; i++)

    {
        el->SetX1(0.5+i*0.01);
        el->Draw();
        c1->Update();
        sleep(1);

    }


}