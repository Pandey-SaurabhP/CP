#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        for (ll i = 0; i < n - 2; i++)
        {
            string temp = "";
            temp = temp + s[i] + s[i + 1] + s[i + 2];
            if (temp == "pie" || temp == "map")
            {
                ans++;
                i = i + 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}