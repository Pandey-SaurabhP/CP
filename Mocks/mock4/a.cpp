#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(int i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    fast();

    map <int, string> mp;

    mp[1995]= "ITMO";
    mp[1996]= "SPbSU";
    mp[1997]= "SPbSU";
    mp[1998]= "ITMO";
    mp[1999]= "ITMO";
    mp[2000]= "SPbSU";
    mp[2001]= "ITMO";
    mp[2002]= "ITMO";
    mp[2003]= "ITMO";
    mp[2004]= "ITMO";
    mp[2005]= "ITMO";
    mp[2007]= "SPbSU";
    mp[2008]= "SPbSU";
    mp[2009]= "ITMO";
    mp[2010]= "ITMO";
    mp[2011]= "ITMO";
    mp[2012]= "ITMO";
    mp[2013]= "SPbSU";
    mp[2014]= "ITMO";
    mp[2015]= "ITMO";
    mp[2016]= "ITMO";
    mp[2017]= "ITMO";
    mp[2018]= "SPbSU";
    mp[2019]= "ITMO";
    mp[2006] = "PetrSU, ITMO";

    int yr;
    cin >> yr;

    cout << mp[yr];

    return 0;
}




