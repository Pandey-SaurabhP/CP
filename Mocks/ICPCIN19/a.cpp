/*----------------------- Directives -----------------------*/
#include <bits/stdc++.h>

/*----------------------- Namespaces -----------------------*/
using namespace std;

/*------------------------- Macros -------------------------*/
#define endl        '\n'
#define pb          push_back
#define pf          push_front
#define mem(a,i)    memset(a,i,sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(),v.end()
#define rall(v)     v.rbegin(),v.rend()
#define w(t)        int t=1,tc=1;cin>>t;while(t--)

/*-------------------- Type Definitions --------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*-------------------------- Maths -------------------------*/
const int MOD = 1000*1000*1000 + 7; // for big mod
template <typename T> inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;} // better than __gcd
template <typename T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
template <typename T> inline bool isPrime(T n){for (T i=2;i*i<=n;i++) if(n%i==0) return false; return n>1;}

/*-------------------------- SOLVE -------------------------*/
vector<ll> v;
vector<vector<pair<int, int>>> adj;

bool primes[50000001];
vector <long long> primeList;

void sieve() {
	long long n = 50000001;

    memset(primes, 1, sizeof(primes)); 
  	
  	for(long long j = 4; j <= n; j += 2){
  		primes[j] = 0;
  	}


    for (long long p = 3; p * p <= n; p += 2) {
        if (primes[p] == 1) { 

            for (long long i = p * p; i <= n; i += p) 
                primes[i] = 0; 
        } 
    } 

    for(int i = 2; i < n; ++i){
    	if(primes[i]){
    		primeList.push_back(i);
    	}
    }
} 

set <long long> ans;
void primeFact(ll x){

	for(int i = 0; (i < primeList.size()) && primeList[i] * primeList[i] <= x; ++i){
		if(x % primeList[i] == 0){
			ans.insert(primeList[i]);

			while(x % primeList[i] == 0){
				x /= primeList[i];
			}
		}
	}

	if(x > 1){
		ans.insert(x);
	}
}

void solve() {
	sieve();

    int m, n, k;
    cin >> m >> n >> k;

    v.resize(n);
    for (auto &i : v) cin >> i;

    adj.resize(m);
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
    }

    for (auto &i : v) primeFact(i);

    for (auto &i : ans) cout << i << " "; cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // w(t) {
        // cout<<"Case #"<<tc<<": ";
        solve();
        // tc++;
    // }

    return 0;
}