/*
Problem link - https://timus.online/problem.aspx?space=1&num=1087
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
const int mod1=1e9+7;
const int mod2=998244353;
//mt19937 rnd(time(NULL));

/*------Global--------*/
bool dp[N];
bool vis[N];
vt<int> ops;
/*-----Functions------*/

ll modexp(ll a,ll b,ll mod) {
    ll x = 1;
    while(b) {
        if(b & 1) {
            x *= a;
            x %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return x;
}

void rf() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

bool f(int n, int k) {
    if(vis[n]) 
        return dp[n];
    vis[n] = 1;
    bool ans = 0;
    if(ops[0] == n) {
        return dp[n] = 0;
    }
  // Can any "ops[i]"(in the sense, is there any one atleast, hence bitwise or) help the current player to win ?
    for(int i = 0; i < k; ++i) {
        if(ops[i] < n) {
            // Other player's lose is win for the current player. 
            ans |= !f(n - ops[i], k);
        }
    }
    return dp[n] = ans;
}

void solve() {
    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);
    int n, k;
    cin >> n >> k;
    ops = vt<int>(k);
    for(auto &it: ops) {
        cin >> it;
    }
    sort(ops.begin(), ops.end());
    cout << (f(n, k) ? 1 : 2) << endl;
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
