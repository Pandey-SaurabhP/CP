
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

    ll t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        vector <int> a(n);
        read(a, n);


        multiset <pair <int, int>> diff;

        for(int i = 0; i < n - 1; ++i){
            diff.insert({abs(a[i + 1] - a[i]), i});
        }


        while(q--){
            int i, v;
            cin >> i >> v;
            --i;


            if(i == 0){

                pair <int, int> d1 = {abs(a[i] - a[i + 1]), i};
                diff.erase(d1);

                a[i] = v;
                diff.insert({abs(a[i] - a[i + 1]), i});
            }
            else if(i == n - 1){
                pair <int, int> d1 = {abs(a[i - 1] - a[i]), i - 1};
                diff.erase(d1);

                a[i] = v;
                diff.insert({abs(a[i - 1] - a[i]), i - 1});
            }
            else{
                pair <int, int> d1 = {abs(a[i] - a[i + 1]), i};
                pair <int, int> d2 = {abs(a[i - 1] - a[i]), i - 1};

                diff.erase(d1);
                diff.erase(d2);

                a[i] = v;
                diff.insert({abs(a[i] - a[i + 1]), i});
                diff.insert({abs(a[i - 1] - a[i]), i - 1});
            }


            pair <int, int> tmp;
            for(auto it : diff){
                tmp = it;
                break;
            }

            cout << tmp.first << "\n";
        }

    }

    return 0;
}



