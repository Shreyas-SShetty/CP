/*
problem = https://www.spoj.com/problems/TOURIST/
Explantion = https://qr.ae/pGCryM
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
int dp[105][105][105];
vt<string> s;
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

bool invalid(int x1, int y1, int x2, int y2, int n, int m) {
    if(x1 < 0 or x1 >= n or x2 < 0 or x2 >= n)
        return 1;
    if(y1 < 0 or y1 >= m or y2 < 0 or y2 >= m)
        return 1;
    return 0;
}

int maxPoints(int x1, int y1, int x2, int n, int m) {
    int y2 = x1 + y1 - x2;
    if(invalid(x1, y1, x2, y2, n, m))
        return -1e9;
    if(x1 == x2 and y1 == y2 and x1 == n-1 and y1 == m-1)
        return (s[x1][y1] == '*');
    if(s[x1][y1] == '#' or s[x2][y2] == '#')
        return -1e9;
    int& val = dp[x1][y1][x2];
    if(val != -1)
        return val;
    val = 0;
    if(x1 == x2 and y1 == y2)
        val = s[x1][y1] == '*';
    else
        val = (s[x1][y1] == '*') + (s[x2][y2] == '*');
    int ans = maxPoints(x1+1, y1, x2+1, n, m);
    ans = max(ans, maxPoints(x1+1, y1, x2, n, m));
    ans = max(ans, maxPoints(x1, y1+1, x2+1, n, m));
    ans = max(ans, maxPoints(x1, y1+1, x2, n, m));
    return val = val + ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n, m;
    cin >> m >> n;
    s = vt<string>(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    cout << maxPoints(0, 0, 0, n, m) << endl;
}

int32_t main()
{
    fast;
    //cin.exceptions(cin.failbit);
    rf();
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
