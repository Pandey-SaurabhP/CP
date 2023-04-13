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

int partition(int l, int h, vector <int> &a){

    int pivot = a[l];

    int i = l + 1;
    int j = h;

    
    vector <int> aux;

    for(int i = l + 1; i <= h; ++i){
        if(a[i] < pivot){
            aux.push_back(a[i]);
        }
    }

    aux.push_back(a[l]);
    int id = aux.size() - 1;

    for(int i = l + 1; i <= h; ++i){
        if(a[i] > pivot){
            aux.push_back(a[i]);
        }
    }

    for(int i = l; i <= h; ++i){
        a[i] = aux[i - l];
    }

    return id;
}

void quickSort(vector <int> &a, int l, int h){

    if(l >= h){
        return;
    }

    int j = partition(l, h, a);

    quickSort(a, l, j - 1);
    quickSort(a, j + 1, h);
}

int main(){

    // fast();

    vector <int> a(5);
    read(a, 5);

    quickSort(a, 0, 4);

    print(a, 5);
    
    return 0;
}