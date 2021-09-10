#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-funroll-loops")
//#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//find_by_order(k)  returns iterator to kth element starting from 0;
//order_of_key(k) returns count of elements strictly smaller than k;
//erase,insert same as normal set

//#define      ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define        fast               ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define        ff                 first
#define        ss                 second
#define        pb                 push_back
#define        forn(i,n)          for(int i=0;i<n;++i)
#define        forf(i, s, e, gap) for(int i = s; i <= e; i += gap)
#define        forb(i, s, e, gap) for(int i = s; i >= e; i += gap)
#define        show(b)            for(auto const&x: b) cout<<x<<" "
#define        fix(b,val)         memset(b,val,sizeof(b))
#define        pill(b,n,v)        fill(b,b+n,v)
#define        w(t)               int t;cin>>t;while(t--)
#define        nl                 "\n"
#define        all(v)             v.begin(),v.end()
#define        vt                 vector
#define        PI                 acos(-1)
#define        sinDegrees(x)      sin((x) * PI / 180.0)
#define        cosDegrees(x)      cos((x) * PI / 180.0)
#define        tanDegrees(x)      tan((x) * PI / 180.0)
#define        atanDegrees(x)     atan(x)* 180.0 / PI
#define        asinDegrees(x)     asin(x)* 180.0 / PI
#define        EPS                0.000000001
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

/*-----Functions------*/

inline int add(int a, int b) { int ret=((ll)a+b)%mod; if(ret<0) ret+=mod; return ret; }
inline int mul(int a, int b) { int ret=((ll)a*b)%mod; if(ret<0) ret+=mod; return ret; }
template<typename... Args>
inline int add(int a, Args... args) { return add(a, add(args...)); }
template<typename... Args>
inline int mul(int a, Args... args) { return mul(a, mul(args...)); }
inline int addm(int a, int b, int MOD) { int ret=((ll)a+b)%MOD; if(ret<0) ret+=MOD; return ret; }
inline int mulm(int a, int b, int MOD) { int ret=((ll)a*b)%MOD; if(ret<0) ret+=MOD; return ret; }
inline int addm(int a, int b, int c, int MOD) { return addm(a, addm(b, c, MOD), MOD); }
inline int mulm(int a, int b, int c, int MOD) { return mulm(a, mulm(b, c, MOD), MOD); }

#define EACH(x, a) for (auto& x: a)
template<class T> void read(T& x) {
    cin >> x;
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}

template<typename T>
void show2d(const vector<vector<T>>& adj) {
    for(auto x:adj) {
        for(auto y:x)
            cout<<y<<" ";
        cout<<"\n";
    }
}

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

// void initSieve(int lim) {
//     sieve  = vt<bool>(lim,1);
//     sieve[0] = 0;
//     sieve[1] = 0;
//     sieve[2] = 1;
//     for(int i=2; (i*i) <= lim; ++i) {
//         if(sieve[i])
//         for(int j=i*i; j<lim; j+=i) {
//             sieve[j] = 0;
//         }
//     }
//     // for(int i=0; i<lim; ++i)
//     // cout<<sieve[i]<<" ";
//     // cout<<nl;
// }

// void initFact(int lim) {
//     fact = vt<ll>(lim);
//     fact[0] = 1;
//     for(int i=1; i<lim; ++i)
//         fact[i] = (fact[i-1]%mod * i%mod) %mod;
//     // for(int i=1; i<lim; ++i)
//     // cout<<fact[i]<<" ";
//     // cout<<nl;
// }

// ll ncr(ll n, ll r) {
//     return ((fact[n]%mod)*((modexp(fact[r], mod-2, mod)%mod * modexp(fact[n-r], mod-2, mod)%mod)% mod)) % mod;
// }

void rf() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

void solve() {
    
}

//Thought  abt edge cases (n == 1??????????????)

int32_t main()
{
    fast;
    //cin.exceptions(cin.failbit);
    rf();
    w(t) 
    {
        solve();
    }
}
