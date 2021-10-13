/*
Problem - https://codeforces.com/problemset/problem/369/C
Submission - https://codeforces.com/contest/369/submission/131692520
Idea - Consider only those nodes whose subtree doesn't have any bad roads but the road from its parent to itself is bad.
*/

int dfs(int v, int p, int typ, int n) {
    int ret = 0;
    for(auto x: e[v]) {
        if(x.ff == p) continue;
        ret += dfs(x.ff, v, x.ss, n);
    }
    if(!ret and typ == 2) {
        ans.push_back(v);
        ++ret;
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    e = vt<vt<pii> >(n+1);
    for(int i = 0; i < n - 1; ++i) {
        int v1, v2, typ;
        cin >> v1 >> v2 >> typ;
        e[v1].push_back({v2, typ});
        e[v2].push_back({v1, typ});
    }
    dfs(1, -1, 1, n);
    if(ans.empty()) {
        cout << 0 << endl;
    }
    else {
        cout << (int)ans.size() << endl;
        show(ans);
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
