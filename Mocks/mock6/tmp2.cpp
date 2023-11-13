
#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        char c;
        cin >> c;

        int n = s.size();

        bool ok = 0;

        for(int i = 0; i < n; ++i){
            if(i == 1 || i == n - 2) continue;

            if(s[i] == c){
                ok = 1;
                break;
            }
        }

        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
