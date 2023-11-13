#include <iostream>

using namespace std;

int compatible[1025][1025];

int isCompatible(int i, int j, int n){

    if(i == 0 && j == 0) return 1;

    int cnt = 0;

    while(n > 0){
        int x = i % 2;
        int y = j % 2;

//        cout  << n << " " << x << " " << y << "\n";

        if(n > 1){
            int nx = (i >> 1) % 2;
            int ny = (j >> 1) % 2;

            bool ans = 0;

            if(x == nx && y == ny){
                ans |= 1;

                if(x == 0 && y == 1){
//                    cout << "Hello! " << i << " " << j << "\n";
                    ++cnt;
                }

                i >>= 2;
                j >>= 2;
                n -= 2;

                continue;
            }
            if(x == 0 && y == 1){
                ans |= 1;
            }
            if(x == 1 && y == 0){
                ans |= 1;
            }

            if(ans == 0) return 0;
        }
        else{
            if(x == y){
                return 0;
            }
        }

        i >>= 1;
        j >>= 1;

        --n;
    }

    return (1 << cnt);
}

int solve(int i, int mask, int &m, int &req){
    if(i == m){
        cout << "h : " << mask << " " << req << "\n";
        return mask == 0;
    }

    int ans = 0;

    for(int j = 0; j <= req; ++j){
        if(compatible[mask][j] > 0){
            ans += solve(i + 1, j, m, req);
        }
    }

    return ans;
}

int main(){

//    isCompatible(0, 3, 2);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < (1 << n); ++i){
        for(int j = 0; j < (1 << n); ++j){
            compatible[i][j] = isCompatible(i, j, n);
        }
    }

    for(int i = 0; i < (1 << n); ++i){
        for(int j = 0; j < (1 << n); ++j){
            cout << i << " " << j << " : " << compatible[i][j]  << "\n";
        }
    }

    int rq = (1 << n) - 1;
    cout << solve(0, 0, m, rq);

    return 0;

}
