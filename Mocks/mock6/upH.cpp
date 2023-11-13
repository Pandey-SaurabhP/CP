#include<bits/stdc++.h>

#include<stack>

using namespace std;

const int vv = 8;
//int graph[vv][vv];

vector <vector <int>> graph(vv);
vector <int> nwId(vv);

int min(int a, int b) {
  return (a < b) ? a : b;
}

void findComponent(int u, vector <int> &disc, vector <int> &lowLink, stack < int > & stk, vector <bool> &stkItem) {
  static int time = 0;
  disc[u] = lowLink[u] = ++time;
  stk.push(u);
  stkItem[u] = true;

  for(auto v : graph[u]) {
      if (disc[v] == -1) {
        findComponent(v, disc, lowLink, stk, stkItem);
        lowLink[u] = min(lowLink[u], lowLink[v]);
      } else if (stkItem[v])
        lowLink[u] = min(lowLink[u], disc[v]);
  }

  int poppedItem = 0;
  if (lowLink[u] == disc[u]) {
    while (stk.top() != u) {
      poppedItem = stk.top();
      cout << poppedItem << " ";
      stkItem[poppedItem] = false;
      stk.pop();
    }
    poppedItem = stk.top();
    cout << poppedItem << endl;
    stkItem[poppedItem] = false;
    stk.pop();
  }
}

void strongConComponent() {

  vector <int> disc(vv), lowLink(vv);
  vector <bool> stkItem(vv);

  stack < int > stk;

  for (int i = 0; i < vv; i++) {
    disc[i] = -1;
    lowLink[i] = -1;
    stkItem[i] = false;
  }

  for (int i = 0; i < vv; i++)
    if (disc[i] == -1)
      findComponent(i, disc, lowLink, stk, stkItem);
}

int main() {

//    graph[1][2] = 1;
//    graph[2][3] = 1;
//    graph[3][1] = 1;
//    graph[6][1] = 1;
//    graph[6][4] = 1;
//    graph[4][5] = 1;
//    graph[7][6] = 1;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;

        --x; --y;

        graph[x].push_back(y);
    }

//    for(int i = 0; i <= n; ++i){
//        cout << i << " : ";
//
//        for(auto it : graph[i]){
//            cout << it << " ";
//        }
//        cout << "\n";
//    }

  strongConComponent();

}
