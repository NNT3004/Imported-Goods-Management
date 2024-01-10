#include"List.h"

List::List()
{
    this->length = 0;
    this->length1  = 0;
    this->t = nullptr;
    this->n = nullptr;
}

List::List(int index, ThongtinSp *t1, Nhacungcap *n1, SPdaco* s1)
{
    this->length = index;
    this->length1 = index;
    this->t = new ThongtinSp[this->length];
    for(int i = 0; i < this->length;i++)
    {
        (*(t + i)) = (*(t1 + i));
    }

    this->n = new Nhacungcap[this->length];
    for(int i = 0; i < this->length;i++)
    {
        (*(n + i)) = (*(n1 + i));
    }

    this->s = new SPdaco[this->length1];
    for(int i = 0; i < this->length1;i++)
    {
        (*(s + i)) = (*(s1 + i));
    }
}


List::List(const List &l)
{
    this->length = l.length;
    this->t = new ThongtinSp[this->length];
    for (int i = 0; i < this->length; i++)
    {
        *(this->t + i) = *(l.t + i);
        *(this->n + i) = *(l.n + i);
    }
    this->length1 = l.length1;
    for (int i = 0; i < this->length1; i++)
    {
        *(this->s + i) = *(l.s + i);
    }
}


List::~List()
{
    delete[] this->t;
    delete[] this->n;
}
 
int List::getLength()
{
    return length;
}

/// Nhap file txt
void List::EnterListSP()
{ 
    Date y;
    int x,n,sl;
    string msp,ten,donvi;
    double price;
    time_t now = time(0);
	tm * T = localtime(&now);
    y.setMonth(1 + T->tm_mon);
    y.setYear(1900 + T->tm_year);
    ifstream input("D:\\Code\\PBL2\\ThongtinSP.txt");
    input >> n;
    this->length = n;
    this->t = new ThongtinSp[this->length];
    input.ignore();
    for (int i = 0; i < this->length; i++)
    {
        input >> x;
        y.setDay(x);
        input >> msp;
        input.ignore();
        getline(input, ten);
        input >> sl;
        input.ignore();
        getline(input, donvi);
        input >> price;
        t[i].setTime(y);
        t[i].setMasp(msp);
        t[i].setName(ten);
        t[i].setSl(sl);
        t[i].setDonvi(donvi);
        t[i].setPrice(price);
    }
    input.close();
    system("cls");
}

///     nhap san pham co san
void List::EnterListDefault()
{ 
    ifstream input("D:\\Code\\PBL2\\Thongtinspdaco.txt");
    int y;
    input >> y;
    this->length1 = y;
    this->s = new SPdaco[this->length1];
    SPdaco a;
    input.ignore();
    for (int i = 0; i < this->length1; i++)
    {
        input >> a;
        s[i] = a;
    }
    input.close();
    system("cls");
}

///   ghi vao file thong tin sp chua co
void List::ExportListDefault()
{
    ofstream output;
    int n;
    n = this->length1;
    output.open("D:\\Code\\PBL2\\Thongtinspdaco.txt");
    output << n <<endl;
    for(int i = 0; i < this->length1 - 1;i++)
    {
        output << s[i].getMsp()<<endl;
        output << s[i].getTensp()<<endl;
        output << s[i].getDonvi()<<endl;
        output << s[i].getSdt()<<endl;
        output << s[i].getTncc()<<endl;
        output << s[i].getEmail()<<endl;
        output << s[i].getDc()<<endl;
        output << s[i].getCn()<<endl;
    }
    output << s[this->length1 - 1].getMsp()<<endl;
    output << s[this->length1 - 1].getTensp()<<endl;
    output << s[this->length1 - 1].getDonvi()<<endl;
    output << s[this->length1 - 1].getSdt()<<endl;
    output << s[this->length1 - 1].getTncc()<<endl;
    output << s[this->length1 - 1].getEmail()<<endl;
    output << s[this->length1 - 1].getDc()<<endl;
    output << s[this->length1 - 1].getCn();
    output.close();
}

/// tu dong them thong tin sp co san
void List::AddSp(List& l, ThongtinSp& t1, Nhacungcap& n1,string x)
{
    for(int i = 0; i < l.length1; i ++)
    {
        if(x == l.s[i].getMsp())
        {
            t1.setMasp(l.s[i].getMsp());
            t1.setName(l.s[i].getTensp());
            t1.setDonvi(l.s[i].getDonvi());
            n1.setTen(l.s[i].getTncc());
            n1.setSdt(l.s[i].getSdt());
            n1.setEmail(l.s[i].getEmail());
            n1.setAddress(l.s[i].getDc());
            n1.setChinhanh(l.s[i].getCn());
        }
    }
}

/// them thong tin nhung sp chua co
void List::AddThongtin(ThongtinSp& t1, Nhacungcap& n1, SPdaco& s1)
{
    s1.setMsp(t1.getMasp());
    s1.setTensp(t1.getName());
    s1.setDonvi(t1.getDonvi());
    s1.setSdt(n1.getSdt());
    s1.setTncc(n1.getTen());
    s1.setEmail(n1.getEmail());
    s1.setDc(n1.getAddress());
    s1.setCn(n1.getChinhanh());

    this->length1++;
    SPdaco *temp = new SPdaco[this->length1];
    
    for(int i = 0; i < length1 - 1; i++)
    {
        *(temp + i) = *(s + i);
    }

    *(temp + length1 - 1) = s1;

    delete[] s;
    s = new SPdaco[this->length1];

    for(int i = 0; i < length1;i++)
    {
        *(s + i) = *(temp + i);
    }
    delete[] temp;
}

// ham kiem tra ngay
bool List::checkDay(List &l, int b)
{
    for(int i = 0; i < l.length;i++)
    {
        if(b == l.t[i].getTime().getDay())
            return true;
    }
    return false;
}

// ham kiem tra sp cua 1 ngay nao do
bool List::checkSP(List& l, int b, string k)
{
    for(int i = 0; i < l.length;i++)
    {
        if(b == l.t[i].getTime().getDay())
        {
            if( k == l.t[i].getMasp() || k == l.t[i].getName())
            {
                return true;
            }
        }
    }
    return false;
}

// ghi vao file nhung sp da nhap
void List::ExportListSP()
{
    ofstream output;
    int n;
    n = this->length;
    output.open("D:\\Code\\PBL2\\ThongtinSP.txt");
    output << n <<endl;
    for(int i = 0; i < this->length - 1;i++)
    {
        output << t[i].getTime().getDay()<<endl;
        output << t[i].getMasp()<<endl;
        output << t[i].getName()<<endl;
        output << this->t[i].getSl()<<endl;
        output << t[i].getDonvi()<<endl;
        output << t[i].getPrice()<<endl;
    }
    output << t[this->length - 1].getTime().getDay()<<endl;
    output << t[this->length - 1].getMasp()<<endl;
    output << t[this->length - 1].getName()<<endl;
    output << t[this->length - 1].getSl()<<endl;
    output << t[this->length - 1].getDonvi()<<endl;
    output << t[this->length - 1].getPrice();
    output.close();

    output.open("Thongtinnhaphang.txt"); 
    int  dem1 = 0;
    for(int i = 1; i <= 31;i++)
    {
        int dem = 0;
        for(int j = 0;j < this->length;j++)
        {
            if(i == t[j].getTime().getDay())
            {
                if(dem == 0)
                {
                    output << t[j].getTime() << ":"<<endl;
                    dem++;
                }
                dem1 ++;
                if(dem1 != this->length)
                {
                    output << t[j].getMasp()<<endl;
                }
                else
                {
                    output << t[j].getMasp();
                }
            }
        }
    }
}

// nhap ds nha cung cap 
void List::EnterListNCC()
{
    ifstream input("D:\\Code\\PBL2\\Nhacungcap.txt");
    int x;
    string sdt,ten,email,dc,cn,tt;
    input >> x;
    this->length = x;
    this->n = new Nhacungcap[this->length];
    Nhacungcap a;
    input.ignore();
    for (int i = 0; i < this->length; i++)
    {
        input >> sdt;
        input.ignore();
        getline(input,ten);
        input >> email;
        input.ignore();
        getline(input,dc);
        getline(input,cn);
        getline(input,tt);
        a = Nhacungcap(ten, email, sdt, dc, cn ,tt);

        n[i] = a;
    }
    input.close();
    system("cls");
}

// ghi lai ds nha cung cap
void List::ExportListNCC()
{
    ofstream output;
    int x;
    x = this->length;
    output.open("D:\\Code\\PBL2\\Nhacungcap.txt");
    output << x <<endl;
    for(int i = 0; i < this->length - 1;i++)
    {
        output << n[i].getSdt()<<endl;
        output << n[i].getTen()<<endl;
        output << n[i].getEmail()<<endl;
        output << n[i].getAddress()<<endl;
        output << n[i].getChinhanh()<<endl;
        output << n[i].getThanhtoan()<<endl;
    }
    output << n[this->length - 1].getSdt()<<endl;
    output << n[this->length - 1].getTen()<<endl;
    output << n[this->length - 1].getEmail()<<endl;
    output << n[this->length - 1].getAddress()<<endl;
    output << n[this->length - 1].getChinhanh()<<endl;
    output << n[this->length - 1].getThanhtoan();
    output.close();
}


//chen sp tai index
void List::InsertAt(int index,const ThongtinSp& t1,const Nhacungcap& n1)
{
    this->length++;
    ThongtinSp *temp = new ThongtinSp[this->length];

    for(int i = this->length - 1; i > index; i--)
    {
        *(temp + i) = *(t + i - 1);
    }
    for(int i = 0; i < index; i++)
    {
        *(temp + i) = *(t + i);
    }

    *(temp + index) = t1;

    delete[] t;
    t = new ThongtinSp[this->length];

    for(int i = 0; i < length; i++)
    {
        *(t + i) = *(temp + i);
    }
    delete[] temp;

    Nhacungcap *temp1 = new Nhacungcap[this->length];

    for(int i = this->length - 1; i > index; i--)
    {
        *(temp1 + i) = *(n + i - 1);
    }
    for(int i = 0; i < index; i++)
    {
        *(temp1 + i) = *(n + i);
    }

    *(temp1 + index) = n1;

    delete[] n;
    n = new Nhacungcap[this->length];

    for(int i = 0; i < length; i++)
    {
        *(n + i) = *(temp1 + i);
    }
    delete[] temp1;
}

// xoa sp
void List::RemoveAt(List& l, string x, int b)
{
    for(int i = 0; i < l.length;i++)
    {
        if(b == l.t[i].getTime().getDay())
        {
            if(x == l.t[i].getMasp() || x == l.t[i].getName())
            {
                int index = i;
                for(int j = index;j < this->length - 1; j++)
                {
                    *(t + j) = *(t + j + 1);
                    *(n + j) = *(n + j + 1);
                }
                this->length--;
                ThongtinSp *temp = new ThongtinSp[this->length];
                Nhacungcap *temp1 = new Nhacungcap[this->length];
                for(int j = 0; j < this->length; j++)
                {
                    *(temp + j) = *(t + j);
                    *(temp1 + j) = *(n + j);
                }

                delete[] t;
                delete[] n;
                t = new ThongtinSp[this->length];
                n = new Nhacungcap[this->length];

                for(int j = 0; j < length; j++)
                {
                    *(t + j) = *(temp + j);
                    *(n + j) = *(temp1 + j);
                }

                delete[] temp;
                delete[] temp1;
            }
        }
    }
}


// show ds nha cung cap
void List::showNCC(const List& l)
{
    cout <<endl;
    cout <<setw(133)<< "______________________________________________________________________________________________"<<endl;
    cout <<setw(41)<<"||"<<setw(3);
    cout <<"STT";
    cout << "|";
    cout << "   Nha cung cap  |";
    cout << "   Ten san pham   |";
    cout << "         Email         |";
    cout << "     SDT     |";
    cout << "  Dia chi  ||"<<endl;
    cout <<setw(133)<< "||___|_________________|__________________|_______________________|_____________|___________||"<<endl;
    for(int i = 0; i < l.length1;i++)
    {
        cout <<setw(41)<<"||" <<setw(2);
        cout << i + 1;
        cout <<" ";
        cout <<"|  "<< l.s[i].getTncc()<<setw(19 - l.s[i].getTncc().size());
        cout << "|   "<<l.s[i].getTensp()<<setw(19 - l.s[i].getTensp().size());
        cout << "|   "<<l.s[i].getEmail()<<setw(23 - l.s[i].getEmail().size());
        cout << "|  "<<l.s[i].getSdt()<<" ";
        cout << "|  "<<l.s[i].getDc()<<setw(11 - l.s[i].getDc().size())<< "||"<<endl;
        cout <<setw(133)<< "||___|_________________|__________________|_______________________|_____________|___________||"<<endl;
    }
}

// ham doi vi tri sp
void List::swapSP(ThongtinSp& a, ThongtinSp& b)
{
    ThongtinSp c;
    c = a;
    a = b;
    b = c;
}

// ham doi vi tri nha cung cap
void List::swapNCC(Nhacungcap& a, Nhacungcap& b)
{
    Nhacungcap c;
    c = a;
    a = b;
    b = c;
}

// ham sap xep theo gia tang dan
void List::InterchangeSorthight(List& l)
{
    for (int i = 0; i < l.length - 1; i++)
    {
        for (int j = i + 1; j < l.length; j++)
        {
	        if(l.t[i].getPrice() > l.t[j].getPrice())
            {
		        swapSP(l.t[i],l.t[j]);
                swapNCC(l.n[i],l.n[j]);
            }
        }
    }
    cout <<endl;
    cout << setw(31)<<" " <<"_______________________________________________________________________________________________________________________"<<endl;
    cout << setw(31)<<" " <<"||"<<setw(3);
    cout <<"STT";
    cout << "|";
    cout << setw(13)<<"Ma san pham ";
    cout << "|";
    cout <<setw(16)<< "Ten san pham"<<"     ";
    cout << "|";
    cout << setw(10)<<"So luong"<<setw(3);
    cout << "|";
    cout << setw(8)<<"Don vi"<<setw(6);
    cout << "|";
    cout << setw(12)<<"Gia tien"<<"   ";
    cout << "|";
    cout << "   Ngay nhap" <<"  ";
    cout << "|";
    cout << "   Nha cung cap  ";
    cout << "||"<<endl;
    cout << setw(31)<<" " << "||___|_____________|_____________________|____________|_____________|_______________|______________|_________________||"<<endl;
    ThongtinSp *temp = new ThongtinSp[l.length];
    temp = l.t;

    for(int i = 0;i < l.length;i ++)
    {
        cout << setw(31)<<" " <<"||" <<setw(2);
        cout << i + 1;
        cout <<" ";
        cout << (*(temp + i));
        cout << "   "<< l.n[i].getTen();
        cout << setw(16 - l.n[i].getTen().size());
        cout <<"||"<<endl;
        cout << setw(31)<<" " << "||___|_____________|_____________________|____________|_____________|_______________|______________|_________________||"<<endl;
    }
}

// ham sap xep theo gia giam dan
void List::InterchangeSortlow(List& l)
{
    for (int i = 0; i < l.length - 1; i++)
    {
        for (int j = i + 1; j < l.length; j++)
        {
	        if(l.t[i].getPrice() < l.t[j].getPrice())
            {
		        swapSP(l.t[i],l.t[j]);
                swapNCC(l.n[i],l.n[j]);
            }
        }
    }
    cout <<endl;
    cout << setw(31)<<" " <<"_______________________________________________________________________________________________________________________"<<endl;
    cout << setw(31)<<" " <<"||"<<setw(3);
    cout <<"STT";
    cout << "|";
    cout << setw(13)<<"Ma san pham ";
    cout << "|";
    cout <<setw(16)<< "Ten san pham"<<"     ";
    cout << "|";
    cout << setw(10)<<"So luong"<<setw(3);
    cout << "|";
    cout << setw(8)<<"Don vi"<<setw(6);
    cout << "|";
    cout << setw(12)<<"Gia tien"<<"   ";
    cout << "|";
    cout << "   Ngay nhap" <<"  ";
    cout << "|";
    cout << "   Nha cung cap  ";
    cout << "||"<<endl;
    cout << setw(31)<<" " << "||___|_____________|_____________________|____________|_____________|_______________|______________|_________________||"<<endl;
    ThongtinSp *temp = new ThongtinSp[l.length];
    temp = l.t;

    for(int i = 0;i < l.length;i ++)
    {
        cout << setw(31)<<" " <<"||" <<setw(2);
        cout << i + 1;
        cout <<" ";
        cout << (*(temp + i));
        cout << "   "<< l.n[i].getTen();
        cout << setw(16 - l.n[i].getTen().size());
        cout <<"||"<<endl;
        cout << setw(31)<<" " << "||___|_____________|_____________________|____________|_____________|_______________|______________|_________________||"<<endl;
    }
}

// ham kiem tra sp
bool List::Search(List& l,string x)
{
    for(int i = 0; i < l.length;i++)
    {
        if(x == l.t[i].getName() || x == l.t[i].getMasp())
            return true;
    }
    return false;
}

// show thong tin cac sp cua 1 ngay 
void List::FindDay(List& l, int b)
{
    for(int i = 0; i < l.length; i++)
    {
        if(b == l.t[i].getTime().getDay())
        {
            l.t[i].show();
        }
    }
}

// ham show thong tin sp
void List::showTTSP(List& l,string x)
{
    for(int i = 0; i < l.length;i++)
    {
        if(x == l.t[i].getName() || x == l.t[i].getMasp())
        {
            l.t[i].show();
        }  
    }
}

// in ra phieu nhap hang
void List::showPNH(List & l)
{
    cout <<"\t\t_________________________________________________________________________________________________________________________________________________"<<endl;
    cout <<"\t\t||  MSP  |"<< setw(16)<<"Ten san pham"<<"    ";
    cout << "|   Nha cung cap  |";
    cout << "  Chi nhanh  |";
    cout << "   Ngay nhap  |";
    cout << setw(10)<<"So luong"<<setw(3)<<"|";
    cout << setw(11)<<"Gia tien"<<"   |";
    cout <<" Tong tien (trieu) ";
    cout <<"|   Thanh toan    ||"<<endl;
    cout <<"\t\t||_______|____________________|_________________|_____________|______________|____________|______________|___________________|_________________||"<<endl;
    for(int i = 0; i < l.length;i++)
    {
        int dem = 1,dem1 = 1;
        cout <<"\t\t|| "<<l.t[i].getMasp()<<" |";
        cout <<"     " <<l.t[i].getName() <<setw(16 - l.t[i].getName().size())<<"|";
        cout <<"    "<< l.n[i].getTen()<<setw(14 - l.n[i].getTen().size()) <<" |";
        cout << "   "<<l.n[i].getChinhanh()<<setw(13 - l.n[i].getChinhanh().size())<<"|  ";
        cout <<l.t[i].getTime()<<"  |";
        int x = l.t[i].getSl();
        while(x >= 10)
        {
            x /= 10;
            dem++;
        }
        cout <<"   "<<l.t[i].getSl()<<setw(10 - dem)<<"|";
        int y = l.t[i].getPrice();
        while(y >= 10)
        {
            y /= 10;
            dem++;
        }
        cout <<"   "<<l.t[i].getPrice()<<"\t |";
        double a = l.t[i].getTong(t[i]);
        cout << "\t "<<a / 1000000 <<"\t     | ";
        if(l.n[i].getThanhtoan() == "Da thanh toan")
        {
            cout <<l.n[i].getThanhtoan()<<"   ||"<<endl;
        }
        if(l.n[i].getThanhtoan() == "Chua thanh toan")
        {
            cout <<l.n[i].getThanhtoan()<<" ||"<<endl;
        }
        cout <<"\t\t||_______|____________________|_________________|_____________|______________|____________|______________|___________________|_________________||"<<endl;
    }
}

// update so luong
void List::UpdateSl(List & l, string x, int y, int b)
{
    int dem = 0;
    for(int i = 0;i < l.length;i++)
    {
        if(b == l.t[i].getTime().getDay())
        {
            if(x == l.t[i].getName() || x == l.t[i].getMasp())
            l.t[i].setSl(y);
            dem++;
        }
    }
    if(dem == 0)
    {
        cout << "San pham nay khong duoc nhap trong ngay "<<b<<endl;
    }
}

// update gia
void List::UpdatePrice(List& l, string x, int y, int b)
{
    for(int i = 0;i < l.length;i++)
    {
        if(b == l.t[i].getTime().getDay())
        {
            if(x == l.t[i].getName() || x == l.t[i].getMasp())
            l.t[i].setPrice(y);
        }
    }
}

// update thanh toan
void List::UpdateThanhtoan(List& l, int b, string k)
{    
    int dem = 0;
    for(int i = 0;i < l.length;i++)
    {
        if(b == l.t[i].getTime().getDay())
        {
            if(k == l.t[i].getName() || k == l.t[i].getMasp())
            {
                cout << "Thanh toan: "<<endl<<endl;
                cout << "1.Da thanh toan"<<endl;
                cout << "2.Chua thanh toan"<<endl;
                cout << "Nhap de chon: ";
                int j;
                cin >> j;
                if(j == 1)
                {
                    l.n[i].setThanhtoan("Da thanh toan");
                }
                if(j == 2)
                {
                    l.n[i].setThanhtoan("Chua thanh toan");
                }
                dem++;
            }
        }
    }
    if(dem == 0)
    {
        cout << "San pham nay khong duoc nhap trong ngay "<<b<<endl;
    }
}

ThongtinSp& List::operator[](const int& index)
{
    static ThongtinSp p;

    if(index >= 0 && index < length)
        return *(this->t + index);
    else
        return p;
    
}

// in ra bang thong ke theo ngay, thang va ghi file
void List::showBTK(List& l)
{
    double tong = 0;
    cout << "\t\t\t\t\t\t_____________________________________________________________________"<<endl;
        cout << "\t\t\t\t\t\t|| Ngay nhap  |";
        cout << setw(16)<< "Ten san pham"<<"    |";
        cout << setw(12)<<"Gia tien"<<"   |";
        cout << setw(13)<<"Tong tien"<<"   |"<<endl;
        cout << "\t\t\t\t\t\t||            |                    |    (trieu)    |     (trieu)    |"<<endl;
        cout << "\t\t\t\t\t\t||____________|____________________|_______________|________________|"<<endl;
    for(int i = 1; i <= 31;i++)
    {
        int dem = 0;
        double sum = 0;
        Date x;

        for(int j = 0; j < l.length;j++)
                {
                    if(i == l.t[j].getTime().getDay())
                        dem++;
                }
        int y = dem;
        int a = 0;
        for(int j = 0; j < l.length;j++)
        {
            if(i == l.t[j].getTime().getDay())
            {
                if(y == dem)
                {
                    cout <<"\t\t\t\t\t\t|| "<<l.t[j].getTime()<<" |";
                    dem++;
                }
                cout << "\t" <<l.t[j].getName()<<setw(16 - l.t[j].getName().size())<<"\t   |";
                cout <<"\t"<<l.t[j].getTong(t[j]) / 1000000<<"\t   |";
                if(a < y - 1)
                {
                    cout <<"                |"<<endl;
                    cout <<"\t\t\t\t\t\t||            |____________________|_______________|                |"<<endl;
                    cout <<"\t\t\t\t\t\t||            |";
                    a++;
                }
                sum += l.t[j].getTong(t[j]);
            }
        }
        if(dem != 0)
        {
            cout << "\t  "<<sum / 1000000<<"\t    |"<<endl;
            tong += sum / 1000000;
            cout << "\t\t\t\t\t\t||____________|____________________|_______________|________________|"<<endl;
        }
    }
    cout << "\t\t\t\t\t\t|| Tong cong  |                    |               |\t  "<<tong<<"\t    |"<<endl;
    cout << "\t\t\t\t\t\t||____________|____________________|_______________|________________|"<<endl;
    
    ofstream output;
    output.open("D:\\Code\\PBL2\\Bangthongke.txt"); 
    double sumall = 0;
    int b = 0;
    for(int i = 1; i <= 31;i++)
    {
        double sum1 = 0;
        int dem = 0;
        for(int j = 0;j < this->length;j++)
        {
            if(i == t[j].getTime().getDay())
            {
                if(dem == 0)
                {
                    output << t[j].getTime() << ":"<<endl;
                    dem++;
                    b = t[j].getTime().getMonth();
                }
                output << "-" <<t[j].getName()<< " : ";
                output << t[j].getTong(t[j]) / 1000000 << " trieu" << endl;
                sum1 += t[j].getTong(t[j]);
            }
        }
        if(dem != 0)
        {
            output << "Tong cong: " << sum1/1000000 << " trieu" <<endl<<endl;
            sumall += sum1 / 1000000;
        }
    }
    
    output << "Tong tien thang " << b << ": " << sumall << " trieu";

}

// show tat ca sp
ostream& operator<<(ostream& o, List& l)
{
    cout <<endl;
    o << setw(31)<<" " <<"_______________________________________________________________________________________________________________________"<<endl;
    o << setw(31)<<" " <<"||"<<setw(3);
    o <<"STT";
    o << "|";
    o << setw(13)<<"Ma san pham ";
    o << "|";
    o <<setw(16)<< "Ten san pham"<<"     ";
    o << "|";
    o << setw(10)<<"So luong"<<setw(3);
    o << "|";
    o << setw(8)<<"Don vi"<<setw(6);
    o << "|";
    o << setw(12)<<"Gia tien"<<"   ";
    o << "|";
    o << "   Ngay nhap" <<"  ";
    o << "|";
    o << "   Nha cung cap  ";
    o << "||"<<endl;
    o << setw(31)<<" " << "||___|_____________|_____________________|____________|_____________|_______________|______________|_________________||"<<endl;
    ThongtinSp *temp = new ThongtinSp[l.length];
    temp = l.t;

    for(int j = 1; j <= 31;j++)
    {
        for(int i = 0;i < l.length;i ++)
        {
            if(j == temp[i].getTime().getDay())
            {
                o << setw(31)<<" " <<"||" <<setw(2);
            o << i + 1;
            o <<" ";
            o << (*(temp + i));
            o << "   "<< l.n[i].getTen();
            o << setw(16 - l.n[i].getTen().size());
            o <<"||"<<endl;
            o << setw(31)<<" " << "||___|_____________|_____________________|____________|_____________|_______________|______________|_________________||"<<endl;
            }
        }
    }
    return o;
} 

istream& operator>>(istream& i, List& l)
{
    while(l.length <= 0)
    {
        cout<<"Nhap so san pham: ";
        i >> l.length;
    }
    l.t = new ThongtinSp[l.length];
    for(int j = 0;j < l.length;j++)
    {
        i >> l[j];
    }
    return i;
}