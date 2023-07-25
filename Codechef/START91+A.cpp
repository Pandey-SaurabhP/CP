    #include <iostream>

    using namespace std;

    int main(){

        int t;
        cin >> t;

        while(t--){
            int n;
            cin >> n;

            string s;
            cin >> s;

            bool server = 0; // 0 Alice 1 Bob

            int sc1 = 0;
            int sc2 = 0;

            for(int i = 0; i < n; ++i){
                if(s[i] == 'A'){
                    if(server == 0){
                        ++sc1;
                    }
                    else{
                        server = 0;
                    }
                }
                else{
                    if(server == 1){
                        ++sc2;
                    }
                    else{
                        server = 1;
                    }
                }
            }

            cout << sc1 << " " << sc2 << "\n";
        }

        return 0;
    }