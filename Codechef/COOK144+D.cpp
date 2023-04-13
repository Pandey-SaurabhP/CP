// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int getAns(priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq){

    map <int, int> cnt;

    int ans = 0;
    int time = 0;

    while(!pq.empty()){

        pair <int, int> tp = pq.top();
        pq.pop();

        time = max(time, tp.first);

        // cout << time << " ";

        ans += time;
    }

    return ans;
}

void pr(priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq){
    cout << "PQ : ";
    while(!pq.empty()){
        cout << pq.top().first << " ";
        pq.pop();
    }
    cout << "\n";
}

int main(){

    fast();

    int n, m;
    cin >> n >> m;

    map <int, int> mp;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

    for(int i = 0; i < m; ++i){
        int px, tx;
        cin >> px >> tx;

        mp[px] += tx;
        pq.push({mp[px], px});

        // pr(pq);

        cout << getAns(pq) << "\n";

    }




    
    return 0;
}