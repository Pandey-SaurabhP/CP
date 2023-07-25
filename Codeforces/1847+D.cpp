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

class segmentTree{
public:
 
    vector <ll> segTree;
 
    segmentTree(){
        segTree.resize(1000005);

        for(ll i = 0; i < segTree.size(); ++i){
            segTree[i] = 0;
        }
    }
 
    segmentTree(ll n){
        segTree.resize(4 * n);

        for(ll i = 0; i < 4 * n; ++i){
            segTree[i] = 0;
        }
    }
 
    void build(ll l, ll r, ll i, vector <ll> &a){
 
        if(l == r){
            segTree[i] = a[l];
            return;
        }
 
        ll mid = (l + r) / 2;
 
        build(l, mid, 2 * i + 1, a);
        build(mid + 1, r, 2 * i + 2, a);
 
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
 
    void pointUpdate(ll l, ll r, ll i, ll uidx, ll uval){
 
        if(l == r){
            segTree[i] = uval;
            return;
        } 
 
        ll mid = (l + r) / 2;
 
        if(mid >= uidx){
            pointUpdate(l, mid, 2 * i + 1, uidx, uval);
        }
        else{
            pointUpdate(mid + 1, r, 2 * i + 2, uidx, uval);
        }
 
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
 
    ll rangeQuery(ll l, ll r, ll i, ll ul, ll ur){
 
        if(l >= ul && r <= ur){
            return segTree[i];
        }
 
        if(r < ul || l > ur){
            return 0;
        }
 
        ll mid = (l + r) / 2;
 
        ll a1 = rangeQuery(l, mid, 2 * i + 1, ul, ur);
        ll a2 = rangeQuery(mid + 1, r, 2 * i + 2, ul, ur);
 
        return a1 + a2;
    }
};
 
int main(){

    fast();

    ll n, m, q;
    cin >> n >> m >> q;

    string s;
    cin >> s;

    vector <ll> l(m), r(m);
    vector <vector <ll>> foHelp(n + 1);
    vector <ll> fo(n + 1, INT_MAX);

    for(ll i = 0; i < m; ++i){

        cin >> l[i] >> r[i];
        --l[i], --r[i];

        if(l == r){
            fo[l[i]] = i;
        }
        else{
            foHelp[l[i]].push_back(i);
            foHelp[r[i]].push_back(i);
        }
    }

    set <ll> st;
    priority_queue <ll, vector <ll>, greater <ll>> pq;
    set <ll> blocked;

    for(ll i = 0; i < n; ++i){
        
        for(auto j : foHelp[i]){
            if(st.count(j)){
                blocked.insert(j);
            }
            else{
                pq.push(j);
                st.insert(j);
            }
        }

        if(!pq.empty()){
            fo[i] = min(pq.top(), fo[i]);
        }

        if(!pq.empty() && blocked.count(pq.top())){
            pq.pop();
        }
    }

    map <ll, vector <ll>> mp;

    for(ll i = 0; i < n; ++i){
        if(fo[i] != INT_MAX){
            mp[fo[i]].push_back(i);
        }
    }

    vector <ll> priority;
    st.clear();

    for(ll i = 0; i < m; ++i){

        for(auto it : mp[i]){
            if(!st.count(it)){
                priority.push_back(it);
                st.insert(it);
            }
        }
    }

    set <ll> unimp;

    for(ll i = 0; i < n; ++i){
        if(!st.count(i)){
            unimp.insert(i);
        }
    }

    ll oneCnt = 0;
    for(auto it : priority){
        if(s[it] == '1'){
            oneCnt++;
        }
    }

    ll oneCnt2 = 0;
    for(auto it : unimp){
        if(s[it] == '1'){
            ++oneCnt2;
        }
    }

    map <ll, ll> ui;

    for(ll i = 0; i < priority.size(); ++i){
        ui[priority[i]] = i;
    }

    segmentTree sg;

    for(ll i = 0; i < priority.size(); ++i){
        if(s[priority[i]] == '1'){
            sg.pointUpdate(0, priority.size() - 1, 0, i, 1);
        }
    }

    while(q--){
        ll x;
        cin >> x;

        --x;

        if(unimp.count(x)){
            if(s[x] == '0'){
                ++oneCnt2;
                s[x] = '1';
            }
            else{
                --oneCnt2;
                s[x] = '0';
            }

        }
        else{
            if(s[x] == '0'){
                ++oneCnt;
                sg.pointUpdate(0, priority.size() - 1, 0, ui[x], 1);

                s[x] = '1';
            }
            else{
                --oneCnt;
                sg.pointUpdate(0, priority.size() - 1, 0, ui[x], 0);

                s[x] = '0';
            }
        }

        ll cntOne = oneCnt + oneCnt2;

        if(cntOne >= priority.size()){
            if(oneCnt == priority.size()){
                cout << 0 << "\n";
            }
            else{
                cout << priority.size() - oneCnt << "\n";
            }
        }
        else{
            ll cnt = sg.rangeQuery(0, priority.size() - 1, 0, 0, cntOne - 1);
            ll zc = cntOne - cnt;

            ll availableOnes = oneCnt - cnt;
            availableOnes += oneCnt2;

            ll ans = max(min(zc, availableOnes), 0);

            cout << ans << "\n";
        }
    }
    
    
    return 0;
}