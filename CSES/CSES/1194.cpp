#include <bits/stdc++.h>

using namespace std;

void bfs1(vector <string> &a, int n, int m){
    queue <pair <int, int>> q;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(i != 0 && j != 0 && i != n - 1 && j != n - 1){
                continue;
            }
            if(a[i][j] == 'M'){
                q.push({i, j});
            }
        }
    }

    vector <vector <int>> dist(n, vector <int> dist(m, INT_MAX));

    while(!q.empty()){
        pair <int, int> fr = q.front();

        int x = fr.first;
    }
}

int main(){

    return 0;
}
