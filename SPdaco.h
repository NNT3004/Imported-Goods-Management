#include<iostream>

using namespace std;

class SPdaco
{
private:
    string msp;
    string tensp;
    string donvi;
    string sdt;
    string tncc;
    string email;
    string dc;
    string cn;
public:
    SPdaco(string = "", string ="", string ="", string ="", string ="", string ="", string ="", string ="");
    ~SPdaco();
    void setMsp(string);
    void setTensp(string);
    void setDonvi(string);
    void setSdt(string);
    void setTncc(string);
    void setEmail(string);
    void setDc(string);
    void setCn(string);
    string getMsp();
    string getTensp();
    string getDonvi();
    string getSdt();
    string getTncc();
    string getEmail();
    string getDc();
    string getCn();
    friend istream& operator>>(istream&, SPdaco&);
};