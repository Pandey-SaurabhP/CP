#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;
int n = 1000001;

int main(){
    long long *one = new long long[n];
    long long *two = new long long[n];

    one[0] = two[0] = 0;
    one[1] = two[1] = 1;

    for(int i = 2; i < n; ++i){
        one[i] = ((one[i - 1] * 2ll) % mod) + two[i - 1];
        one[i] %= mod;

        two[i] = ((two[i - 1] * 4ll) % mod) + one[i - 1];
        two[i] %= mod;
    }

    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;

        cout << (one[x] + two[x]) % mod << "\n";
    }

    return 0;
}
