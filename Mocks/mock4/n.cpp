#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(int128_t i = 0; i < n; ++i) cin >> a[i];
#define print128_t(a, n) for(int128_t i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int int128_t;
typedef long double ld;

const int128_t mod = 1e9 + 7;
const int128_t mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int128_t ncr(int128_t n, int128_t r){
    int128_t ans = 1;
    for(int128_t i = n; i > r; --i){
        ans *= i;
    }

    int128_t fct = 1;
    for(int128_t i = 1; i <= r; ++i){
        fct *= i;
    }

    ans /= fct;

    return ans;
}

int main(){

    cout << ncr(50ll, 25ll);
    int128_t n, k;
    cin >> n >> k;

    int128_t ans = 0;

    vector <int128_t> a(k + 1);

    for(int128_t i = 0; i <= k; ++i){
        a[i] = ncr(n, i);
        a[i] = (a[i] + 1) / 2;
    }

    set <pair <int128_t, int128_t>> st;


    for(int128_t i = 0; i <= k; ++i){
        if(st.count({i, k - i})){
            continue;
        }

        if(i > n || (k - i) > n){
            continue;
        }

        int128_t l = a[i];
        int128_t r = a[k - i];

        l = (l + 1) / 2;
        r = (r + 1) / 2;


        ans += (l + r);

        st.insert({i, k - i});
        st.insert({k - i, i});
    }

    cout << ans;

    return 0;
}






