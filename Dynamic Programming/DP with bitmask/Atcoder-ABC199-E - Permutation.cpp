/*
https://atcoder.jp/contests/abc199/tasks/abc199_e
Here dp states are dp[i][mask]
i - position
mask - contains all processed numbers till that position.
Here for any position, the order of elements is not imp, but only info about their values is.
*/
#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")

//#define      ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define        fast               ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define        ff                 first
#define        ss                 second
#define        show(b)            for(auto const&x: b) cout<<x<<" "; cout << "\n";
#define        endl               "\n"
#define        vt                 vector
#define        chk                cout << "here\n";

#define        trace1(x)                cerr<<#x<<": "<<x<<endl
#define        trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define        trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define        trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define        trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define        trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef       long long int ll;
typedef       long double LD;
typedef       pair<int,int> pii;
typedef       pair<long long int,long long int> pll;
const int N=1e5+5;
const int mod=1e9+7;
//mt19937 rnd(time(NULL));

/*------Global--------*/
vt<pair<ll, ll> > a[20];
ll dp[18][1<<18];
/*-----Functions------*/

ll modexp(ll a,ll b,ll mod) {
    ll x=1;
    while(b)
    {
        if(b&1) x = ((x%mod) * (a%mod))%mod;
        a = ((a%mod) * (a%mod))%mod;
        b = b / 2;
    }
    return x;
}

void rf() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

ll f(int i, int mask, int n) {
    if(i == n)
        return 1;
    if(dp[i][mask] != -1) {
        return dp[i][mask];
    }
    ll ans = 0;
    for(auto it: a[i]) {
        int y = it.ff;
        int z = it.ss;
        // Reducing mask to contain elements which are smaller than y. [0-based]
        int remainder = mask % (1 << y);
        int smaller = __builtin_popcount(remainder);
        if(smaller > z) {
            return 0;
        }
    }
    for(int j = 0; j < n; ++j) {
        if(!(mask & (1 << j))) {
            ans += f(i+1, mask | (1 << j), n);
        }
    }
    return dp[i][mask] = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 20; ++i) {
        a[i].clear();
    }
    int n, m;
    cin >> n >> m;
    while(m--) {
        ll x, y, z;
        cin >> x >> y >> z;
        a[x].push_back({y, z});
    }
    cout << f(0, 0, n) << endl;
}

int32_t main()
{
    fast;
    //cin.exceptions(cin.failbit);
    rf();
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
