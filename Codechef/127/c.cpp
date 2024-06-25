#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a>> b;

    queue <int> q;

    int bi = -1;

    for(int i = 0; i < n; ++i){
        if(a[i] == 'b' || b[i] == 'b'){
            if(a[i] != b[i]){
                cout << "No\n";
                return;
            }
            else{
                bi = i;
            }
        }

        if(a[i] == 'a' && b[i] == 'c'){
            q.push(i);
        }
        else if(a[i] == 'c' && b[i] == 'a'){
            if(bi == -1){
                cout << "No\n";
                return;
            }
            else{
                if(q.empty()){
                    cout << "No\n";
                    return;
                }
                
                if(q.front() < bi){
                    q.pop();
                }
                else{
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    if(q.empty()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}