#pragma once
#ifndef DIEM_H
#define DIEM_H
#include<iostream>
#include<cmath>
#include<iomanip>
#define epsilon 0.0000000001
#define pi 3.14159265358979323846
using namespace std;
class DIEM{
    protected:
        double x, y;
        static int dem;
    public:
        ~DIEM();
        DIEM();
        DIEM(double);
        DIEM(double, double);
        DIEM(const DIEM&);
        DIEM& operator=(const DIEM&);
        double GetX() const;
        double GetY() const;
        static int GetDem();
        void SetX(double);
        void SetY(double);
        void SetXY(double, double);
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream& in, DIEM& d);
        friend ostream& operator<<(ostream& out, const DIEM& d);
        void TinhTien(double, double);
        bool KiemTraTrung(DIEM) const;
        double TinhKhoangCach(const DIEM&) const;
        DIEM TimDiemDoiXung() const;
        bool KiemTraTGHopLe(const DIEM&, const DIEM&) const;
        double TinhChuVi(const DIEM&, const DIEM&) const;
        double TinhDienTich(const DIEM&, const DIEM&) const;
        string PhanLoaiTG(const DIEM&, const DIEM&) const;
        void PhongTo(double);
        void ThuNho(double);
        void Quay(int);
        void DoiXungOx();
        void DoiXungOy();
        void DoiXungGoc();
};
#endif
int DIEM::dem=0;
DIEM::~DIEM(){
    --dem;
}
DIEM::DIEM():x(0), y(0){
    //x=y=0;
    ++dem;
}
DIEM::DIEM(double x):x(x), y(0){
    //this->x=x; y=0;
    ++dem;
}
DIEM::DIEM(double x, double y):x(x), y(y){
    //this->x=x; this->y=y;
    ++dem;
}
DIEM::DIEM(const DIEM& d):x(d.x), y(d.y){
    //this->x=d.x;
    //this->y=d.y;
    ++dem;
}
DIEM& DIEM::operator=(const DIEM& d){
    this->x=d.x;
    this->y=d.y;
    return *this;
}
double DIEM::GetX() const{
    return this->x;
}
double DIEM::GetY() const{
    return this->y;
}
int DIEM::GetDem(){
    return dem;
}
void DIEM::SetX(double x){
    this->x=x;
}
void DIEM::SetY(double y){
    this->y=y;
}
void DIEM::SetXY(double x, double y){
    SetX(x); SetY(y);
}
istream& operator>>(istream& in, DIEM& d){
    d.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const DIEM& d){
    d.Xuat();
    return out;
}
void DIEM::Nhap(){
    cout<<"Nhap hoanh do: "; cin>>x;
    cout<<"Nhap tung do: "; cin>>y;
}
void DIEM::Xuat() const{
    cout<<fixed<<setprecision(2)<<x<<", "<<fixed<<setprecision(2)<<y;
}
bool DIEM::KiemTraTrung(DIEM d) const{
    return x==d.x&&y==d.y;
}
double DIEM::TinhKhoangCach(const DIEM &d) const{
    return sqrt(pow(x-d.x, 2)+pow(y-d.y, 2));
}
DIEM DIEM::TimDiemDoiXung() const{
    return DIEM(-x, -y);
}
bool DIEM::KiemTraTGHopLe(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    return a>0&&b>0&&c>0&&a+b>c&&b+c>a&&a+c>b;
}
double DIEM::TinhChuVi(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    return KiemTraTGHopLe(d1, d2)?a+b+c:0;
}
double DIEM::TinhDienTich(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    double p=TinhChuVi(d1, d2)/2;
    return KiemTraTGHopLe(d1, d2)?sqrt(p*(p-a)*(p-b)*(p-c)):0;
}
string DIEM::PhanLoaiTG(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    if(!KiemTraTGHopLe(d1, d2)) return "TG khong hop le";
    else if(a==b&&b==c) return "TG deu";
    else if(a==b||b==c||c==a){
        if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon) return "TG vuong can";
        else return "TG can";
    }
    else if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon) return "TG vuong";
    else return "TG thuong";
}
void DIEM::DoiXungOx(){
    x=-x;
}
void DIEM::DoiXungOy(){
    y=-y;
}
void DIEM::DoiXungGoc(){
    x=-x; y=-y;
}
void DIEM::TinhTien(double dx, double dy){
    x+=dx;
    y+=dy;
}
void DIEM::PhongTo(double scale){
    if(scale>0){
        x*=scale; y*=scale;
    }
}
void DIEM::ThuNho(double scale){
    if(scale>0){
        x/=scale; y/=scale;
    }
}
void DIEM::Quay(int alpha){
    double rad=alpha*pi/180.0;
    double xMoi=x*cos(rad)-y*sin(rad);
    double yMoi=x*sin(rad)+y*cos(rad);
    x=xMoi;
    y=yMoi;
}
#pragma once
#ifndef DIEM3C_H
#define DIEM3C_H
class DIEM3C : public DIEM{
    private:
        double z;
        static int dem;
    public:
        ~DIEM3C();
        DIEM3C();
        DIEM3C(double);
        DIEM3C(double, double);
        DIEM3C(double, double, double);
        DIEM3C(const DIEM3C&);
        DIEM3C& operator=(const DIEM3C&);
        double GetZ() const;
        static int GetDem();
        void SetZ(double);
        void SetXYZ(double, double, double);
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream&, DIEM3C&);
        friend ostream& operator<<(ostream&, const DIEM3C&);
        void TinhTien(double, double, double);
        bool KiemTraTrung(DIEM3C) const;
        double TinhKhoangCach(const DIEM3C&) const;
        DIEM3C TimDiemDoiXung() const;
        bool BaDiemThangHang(const DIEM3C&, const DIEM3C&) const;
        bool KiemTraTGHopLe(const DIEM3C&, const DIEM3C&) const;
        double TinhChuVi(const DIEM3C&, const DIEM3C&) const;
        double TinhDienTich(const DIEM3C&, const DIEM3C&) const;
        string PhanLoaiTG(const DIEM3C&, const DIEM3C&) const;
        void PhongTo(double);
        void ThuNho(double);
        void Quay(int);
        void DoiXungOx();
        void DoiXungOy();
        void DoiXungOz();
        void DoiXungOxy();
        void DoiXungOxz();
        void DoiXungOyz();
};
#endif
int DIEM3C::dem=0;
DIEM3C::~DIEM3C(){
    --dem;
}
DIEM3C::DIEM3C():DIEM(), z(0){
    ++dem;
}
DIEM3C::DIEM3C(double x):DIEM(x), z(0){
    ++dem;
}
DIEM3C::DIEM3C(double x, double y):DIEM(x, y), z(0){
    ++dem;
}
DIEM3C::DIEM3C(double x, double y, double z):DIEM(x, y), z(z){
    //this->z=z;
    ++dem;
}
DIEM3C::DIEM3C(const DIEM3C& d):DIEM(d), z(d.z){
    //this->z=d.z;
    ++dem;
}
DIEM3C& DIEM3C::operator=(const DIEM3C& d){
    this->x=d.x;
    this->y=d.y;
    this->z=d.z;
    return *this;
}
double DIEM3C::GetZ() const{
    return this->z;
}
int DIEM3C::GetDem(){
    return dem;
}
void DIEM3C::SetZ(double z){
    this->z=z;
}
void DIEM3C::SetXYZ(double x, double y, double z){
    SetXY(x, y);
    SetZ(z);
}
void DIEM3C::Nhap(){
    DIEM::Nhap();
    cout<<"Nhap cao do: "; cin>>z;
}
void DIEM3C::Xuat() const{
    DIEM::Xuat();
    cout<<", "<<fixed<<setprecision(2)<<z;
}
istream& operator>>(istream& in, DIEM3C& d){
    d.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const DIEM3C& d){
    d.Xuat();
    return out;
}
void DIEM3C::TinhTien(double dx, double dy, double dz){
    DIEM::TinhTien(dx, dy);
    z+=dz;
}
bool DIEM3C::KiemTraTrung(DIEM3C d) const{
    return DIEM::KiemTraTrung(d)&&abs(z-d.z)<=epsilon;
}
double DIEM3C::TinhKhoangCach(const DIEM3C& d) const{
    return sqrt(pow(x-d.x, 2)+pow(y-d.y, 2)+ pow(z-d.z, 2));
}
DIEM3C DIEM3C::TimDiemDoiXung() const{
    return DIEM3C(-x, -y, -z);
}
bool DIEM3C::BaDiemThangHang(const DIEM3C& d1, const DIEM3C& d2) const{
    double v1x=d1.x-x, v1y=d1.y-y, v1z=d1.z-z;
    double v2x=d2.x-d1.x, v2y=d2.y-d1.y, v2z=d2.z-d1.z;
    double cx=v1y*v2z-v2y*v1z;
    double cy=v1x*v2z-v2x*v1z;
    double cz=v1x*v2y-v2x*v1y;
    return abs(cx)<=epsilon&&abs(cy)<=epsilon&&abs(cz)<=epsilon;
}
bool DIEM3C::KiemTraTGHopLe(const DIEM3C& d1, const DIEM3C& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    return a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a;
}
double DIEM3C::TinhChuVi(const DIEM3C& d1, const DIEM3C& d2) const{
    if(!KiemTraTGHopLe(d1, d2)) return 0;
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    return a+b+c;
}
double DIEM3C::TinhDienTich(const DIEM3C& d1, const DIEM3C& d2) const{
    if(!KiemTraTGHopLe(d1, d2)) return 0;
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
string DIEM3C::PhanLoaiTG(const DIEM3C& d1, const DIEM3C& d2) const{
    if(!KiemTraTGHopLe(d1, d2)) return "TG khong hop le";
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    if(a==b&&b==c) return "TG deu";
    else if(a==b||b==c||a==c){
        if(abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon||abs(a*a+b*b-c*c)<=epsilon) return "TG vuong can";
        else return "TG can";
    }
    else if(abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon||abs(a*a+b*b-c*c)<=epsilon) return "TG vuong";
    else return "TG thuong";
}
void DIEM3C::PhongTo(double scale){
    if(scale>0){
        DIEM::PhongTo(scale);
        z*=scale;
    }
}
void DIEM3C::ThuNho(double scale){
    if(scale>0){
        DIEM::ThuNho(scale);
        z/=scale;
    }
}
void DIEM3C::Quay(int alpha){
    double rad=alpha*pi/180.0;
    double xMoi=x*cos(rad)-y*sin(rad);
    double yMoi=x*sin(rad)+y*cos(rad);
    x=xMoi; y=yMoi;
}
void DIEM3C::DoiXungOx(){
    DIEM::DoiXungOx();
    z=-z;
}
void DIEM3C::DoiXungOy(){
    DIEM::DoiXungOy();
    z=-z;
}
void DIEM3C::DoiXungOz(){
    x=-x;
    y=-y;
}
void DIEM3C::DoiXungOxy(){
    z=-z;
}
void DIEM3C::DoiXungOxz(){
    y=-y;
}
void DIEM3C::DoiXungOyz(){
    x=-x;
}
int main(){
    cout<<"===== CHUONG TRINH MINH HOA DIEM 3D =====\n\n";
    cout<<"1. Nhap diem 3D thu nhat:\n";
    DIEM3C d1; cin>>d1;
    cout<<"Diem d1: "<<d1<<endl;
    cout<<"\n2. Nhap diem 3D thu hai:\n";
    DIEM3C d2; cin>>d2;
    cout<<"Diem d2: "<<d2<<endl;
    cout<<"\n3. Nhap diem 3D thu ba:\n";
    DIEM3C d3; cin>>d3;
    cout<<"Diem d3: "<<d3<<endl;
    cout<<"\n4. Kiem tra trung diem:\n";
    cout<<"d1 va d2 "<<(d1.KiemTraTrung(d2)?"trung nhau":"khong trung nhau")<<endl;
    cout<<"\n5. Khoang cach giua d1 va d2: "<<fixed<<setprecision(2)<<d1.TinhKhoangCach(d2)<<endl;
    cout<<"\n6. Diem doi xung qua goc cua d1: "<<d1.TimDiemDoiXung()<<endl;
    cout<<"\n7. Tam giac d1, d2, d3:\n";
    if(d1.KiemTraTGHopLe(d2, d3)){
        cout<<"- Hop le\n";
        cout<<"- Chu vi: "<<d1.TinhChuVi(d2, d3)<<endl;
        cout<<"- Dien tich: "<<d1.TinhDienTich(d2, d3)<<endl;
        cout<<"- Loai tam giac: "<<d1.PhanLoaiTG(d2, d3)<<endl;
    }
    else cout<<"- Tam giac khong hop le\n";
    cout<<"\n8. Ba diem thang hang: "<<(d1.BaDiemThangHang(d2, d3)?"Co":"Khong")<<endl;
    cout<<"\n9. Cac phep bien doi voi d1:\n";
    DIEM3C d1_copy=d1;
    double dx, dy, dz;
    cout<<"Nhap vector tinh tien (dx, dy, dz): "; cin>>dx>>dy>>dz;
    d1_copy.TinhTien(dx, dy, dz);
    cout<<"a) Sau khi tinh tien: "<<d1_copy<<endl; d1_copy=d1;
    double scale;
    cout<<"Nhap ti le phong to: "; cin>>scale;
    d1_copy.PhongTo(scale);
    cout<<"b) Sau khi phong to "<<scale<<" lan: "<<d1_copy<<endl; d1_copy=d1;
    cout<<"Nhap ti le thu nho: "; cin>>scale;
    d1_copy.ThuNho(scale);
    cout<<"c) Sau khi thu nho "<<scale<<" lan: "<<d1_copy<<endl; d1_copy=d1;
    int alpha;
    cout<<"Nhap goc quay (do): ";
    cin>>alpha;
    d1_copy.Quay(alpha);
    cout<<"d) Sau khi quay "<<alpha<<" do quanh truc z: "<<d1_copy<<endl; d1_copy=d1;
    d1_copy.DoiXungOx(); 
    cout<<"e) Doi xung qua truc Ox: "<<d1_copy<<endl; d1_copy=d1;
    d1_copy.DoiXungOy(); 
    cout<<"f) Doi xung qua truc Oy: "<<d1_copy<<endl; d1_copy=d1;
    d1_copy.DoiXungOz(); 
    cout<<"g) Doi xung qua truc Oz: "<<d1_copy<<endl; d1_copy=d1;
    d1_copy.DoiXungOxy(); 
    cout<<"h) Doi xung qua mat Oxy: "<<d1_copy<<endl; d1_copy=d1;
    d1_copy.DoiXungOxz(); 
    cout<<"i) Doi xung qua mat Oxz: "<<d1_copy<<endl; d1_copy=d1;
    d1_copy.DoiXungOyz(); 
    cout<<"j) Doi xung qua mat Oyz: "<<d1_copy<<endl;
    cout<<"\n10. Thong ke:\n";
    cout<<"- So luong diem DIEM: "<<DIEM::GetDem()<<endl;
    cout<<"- So luong diem DIEM3C: "<<DIEM3C::GetDem()<<endl;
    cout<<"\n=== KET THUC CHUONG TRINH ===\n";
    return 0;
}