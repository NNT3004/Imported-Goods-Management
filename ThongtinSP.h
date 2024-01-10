#include<iostream>
#include<string.h>
#include <fstream>
#include<iomanip>
#include"Date.h"
#pragma once
using namespace std;
 
class ThongtinSp
{
protected:
    string masp;
    string name;
    Date time;
    int sl; 
    string donvi;
    double price;
    double tong;
public:
    ThongtinSp(string = "", string = "", int = 0, string ="", double = 0, double = 0, Date = Date(1,1,1));
    ~ThongtinSp();
    void setMasp(string);
    void setName(string);
    void setSl(int); 
    void setDonvi(string); 
    void setPrice(double);
    void setTime(Date);
    string getMasp();
    int getSl();
    string getDonvi();
    string getName();
    double getPrice();
    Date getTime();
    double getTong(ThongtinSp&);
    bool checkMasp(string);
    void show();
    friend void congsl(ThongtinSp&, int);
    friend ostream& operator<<(ostream& , ThongtinSp&); 
    friend istream& operator>>(istream& , ThongtinSp&);
};
