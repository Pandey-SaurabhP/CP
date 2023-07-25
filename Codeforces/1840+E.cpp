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

vector <int> a(mxn);

int main(){

    fast();

    int T;
    cin >> T;

    while(T--){
        string s[2];
        cin >> s[0] >> s[1];

        int t, q;
        cin >> t >> q;

        for(int i = 0; i <= min(q, t); ++i){
            a[i] = -1;
        }

        set <int> blocked;

        set <int> different;
        for(int i = 0; i < s[0].size(); ++i){
            if(s[0][i] != s[1][i]){
                different.insert(i);
            }
        }

        for(int i = 0; i < q; ++i){
            if(i - t >= 0 && a[i - t] != -1){
                // Unblock the i - th character
                blocked.erase(a[i - t]);
                if(s[0][a[i - t]] != s[1][a[i - t]]){
                    different.insert(a[i - t]);
                }

                a[i - t] = -1;
            }
            
            int type;
            cin >> type;

            if(type == 3){
                if(different.size() == 0){
                    cout << "YES\n";
                }
                else cout << "NO\n";
            }

            else if(type == 2){

                int from, id1;
                cin >> from >> id1;

                int to, id2;
                cin >> to >> id2;

                --to; --from;

                --id1;
                --id2;

                if(blocked.count(id1) || blocked.count(id2)){
                    continue;
                }

                if(different.count(id1)){
                    different.erase(id1);
                }

                if(different.count(id2)){
                    different.erase(id2);
                }

                swap(s[from][id1], s[to][id2]);

                if(s[0][id1] != s[1][id1]){
                    different.insert(id1);
                }
                if(s[0][id2] != s[1][id2]){
                    different.insert(id2);
                }
            }
            else{
                
                int id;
                cin >> id;

                --id;

                a[i] = id;

                blocked.insert(id);

                if(different.count(id)){
                    different.erase(id);
                }
            }

            // print(a, t + 1);
            // for(auto it : different){
            //     cout << it << " ";
            // }
            // cout << "\n";
            // cout << s[0] << "\n" << s[1] << "\n\n";

        }

        

    }
    
    return 0;
}