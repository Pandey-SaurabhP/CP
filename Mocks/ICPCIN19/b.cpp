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
#define w(t)        long long t=1,tc=1;cin>>t;while(t--)

/*-------------------- Type Definitions --------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*-------------------------- Maths -------------------------*/
const long long MOD = 1000*1000*1000 + 7; // for big mod
template <typename T> inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;} // better than __gcd
template <typename T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
template <typename T> inline bool isPrime(T n){for (T i=2;i*i<=n;i++) if(n%i==0) return false; return n>1;}

/*-------------------------- SOLVE -------------------------*/

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


vector<ll> v;
vector<vector<pair<long long, long long>>> adj;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

long long reduce(long long x) {
    long long res = v[adj[x][0].ff];
    long long n = v[adj[x][0].ff];
    long long done = 0;

    int nn = primeList.size();


    for(long long i = 0; !done && (i < nn) && primeList[i] * primeList[i] <= n; ++i){
		if(n % primeList[i] == 0){
			res = primeList[i];
			done = 1;
			break;
		}
	}


    for (auto it : adj[x]) {
    	long long u = it.ff;
    	long long _v = it.ss;

        v[u] /= binpow(res, _v);
    }

    return res;
}

void solve() {
	sieve();
	// cout << primeList[primeList.size() - 1] << "\n";

    long long m, n, k;
    cin >> m >> n >> k;

    v.resize(n);
    for (auto &i : v) cin >> i;

    adj.resize(m);
    for (long long i = 0; i < k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
    }

    vector<long long> ans(m);
    for (long long i = 0; i < m; i++) {
        ans[i] = reduce(i);
        // for (auto &x : v) cout << x << " "; cout << endl;
    }

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