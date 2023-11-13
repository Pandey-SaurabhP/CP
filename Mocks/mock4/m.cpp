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

    int n;
    cin >> n;

    vector <int> a(n);
    read(a, n);

    a.push_back(0);
    sort(a.begin(), a.end());

    ++n;

    int mxDiff = 0;

    for(int i = 1; i < n; ++i){
        mxDiff = max(mxDiff, a[i] - a[i - 1]);
    }


    int l = 0;
    int r = 1;

    bool ok = 1;

    while(r < n){
        while(r < n && (a[r] - a[l]) <= mxDiff){
            ++r;
        }

//        cout << l << " " << r << "\n";

        if(r - l > 2){
            ok = 0;
            break;
        }
        else{
            ++l;
        }
    }

    if(ok){
        cout << mxDiff;
    }
    else{
        cout << 0;
    }

    return 0;
}






