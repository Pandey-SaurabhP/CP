// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n == 1){
            cout << -1 << "\n";
        }
        else{
            if(n % 2 == 0){
                for(int i = n; i >= 1; --i){
                    cout << i << " ";
                }
                cout << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }
    
    return 0;
}