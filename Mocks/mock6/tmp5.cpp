
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

        int ans = 0;

        for(int i = 0; i < n; ++i){

            int cnt = 0;

            if(a[i] == 0){
                int j = i;
                while(j < n && a[j] == 0){
                    ++j;
                    ++cnt;
                }


                ans = max(ans, cnt);
            }
        }

        cout << ans << "\n";

    }
    return 0;
}



