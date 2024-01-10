#include"Date.h"

Date::Date(int day, int month, int year)
:day(day), month(month), year(year)
{
}

void Date::setDay(int day)
{
    this->day = day;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setYear(int year)
{
    this->year = year;
}

int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getYear()
{
    return this->year;
}


bool Date::isLeapYear(int year)
{
    if(year % 400 == 0)
        return true;
    if(year % 4 == 0 && year % 100 != 0)
        return true;
    return false;
}

bool Date::checkDay(int d, int m, int y)
{   
    if (isLeapYear(y) == true)
    {
        if(m == 2)
        {
            if(d <= 0 || d >29)
                return false;
        }
    }
    else
    {
        if(m == 2)
        {
            if(d <= 0 || d >28)
                return false;
        }
    }
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m ==10 || m ==12)
        {
            if(d <= 0 || d >31)
                return false;
        }
    if(m == 4 || m == 6 || m == 9 || m == 11)
    {
        if(d <= 0 || d > 30)
            return false;
    }
    
    return true;
    
}

void Date::show()
{
    cout<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
}

ostream& operator<<(ostream& o, const Date& d)
{
    if(d.day < 10 && d.month <10)
    {
        o <<"0"<<d.day<<"/0"<<d.month<<"/"<<d.year;
    }
    if(d.day < 10 && d.month > 9)
    {
        o << "0"<<d.day<<"/"<<d.month<<"/"<<d.year;
    }
    if(d.day > 9 && d.month < 10)
    {
        o <<d.day<<"/0"<<d.month<<"/"<<d.year;
    }
    if(d.day > 9 && d.month > 9)
    {
        o <<d.day<<"/"<<d.month<<"/"<<d.year;
    }
    return o;
}

istream& operator>>(istream& i, Date& d)
{
    time_t now = time(0);
	tm * t = localtime(&now);
    cout<<"Nhap ngay: ";
    i >>d.day;
    d.month = 1 + t->tm_mon;
    d.year = 1900 + t->tm_year;
    while(!(d.checkDay(d.day,d.month,d.year)))
    {
        cout <<"Thoi gian sai,vui long nhap lai... "<<endl;
        cout<<"Nhap ngay:";
        i >>d.day;
    }
    return i;
}