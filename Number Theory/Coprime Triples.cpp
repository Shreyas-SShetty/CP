/*
https://www.codechef.com/problems/COPRIME3
*/

/*
Idea - https://codeforces.com/blog/entry/55822
Inclusion - Exclusion principle!
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
const int N=1e6+5;
const int mod=1e9+7;
//mt19937 rnd(time(NULL));

/*------Global--------*/
vt<int> a;
int spf[N];
bool prime[N];
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
    int n;
    cin >> n;
    a.resize(n);
    map<int, int> cnt, eles;
    // cnt stores the number of times a subset 'X' occurs in all the elements
    // eles stores the number of terms in a subset 'X'.
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        vt<int> factors;
        // Generating all distinct prime factors of the number.
        while(a[i] != 1) {
            factors.push_back(spf[a[i]]);
            int div = spf[a[i]];
            while(a[i] % div == 0) {
                a[i] /= div;
            }
        }
        int m = factors.size();
        // Generating all non empty subsets 
        // Its possible because number of distinct prime factors is O(log(log(a[i])))
        for(int i = 1; i < (1 << m); ++i) {
            int prod = 1;
            int num = 0;
            for(int j = 0; j < m; ++j) {
                if(i & (1 << j)) {
                    prod *= factors[j];
                    ++num;
                }
            }
            cnt[prod]++;
            eles[prod] = num;
        }
    }
    if(n <= 2) {
        cout << 0 << endl;
        return;
    }
    ll ans = (n * 1LL * (n - 1) * 1LL * (n - 2))/6;

    // Inclusion - Exclusion Principle
    for(auto x: eles) {
        int num = x.ss;
        int times = cnt[x.ff];
        // cout << x.ff << " " << x.ss << " " << cnt[x.ff] << endl;
        if(times <= 2) continue;
        // if there are 'times' number of elements having 'x.ff' as product subset, then 
        // times(c)3 pairs are not coprime.
        ll choose = (times * 1LL * (times - 1) * 1LL * (times - 2)) / 6;
        if(num & 1) {
            ans -= choose;
        }
        else {
            ans += choose;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    fast;
    //cin.exceptions(cin.failbit);
    rf();
    int t = 1;
    iota(spf, spf + N, 0);
    memset(prime, 1, sizeof prime);
    for(int i = 2; i * i < N; ++i) {
        if(prime[i]) {
            for(int j = i; j < N; j += i) {
                prime[j] = 0;
                spf[j] = i;
            }
        }
    }
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
