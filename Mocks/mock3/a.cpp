#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct s{
    int g, s, b;
    string nm;
};

bool cmp(s a, s b){
    if(a.g > b.g){
        return 1;
    }
    else if(a.g == b.g && a.s > b.s){
        return 1;
    }
    else if(a.g == b.g && a.s == b.s && a.b > b.b){
        return 1;
    }

    return 0;
}

int main(){

    fast();

    int n;
    cin >> n;


    s a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i].g >> a[i].s >> a[i].b;
        getline(cin, a[i].nm);
    }

    sort(a, a + n, cmp);


    string ans = a[0].nm;
    string nw;

    int i = 0;
    while(ans[i] == ' '){
        ++i;
    }

    while(i != ans.size()){
        nw += ans[i];++i;
    }

    cout << nw;


    return 0;
}

