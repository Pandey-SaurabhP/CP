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
        int n, m;
        cin >> n >> m;

        int x1, y1;
        int x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int ans1;
        int ans2;

        if((x1 == 1 && y1 == 1) || (x1 == n && y1 == m) || (x1 == 1 && y1 == m) || (x1 == n && y1 == 1)){
            ans1 = 2;
        }
        else if(x1 == 1 || y1 == 1 || x1 == n || y1 == m){
            ans1 = 3;
        }
        else{
            ans1 = 4;
        }

        if((x2 == 1 && y2 == 1) || (x2 == n && y2 == m) || (x2 == 1 && y2 == m) || (x2 == n && y2 == 1)){
            ans2 = 2;
        }
        else if(x2 == 1 || y2 == 1 || x2 == n || y2 == m){
            ans2 = 3;
        }
        else{
            ans2 = 4;
        }

        cout << min(ans1, ans2) << "\n";
    }
    
    return 0;
}