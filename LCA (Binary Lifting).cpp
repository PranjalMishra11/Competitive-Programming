/*input

*/		
#include<bits/stdc++.h>
using namespace std;
		 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vst;
typedef pair<ll,ll> pll;
typedef pair<char,ll> pcl;
typedef pair<string,ll> psl;
typedef set<ll> sll;
typedef set<char> sc;
typedef set<string> sst;
typedef map<char,ll> mcl;
typedef map<ll,ll> mll;
typedef map<string,ll> msl;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define fill(a,v) memset(a,v,sizeof a)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define srep(i,s) for(ll i=0;s[i]!='\0';i++)
#define PI 3.1415926535897932384626
#define INF 999999999999999
#define mod 1000000007
#define nn cout<<"\n"
#define sp cout<<" "
#define ifalse ios_base::sync_with_stdio(false),cin.tie(NULL)

#define maxN 100005
vll v[maxN];
vector<vll> up;
vll tin,tout;
ll timer;
ll n,l;

void dfs(ll x,ll p)
{
	tin[x]=++timer;
	up[x][0]=p;

	rep(i,1,l+1) up[x][i]=up[up[x][i-1]][i-1];

	for(auto u:v[x])
	{
		if(u==p) continue;
		dfs(u,x);
	}

	tout[x]=++timer;
}

bool ances(ll u,ll v)
{
	return tin[u]<=tin[v] and tout[u]>=tout[v];
}

ll lca(ll u,ll v)
{
	if(ances(u,v)) return u;
	if(ances(v,u)) return v;

	rrep(i,l,0) if(!ances(up[u][i],v)) u=up[u][i];

	return up[u][0];
}

void pre(ll root)
{
	tin.resize(n+1);
	tout.resize(n+1);
	timer=0;
	l=ceil(log2(n));
	up.assign(n+1,vll(l+1));
	dfs(root,root);
}

int main()
{
	ifalse;
    cin>>n;
    rep(i,0,n-1)
    {
    	ll x,y;
    	cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }


    pre(1);
   
    ll q=0;
    cin>>q;
    while(q--)
    {
    	ll a,b;
    	cin>>a>>b;
    	cout<<lca(a,b)<<"\n";
    }
    
	return 0;
}