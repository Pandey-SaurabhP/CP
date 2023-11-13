#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(int i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mxn = 1e6 + 5;

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

        sort(a.begin(), a.end());

        map <int, int> st;

        for(auto it : a){
            st[it]++;
        }

        if(st.size() == 1){
            cout << "Yes\n";
        }
        else if(st.size() == 2){
            int b[2];
            b[0] = b[1] = 0;

            int x = 0;
            for(auto it : st){
                b[x++] = it.second;
            }

            if(abs(b[0] - b[1]) <= 1){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}



