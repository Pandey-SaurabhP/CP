// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);
        sort(a.begin(), a.end());

        vector <char> type;

        int lst = a[0];
        int cnt = 0;

        for(int i = 0; i < n; ++i){

            if(a[i] == lst){
                ++cnt;
            }
            else{
                if(cnt % 2 == 0){
                    type.push_back('e');
                }
                else{
                    type.push_back('o');
                }

                cnt = 1;
                lst = a[i];
            }

            if(i == n - 1){
                if(cnt % 2 == 0){
                    type.push_back('e');
                }
                else{
                    type.push_back('o');
                }

                cnt = 1;
                lst = a[i];
            }
            
        }

        bool mWins = 0;

        for(auto it : type){
            if(it == 'o'){
                mWins = 1;
                break;
            }
        }

        if(mWins){
            cout << "Marichka";
        }
        else{
            cout << "Zenyk";
        }
        cout << "\n";

        // print(type, type.size());

    }
    
    return 0;
}