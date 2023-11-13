
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long  ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

int cmp(pair <int, int> p1, pair <int, int> p2, pair<int, int> p3) {
    int x1 = p1.first, y1 = p1.second;
    int x2 = p2.first, y2 = p2.second;
    int x3 = p3.first, y3 = p3.second;

    return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
}

void outerTrees2(vector<pair<int, int>>& trees) {
    unordered_map <pair <int, int>, int, hash_pair> mp;

    for(int i = 0; i < trees.size(); ++i){
        mp[trees[i]] = i + 1;
    }

    vector<pair<int, int>> lower, upper;

    sort(trees.begin(), trees.end());

    for(pair<int,int>& p:trees) {
        while(lower.size()>=2 and cmp(lower[lower.size()-2], lower[lower.size()-1], p)>0) lower.pop_back();
        while(upper.size()>=2 and cmp(upper[upper.size()-2], upper[upper.size()-1], p)<0) upper.pop_back();
        lower.push_back(p);
        upper.push_back(p);
    }

    set<pair<int, int>> s;
    vector<pair<int, int>> ans;

    for(auto v:lower) s.insert(v);
    for(auto v:upper) s.insert(v);

    set <int> st2;
    for(auto it:s)
//            ans.push_back(it);
        st2.insert(mp[it]);

    for(auto it : st2){
        cout << it << " ";
    }
}



int main(){
    fast();

    int n;
    cin >> n;

    vector <pair <int, int>> p(n);

    for(int i = 0; i < n; ++i){
        double x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    if(n <= 4){
        for(int i = 1; i <= n; ++i){
            cout << i << " ";
        }

    }
    else outerTrees2(p);



    return 0;
}




