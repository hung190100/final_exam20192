#include <iostream>
#define a 3

using namespace std;
/*
typedef struct sHCN {
    float chieu_dai;
    float chieu_rong;
};

float dientich(sHCN s) {
    return s.chieu_dai * s.chieu_rong;
}

int main()
{
    sHCN arr[10+a];
    int c = 0;
    for (int i = 0; i < 10 + a; i++) {
        c++;
        cout << "Nhap gia tri phan tu thu " << c << ": ";
        cin >> arr[i].chieu_dai >> arr[i].chieu_rong;
    }

    float s = 0;
    for (int i = 0; i < 10 + a; i++) {
        s += dientich(arr[i]);
    }

    cout << "\nTong dien tich la: " << s << endl;

    return 0;
}*/

class sHCN
{
    double chieu_dai;
    double chieu_rong;
public:
    sHCN () {chieu_dai = chieu_rong = 0;}

    sHCN (double chieu_dai, double chieu_rong) {
        this -> chieu_dai = chieu_dai;
        this -> chieu_rong = chieu_rong;
    }

    double dientich () {
        return this -> chieu_dai * this -> chieu_rong;
    }
};

int main()
{
    sHCN c1(10*(a+1), a+1);
    sHCN c2(100, a+1);
    double s = c1.dientich() + c2.dientich();
    cout << "Tong dien tich c1 va c2 la: " << s << endl;
    return 0;
}
