#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

        int x;
        cin >> x;

        vector <int> ans;
        ans.push_back(1);

        while(ans[ans.size() - 1] <= x){
            ans.push_back(ans[ans.size() - 1] * 2);
        }

        ans.pop_back();

        while(ans[ans.size() - 1] != x){
            int rq = x - ans[ans.size() - 1];

            int st = 1;
            while(st <= rq){
                st *= 2;
            }
            st /= 2;

            ans.push_back(ans[ans.size() - 1] + st);
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto it : ans){
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}
