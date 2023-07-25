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

vector <int> getMax(vector <int> &a, vector <int> &b, int &n){

    for(int i = 0; i < n; ++i){
        if(a[i] > b[i]){
            return a;
        }
        else if(b[i] > a[i]){
            return b;
        }
    }

    return a;
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

        int mxId = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] > a[mxId]){
                mxId = i;
            }
        }

        if(n == 1){
            cout << 1 << "\n";
            continue;
        }

        // We got mxId

        if(mxId == 0){
            int spId = -1;

            for(int i = 0; i < n; ++i){
                if(a[i] == n - 1){
                    spId = i;
                    break;
                }
            }

            vector <int> b;

            if(spId == n - 1){
                b.push_back(a[spId]);

                for(int i = 0; i < spId; ++i){
                    b.push_back(a[i]);
                }

                print(b, n);
                continue;
            }
            
            vector <int> ans(n, 0);

            for(int i = spId - 1; i >= 0; --i){
                // Start at i to spId - 1

                vector <int> localAns;

                for(int j = spId; j < n; ++j){
                    localAns.push_back(a[j]);
                }

                for(int j = spId - 1; j >= i; --j){
                    localAns.push_back(a[j]);
                }

                for(int j = 0; j < i; ++j){
                    localAns.push_back(a[j]);
                }

                ans = getMax(ans, localAns, n);
            }

            print(ans, n);
        }
        else{
            // part 1 will be mxId till n

            int j = mxId - 1;

            vector <int> ans(n, 0);

            vector <int> b;
            b.push_back(a[n - 1]);
            for(int i = 0; i < n - 1; ++i){
                b.push_back(a[i]);
            }

            ans = getMax(ans, b, n);

            for(int i = j; i >= 0; --i){
                b.clear();

                for(int k = j + 1; k < n; ++k){
                    b.push_back(a[k]);
                }

                for(int k = j; k >= i; --k){
                    b.push_back(a[k]);
                }

                for(int k = 0; k < i; ++k){
                    b.push_back(a[k]);
                }

                // print(b, n);

                ans = getMax(ans, b, n);
            }

           print(ans, n);


        }
    }
    
    return 0;
}