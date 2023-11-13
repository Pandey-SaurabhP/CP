
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector <string> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        bool ok = 0;

        for(int j = 0; j < m; ++j){
            for(int k = j + 1; k < m; ++k){
                for(int l = k + 1; l < m; ++l){
                    for(int o = l + 1; o < m; ++o){

                        bool ok1, ok2, ok3, ok4;
                        ok1 = ok2 = ok3 = ok4 = 0;


                        for(int p = 0; p < n; ++p){
                            if(a[p][j] == 'v') ok1 = 1;
                            if(a[p][k] == 'i') ok2 = 1;
                            if(a[p][l] == 'k') ok3 = 1;
                            if(a[p][o] == 'a') ok4 = 1;
                        }

                        if(ok1 && ok2 && ok3 && ok4){
                            ok = 1;
                            break;
                        }
                    }

                    if(ok) break;
                }

                if(ok) break;
            }

            if(ok) break;
        }

        if(ok) cout << "YES\n";
        else{
            cout << "NO\n";
        }

    }
    return 0;
}


