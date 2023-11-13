#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(int i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string insertBefore(string &s, int j){

    string nw;

    for(int i = 0; i < j; ++i){
        nw += s[i];
    }

    nw += "01";

    for(int i = j; i < s.size(); ++i){
        nw += s[i];
    }

    return nw;
}

string insertAfter(string &s, int j){

    string nw;

    for(int i = 0; i <= j; ++i){
        nw += s[i];
    }

    nw += "01";

    for(int i = j + 1; i < s.size(); ++i){
        nw += s[i];
    }

    return nw;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string a;
        cin >> a;

        if(n % 2 == 1){
            cout << "-1\n";
        }
        else{
            bool ok = 1;
            int cnt = 0;

            int l = 0;
            int r = n - 1;

            vector <int> pos;

            while(l < r){
//                cout << l << " " << r << " : " << a << "\n";
                if(a[l] == a[r]){
                    // Insert 01
                    if(a[l] == '1'){
                        // Insert 01 before a[l]
                        a = insertBefore(a, l);
                        pos.push_back(l);

                        ++l;
                        ++r;

                        ++cnt;
                    }
                    else{
                        a = insertAfter(a, r);
                        pos.push_back(r + 1);

                        ++l;
                        ++r;

                        ++cnt;
                    }

                    if(cnt > 300){
                        ok = 0;
                        break;
                    }
                }
                else{
                    ++l;
                    --r;
                }


            }

            if(ok){
                cout << pos.size() << "\n";
                print(pos, pos.size());
                cout << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}




