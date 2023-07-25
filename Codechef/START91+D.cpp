    #include <bits/stdc++.h>

    using namespace std;

    typedef long long int ll;


    int main(){

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll t;
        cin >> t;

        while(t--){
            
            ll n, q;
            cin >> n >> q;

            vector <ll> a(n);
            for(ll i = 0; i < n; ++i) cin >> a[i];

            sort(a.begin(), a.end());

            vector <ll> sm(n + 5, 0ll);

            while(q--){
                ll l, r;
                cin >> l >> r;

                sm[l] += 1ll;
                sm[r + 1] -= 1ll;
            }

            vector <ll> pre(n + 5);
            pre[0] = sm[1];

            ll mx = 0;

            for(ll i = 1; i <= n; ++i){
                pre[i] = pre[i - 1] + sm[i + 1];
                mx = max(mx, pre[i]);
            }

            vector <vector <ll>> mp(mx + 5);

            for(ll i = 0; i < n; ++i){
                mp[pre[i]].push_back(i);
            }

            vector <ll> ans(n + 5);

            ll j = n - 1;

            for(ll i = mx; i >= 0; --i){

                if(mp[i].size() != 0){

                    
                    for(auto it : mp[i]){
                        ans[it] = a[j];
                        --j; 
                    }
                }
            }

            ll sma = 0ll;

            sort(pre.begin(), pre.begin() + n);

            for(ll i = 0; i < n; ++i){
                sma += (1ll * pre[i] * a[i]);
            }

            cout << sma << "\n";
            for(ll i = 0; i < n; ++i){
                cout << ans[i] << " ";
            }
            cout << "\n";

        }

        return 0;
    }