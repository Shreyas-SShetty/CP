/*
https://atcoder.jp/contests/abc196/tasks/abc196_d
dfs with backtracking.
representing rows and columns in a single variable.
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
int ans = 0;
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

void dfs(int i, int n, int m, int a, int b, int mask) {
    // trace4(a, b, mask, i);
    if(i == n * m) {
        return (void)ans++;
    }
    if(mask & (1 << i)) {
        return dfs(i + 1, n, m, a, b, mask);
    }
    if(a) {
        if(((i + 1) % m != 0) and !(mask & (1 << (i + 1)))) {
            dfs(i + 1, n, m, a - 1, b, mask | (1 << i) | (1 << (i + 1)));
        }
        if(((i + m) < (n * m)) and !(mask & (1 << (m + i)))) {
            dfs(i + 1, n, m, a - 1, b, mask | (1 << i) | (1 << (m + i)));
        }
    }
    if(b) {
        dfs(i + 1, n, m, a, b - 1, mask | (1 << i));
    }
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    dfs(0, n, m, a, b, 0);
    cout << ans << endl;
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
