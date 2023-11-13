#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector <int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        vector <int> cnt(101, 0);
        for(auto it : a){
            cnt[it]++;
        }

        set <int> st;

        for(int i = 0; i < 101; ++i){
            if(cnt[i] >= 2){
                st.insert(i);
            }

            if(st.size() == 2) break;
        }

        if(st.size() >= 2){

            vector <int> b(n, 1);

            for(int i = 0; i < n; ++i){
                if(st.count(a[i])){
                    for(int j = i + 1; j < n; ++j){
                        if(a[i] == a[j]){
                            b[i] = 1;
                            b[j] = 2;
                            st.erase(a[i]);
                            break;
                        }
                    }

                    break;
                }
            }

            for(int i = 0; i < n; ++i){
                if(st.count(a[i])){
                    for(int j = i + 1; j < n; ++j){
                        if(a[i] == a[j]){
                            b[i] = 1;
                            b[j] = 3;
                            st.erase(a[i]);
                            break;
                        }
                    }

                    break;
                }
            }

            for(auto it : b){
                cout << it << " ";
            }
            cout << "\n";
        }
        else{
            cout << -1 << "\n";
        }



    }
    return 0;
}
