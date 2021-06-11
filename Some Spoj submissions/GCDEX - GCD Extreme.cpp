/*
Explanation - https://qr.ae/pGAbfa
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
const int N=1e6+5;
const int mod=1e9+7;
//mt19937 rnd(time(NULL));

/*------Global--------*/
ll ans[N];
ll phi[N];
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

void solve() {
    while(true) {
        ll n;
        cin >> n;
        if(n == 0) return;
        cout << ans[n] << endl;
    }
}

int32_t main()
{
    fast;
    //cin.exceptions(cin.failbit);
    rf();
    iota(phi, phi+N, 0);

    for(int i = 2; i < N; ++i) {
        if(phi[i] == i) {
            for(int j = i; j < N; j += i) {
                phi[j] = phi[j] - phi[j]/i;
            }
        }
    }

    memset(ans, 0, sizeof ans);
    for(int i = 2; i < N; ++i) {
        for(int j = i; j < N; j += i) {
            ans[j] += (phi[i] * (j / i));
        }
    }

    for(int i = 1; i < N; ++i)
        ans[i] += ans[i-1];

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
