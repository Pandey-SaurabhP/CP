
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        int sm = accumulate(a.begin(), a.end(), 0);

        if(sm % 2 != 0){
            cout << "NO\n";
        }
        else{
            int ocnt, ecnt;
            ocnt = ecnt = 0;

            for(auto it : a){
                if(it % 2 == 0){
                    ++ecnt;
                }
                else{
                    ++ocnt;
                }
            }

            if(ocnt % 2 == 1){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }

        }
    }
    return 0;
}

