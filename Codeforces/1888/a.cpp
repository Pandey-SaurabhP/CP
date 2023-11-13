#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){
            fast();

    ll t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector <int> cnt(256, 0);

        for(auto it : s){
            cnt[it]++;
        }

        if(n % 2 == 1){
            // All letters should come twice except one

            set <char> st;

            for(int i = 'a'; i <= 'z'; ++i){
                if(cnt[i] % 2 == 1){
                    st.insert(i);
                    --cnt[i];

                }
            }

            // st size must be odd
            if(k % 2 == 0){
                if(st.size() == 1){
                    cout << "YES\n";
                }
                else if(k >= st.size()){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
            else{
                if(st.size() <= k){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
        else{
            // All letters should come twice;
            set <char> st;

            for(int i = 'a'; i <= 'z'; ++i){
                if(cnt[i] % 2 == 1){
                    st.insert(i);
                    --cnt[i];

                }
            }

            if(k % 2 == 0){
                if(st.size() <= k){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
            else{
                if(st.size() <= k){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }

        }
    }

    return 0;
}





