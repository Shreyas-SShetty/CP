/* 
  https://codeforces.com/contest/1476/problem/C
  less obvious dp solution
  available = 1 when we can start a cycle from current index
  when cycle is already started we can't stop and create new one for next index 
  so when available = 0 from some index it remains like that throughout
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
#define        chk                cout << "here\n"

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
ll dp[N][2];
vt<ll> a, b, c;
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

ll f(int i, int n, bool available) {
    if(i == n)
        return 0;
    ll& val = dp[i][available];
    if(val != -1)
        return val;
    val = 0;
    if(available) {
        val = max(f(i+1, n, 1), c[i] - b[i] + 1 + a[i]);
        if(i < n-1 and b[i+1] != c[i+1])
            val = max(val, f(i+1, n, 0) + c[i] - b[i] + 1 + a[i]);
    }
    else {
        val = a[i] - (c[i] - b[i] - 1);
        if(i < n - 1 and b[i+1] != c[i+1])
            val = max(val, f(i+1, n, 0) + a[i] - (c[i] - b[i] - 1));
    }
    return val;
}

void solve() {
    memset(dp, -1, sizeof dp);
    ll n;
    cin >> n;
    ll ans = 0;
    a = b = c = vt<ll>(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
        if(b[i] > c[i])
            swap(b[i], c[i]);
    }    
    cout << f(1, n, 1) << endl;
}

int32_t main()
{
    fast;
    //cin.exceptions(cin.failbit);
    // rf();
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
