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
        a.push_back(INT_MAX);

        vector <pair <int, int>> cnt;
        for(int i = 0; i < n; ++i){
            
            int j = i;
            while(j < n && a[j] == a[i]){
                ++j;
            }

            cnt.push_back({a[i], j - i});
        }

        vector <int> pre(n, 0);

        int ans = 0;
        int mn = a[0].second;

        int st = 0;

        for(int i = 1; i < cnt.size(); ++i){
            
            if(a[i].first - a[i - 1].first == 1){

                if(a[i].second <= mn){
                    ans += mn - a[i].second;
                    mn = a[i].second;

                    pre[st] -= (mn - a[i].second);
                    pre[i] += (mn - a[i].second);

                    st = i;
                }
            }
            else{
                
            }
        }

    }
    
    return 0;
}