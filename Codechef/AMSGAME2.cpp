// pSaurabh
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << "\n"; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

vector <int> ax;

int getGCD(int a, int b){
    if(a == 0) return b;
    return(b % a, a);
}

int solve(int x, int i, vector <int> &a, int &n){
    
    if(i == n){
        cout << "\n";
        print(ax, ax.size());
        cout << "x : " << x << "\n";

        if(x == 1){
            return 1;
        }
        else return 0;
    }    

    if(x == 0){

        ax.push_back(a[i]);
        int ans = solve(a[i], i + 1, a, n);
        ax.pop_back();

        ans += solve(x, i + 1, a, n);

        return ans;
    }
    else{
        int aa = max(x, a[i]);
        int bb = min(x, a[i]);

        ax.push_back(a[i]);
        int ans = solve(max(aa % bb, bb), i + 1, a, n);
        ax.pop_back();

        ans += solve(x, i + 1, a, n);

        return ans;
    }

}

int main(){
    // fast();
	int t;
    cin >> t;

    while(t--){

        int n; 
        cin >> n;

        vector <int> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        cout << solve(0, 0, a, n) << "\n";
    }

	return 0;	
}