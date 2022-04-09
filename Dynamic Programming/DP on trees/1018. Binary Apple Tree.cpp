/*
Problem link - https://timus.online/problem.aspx?space=1&num=1018 
Idea - NO NOT GREEDY:P ..  Its dp .. states are the current node and the number of branches that must be preserved in its subtree .. nice one .. but made me feel like an imposter lol.
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
    int n, q;
    cin >> n >> q;
    vt<vt<pii> > v(n + 1);
    for(int i = 0; i <= n; ++i) {
        v[i].clear();
    }
    
    for(int i = 0; i < n - 1; ++i) {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        v[v1].push_back({v2, weight});
        v[v2].push_back({v1, weight});
    }

    vt<vt<int> > dp(n + 1, vt<int>(q + 1, -1));

    auto f = [&](int node, int q, int parent, auto& f) -> int {
        // trace2(node, q);
        if(q == 0) {
            return 0;
        }
        int& val = dp[node][q];
        if(val != -1) {
            return val;
        }
        val = 0;
      
        // If q > 0 but node has no children.
        if(v[node].size() == 1) {
            return -1e9;
        }
      
        // Fetching the children of the current node. 
        int v1 = -1, v2, w1, w2;
        for(auto x: v[node]) {
            if(x.ff == parent) continue;
            else if(v1 == -1) v1 = x.ff, w1 = x.ss;
            else v2 = x.ff, w2 = x.ss;
        }

        // trace4(v1, v2, w1, w2);
      
        // All valid distribution between left and right subtrees. 
        for(int i = 0; i <= q; ++i) {
            val = max(val, (i == 0 ? 0 : w1 + f(v1, i - 1, node, f)) + (i == q ? 0 : w2 + f(v2, q - i - 1, node, f)));
        }
        return val;
    };

    cout << f(1, q, -1, f) << endl;
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
