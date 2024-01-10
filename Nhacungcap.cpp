#include"Nhacungcap.h"
#include"ThongtinSP.h"
 
Nhacungcap::~Nhacungcap()
{ 
}

Nhacungcap::Nhacungcap(string ten, string email,string sdt, string address, string chinhanh, string thanhtoan)
: ten(ten), email(email), sdt(sdt), address(address), chinhanh(chinhanh), thanhtoan(thanhtoan)
{
}

void Nhacungcap::setTen(string ten)
{
    this->ten = ten;
}

void Nhacungcap::setSdt(string sdt)
{
    this->sdt = sdt;
}
void Nhacungcap::setEmail(string email)
{
    this->email = email;
}

void Nhacungcap::setAddress(string address)
{
    this->address = address;
}

void Nhacungcap::setChinhanh(string chinhanh)
{
    this->chinhanh = chinhanh;
}

void Nhacungcap::setThanhtoan(string thanhtoan)
{
    this->thanhtoan = thanhtoan;
}

string Nhacungcap::getTen()
{
    return this->ten;
}

string Nhacungcap::getEmail()
{
    return this->email;
}

string Nhacungcap::getSdt()
{
    return this->sdt;
}

string Nhacungcap::getAddress()
{
    return this->address;
}

string Nhacungcap::getChinhanh()
{
    return this->chinhanh;
}

string Nhacungcap::getThanhtoan()
{
    return this->thanhtoan;
}

bool Nhacungcap::checksdt(string a)
{
    if(a.size() != 10)
        return false;
    return true;
}

bool Nhacungcap::checkemail(string a)
{   
    if(a.size() < 11)
        return false;
    int b = a.find("@gmail.com");
    if(b == a.size() - 10)
        return true;
    return false;
}

void Nhacungcap::Show()
{
    cout << "Ten Nha cung cap: " ;
}


ostream& operator<<(ostream& o,const Nhacungcap& n)
{
    o << "Ten nha cung cap: " << n.ten << endl;
    o << "Email: " << n.email <<endl;
    o << "SDT: " << n.sdt<<endl;
    o << "Dia chi: " << n.address <<endl;
    o << "Chi nhanh:" << n.chinhanh<<endl;
    o << "Thanh toan:" << n.thanhtoan <<endl;
    return o;
}

istream& operator>>(istream& i, Nhacungcap& n) 
{
    cout << n.sdt;
    cout << "Nhap SDT cua nha cung cap: "; 
    i >> n.sdt;
    while(!(n.checksdt(n.sdt)))
    {
        cout <<"SDT sai, vui long nhap lai: ";
        i >> n.sdt;
    }
    cout << "Nhap ten nha cung cap: ";
    i.ignore();
    getline(i, n.ten);
    cout << "Nhap email: ";
    i >> n.email;
    while(!(n.checkemail(n.email)))
    {
        cout <<"Email khong dung dinh dang, vui long nhap lai: ";
        i >> n.email;
    }
    cout << "Nhap dia chi: ";
    i.ignore();
    getline(i,n.address);
    cout << "Nhap chi nhanh: ";
    getline(i,n.chinhanh);
    return i;
}