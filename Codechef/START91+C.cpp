    #include <bits/stdc++.h>

    using namespace std;

    typedef long long int ll;

    int main(){

        ll t;
        cin >> t;

        while(t--){
            ll n, k;
            cin >> n >> k;

            ll oddCnt = (n + 1) / 2;

            if(2 * k > n){
                cout << "NO\n";
                continue;
            }

            oddCnt -= k;
            if(oddCnt < 0){
                cout << "NO\n";
                continue;
            }
            // Ek ek baat diye

            if(oddCnt % 2 == 0){
                cout << "YES\n";
                continue;
                // Ek hi me sb
            }
            if(oddCnt < k){ // odd hai
                cout << "NO\n";
                continue;
            }

            // Current scenario me YES ho rha
            
            ll x = (oddCnt / k) * k;

            if((x / k) % 2 == 0){
                
                oddCnt -= x;

                if(oddCnt % 2 == 0){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
            else{
                cout << "NO\n";
            }

        }

        return 0;
    }