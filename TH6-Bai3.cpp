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
#ifndef MAU_H
#define MAU_H
class MAU{
    protected:
        int r, g, b;
        static int dem;
    public:
        ~MAU();
        MAU();
        MAU(int);
        MAU(int, int);
        MAU(int, int, int);
        MAU(const MAU&);
        MAU& operator=(const MAU&);
        int GetR() const;
        int GetG() const;
        int GetB() const;
        static int GetDem();
        void SetR(int);
        void SetG(int);
        void SetB(int);
        void SetRGB(int, int, int);
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream&, MAU&);
        friend ostream& operator<<(ostream&, const MAU&);
        bool KiemTraTrungMau(const MAU&) const;
};
#endif
int MAU::dem=0;
MAU::~MAU(){
    --dem;
}
MAU::MAU(): r(0), g(0), b(0){
    //r=g=b=0;
    ++dem;
}
MAU::MAU(int r){
    SetR(r);
    ++dem;
}
MAU::MAU(int r, int g){
    SetR(r);
    SetG(g);
    ++dem;
}
MAU::MAU(int r, int g, int b){
    SetRGB(r, g, b);
    ++dem;
}
MAU::MAU(const MAU& m): r(m.r), g(m.g), b(m.b){
    ++dem;
}
MAU& MAU::operator=(const MAU& m){
    SetRGB(m.r, m.g, m.b);
    return *this;
}
int MAU::GetR() const{
    return this->r;
}
int MAU::GetG() const{
    return this->g;
}
int MAU::GetB() const{
    return this->b;
}
int MAU::GetDem(){
    return dem;
}
void MAU::SetR(int r){
    if(r<0) r=0;
    if(r>255) r=255;
    this->r=r;
}
void MAU::SetG(int g){
    if(g<0) g=0;
    if(g>255) g=255;
    this->g=g;
}
void MAU::SetB(int b){
    if(b<0) b=0;
    if(b>255) b=255;
    this->b=b;
}
void MAU::SetRGB(int r, int g, int b){
    SetR(r); SetG(g), SetB(b);
}
void MAU::Nhap(){
    do{
        cout<<"Nhap R (0-255): "; cin>>r;
    }while(r<0||r>255);
    do{
        cout<<"Nhap G (0-255): "; cin>>g;
    }while(g<0||g>255);
    do{
        cout<<"Nhap B (0-255): "; cin>>b;
    }while(b<0||b>255);
}
void MAU::Xuat() const{
    cout<<" - Mau RGB("<<r<<", "<<g<<", "<<b<<")";
}
istream& operator>>(istream& in, MAU& m){
    m.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const MAU& m){
    m.Xuat();
    return out;
}
bool MAU::KiemTraTrungMau(const MAU& m) const{
    return r==m.r&&g==m.g&&b==m.b;
}
#pragma once
#ifndef DIEMMAU_H
#define DIEMMAU_H
class DIEMMAU : public DIEM, public MAU{
    private:
        static int dem;
    public:
        ~DIEMMAU();
        DIEMMAU();
        DIEMMAU(double);
        DIEMMAU(double, double);
        DIEMMAU(double, double, int);
        DIEMMAU(double, double, int, int);
        DIEMMAU(double, double, int, int, int);
        DIEMMAU(const DIEMMAU&);
        DIEMMAU& operator=(const DIEMMAU&);
        static int GetDem();
        void Nhap();
        void Xuat() const;
        friend istream& operator>>(istream&, DIEMMAU&);
        friend ostream& operator<<(ostream&, const DIEMMAU&);
        bool KiemTraTrung(const DIEMMAU&) const;
};
#endif
int DIEMMAU::dem=0;
DIEMMAU::~DIEMMAU(){
    --dem;
}
DIEMMAU::DIEMMAU(): DIEM(), MAU(){
    ++dem;
}
DIEMMAU::DIEMMAU(double x): DIEM(x), MAU(){
    ++dem;
}
DIEMMAU::DIEMMAU(double x, double y): DIEM(x, y), MAU(){
    ++dem;
}
DIEMMAU::DIEMMAU(double x, double y, int r): DIEM(x, y), MAU(r){
    ++dem;
}
DIEMMAU::DIEMMAU(double x, double y, int r, int g): DIEM(x, y), MAU(r, g){
    ++dem;
}
DIEMMAU::DIEMMAU(double x, double y, int r, int g, int b): DIEM(x, y), MAU(r, g, b){
    ++dem;
}
DIEMMAU::DIEMMAU(const DIEMMAU& d): DIEM(d), MAU(d){
    ++dem;
}
DIEMMAU& DIEMMAU::operator=(const DIEMMAU& d){
    DIEM::operator=(d);
    MAU::operator=(d);
    return *this;
}
int DIEMMAU::GetDem(){
    return dem;
}
void DIEMMAU::Nhap(){
    DIEM::Nhap();
    MAU::Nhap();
}
void DIEMMAU::Xuat() const{
    DIEM::Xuat();
    MAU::Xuat();
}
istream& operator>>(istream& in, DIEMMAU& d){
    d.Nhap();
    return in;
}
ostream& operator<<(ostream& out, const DIEMMAU& d){
    d.Xuat();
    return out;
}
bool DIEMMAU::KiemTraTrung(const DIEMMAU& d) const{
    return DIEM::KiemTraTrung(d)&&MAU::KiemTraTrungMau(d);
}
int main(){
    cout<<"===== CHUONG TRINH MINH HOA DIEM MAU 2D =====\n\n";
    cout<<"1. Nhap diem mau 2D thu nhat:\n";
    DIEMMAU d1; cin>>d1;
    cout<<"Diem d1: "<<d1<<endl;
    cout<<"\n2. Nhap diem mau 2D thu hai:\n";
    DIEMMAU d2; cin>>d2;
    cout<<"Diem d2: "<<d2<<endl;
    cout<<"\n3. Nhap diem mau 2D thu ba:\n";
    DIEMMAU d3; cin>>d3;
    cout<<"Diem d3: "<<d3<<endl;
    cout<<"\n4. Kiem tra trung diem va trung mau:\n";
    cout<<"d1 va d2 "<<(d1.KiemTraTrung(d2)?"trung nhau (vi tri va mau)":"khong trung nhau (vi tri hoac mau)")<<endl;
    cout<<"d1 va d2 "<<(d1.KiemTraTrungMau(d2)?"trung mau":"khong trung mau")<<endl;
    cout<<"\n5. Khoang cach giua d1 va d2: "<<fixed<<setprecision(2)<<d1.TinhKhoangCach(d2)<<endl;
    cout<<"\n6. Diem doi xung qua goc cua d1: "<<d1.TimDiemDoiXung()<<endl;
    cout<<"\n7. Tam giac d1, d2, d3:\n";
    if(d1.KiemTraTGHopLe(d2, d3)){
        cout<<"- Hop le\n";
        cout<<"- Chu vi: "<<fixed<<setprecision(2)<<d1.TinhChuVi(d2, d3)<<endl;
        cout<<"- Dien tich: "<<fixed<<setprecision(2)<<d1.TinhDienTich(d2, d3)<<endl;
        cout<<"- Loai tam giac: "<<d1.PhanLoaiTG(d2, d3)<<endl;
    }
    else cout<<"- Tam giac khong hop le\n";
    cout<<"\n8. Cac phep bien doi voi d1:\n";
    DIEMMAU d1_copy=d1;
    double dx, dy;
    cout<<"Nhap vector tinh tien (dx, dy): "; cin>>dx>>dy;
    d1_copy.TinhTien(dx, dy);
    cout<<"a) Sau khi tinh tien: "<<d1_copy<<endl;
    d1_copy=d1; double scale;
    cout<<"Nhap ti le phong to: "; cin>>scale;
    d1_copy.PhongTo(scale);
    cout<<"b) Sau khi phong to "<<scale<<" lan: "<<d1_copy<<endl;
    d1_copy=d1;
    cout<<"Nhap ti le thu nho: "; cin>>scale;
    d1_copy.ThuNho(scale);
    cout<<"c) Sau khi thu nho "<<scale<<" lan: "<<d1_copy<<endl;
    d1_copy=d1; int alpha;
    cout<<"Nhap goc quay (do): "; cin>>alpha;
    d1_copy.Quay(alpha);
    cout<<"d) Sau khi quay "<<alpha<<" do quanh goc toa do: "<<d1_copy<<endl;
    d1_copy=d1;
    d1_copy.DoiXungOx();
    cout<<"e) Doi xung qua truc Ox: "<<d1_copy<<endl;
    d1_copy=d1;
    d1_copy.DoiXungOy();
    cout<<"f) Doi xung qua truc Oy: "<<d1_copy<<endl;
    d1_copy=d1;
    d1_copy.DoiXungGoc();
    cout<<"g) Doi xung qua goc: "<<d1_copy<<endl;
    cout<<"\n9. Thay doi mau cho d1:\n";
    int r, g, b;
    cout<<"Nhap gia tri mau RGB moi (0-255):\n";
    cout<<"R: "; cin>>r;
    cout<<"G: "; cin>>g;
    cout<<"B: "; cin>>b;
    d1.SetRGB(r, g, b);
    cout<<"Diem d1 sau khi thay doi mau: "<<d1<<endl;
    cout<<"\n10. Thong ke:\n";
    cout<<"- So luong diem DIEM: "<<DIEM::GetDem()<<endl;
    cout<<"- So luong diem MAU: "<<MAU::GetDem()<<endl;
    cout<<"- So luong diem DIEMMAU: "<<DIEMMAU::GetDem()<<endl;
    cout<<"\n=== KET THUC CHUONG TRINH ===\n";
    return 0;
}