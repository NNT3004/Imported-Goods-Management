#include"ThongtinSP.h"

ThongtinSp::ThongtinSp(string masp,string name,int sl,string donvi, double price, double tong, Date time)
: masp(masp), name(name), sl(sl), donvi(donvi), price(price), time(time)
{

}

ThongtinSp::~ThongtinSp()
{
}

void ThongtinSp::setMasp(string masp)
{
    this->masp = masp;
}

void ThongtinSp::setName(string name)
{
    this->name  = name;
}

void ThongtinSp::setSl(int sl)
{
    this->sl = sl;
}

void ThongtinSp::setDonvi(string donvi)
{
    this->donvi = donvi;
}
void ThongtinSp::setPrice(double price)
{
    this->price =  price;
}

void ThongtinSp::setTime(Date time)
{
    this->time = time;
}

string ThongtinSp::getMasp()
{
    return this->masp;
}

int ThongtinSp::getSl()
{
    return this->sl;
}

string ThongtinSp::getName()
{
    return this->name;
}

string ThongtinSp::getDonvi()
{
    return this->donvi;
}

double ThongtinSp::getPrice()
{
    return this->price;
}

double ThongtinSp::getTong(ThongtinSp& a)
{
    if(a.sl <= 100)
    {
        return a.sl * a.price;
    }
    if(a.sl > 100 && a.sl <= 200)
    {
        return (a.sl * a.price) - (a.sl * a.price)*10/100;
    }
    return (a.sl * a.price) - (a.sl * a.price)*15/100;
}

Date ThongtinSp::getTime()
{
    return this->time;
}

bool ThongtinSp::checkMasp(string a)
{
    if(a.size() != 5)
        return false;
    if(a[0] < '1' || a[0] > '5')
        return false;
    for(int i = 1; i < a.size(); i++)
    {
        if(a[i] < '0' || a[i] > '9')
            return false;
    }
    return true;
}

ostream& operator<<(ostream& o, ThongtinSp& t)
{
    int x = t.getSl(),dem  = 1;
    o <<"|";
    o <<setw(9)<<t.masp <<"    "<<"|";
    o << "\t" <<t.name <<setw(16 - t.name.size())<<"\t|";
    while(x >= 10)
    {
        x /= 10;
        dem++;
    }
    o << "    " <<t.getSl()<<setw(9 -dem)<<"|";
    o << "  " << t.donvi <<setw(12 - t.donvi.size())<<"|";
    o << "   " <<t.price<<"\t   "<<"|";
    o << "  " << t.time <<"  |";
    return o;
}

istream& operator>>(istream& i, ThongtinSp& t)
{
    cout << "Vui long nhap ngay nhap san pham"<<endl;
    i >> t.time;
    cout << "Nhap ma san pham: " <<endl;
    i >> t.masp;
    while(!(t.checkMasp(t.masp))) 
    {
        cout << "Ma san pham sai, vui long nhap lai: ";
        cin >>t.masp;
    }
    cout << "Nhap ten san pham: "<<endl;
    i.ignore();
    getline(i, t.name);
    cout << "Nhap so luong: " <<endl;
    i >> t.sl;
    cout << "Nhap don vi: " <<endl;
    i >> t.donvi;
    cout << "Nhap gia tien: " <<endl;
    i >> t.price;
    return i;
}

void ThongtinSp::show()
{
    int n = this->sl,dem;
    dem = 1;
    cout<<"__________________________________"<<endl;
    cout<<"||"<<setw(18)<<this->name<<"\t\t||"<<endl;
    cout<<"||______________________________||"<<endl;
    cout<<"|| Ma san pham: "<<this->masp<<"\t\t||"<<endl;
    cout<<"|| Thoi gian nhap: "<<this->time<<"\t||"<<endl;
    while(n >= 10)
    {
        n /= 10;
        dem ++;
    }
    cout<<"|| So luong: "<<this->sl<<setw(21 - dem)<<"||"<<endl;
    cout<<"|| Don vi: "<<setw(5)<<this->donvi<<setw(18)<<"||"<<endl;
    dem = 1;
    n = this->price;
    while(n >= 10)
    {
        n /= 10;
        dem ++;
    }   
    cout<<"|| Gia: "<<this->price<<" dong"<<setw(21 - dem)<<"||"<<endl;
    cout<<"||______________________________||"<<endl;
}