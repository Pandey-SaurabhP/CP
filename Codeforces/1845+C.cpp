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
        string s;
        cin >> s;

        vector <vector <int>> occ(256);

        for(int i = 0; i < s.size(); ++i){
            occ[s[i]].push_back(i);
        }

        int n;
        cin >> n;

        string s1, s2;
        cin >> s1 >> s2;

        int curAt = -1;
        bool fnd = 0;

        for(int i = 0; i < n; ++i){

            // cout << curAt << " ";

            int mx = -1;

            for(int j = s1[i]; j <= s2[i]; ++j){
                
                int id = upper_bound(occ[j].begin(), occ[j].end(), curAt) - occ[j].begin();

                if(id == occ[j].size()){
                    fnd = 1;
                    break;
                }

                if(occ[j][id] > mx){
                    mx = occ[j][id];
                }

            }

            if(fnd) break;

            curAt = mx;
        }

        if(!fnd){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    
    return 0;
}