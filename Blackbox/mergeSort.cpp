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

void merge(int l, int r, vector <int> &a){

    int mid = (l + r) / 2;

    vector <int> aux;

    int i = l;
    int j = mid + 1;

    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            aux.push_back(a[i]);
            ++i;
        }
        else if(a[i] > a[j]){
            aux.push_back(a[j]);
            ++j;
        }
        else{
            aux.push_back(a[i]);
            aux.push_back(a[j]);
            ++i; ++j;
        }
    }

    while(i <= mid){
        aux.push_back(a[i]);
        ++i;
    }

    while(j <= r){
        aux.push_back(a[j]);
        ++j;
    }

    for(int i = l; i <= r; ++i){
        a[i] = aux[i - l];
    }
}

void mergeSort(vector <int> &a, int l, int r){
    
    if(l == r){
        return;
    }

    int mid = (l + r) / 2;

    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);

    merge(l, r, a);

}

int main(){

    // fast();
    int a[5] = new int[size];


    vector <int> a = {5, 9, 1, 2, 3, 4, 6, 10};

    mergeSort(a, 0, 7);

    print(a, 10);
    
    
    return 0;
}