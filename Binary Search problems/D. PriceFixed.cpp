/*
problem - https://codeforces.com/contest/1539/problem/D
Idea - Fix the number of items bought for 2. Check if the remaining items can be bought for 1. If yes, decrease high as we can reduce the cost further, If no increment low!
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
vt<pll> a;
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

bool ok(ll m, ll n, ll sum) {
    ll balance = 0;
    ll stop = 0;
    ll store = m;
    for(int i = n - 1; i >= 0; --i) {
        if(m >= a[i].ff)
            m -= a[i].ff;
        else {
            balance = m;
            a[i].ff -= m;
            stop = i;
            break;
        }
    }

    for(int i = 0; i <= stop; ++i) {
        if(a[i].ss > store) {
            a[stop].ff += balance;
            return 0;
        }
        store += a[i].ff;
    }
    a[stop].ff += balance;
    return 1;
}

void solve() {
    ll n;
    cin >> n;
    a = vt<pll>(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i].ff >> a[i].ss;
    sort(a.begin(), a.end(), [&](auto& x, auto &y) {
        if(x.ss == y.ss)
            return x.ff < y.ff;
        return x.ss < y.ss;
    });

    ll sum = 0;
    for(int i = 0; i < n; ++i)
        sum += a[i].ff;

    ll l = 0, h = sum;
    while(l < h) {
        ll m = (l + h) >> 1;
        if(ok(m, n, sum))
            h = m;
        else
            l = m + 1;
    }
    cout << (2 * l) + (sum - l) << endl;
}

int32_t main()
{
    fast;
    //cin.exceptions(cin.failbit);
    // rf();
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
