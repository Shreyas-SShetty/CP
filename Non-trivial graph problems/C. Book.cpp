/*
Problem - https://codeforces.com/contest/1573/problem/C
Idea - Toposort + DP
Submission - https://codeforces.com/contest/1573/submission/131091117
*/

// Returns output. if output.size() != n then no topo
vt<int> topoSort(vt<vt<int> >& e, vt<int>& in, int n) {
    vt<int> output;
    queue<int> q;
    int cnt = n;
    for(int i = 1; i <= n; ++i) {
        if(in[i] == 0) {
            q.push(i);
            output.push_back(i);
            --cnt;
        }
    }
    while(!q.empty()) {
        int tp = q.front();
        q.pop();
        for(auto x: e[tp]) {
            --in[x];
            if(in[x] == 0) {
                --cnt;
                output.push_back(x);
                q.push(x);
            }
        }
    }
    return output;
}

void solve() {
    int n;
    cin >> n;
    vt<vt<int> > e(n+1);
    vt<int> in(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        int dep;
        cin >> dep;
        in[i] = dep;
        for(int j = 0; j < dep; ++j) {
            int v;
            cin >> v;
            e[v].push_back(i);
        }
    }
    vt<int> output = topoSort(e, in, n);
    if(output.empty() or output.size() != n) {
        cout << -1 << endl;
        return;
    }

    vt<int> dp(n+1, -1e9);
    for(int i = 1; i <= n; ++i) {
        if(in[i] == 0) {
            dp[i] = 1;
        }
    }

    for(auto x: output) {
        for(auto y: e[x]) {
            if(x > y) {
                dp[y] = max(dp[y], dp[x] + 1);
            }
            else {
                dp[y] = max(dp[y], dp[x]);
            }
        }
    }

    int ans = -1e9;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int32_t main()
{
    fast;
    //cin.exceptions(cin.failbit);
    // rf();
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
