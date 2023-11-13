#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll s=2001;
ll gr[2001][2001],vis[2001][2001];

void f(int i,int j,ll &ans)
{
	if(i==0 || i>2000 || j==0 || j>2000)
	{
		ans=INT_MIN;
		return ;
	}
	if(vis[i][j] == 1)return;
	vis[i][j]=1;

	if(gr[i][j] == 1)
	{
		return ;
	}
	if(i%2 == 0 || j%2 == 0)
	{
		f(i+1,j,ans);
	    f(i-1,j,ans);
	    f(i,j+1,ans);
	    f(i,j-1,ans);
		return ;
	}

    ans++;

	f(i+1,j,ans);
	f(i-1,j,ans);
	f(i,j+1,ans);
	f(i,j-1,ans);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll mod = 998244353;

// cout<<"a";
	ll n;
	cin>>n;

	ll a[n+1],b[n+1];

// cout<<"a";
	for(int i=0;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		a[i]+=a[i];
		b[i]+=b[i];
	}
// cout<<"a";
	for(ll i=0;i<=2000;i++)for(ll j=0;j<=2000;j++)
	gr[i][j] = vis[i][j]=0;


	// cout<<"a";
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
		for(ll f=a[i];f!=a[i+1];)
		{
			gr[f][b[i]] = 1;
			if(f<a[i+1])f++;
			else f--;
		}
		}
		if(b[i]!=b[i+1])
		{
		for(ll f=b[i];f!=b[i+1];)
		{
			gr[a[i]][f] = 1;
			if(f<b[i+1])f++;
			else f--;
		}
		}
	}
	// cout<<"a";
	ll ans=0;
	// for(int i=1;i<=20;i++)
	// {
	// 	for(int j=1;j<=20;j++)cout<<gr[i][j];
	// 	cout<<"\n";
	// }
	for(int i=1;i<s;i++)
	{
		for(int j=1;j<s;j++)
		{
			// cout<<gr[i][j]<<" ";
			if(gr[i][j] == 1)continue;
			if(vis[i][j] == 1)continue;
			ll anss=0;
			f(i,j,anss);
			ans=max(ans,anss);
		}
		// cout<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
