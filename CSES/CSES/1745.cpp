#include <bits/stdc++.h>

using namespace std;

vector <bool> valid(100005, 0);
int dp[103][100005];

void solve(int i, int sm, vector <int> &a){
    if(i == a.size()){
        valid[sm] = 1;
        return;
    }

    if(dp[i][sm] != -1) return;

    solve(i + 1, sm + a[i], a);
    solve(i + 1, sm, a);

    dp[i][sm] = 1;
}

int main(){
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;

    vector <int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    solve(0, 0, a);

    set <int> st;

    for(int i = 1; i < 100005; ++i){
        if(valid[i]){
            st.insert(i);
        }
    }

    cout << st.size() << "\n";
    for(auto it : st){
        cout << it << " ";
    }

    return 0;
}
