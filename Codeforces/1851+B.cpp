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

        if(n == 1){
            cout << "YES\n";
            continue;
        }

        vector <int> oddId, evenId;
        vector <int> odd, even;

        for(int i = 0; i < n; ++i){
            if(a[i] % 2 == 0){
                evenId.push_back(i);
                even.push_back(a[i]);
            }
            else{
                oddId.push_back(i);
                odd.push_back(a[i]);
            }
        }

        evenId.push_back(INT_MAX);
        oddId.push_back(INT_MAX);

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        
        // print(evenId, evenId.size());
        // print(oddId, oddId.size());

        vector <int> fin;

        int x = 0;
        int y = 0;

        for(int i = 0; i < n; ++i){
            if(evenId[x] == i){
                fin.push_back(even[x]);
                ++x;
            }
            else{
                fin.push_back(odd[y]);
                ++y;
            }
        }

        bool ok = 1;
        for(int i = 1; i < n; ++i){
            if(fin[i] < fin[i - 1]){
                ok = 0;
                break;
            }
        }

        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}