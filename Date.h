#include<iostream>
#include<ctime>
using namespace std;

class Date 
{
private:
    int day;
    int month;
    int year;
public:
    Date(int = 0, int = 0, int =0);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    bool isLeapYear(int);
    bool checkDay(int, int ,int);
    void show();


    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);


};