#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
class A {
private:
    // Biến thành viên nếu cần
public:
    A() { cout << "Tạo đối tượng A" << endl; } // Constructor
     ~A() { cout << "Hủy A" << endl; }  // Destructor, dùng virtual

    int get_A(); // Hàm thành viên
};

int A::get_A() {
    cout << "A" << endl;
    return 0;
}

class C {
private:
    // Biến thành viên nếu cần
public:
    C() { cout << "Tạo đối tượng C" << endl; } // Constructor
    ~C() { cout << "Hủy C" << endl; }  // Destructor, dùng virtual

    int get_C(); // Hàm thành viên
};

int C::get_C() {
    cout << "C" << endl;
    return 0;
}


class B : public A , public C {
private:
    // Biến thành viên nếu cần
public:
    B() { cout << "Tạo đối tượng B" << endl; }  // Constructor
    ~B() { cout << "Hủy B" << endl; }           // Destructor

    int get_B(); // Hàm thành viên
};

int B::get_B() {
    cout << "B" << endl;
    return 0;
}
int main(){
   
    B b;
   

    return 0;
}
