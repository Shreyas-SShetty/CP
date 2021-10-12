/*
Problem - https://atcoder.jp/contests/abc222/tasks/abc222_d 
Idea - Initially the dp states seems to be 'i' the current position, and 'prev' the previous number in the sequence.
       But the transition time in this case in O(N) leading to overall time complexity of O(N^3) :(
       So, trying some other dp states, we can replace 'prev' with 'j' where j is the value of the element at current position.
       Hence dp[i][j] means number of valid sequences till 'i'th position and ending at position <= 'j'.
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

void solve() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll dp[n][3005];
    memset(dp, 0, sizeof dp);
    // dp[i][j] = number of sequences till 'i'th position
    // ending <= 'j'.
    for(int i = 0; i < n; ++i) {
        for(int j = a[i]; j <= b[i]; ++j) {
            if(i == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
        for(int j = 1; j <= 3000; ++j) {
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod2;
        }
    }
    cout << dp[n-1][3000] << endl;
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
