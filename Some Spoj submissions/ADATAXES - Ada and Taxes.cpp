/*
Idea - Segment tree + Binary Search
     - Each node is a vector containing all descendents in sorted order.
     - Apply binary search if a range is entirely covered by a node.
*/

#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")

//#define      ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define        fast               ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define        ff                 first
#define        ss                 second
#define        show(b)            for(auto const&x: b) cout<<x<<" "
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
const int N=3e5+5;
const int mod=1e9+7;
//mt19937 rnd(time(NULL));

/*------Global--------*/
// ll minv[4 * N], maxv[4 * N], prod[4 * N];
vt<ll> a;
vt<ll> seg[4*N];
vt<ll> prod[4*N];
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

void merge(int c, int l, int r) {
    int lz = seg[l].size();
    int rz = seg[r].size();
    int i = 0;
    int j = 0;
    vt<ll> temp;
    while(i < lz and j < rz) {
        if(seg[l][i] <= seg[r][j]) {
            temp.push_back(seg[l][i]);
            ++i;
        }
        else {
            temp.push_back(seg[r][j]);
            ++j;
        }
    }
    while(i < lz)
        temp.push_back(seg[l][i++]);
    while(j < rz)
        temp.push_back(seg[r][j++]);
    seg[c] = move(temp);
}

void product(int pos) {
    ll ans = 1;
    for(auto x: seg[pos]) {
        ans = (ans%mod * x%mod) % mod;
        prod[pos].push_back(ans);
    }
}

void build(int l, int h, int n, int pos) {
    if(l > h) return;
    if(l == h) {
        seg[pos].push_back(a[l]);
        prod[pos].push_back(a[l]);
        return;
    }
    int m = (l + h) / 2;
    build(l, m, n, 2*pos+1);
    build(m+1, h, n, 2*pos+2);
    merge(pos, 2*pos+1, 2*pos+2);
    product(pos);
}

ll query(int l, int r, ll height, int curl, int curr, int pos, int n) {
    if(curr < l or curl > r)
        return 1;
    if(curl >= l and curr <= r) {
        int loc = upper_bound(seg[pos].begin(), seg[pos].end(), height) - seg[pos].begin();
        --loc;
        return (loc == -1 ? 1 : prod[pos][loc]);
    }
    if(curl == l and curr == r)
        return prod[pos][0];
    int mid = (curl + curr)/2;
    return (query(l, r, height, curl, mid, 2*pos+1, n) * 
           query(l, r, height, mid+1, curr, 2*pos+2, n)) % mod;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    a = vt<ll>(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    build(0, n-1, n, 0);
    while(q--) {
        ll l, r, height;
        cin >> l >> r >> height;
        cout << query(l, r, height, 0, n-1, 0, n) << endl;
    }
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
