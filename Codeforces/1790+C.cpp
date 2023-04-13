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

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <vector <int>> a(n, vector <int> (n - 1));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n - 1; ++j){
                cin >> a[i][j];
            }
        }

        vector <bool> done(105, 0);
        for(int i = 0; i < n - 1; ++i){
            done[a[0][i]] = 1;
        }

        int missing = -1;
        for(int i = 1; i <= n; ++i){
            if(!done[i]){
                missing = i;
                break;
            }
        }

        // Equation 2 btaegi missing kiske baad hai
        int nt1, nt2;

        for(int i = 0; i < n - 1; ++i){
            if(a[1][i] == missing){
                if(i == 0) nt1 = -1;
                else{
                    nt1 = a[1][i - 1];
                }
            }
        }

        for(int i = 0; i < n - 1; ++i){
            if(a[2][i] == missing){
                if(i == 0) nt2 = -1;
                else{
                    nt2 = a[2][i - 1];
                }
            }
        }


    // Ans nikalne ka process
        vector <int> ans;
        int cnt = 0;

        if(nt1 == -1 && nt2 == -1){
            ans.push_back(missing);
            cnt = INT_MIN;
        }
        else if(nt1 == -1 || nt2 == -1){
            cnt = 1;
        }
        else if(nt1 == nt2 && nt1 != -1){
            cnt = 1;
        }
        else cnt = 2;

        
        bool d = 0;

        for(int i = 0; i < n - 1; ++i){
            ans.push_back(a[0][i]);

            if(a[0][i] == nt1 || a[0][i] == nt2){
                --cnt;
            }

            if(cnt == 0 && d == 0){
                ans.push_back(missing);
                d = 1;
            }
        }

        print(ans, ans.size());

    }
    
    return 0;
}