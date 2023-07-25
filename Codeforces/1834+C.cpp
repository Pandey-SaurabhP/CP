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

int solve1(string a, string b){
    int n = a.size();

    int change = 0;
    int changeRev = 0;

    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]) ++ change;
        if(a[i] != b[n - i - 1]) ++changeRev;
    }

    if(change == 0){
        return 0;
    }
    else if(change == 1){
        return 1;
    }
    else if(changeRev == 0){
        return 2;
    }
    else{
        int a1;
        int a2;

        if(changeRev % 2 == 0){
            a1 = change * 2;
            
            a2 = (changeRev * 2) - 1;
        }
        else{
            a1 = (change * 2) - 1;
            a2 = (changeRev * 2);
        }

        return min(a1, a2);
    }
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        cout << min(solve1(a, b), solve1(b, a)) << "\n";
        

    }
    
    return 0;
}