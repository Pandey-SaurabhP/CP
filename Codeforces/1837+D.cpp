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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int on, c;
        on = c = 0;

        for(int i = 0; i < n; ++i){
            if(s[i] == '(') ++on;
            else ++c;
        }

        if(on != c){
            cout << -1 << "\n";
            continue;
        }

        stack <char> st;
        bool reverse = 0;

        vector <int> color;
        int code = 1;

        for(int i = 0; i < n; ++i){

            if(!reverse){
                if(s[i] == '('){
                    st.push('(');
                    color.push_back(code);
                }
                else{
                    if(!st.empty()){
                        color.push_back(code);
                        st.pop();
                    }
                    else{
                        reverse = 1;
                        st.push(')');

                        // cout << "Rervsersing\n";

                        ++code;
                        color.push_back(code);
                    }
                }
            }
            else{

                if(s[i] == ')'){
                    st.push(')');
                    color.push_back(code);
                }
                else{
                    if(!st.empty()){
                        color.push_back(code);
                        st.pop();
                    }
                    else{
                        reverse ^= 1;
                        st.push('(');

                        ++code;
                        color.push_back(code);
                    }
                }
            }

            
        }

        for(int i = 0; i < n; ++i){
            color[i] %= 2;
        }

        bool z, o;
        z = o = 0;

        for(int i = 0; i < n; ++i){
            if(color[i] == 0){
                z = 1;
            }
            else o = 1;
        }

        if(z & o){
            for(int i = 0; i < n; ++i){
                ++color[i];
            }

            cout << 2 << "\n";
            print(color, color.size());
        }
        else{
            cout << 1 << "\n";

            for(int i = 0; i < n; ++i){
                cout << "1 ";
            }
            cout << "\n";
        }

        
    }
    
    return 0;
}