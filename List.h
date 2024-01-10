#include"ThongtinSP.h"
#include"Nhacungcap.h"
#include"SPdaco.h"
class List
{
private: 
    int length, length1;
    ThongtinSp *t;
    Nhacungcap *n;
    SPdaco *s;
public:
    List();
    List(int, ThongtinSp*, Nhacungcap*, SPdaco*); 
    List(const List&);
    ~List();
    void EnterListSP();
    void ExportListSP();
    void EnterListNCC();
    void ExportListNCC();
    int getLength();
    void AddSp(List&, ThongtinSp&, Nhacungcap&, string);
    void AddThongtin(ThongtinSp&, Nhacungcap&, SPdaco&);
    bool checkDay(List& ,int);
    bool checkSP(List&, int, string);
    void EnterListDefault();
    void ExportListDefault();

    void InsertAt(int, const ThongtinSp&, const Nhacungcap&);
    void RemoveAt(List&, string,int);
    ThongtinSp& operator[](const int&);
    void showNCC(const List&);
    void swapSP(ThongtinSp&, ThongtinSp&);
    void swapNCC(Nhacungcap&, Nhacungcap&);
    void InterchangeSorthight(List&);
    void InterchangeSortlow(List&);
    bool Search(List&,string);
    void FindDay(List& ,int);
    void UpdatePrice(List&, string, int, int);
    void UpdateSl(List&, string, int, int);
    void UpdateThanhtoan(List&, int, string);
    void showTTSP(List&,string);
    void showPNH(List&);
    void showBTK(List&);
    friend ostream& operator<<(ostream& , List&);
    friend istream& operator>>(istream& , List&);
    
};

