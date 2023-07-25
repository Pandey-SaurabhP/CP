// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

class Complex{
public:
    int real, img;

public:
    Complex(int r, int i){
        real = r;
        img = i;
    }
};

ostream& operator <<(ostream &out, Complex &c1){
    out << "( " << c1.real << " " << c1.img << " )\n";
}

istream& operator >>(istream &in, Complex &c1){
    in >> c1.real >> c1.img;
}

int main(){

    // fast();
    Complex c1(2, 5);
    cin >> c1;
    cout << c1;
    
    
    return 0;
}