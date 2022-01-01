#include <iostream>
#include<string>

using namespace std;

template<class T> class Node{
public:
    T Value;
    Node *Next;
    Node(T v) : Value(v), Next(0){} // Một node mới được tạo ra có giá trị v, trỏ tới rỗng
};

template <class T> class List {
    Node<T> *head, *tail;
    int count; // Số node
public:
    List() : count(0){ }
    ~List();//Hàm hủy

    // Xóa toàn bộ list
    void RemoveAll(){
        while (count){
            --count;
            Node<T> *p = head;
            head = p -> Next;
            delete p;
        }
    }

    // Thêm node vào cuối list
    void Add(T v){
        Node<T> *p = new Node<T>(v);
        if(count++ == 0){
            head = p;
        }
        else{
            tail -> Next = p;
        }
        tail = p;
    }

    // Trả về đầu list
    Node<T> * First() const { return head; }

    // Đếm số node của list
    int Count() const { return count; }

    // Chuyển list thành mảng
    T* ToArray(){
        T* arr= new T[count];
        Node<T> *p = head;
        for(int i = 0; i < count; i++, p = p -> Next){
            arr[i] = p -> Value;
        }
        return arr;
    }
};

class Date{
public:
    int Day, Month, Year;

    Date(){Day = Month = Year = 0;}

    Date(int y, int m, int d): Year(y), Month(m), Day(d) {}//Ham khoi tao thiết lập các gia trị năm thang ngày

    friend ostream& operator << (ostream& output, const Date& d) {
        if (d.Day < 10 && d.Month < 10) {
            output << "0" << d.Day << ".0" << d.Month << "." << d.Year;
        } else if (d.Day < 10) {
            output << "0" << d.Day << "." << d.Month << "." << d.Year;
        } else if (d.Month < 10) {
            output << d.Day << ".0" << d.Month << "." << d.Year;
        } else {
            output << d.Day << "." << d.Month << "." << d.Year;
        }
    }; //Toán tử luồng ra
};

class ThiSinh{
public:
    Date NgaySinh;
    string HoTen;
    double Toan, Ly, Anh;//Điểm các môn thi, điểm toán hệ số 2
public:
    ThiSinh(){}

    ThiSinh(const char *hoTen, const Date ns, double toan, double ly, double anh) {
        HoTen = *hoTen;
        NgaySinh = ns;
        Toan = toan;
        Ly = ly;
        Anh = anh;
    }

    double Tong() const {
        return Toan * 2 + Ly + Anh;
    } //Tinh tổng điểm

    double TB() const {
        return (this -> Tong()) / 4;
    } //Trung binh các điểm

    friend ostream& operator << (ostream& output, const ThiSinh& ts) {
        output << ts.HoTen << "\t" << ts.NgaySinh << "\t";
        output << ts.Toan << "\t" << ts.Ly << "\t" << ts.Anh << "\t";
        output << ts.Tong() << "\t" << ts.TB();
    }//toan tu luong ra
};

class ListThiSinh : public List<ThiSinh *>{
public:
    ListThiSinh(ThiSinh **arr){
        int i = 0;
        while(arr[i]){
            this -> Add(arr[i++]);
        }
    }
};

int main()
{
    ThiSinh *arr[] = {
        new ThiSinh("Nguyen Thanh Son", Date(2020, 1, 15), 8, 7, 8),
        new ThiSinh("Tran Hai Nam", Date(2020, 10, 6), 9, 8, 6),
        new ThiSinh("Vu Duy Anh", Date(2020, 7, 31), 7, 10, 9),
        new ThiSinh("Hoang Anh Tuan", Date(2020, 12, 22), 3, 5, 7),
        new ThiSinh("Pham Thanh Huyen", Date(2020, 8, 10), 8, 8, 8),
        new ThiSinh("Phung Ngoc Linh", Date(2020, 4, 5), 9, 9, 9),
        0
    };
    ListThiSinh cacThiSinh(arr);
    auto p = cacThiSinh.First();
    int soLuong = cacThiSinh.Count();
    for(int i = 0; i < soLuong; i++, p = p -> Next)
    {
        cout << *p -> Value << endl;
    }
}
