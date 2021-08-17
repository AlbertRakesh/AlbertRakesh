void tut12()
{
    TCanvas *c1 = new TCanvas();
    TF1 *func = new TF1("func","exp(-[1]*x)*[0]*sin(x)", 0, 10*TMath::Pi());  //we are defining a function with limit 0 to 10 pi

    func->SetTitle("");

    func->SetParameter(0,1);//parameter 0 has the value 1
    func->SetParameter(1,0.1);//parameter 1 has the value 2

    func->Draw();
}