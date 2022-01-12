#include <iostream>
#define a 3 // so cuoi MSSV

using namespace std;

class cHocphan
{
    string maHP;
    string tenHP;
    int tinchi;
public:
    cHocphan() { }

    cHocphan(string maHP, string tenHP, int tinchi) {
        this -> maHP = maHP;
        this -> tenHP = tenHP;
        this -> tinchi = tinchi;
    }
    /*
    string khoiKT() {
        switch(maHP[2]) {
            case '1':
                return "Dai cuong";
            case '2':
                return "Co so nganh";
            case '3':
                return "Cot loi nganh";
            case '4':
                return "Chuyen nganh (tu chon)";
            case '5':
                return "Chuyen nganh nang cao";
        }
    }*/

    int KT() {
        switch(maHP[2]) {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
        }
    }

    /*void nhap() {
        cin >> maHP >> tenHP >> tinchi;
    }*/

    friend istream& operator >>(istream &in, cHocphan &hp) {
        in >> hp.maHP;
        in.ignore();
        getline(in, hp.tenHP);
        in >> hp.tinchi;
        return in;
    }

    friend ostream& operator <<(ostream &out, const cHocphan &hp) {
        out << hp.maHP << endl;
        out << hp.tenHP << endl;
        out << hp.tinchi << endl;
        return out;
    }

    void xuatTC3() {
        if (this -> KT() == 3 && this -> tinchi == 3) {
            cout << "Ma HP: " << this -> maHP << endl;
            cout << "Ten HP: " << this -> tenHP << endl;
        }
    }
};

int main()
{
    cHocphan c1("ET2031", "KTLT", (a+1) % 3);

    cHocphan *c = new cHocphan[a+3];

    int k = 1;
    for (int i = 0; i < a + 3; i++) {
        cout << "Nhap hoc phan thu " << k++ << ":\n";
        cin >> c[i];
    }

    cout << "Cac hoc phan thuoc khoi kien thuc cot loi nganh co so tin chi bang 3 la: " << endl;
    for (int i = 0; i < a + 3; i++) {
       c[i].xuatTC3();
    }

    return 0;
}
