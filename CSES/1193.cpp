#include <bits/stdc++.h>

using namespace std;

void printQ(queue <pair <int, int>> q){

    while(!q.empty()){
        cout << q.front().first << " " << q.front().second << "   ";
        q.pop();
    }
    cout << "\n";
}

int main(){

    int n, m;
    cin >> n >> m;

    vector <string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    pair <int, int> st;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i][j] == 'A'){
                st.first = i;
                st.second = j;
            }
        }
    }

    queue <pair <int, int>> q;

    vector <vector <bool>> vis(n + 1, vector <bool> (m + 1, 0));
    map <pair <int, int>, pair <int, int>> mp;

    q.push(st);
    q.push({-1, -1}); // Increase distance by 1

    int d = 0;
    bool fnd = 0;

    pair <int, int> ed;

    while(!q.empty()){
//        printQ(q);

        pair <int, int> tp = q.front();
        q.pop();

        if(tp.first == -1){
            ++d;
            if(q.back().first != -1){
                q.push({-1, -1});
            }

            continue;
        }

        if(s[tp.first][tp.second] != '#'){
            int x = tp.first;
            int y = tp.second;

            if(s[x][y] == 'B'){
                ed = tp;
                fnd = 1;
                break;
            }

            if(x + 1 < n && s[x + 1][y] != '#' && !vis[x + 1][y]){
                q.push({x + 1, y});
                mp[{x + 1, y}] = tp;
                vis[x + 1][y] = 1;
            }
            if(x - 1 >= 0 && s[x - 1][y] != '#' && !vis[x - 1][y]){
                q.push({x - 1, y});
                mp[{x - 1, y}] = tp;
                vis[x - 1][y] = 1;
            }
            if(y + 1 < m && s[x][y + 1] != '#' && !vis[x][y + 1]){
                q.push({x, y + 1});
                mp[{x, y + 1}] = tp;
                vis[x][y + 1] = 1;
            }
            if(y - 1 >= 0 && s[x][y - 1] != '#' && !vis[x][y - 1]){
                q.push({x, y - 1});
                mp[{x, y - 1}] = tp;
                vis[x][y - 1] = 1;
            }
        }
    }

    if(!fnd){
        cout << "NO\n";
        return 0;
    }

    string ans;

    while(1){
        int x = mp[ed].first;
        int y = mp[ed].second;

        int cx = ed.first;
        int cy = ed.second;

        if(x - 1 == cx){
            ans += 'U';
        }
        else if(x + 1 == cx){
            ans += 'D';
        }
        else if(y - 1 == cy){
            ans += 'L';
        }
        else if(y + 1 == cy){
            ans += 'R';
        }

        ed = mp[ed];
        if(s[ed.first][ed.second] == 'A'){
            break;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";
    cout << d << "\n";
    cout << ans << "\n";


    return 0;
}
