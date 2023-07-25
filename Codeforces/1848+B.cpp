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
        int n, k;
        cin >> n >> k;

        vector <int> a(n);
        read(a, n);

        map <int, vector <int>> mp;

        for(int i = 0; i < n; ++i){
            if(mp.find(a[i]) == mp.end()){
                mp[a[i]].push_back(-1);
            }
            mp[a[i]].push_back(i);
        }

        for(auto it : mp){
            mp[it.first].push_back(n);
            

            // cout << it.first << " : ";
            // print(it.second, it.second.size());
        }

        


        int ans = n - 1;
        vector <int> tmp;

        for(auto it : mp){

            tmp.clear();
            // tmp.resize(it.second.size());

            for(int i = 1; i < it.second.size(); ++i){
                int gap = it.second[i] - it.second[i - 1] - 1;
                tmp.push_back(gap);
            }

            sort(tmp.begin(), tmp.end());

            // cout << it.first << " : ";
            // print(tmp, tmp.size());

            // cout << "Hello!\n";

            if(tmp.size() == 1){
                ans = min(ans, tmp[0] / 2);
            }
            else{
                ans = min(ans, max(tmp[tmp.size() - 2], tmp[tmp.size() - 1] / 2));
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}