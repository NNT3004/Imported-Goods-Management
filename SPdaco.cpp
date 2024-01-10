#include"SPdaco.h"

SPdaco::SPdaco(string msp, string tensp, string donvi, string sdt, string tncc, string email, string dc, string cn)
: msp(msp), tensp(tensp), donvi(donvi), sdt(sdt), tncc(tncc), email(email), dc(dc), cn(cn)
{
}

SPdaco::~SPdaco()
{
}

void SPdaco::setMsp(string msp)
{
    this->msp = msp;
}

void SPdaco::setTensp(string tensp)
{
    this->tensp = tensp;
}

void SPdaco::setDonvi(string donvi)
{
    this->donvi = donvi;
}

void SPdaco::setTncc(string tncc)
{
    this->tncc = tncc;
}

void SPdaco::setSdt(string sdt)
{
    this->sdt = sdt;
}

void SPdaco::setEmail(string email)
{
    this->email = email;
}

void SPdaco::setDc(string dc)
{
    this->dc = dc;
}

void SPdaco::setCn(string cn)
{
    this->cn = cn;
}

string SPdaco::getMsp()
{
    return this->msp;
}

string SPdaco::getTensp()
{
    return this->tensp;
}

string SPdaco::getDonvi()
{
    return this->donvi;
}

string SPdaco::getTncc()
{
    return this->tncc;
}

string SPdaco::getSdt()
{
    return this->sdt;
}

string SPdaco::getEmail()
{
    return this->email;
}

string SPdaco::getDc()
{
    return this->dc;
}

string SPdaco::getCn()
{
    return this->cn;
}

istream& operator>>(istream& i, SPdaco& s)
{
    i >> s.msp; 
    i.ignore();
    getline(i, s.tensp);
    i >> s.donvi;
    i >> s.sdt;
    i.ignore();
    getline(i, s.tncc);
    i >> s.email;
    i.ignore();
    getline(i, s.dc);
    getline(i, s.cn);
    return i;
}