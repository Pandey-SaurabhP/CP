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

int solve(int f, vector <int> &a, int &n){

    int l = 0;
    int h = INT_MAX;

    int gbCnt = INT_MAX;

    while(l < h){
        int mid = (l + h) / 2;
        
        int start = a[0];
        int cnt = 1;
        int ub = upper_bound(a.begin(), a.end(), start + mid) - a.begin();

        while(ub != n){
            ++cnt;
            start = a[ub];
            ub = upper_bound(a.begin(), a.end(), start + mid) - a.begin();
        }

// Improve by taking maximum of all starts and currents, and then fix answer for a certain range of f
        

        if(cnt <= f){
            gbCnt = min(gbCnt, mid);
            h = mid;
        }
        else{
            l = mid + 1;
        }
    }

    return gbCnt;
}

int main(){

    fast();

    int n, A;
    cin >> n >> A;

    vector <int> a(n);
    read(a, n);
    sort(a.begin(), a.end());

    int q;
    cin >> q;


    while(q--){
        int f;
        cin >> f;

        f = min(f, n);

        cout << solve(f, a, n) << "\n";
    }
    
    return 0;
}