Problem - https://www.spoj.com/problems/DQUERY/

Idea - This time using binary indexed tree.
       Sort queries according to 'r'.
       Normal range query but in a particular range we don't want numbers both in the current range and in range[0,l-1] to be inc twice (then it will reduce the actual ans).
       So maintain vis array which tells last occurence of a number.
       If that number is visited twice delete the last occurence and update the current occurence.

Code - https://ideone.com/1OOG8r

class Fentree {
private:
    vt<ll> bit;
public:
    Fentree(){}
    Fentree(int n) {
        bit = vt<ll> (n+100, 0);
    }
    void update(int pos, ll val) {
        for(int i = pos; i < bit.size(); i += (i & (-i))) {
            bit[i] += val;
        }
    }
    ll query(int pos) {
        ll smallerOrEq = 0;
        for(int i = pos; i > 0; i -= (i & (-i))) {
            smallerOrEq += bit[i];
        }
        return smallerOrEq;
    }
};

void solve() {
    memset(vis, -1, sizeof vis);
    ll n;
    cin >> n;
    a = vt<ll>(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    ll q;
    cin >> q;
    ans = vt<ll>(q);
    queries = vt<pair<pll, ll> >(q);
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].ff.ss >> queries[i].ff.ff;
        --queries[i].ff.ss;
        --queries[i].ff.ff;
        queries[i].ss = i;
    }

    sort(queries.begin(), queries.end());
    // for(int i = 0; i < q; ++i)
    //     cout << queries[i].ff.ff << " " << queries[i].ff.ss << " " << queries[i].ss << endl;

    int cur = 0;
    Fentree farray(n);
    for(int i = 0; i < q; ++i) {
        int till = queries[i].ff.ff;
        while(cur <= till and cur < n) {
            if(vis[a[cur]] != -1)
                farray.update(vis[a[cur]]+1, -1);
            farray.update(cur+1, 1);
            vis[a[cur]] = cur;
            ++cur;
        }
        ans[queries[i].ss] = farray.query(till+1) - farray.query(queries[i].ff.ss);
    }

    for(int i = 0; i < q; ++i)
        cout << ans[i] << endl;
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
