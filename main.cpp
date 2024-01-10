#include"List.h"
#include<windows.h>
using namespace std;
List a;
static int b = 0;
void TextColor(int x)     //X là mã màu
{
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}


void chon(int x)
{
    a.EnterListSP();
    a.EnterListNCC();

    switch (x)
    {
    case 1://In danh sach san pham
    {
        TextColor(2);
        int q;
        cout<<"\t\t\t\t\t  __________________________  "<<endl;
        cout<<"\t\t\t\t\t||                          ||"<<endl;
        cout<<"\t\t\t\t\t|| 1.Danh sach san pham     ||"<<endl;
        cout<<"\t\t\t\t\t|| 2.Danh sach nha cung cap ||"<<endl;
        cout<<"\t\t\t\t\t||__________________________||"<<endl<<endl;
        cout<<"\t====> Chon de tiep tuc: ";
        cin >>q;
        system("cls");
        switch(q)
        {
            case 1:
            {
                TextColor(8);
                cout <<endl<<endl;
                cout <<setw(110)<<"********** DANH SACH SAN PHAM **********"<<endl;
                cout <<a<<endl;
                break;
            }
            case 2:
            {
                TextColor(8);
                cout <<endl<<endl;
                cout <<"\t\t\t\t\t\t\t\t********** DANH SACH NHA CUNG CAP **********"<<endl;
                a.showNCC(a);
                break;
            }
        }
        break;
    }
    case 2:                   //them san pham
    {
        int k;
        double w;
        Date y;
        string m,n,v;
        ThongtinSp b;
        Nhacungcap c;
        SPdaco s;
        time_t now = time(0);
	    tm * t = localtime(&now);
        y.setDay(t->tm_mday);
        y.setMonth(1 + t->tm_mon);
        y.setYear(1900 + t->tm_year);
        cout<<endl;
        cout << setw(85)<<"-------------------- TODAY: "<<y <<" --------------------"<<endl<<endl;
        cout <<"< THEM SAN PHAM >"<<endl;
        cout <<"______________________________________________"<<endl<<endl;
        cout << "Nhap ma san pham: ";
        cin >> m;
        while(!(b.checkMasp(m)))
        {
            cout << "Ma san pham sai, vui long nhap lai: ";
            cin >>m;
        }
        if(a.Search(a,m) == true)
        {
            cout << "Da co san pham nay trong danh sach..."<<endl;
            a.showTTSP(a,m);
            cout <<endl;
            cout << "Ban co muon them san pham nay khong(y/n)?";
            char p;
            cin >> p;
            if(p == 'y')
            {
                b.setTime(y);
                a.AddSp(a,b,c,m);
                cout <<"Nhap so luong: ";
                cin >> k;
                b.setSl(k);
                cout << "Nhap gia: ";
                cin >> w;
                cout << "Thanh toan: "<<endl<<endl;
                cout << "1.Da thanh toan"<<endl;
                cout << "2.Chua thanh toan"<<endl;
                cout << "Nhap de chon: ";
                int i;
                cin >> i;
                if(i == 1)
                {
                    c.setThanhtoan("Da thanh toan");
                }
                if(i == 2)
                {
                    c.setThanhtoan("Chua thanh toan");
                }
                b.setPrice(w);
                a.InsertAt(a.getLength(),b,c);
                a.ExportListSP();
                a.ExportListNCC();
                cout<<endl;
                cout <<"------Da them san pham thanh cong------"<<endl;
                break;
            }
            else
            {
                break;
            }  
        }
        else
        {
            cout << "Nhap ten san pham: ";
            cin.ignore();
            getline(cin,n);
            b.setName(n);
            if(a.Search(a,n) == true)
            {
                cout <<"Da co san pham nay trong danh sach..."<<endl;
                break;
            }
        }
        b.setMasp(m);
        b.setTime(y);
        cout <<"Nhap so luong: ";
        cin >> k;
        b.setSl(k);
        cout <<"Nhap don vi: ";
        cin >> v;
        b.setDonvi(v);
        cout <<"Nhap gia: ";
        cin >>w;
        b.setPrice(w);
        cout << "*Thanh toan: "<<endl<<endl;
        cout << "1.Da thanh toan"<<endl;
        cout << "2.Chua thanh toan"<<endl;
        cout << "Nhap de chon: ";
        int i;
        cin >> i;
        if(i == 1)
        {
            c.setThanhtoan("Da thanh toan");
        }
        if(i == 2)
        {
            c.setThanhtoan("Chua thanh toan");
        }
        cin >> c;
        a.InsertAt(a.getLength(),b,c);
        a.AddThongtin(b,c,s);
        a.ExportListSP();
        a.ExportListNCC();
        a.ExportListDefault();
        cout <<endl;
        cout <<"------Da them san pham thanh cong------"<<endl;
        break;
    }
    case 3:  /// xoa san pham
    {
        int k;
        string w;
        Date y;
        cout <<endl;
        cout << "< XOA SAN PHAM >"<<endl;
        cout <<"______________________________________________"<<endl<<endl;
        cout << "Nhap ngay co san pham can xoa: ";
        cin >> k;
        time_t now = time(0);
	    tm * t = localtime(&now);
        y.setDay(k);
        y.setMonth(1 + t->tm_mon);
        y.setYear(1900 + t->tm_year);
        cout <<endl;
        cout << "TIME: "<<y<<endl<<endl;;
        if(a.checkDay(a,k) == true)
        {
            a.FindDay(a,k);
            cout <<endl;
            cout << "Nhap ten hoac ma san pham can xoa: ";
            cin.ignore();
            getline(cin,w);
            if (a.Search(a,w) == true)
            {
                if(a.checkSP(a,k,w))
                {
                a.RemoveAt(a,w,k);
                a.ExportListSP();
                a.ExportListNCC();
                a.EnterListSP();
                a.EnterListNCC();
                cout <<endl;
                cout <<"-------------Xoa san pham thanh cong-------------"<<endl;
                break;
                }
                else
                {
                    cout <<endl;
                    cout << "San pham nay khong duoc nhap trong ngay "<<y<<"..."<<endl;
                    break;
                }
            }
            else
            {
                cout <<endl;
                cout<<"Khong co san pham nay trong danh sach..."<<endl;
                break;
            }
        }
        else
        {
            cout<<endl;
            cout <<"Ngay nay khong nhap hang..."<<endl;
            break;
        }
    break;
    }
    case 4:    ///In phieu nhap kho
    {
        TextColor(8);
        Date y;
        time_t now = time(0);
	    tm * t = localtime(&now);
        y.setMonth(1 + t->tm_mon);
        y.setYear(1900 + t->tm_year);
        cout <<endl<<endl;
        cout<<"\t\t\t\t\t\t\t--------------- Phieu nhap kho thang "<<y.getMonth()<<" nam "<<y.getYear()<<" ---------------"<<endl;
        a.showPNH(a);
        break;
    }
    case 5:
    {
        cout <<endl;
        cout << "< SAP XEP >"<<endl;
        cout <<"______________________________________________"<<endl<<endl;
        int q;
        cout <<"1.Sap xep theo gia tang dan"<<endl;
        cout <<"2.Sap xep theo gia giam dan"<<endl;
        cout <<"Chon de tiep tuc: ";
        cin >> q;
        switch (q)
        {
            case 1:
            {
                TextColor(8);
                cout <<setw(110)<<"********** DANH SACH SAN PHAM **********"<<endl;
                a.InterchangeSorthight(a);
                break;
            }
            case 2:
            {   
                TextColor(8);
                cout <<setw(110)<<"********** DANH SACH SAN PHAM **********"<<endl;
                a.InterchangeSortlow(a);
                break;
            }
        }
        break;
    }
    case 6:
    {
        cout <<endl;
        cout << "< TIM KIEM >"<<endl;
        cout <<"______________________________________________________"<<endl<<endl;
        string d;
        cout <<"Nhap ten san pham hoac ma san pham can tim kiem: ";
        cin.ignore();
        getline(cin,d);
        if(a.Search(a,d) == true)
        {   
            TextColor(8);
            a.showTTSP(a,d);
        }
        else
        {
            cout <<"Khong tim thay san pham..."<<endl;
        }
        break;
    }
    case 7:
    {
        Date y;
        time_t now = time(0);
	    tm * t = localtime(&now);
        TextColor(8);
        cout<<endl<<endl;
        cout <<"\t\t\t\t\t\t\t\t\tBANG THONG KE THANG "<<1 + t->tm_mon<< " nam "<< 1900 + t->tm_year<<endl;
        a.showBTK(a);
        break;
    }
    case 8:
    {
        Date y;
        double c;
        string m;
        int k,q;
        time_t now = time(0);
        tm * t = localtime(&now);
        y.setMonth(1 + t->tm_mon);
        y.setYear(1900 + t->tm_year);
        cout <<"______________________________________________________"<<endl<<endl;
        cout << "1.Update gia"<<endl;
        cout << "2.Update so luong"<<endl;
        cout << "3.Bo sung them san pham"<<endl<<endl;
        cout << "====>Chon de tiep tuc: ";
        cin >> q;
        while(q < 1 || q > 3)
        {
            cout << "Nhap sai, nhap lai: ";
            cin >> q;
        }
        system("cls");
        switch (q)
        {
        case 1:
        {
            cout <<endl;
            cout << "< CHINH SUA GIA SAN PHAM >"<<endl;
            cout <<"______________________________________________________"<<endl<<endl;
            cout << "Nhap ngay can chinh sua: ";
            cin >> k;
            while(k <= 0 || k > 31)
            {
                cout << "Sai ngay, vui long nhap lai: ";
                cin >> k;
            }
            y.setDay(k);
            if(a.checkDay(a,k) == true)
            {
                TextColor(8);
                a.FindDay(a,k);
                TextColor(2);
                cout <<endl;
                cout << "Nhap ten hoac ma san pham can chinh sua gia: ";
                cin.ignore();
                getline(cin,m);
                if(a.Search(a,m) == true)
                {
                    if(a.checkSP(a,k,m) == true)
                    {
                        cout <<"Nhap gia moi: ";
                        cin >> c;
                        a.UpdatePrice(a, m, c, k);
                        a.ExportListSP();
                        cout <<endl;
                        cout <<"----------DA CHINH SUA THANH CONG----------"<<endl;
                        break;
                    }
                    else
                    {
                        cout << "San pham nay khong duoc nhap trong ngay "<<y<< " ..."<<endl;
                        break;
                    }
                }
                else
                {
                    cout << "Khong co san pham nay trong danh sach..."<<endl;
                    break;
                }
            }
            else
            {
                cout << "Ngay "<< k << " khong co nhap hang..."<<endl;
                break;
            }
            break;
        }   
        case 2:
        {
            int p;
            cout <<endl;
            cout << "< CHINH SUA SO LUONG SAN PHAM >"<<endl;
            cout <<"______________________________________________________"<<endl<<endl;
            cout << "Nhap ngay can chinh sua: ";
            cin >> k;
            while(k <= 0 || k > 31)
            {
                cout << "Sai ngay, vui long nhap lai: ";
                cin >> k;
            }
            y.setDay(k);
            if(a.checkDay(a,k) == true)
            {
                TextColor(8);
                a.FindDay(a,k);
                TextColor(2);
                cout <<endl;
                cout << "Nhap ten hoac san pham can chinh sua so luong: ";
                cin.ignore();
                getline(cin,m);
                if(a.Search(a,m) == true)
                {
                    if(a.checkSP(a,k,m) == true)
                    {
                        cout <<"Nhap so luong: ";
                        cin >> p;
                        a.UpdateSl(a, m, p, k);
                        a.ExportListSP();
                        cout <<endl;
                        cout <<"----------DA CHINH SUA THANH CONG----------"<<endl;
                        break;
                    }
                    else
                    {
                        cout << "San pham nay khong duoc nhap trong ngay "<<y<<"..."<<endl;
                    }
                }
                else
                {
                    cout << "Khong co san pham nay trong danh sach..."<<endl;
                    break;
                }
            }
            else
            {
                cout << "Ngay "<< k << " khong co nhap hang..."<<endl;
                break;
            }
            break;
        }
        case 3:
        {
            double w;
            string n,v;
            ThongtinSp b;
            Nhacungcap d;
            SPdaco s;
            cout <<endl;
            cout << "< BO SUNG SAN PHAM >"<<endl;
            cout <<"______________________________________________________"<<endl<<endl;
            cout << "Nhap ngay can bo sung: ";
            cin >> k;
            y.setDay(k);
            while(y.checkDay(k, 1 + t->tm_mon, 1900 + t->tm_year) == false  || k > t->tm_mday)
            {
                cout << "Sai ngay nhap,vui long nhap lai: ";
                cin >> k;
                y.setDay(k);
            }
            cout << "Nhap ma san pham: ";
            cin >> m;
            while(!(b.checkMasp(m)))
            {
                cout << "Ma san pham sai, vui long nhap lai: ";
                cin >>m;
            }
            if(a.Search(a,m) == true)
            {
                cout << "Da co san pham nay trong danh sach..."<<endl;
                TextColor(8);
                a.showTTSP(a,m);
                TextColor(2);
                cout << "Ban co muon them san pham nay khong(y/n)?";
                char p;
                cin >> p;
                if(p == 'y')
                {
                    b.setTime(y);
                    b.setMasp(m);
                    a.AddSp(a,b,d,m);
                    cout <<"Nhap so luong: ";
                    cin >> k;
                    b.setSl(k);
                    cout << "Nhap gia: ";
                    cin >> w;
                    cout << "*Thanh toan: "<<endl<<endl;
                    cout << "1.Da thanh toan"<<endl;
                    cout << "2.Chua thanh toan"<<endl;
                    cout << "Nhap de chon: ";
                    int i;
                    cin >> i;
                    if(i == 1)
                    {
                        d.setThanhtoan("Da thanh toan");
                    }
                    if(i == 2)
                    {
                        d.setThanhtoan("Chua thanh toan");
                    }
                    b.setPrice(w);
                    a.InsertAt(a.getLength(),b,d);
                    a.ExportListSP();
                    a.ExportListNCC();
                    cout <<endl;
                    cout <<"------Da bo sung san pham thanh cong------"<<endl;       
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout << "Nhap ten san pham: ";
                cin.ignore();
                getline(cin,n);
                b.setName(n);
                if(a.Search(a,n) == true)
                {
                    cout <<"Da co san pham nay trong danh sach..."<<endl;
                    break;
                }
            }
            b.setMasp(m);
            b.setTime(y);
            cout <<"Nhap so luong: ";
            cin >> k;
            b.setSl(k);
            cout <<"Nhap don vi: ";
            cin >> v;
            b.setDonvi(v);
            cout <<"Nhap gia: ";
            cin >>w;
            b.setPrice(w);
            cout << "*Thanh toan: "<<endl<<endl;
            cout << "1.Da thanh toan"<<endl;
            cout << "2.Chua thanh toan"<<endl;
            cout << "Nhap de chon: ";
            int i;
            cin >> i;
            if(i == 1)
            {
                d.setThanhtoan("Da thanh toan");
            }
            if(i == 2)
            {
                d.setThanhtoan("Chua thanh toan");
            }
            cin >> d;
            a.InsertAt(a.getLength(),b,d);
            a.AddThongtin(b,d,s);
            a.ExportListSP();
            a.ExportListNCC();
            a.ExportListDefault();
            cout <<endl;
            cout <<"Da bo sung san pham thanh cong------"<<endl;
            break;
        }
        }
        break;
    }
    case 9:
    {
        Date y;
        int i;
        string m;
        cout <<endl;
        cout << "< UPDATE THANH TOAN >"<<endl;
        cout <<"______________________________________________________"<<endl<<endl;
        cout << "Nhap ngay can update: ";
        cin >> i;
        time_t now = time(0);
	    tm * t = localtime(&now);
        y.setMonth(1 + t->tm_mon);
        y.setYear(1900 + t->tm_year);
        while(y.checkDay(i, 1 + t->tm_mon, 1900 + t->tm_year) == false  || i > t->tm_mday)
        {
            cout << "Sai ngay nhap,vui long nhap lai: ";
            cin >> i;
        }
        y.setDay(i);
        if(a.checkDay(a,i) == true)
        {
            cout << "TIME: "<<y<<endl;
            TextColor(8);
            a.FindDay(a,i);
            TextColor(2);
            cout << "Nhap ten hoac san pham can update: ";
            cin.ignore();
            getline(cin,m); 
            if(a.Search(a,m) == true)
            {
                a.UpdateThanhtoan(a,i,m);
                a.ExportListNCC();
                cout <<endl;
                cout << "-------------UPDATE thanh cong-------------"<<endl;
                break;
            }
            else
            {
                cout << "San pham nay khong co trong danh sach..."<<endl;
            }
            
        }
        else
        {
            cout << "Ngay "<< y << " khong co nhap hang..."<<endl;
            break;
        }
        break;
    }
    case 10:
    {
        b++;
        break;
    }
    }
}



void check(int &x)
{
    while( x < 1 || x > 10)
    {
        cout<< "Chon sai, vui long chon lai: ";
        cin >> x;
    }
}


void Menu(int &x)
{
    TextColor(2);
    cout <<endl<<endl<<endl<<endl;
    cout <<"\t\t\t\t\t____________________________________________________________________________________________"<<endl;
    cout <<setw(41)<<"|"<<setw(91)<<"|"<<endl;
    cout <<"\t\t\t\t\t|\t\t\t\tQUAN LI HANG NHAP TRONG 1 THANG"<<setw(29)<<"|"<<endl;
    cout <<setw(41)<<"|"<<setw(91)<<"|"<<endl;
    cout <<"\t\t\t\t\t|\t1.In danh sach" <<"\t\t\t\t\t\t2.Them san pham"<<setw(13)<<"|"<<endl;
    cout <<setw(41)<<"|"<<setw(91)<<"|"<<endl;
    cout <<"\t\t\t\t\t|\t3.Xoa san pham" <<"\t\t\t\t\t\t4.In phieu nhap kho"<<setw(9)<<"|"<<endl;
    cout <<setw(41)<<"|"<<setw(91)<<"|"<<endl;
    cout <<"\t\t\t\t\t|\t5.Sap xep san pham"<<"\t\t\t\t\t6.Tim kiem san pham"<<setw(9)<<"|"<<endl;
    cout <<setw(41)<<"|"<<setw(91)<<"|"<<endl;
    cout <<"\t\t\t\t\t|\t7.Bang thong ke\t\t\t\t\t\t8.Update san pham"<<setw(11)<<"|"<<endl;
    cout <<setw(41)<<"|"<<setw(91)<<"|"<<endl;
    cout <<"\t\t\t\t\t|\t9.Update thanh toan\t\t\t\t\t10.Thoat"<<setw(20)<<"|"<<endl;
    cout<<"\t\t\t\t\t|__________________________________________________________________________________________|"<<endl<<endl;
    cout <<"=====> Chon de tiep tuc: ";
    cin >> x;
    while(!cin.good())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Nhap sai, nhap lai: ";
        cin >> x;
    }
    check(x);
}


void Lap(int x, char &c)
{   
    Menu(x);
    system("cls");
    chon(x);
    if(b == 0)
    {
        cout <<endl;
        TextColor(2);
        cout <<"=====> Ban co muon tiep tuc khong?(y/n): ";
        cin >>c;
        while(c != 'y' && c != 'n')
        {
            cout <<"Nhap sai, nhap lai: ";
            cin >> c;
        }
    }
    system("cls");
}

int main() 
{
    TextColor(3);
    cout << "\t\t\t\t\t\t ________________________________________________________________________ "<<endl;
    cout << setw(122) << "|                                                                        |"<<endl;
    cout << "\t\t\t\t\t\t|\t\t\t _______________________\t\t         |"<<endl;
    cout << "\t\t\t\t\t\t|\t\t\t|                       |\t\t         |"<<endl;
    cout << "\t\t\t\t\t\t|\t\t\t| DO AN CO SO LAP TRINH |\t\t         |"<<endl;
    cout << "\t\t\t\t\t\t|\t\t\t|_______________________|\t\t         |"<<endl;
    cout << setw(122) << "|                                                                        |"<<endl;
    cout << setw(122) << "|                                                                        |"<<endl;
    cout << "\t\t\t\t\t\t| DE TAI: QUAN LI HANG NHAP TRONG 1 THANG\t\t\t         |"<<endl;
    cout << "\t\t\t\t\t\t| G.V HUONG DAN: Th.S DO THI TUYET HOA\t\t\t\t         |"<<endl;
    cout << "\t\t\t\t\t\t| NHOM HP: 21.15B\t\t\t\t\t\t         |"<<endl;
    cout << setw(122) << "|                                                                        |"<<endl;
    cout << "\t\t\t\t\t\t|\t\t\t\t\t\t ________________________|"<<endl; 
    cout << "\t\t\t\t\t\t|\t\t\t\t\t\t|SVTH: HOANG MINH TIN    |"<<endl;
    cout << "\t\t\t\t\t\t|\t\t\t\t\t\t|MSSV: 102210381         |"<<endl;
    cout << "\t\t\t\t\t\t|\t\t\t\t\t\t|SVTH: NGUYEN NGOC THINH |"<<endl;
    cout << "\t\t\t\t\t\t|\t\t\t\t\t\t|MSSV: 102210377         |"<<endl;
    cout << "\t\t\t\t\t\t|_______________________________________________|________________________| "<<endl<<endl;
    system("pause");
    a.EnterListDefault();
    // Nhacungcap a;
    // cin >> a;
    // cout << a;
    // cout << a;
    int x;
    char c;
    Lap(x,c);
    while (c == 'y')
    {
        Lap(x,c);
        if(b != 0)
            break;
    }

    return 0;
}


