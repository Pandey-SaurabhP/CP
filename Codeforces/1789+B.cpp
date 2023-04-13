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

bool isPalindrome(string &s, int &n){
    int l = 0;
    int r = n - 1;

    while(l < r){
        if(s[l] != s[r]){
            return 0;
        }

        ++l;
        --r;
    }

    return 1;
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

        int l = 0;
        int r = n - 1;

        bool invStart = 0;

        while(l < r){

            if(invStart){
                if(s[l] == s[r]){
                    break;
                }
                else{
                    s[r] = (s[r] == '1'? '0': '1');
                }
            }
            else{
                if(s[l] != s[r]){
                    invStart = 1;
                    continue;
                }
            }

            ++l;
            --r;
        }

        // cout << s << "\n";

        if(isPalindrome(s, n)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    
    return 0;
}