
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
        int l, r;
        cin >> l >> r;

        if(r - l >= 1){
            // There should exist an even number in between

            if(r % 2 == 0){
                int a = (r / 2);
                int b = (r / 2);

                if(a != 1){
                    cout << a << " " << b << "\n";
                }
                else{
                    cout << -1 << "\n";
                }
            }
            else{
                int a = (r - 1) / 2;
                int b = (r - 1) / 2;

                if(a != 1){
                    cout << a << " " << b << "\n";
                }
                else{
                    cout << -1 << "\n";
                }
            }
        }
        else{
            if(r % 2 == 0){
                int a = r / 2;
                int b = r / 2;

                if(a == 1){
                    cout << -1 << "\n";
                }
                else{
                    cout << a << " " << b << "\n";
                }
            }
            else{
                int a1, a2;
                a1 = a2 = -1;

                for(int i = 2; i * i <= l; ++i){
                    if(l % i == 0){
                        int one = i;
                        int two = l - i;

                        if(__gcd(one, two) != 1){
                            a1 = one;
                            a2 = two;
                            break;
                        }
                    }
                }

                if(a1 != -1){
                    cout << a1 << " " << a2 << "\n";
                }
                else{
                    cout << -1 << "\n";
                }
            }
        }
    }

    return 0;
}




