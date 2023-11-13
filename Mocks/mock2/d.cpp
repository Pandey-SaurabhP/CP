#include <bits/stdc++.h>

using namespace std;

#define read(filled, n) for(ll i = 0; i < n; ++i) cin >> filled[i];
#define print(filled, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << filled[i] << endl; } else { cout << filled[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool filled[301];
int n;

int num = 0;
int den = 0;

void solve(int i){

    if(i == n - 1){
        if(!filled[n - 1]){
            ++num;
        }
        ++den;
        return;
    }

    if(i == 0){
        for(int j = 1; j < n; ++j){
            filled[j] = 1;
            solve(i + 1);
            filled[j] = 0;
        }
        return;
    }
    else{
        if(!filled[i]){
            filled[i] = 1;
            solve(i + 1);
            filled[i] = 0;
        }
        else{
            for(int j = 0; j < n; ++j){
                if(!filled[j]){
                    filled[j] = 1;
                    solve(i + 1);
                    filled[j] = 0;
                }
            }
        }
    }
}

int main(){

//    fast();
    for(int i = 0; i < 300; ++i){
        filled[i] = 0;
    }

    cin >> n;
    solve(0);

    cout << den - num << " " << den << "\n";


    return 0;
}


