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
#define maxN 1005
#define nn cout<<"\n"
#define sp cout<<" "
#define ifalse ios_base::sync_with_stdio(false),cin.tie(NULL)


inline ll add(ll x, ll y) { x += y; if(x >= mod) x -= mod; return x; }
inline ll sub(ll x, ll y) { x -= y; if(x < 0) x += mod; return x; }
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }
inline ll pwr(ll a, ll b){
    ll x = 1LL;
    while(b) {
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}

bool CHK(ll n)
{
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    if(n % 2 == 0 or n % 3 == 0) return 0;

    for(ll i = 5; i * i <= n; i += 6) if(n % i == 0 or n % (i + 2) == 0) return 0;
    return 1;
}

//*/%+-*/%+-*/%+-*/%+-*/%+-*/%+-*/%+-*/%+-*/%+-FLASH_CUSTOM_ROM*/%+-*/%+-*/%+-*/%+-*/%+-*/%+-*/%+-*/%+-*/%+-//

ll fac[maxN],inv[maxN];

void GEN()
{
    fac[0]=1;
    rep(i,1,maxN) fac[i]=mul(fac[i-1],i);

    inv[maxN-1]=pwr(fac[maxN-1],mod-2);
    rrep(i,maxN-2,0) inv[i]=mul(inv[i+1],i+1);
}

ll NCR(ll n,ll r)
{
    if(r>n) return 0;
    return mul(mul(fac[n],inv[n-r]),inv[r]);
}

int main()
{
    ifalse;
    GEN();
    cout<<NCR(4,2);
    return 0;
}
