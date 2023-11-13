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

int main(){

     fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        vector <int> ans;
        ans.push_back(a[0]);

        for(int i = 1; i < n; ++i){
            if(ans[ans.size() - 1] <= a[i]){
                ans.push_back(a[i]);
            }
            else{
                ans.push_back(1);
                ans.push_back(a[i]);
            }
        }

        cout << ans.size() << "\n";
        print(ans, ans.size());
    }

    return 0;
}
