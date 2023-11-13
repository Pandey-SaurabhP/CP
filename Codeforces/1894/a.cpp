#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

//    fast();

    ll t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        cin >> s;

        bool feasible = 0;

        for(int x = n; x >= 1; --x){
            int a, b;
            a = b = 0;

            int cnta, cntb;
            cnta = cntb = 0;

            bool tillEnd = 0;

            for(int j = 0; j < n; ++j){
                cnta += (s[j] == 'A');
                cntb += (s[j] == 'B');

                if(j == n - 1){
                    tillEnd = 1;
                }

                if(cnta == x){
                    cnta = cntb = 0;
                    ++a;
                    break;
                }
                else if(cntb == x){
                    ++b;
                    cnta = cntb = 0;
                    break;
                }
            }

            if(tillEnd){
                if(cnta == 0 && cntb == 0){
                    // Feasible game
                    if(a > b){
                        cout << "A\n";
                    }
                    else if(b > a){
                        cout << "B\n";
                    }
                    else{
                        cout << "?\n";
                    }
                    feasible = 1;
                    break;
                }
                else{
                    //Continue Checking
                    continue;
                }
            }
        }

        if(!feasible){
            cout << "?\n";
        }
    }

    return 0;
}
