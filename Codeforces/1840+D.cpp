#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


bool check(vector <int> &a, int n, int mid){

    int start = 0;
    int end = 0;
    int cut = 0;

    // cout << mid << " : ";
    while(end < n){
        
        if((a[end] - a[start] + 1) / 2 > mid){
            // Mark a cut here
            start = end;

            // cout << start << " ";
            ++cut;
        }

        if(cut > 2) return 0;

        ++end;
    }

    // cout << "\n";

    return 1;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        int ans = INT_MAX;

        int lo = 0;
        int hi = INT_MAX;

        while(lo < hi){

            int mid = (lo + hi) / 2;

            if(check(a, n, mid)){
                ans = mid;
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}