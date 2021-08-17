void tut24()
{
    TVector3 v1(1,2,3);

    //cout<< v1.X() << endl;

    //cout<< v1.Y() << endl;

    cout<< v1.z() << endl;

    cout << v1[0] <<endl;


    v1.Print();

    double rho = v1.Mag();
    double theta = v1.Theta()*180/TMath::Pi();//to covert radian into degree
    double phi = v1.Phi();

    cout<< rho << "\t" << theta << "\t" << phi << endl;

    v1.RotateZ(90*TMath::Pi()/180); //rotating the vector around the z axis
    v1.Print();


    TVector3 v2;


    v2.SetX(4);
    v2.SetY(5);
    v2.SetZ(6);
    v2.Print();



    TVector3 v3;
    v3.SetZ(10);
    v3.SetTheta(10*TMath::Pi()/180.);
    v3.SetPhi(45*TMath::Pi()/180.);

    v3.Print();

    TVector3 v4= v1+v2;

    v4.Print();
    
    cout<< v1.Dot(v2)<<endl;
    cout<< v1.Angle(v2)<<endl;

}