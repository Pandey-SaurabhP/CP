#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << '\t'; }

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

    // fast();

    int n;
    cin >> n;

    vector <int> a(n);
    read(a, n);

    vector <int> preOdd(n);
    vector <int> preEven(n);

    vector <int> postOdd(n);
    vector <int> postEven(n);

    preOdd[0] = a[0];
    preEven[0] = 0;

    if(n >= 2){
        preEven[1] = a[1];
        preOdd[1] = a[0];
    }

    for(int i = 2; i < n; ++i){
        if(i % 2 == 1){
            preEven[i] = preEven[i - 2] + a[i];
            preOdd[i] = preOdd[i - 1]; 
        }
        else{
            preEven[i] = preEven[i - 1];
            preOdd[i] = preOdd[i - 2] + a[i];
        }
    }    

    if(n % 2 == 0){
        postOdd[n - 1] = 0;
        postEven[n - 1] = a[n - 1];

        if(n >= 2){
            postOdd[n - 2] = a[n - 2];
            postEven[n - 2] = postEven[n - 1];
        }

        for(int i = n - 3; i >= 0; --i){
            if(i % 2 == 1){
                postEven[i] = postEven[i + 2] + a[i];
                postOdd[i] = postOdd[i + 1];
            }
            else{
                postEven[i] = postEven[i + 1];
                postOdd[i] = postOdd[i + 2] + a[i];
            }
        }
    }
    else{

        postOdd[n - 1] = a[n - 1];
        postEven[n - 1] = 0;

        if(n >= 2){
            postEven[n - 2] = a[n - 2];
            postOdd[n - 2] = postOdd[n - 1];
        }

        for(int i = n - 3; i >= 0; --i){
            if(i % 2 == 1){
                postEven[i] = postEven[i + 2] + a[i];
                postOdd[i] = postOdd[i + 1];
            }
            else{
                postEven[i] = postEven[i + 1];
                postOdd[i] = postOdd[i + 2] + a[i];
            }
        }
    }

    // print(preEven, n);
    // print(preOdd, n);

    // print(postEven, n);
    // print(postOdd, n);

    int ans = 0;

    for(int i = 0; i < n; ++i){

            int even = 0;
            int odd = 0;

            if(i - 1 >= 0){
                even += preEven[i - 1];
                odd += preOdd[i - 1];
            }
            if(i + 1 < n){
                even += postOdd[i + 1];
                odd += postEven[i + 1];
            }
        
        // cout << i << " " << even << " " << odd << "\n";

        if(even == odd){
            ++ans;
        }
    }

    cout << ans;

    
    return 0;
}