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

    string match;

    for(int i = 1; i <= 1000; ++i){
        if(i % 3 == 0){
            match += 'F';
        }
        if(i % 5 == 0){
            match += 'B';
        }
    }

    while(t--){
        
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool ok = 0;

        for(int i = 0; i < match.size() - n; ++i){

            string s2 = match.substr(i, n);

            if(s2 == s){
                ok = 1;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}