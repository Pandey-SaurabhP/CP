#include <bits/stdc++.h>

using namespace std;

void floodFill(int i, int j, vector <string> &s, int &n, int &m){

    if((i >= n || i < 0) || (j >= m || j < 0)){
        return;
    }

    if(s[i][j] == '#'){
        return;
    }

    s[i][j] = '#';

    floodFill(i + 1, j, s, n, m);
    floodFill(i - 1, j, s, n, m);
    floodFill(i, j + 1, s, n , m);
    floodFill(i, j - 1, s, n, m);
}

int main(){

    int n, m;
    cin >> n >> m;

    vector <string> s(n);

    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    int cnt = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '.'){
                floodFill(i, j, s, n, m);
                ++cnt;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
