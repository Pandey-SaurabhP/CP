// pandeyGRocks
#include <bits/stdc++.h>
using namespace std;

class coordinate{
private:
    int x, y, z;

public:
    coordinate(int xx = 0, int yy = 0, int zz = 0){
        x = xx;
        y = yy;
        z = zz;
    }

    float operator +(coordinate &b){
        float xxx = (this -> x - b.x);
        float yyy = (this -> y - b.y);
        float zzz = (this -> z - b.z);

        xxx *= xxx;
        yyy *= yyy;
        zzz *= zzz;

        return sqrt(xxx + yyy + zzz); 
    }
};

int main(){

    // fast();

    coordinate a(1, 2, 3);
    coordinate b(0, 0, 0);

    float c = a + b;

    cout << c << "\n";
    
    return 0;
}