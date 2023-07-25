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

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector <int> a(n);
        read(a, n);

        if(a[0] != 1){
            cout << 1 << "\n";
            continue;
        }

        set <int> st;

        for(auto it : a){
            st.insert(it);
        }

        int done = 0;
        int ans = -1;
        int cnt = 1;

        for(int i = 2; i < 100; ++i){

            int x = i;

            if(x > a[n - 1]){
                x %= n;
            }

            int tmp = x;

            if(st.count(x)){
                ++cnt;
            }

            while(!st.count(x)){
                
                x -= cnt;
                // cout << x << " ";

                if(x == 1){
                    ++done;
                    cout << "Part : " << tmp << " ";

                    if(done == k){
                        ans = tmp;
                    }

                    break;
                }
                

                if(!st.count(x) || x <= 0){
                    ++cnt;
                }
            }

            if(ans != -1){
                break;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}