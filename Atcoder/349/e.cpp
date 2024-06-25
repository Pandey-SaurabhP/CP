#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

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

const ll inf = 1e18 + 5;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

int done[3][3];
ll a[3][3];

bool check(){

    for(int i = 0; i < 3; ++i){
        if(done[i][0] != -1 && done[i][0] == done[i][1] && done[i][1] == done[i][2]){
            return 1;
        }

        if(done[0][i] != -1 && done[0][i] == done[1][i] && done[1][i] == done[2][i]){
            return 1;
        }
    }

    if(done[0][0] != -1 && done[0][0] == done[1][1] && done[1][1] == done[2][2]){
        return 1;
    }


    if(done[0][2] != -1 && done[0][2] == done[1][1] && done[1][1] == done[2][0]){
        return 1;
    }

    return 0;
}

// for player a 1 for b
bool slv(bool turn, ll cnt, ll sca, ll scb){

    if(check()){
        return turn ^ 1;
    }
    
    if(cnt == 9ll){
        return (sca < scb);
    }

    for(ll i = 0ll; i < 3ll; ++i){
        for(ll j = 0ll; j < 3ll; ++j){
            if(!done[i][j]){

                sca += (!turn) * a[i][j];
                scb += turn * a[i][j];
                done[i][j] = turn;

                bool x = slv(turn ^ 1, 1ll + cnt, sca, scb);

                if(!turn && !x){
                    return 0;
                }
                if(turn && x){
                    return 1;
                }

                sca -= (!turn) * a[i][j];
                scb -= turn * a[i][j];
                done[i][j] = -1;
            }
        }
    }
}

void solve() {
    ll sm = 0ll;

    for(ll i = 0ll; i < 3ll; ++i){
        for(ll j = 0ll; j < 3ll; ++j){
            cin >> a[i][j];
            sm += a[i][j];
            done[i][j] = -1;
        }
    }

    ll tx = slv(0ll, 0ll, 0ll, 0ll);

    if(!tx){
        cout << "Takahashi";
    }
    else{
        cout << "Aoki";
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}