#include<iostream>
#include<string.h>
using namespace std;

class Nhacungcap 
{
private:
    string ten;
    string email;
    string sdt; 
    string address;
    string chinhanh;
    string thanhtoan;
public:
    Nhacungcap(string =  "", string = "", string = "", string = "", string = "", string = "");
    ~Nhacungcap();
    void Show();
    void setTen(string);
    void setEmail(string);
    void setSdt(string);
    void setAddress(string);
    void setChinhanh(string);
    void setThanhtoan(string);
    string getTen();
    string getEmail();
    string getSdt();
    string getAddress();
    string getThanhtoan();
    string getChinhanh();
    bool checksdt(string);
    bool checkemail(string);
    Nhacungcap& operator[](const int&);
    friend ostream& operator<<(ostream& ,const Nhacungcap&);
    friend istream& operator>>(istream& , Nhacungcap&);

};