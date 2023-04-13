// pandeyGRocks
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

int main(){

	// fast();

	ll t;
	cin >> t;

	while(t--){

		ll n, m;
		cin >> n >> m;

		vector <ll> a(n);
		read(a, n);

		ll ans = 0;

		ll sm = 0;

		priority_queue <ll> pq;

		ll x = pre[m - 1];

		for(ll i = m - 1; i >= 0; --i){
			pq.push(a[i]);

			if(pre[i] < x){
				while(pre[i] < x){
					x -= (2 * pq.top());
					pq.pop();
					++ans;
				}
			}
		}

		pre[0] = a[0];
		for(int i = 1; i < n; ++i){
			pre[i] = pre[i - 1] + a[i];
		}

		priority_queue <ll, vector <ll>, greater <ll>> pq2;

		ll carry = 0;
		x = pre[m - 1];

		for(ll i = m; i < n; ++i){

			if(pre[i] < x){
				pq2.push(a[i]);

				while((pre[i] + carry) < x){

					carry -= (2 * pq2.top());

					pq2.pop();
					++ans;
				}
			}
		}


		cout << ans << "\n";
	}

	return 0;	
}