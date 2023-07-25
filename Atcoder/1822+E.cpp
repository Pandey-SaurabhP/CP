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

        string s;
        cin >> s;

        if(n % 2 == 1){
            cout << "-1\n";
            continue;
        }

        int l = 0;
        int r = n - 1;

        vector <int> cntMatch(256, 0);
        vector <pair <char, char>> vc;

        while(l < r){
            if(s[l] != s[r]){
                vc.push_back(s[l], s[r]);
            }
            else{
                cntMatch[s[l]]++;
            }

            ++l;
            --r;
        }

        int ans = 0;

// Change each matching with aanother matching
        for(int i = 'a'; i <= 'z'; ++i){
            for(int j = 'a'; j <= 'z'; ++j){
                if(i == j) continue;
                else{
                    int mn = min(cntMatch[i], cntMatch[j]);

                    cntMatch[i] -= mn;
                    cntMatch[j] -= mn;
                }
            }
        }

// Now we have some elements left which cannot be matched with another matching
        
        
    }
    
    return 0;
}