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

void merge(vector <int> &a, int l, int r){

    vector <int> aux(r - l + 1);

    int mid = (l + r) / 2;

    
}

void mergeSort(vector <int> &a, int l, int r){

    if(l == r){
        return;
    }

    int mid = (l + r) / 2;

    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);

    merge(a, l, r);
}

int main(){

    // fast();

    int n;
    cin >> n;

    vector <int> a(n);
    read(a, n);


    
    return 0;
}