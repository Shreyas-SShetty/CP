Problem - https://www.spoj.com/problems/TRIPINV/

Idea - For each number calculate how many 3-length decreasing sequence it can form. Then add everything using fenwick tree.

Code -

ll query(ll k, ll idx) {
    ll ans = 0;
    while(idx > 0) {
        ans += bit[k][idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void upd(ll k, ll idx, ll val) {
    while(idx < N) {
        bit[k][idx] += val;
        idx += (idx & (-idx));
    }
}

void solve() {
    ll n;
    cin >> n;
    vt<ll> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = n-1; i >= 0; --i) {
        upd(1, a[i], 1);
        upd(2, a[i], query(1, a[i]-1));
        upd(3, a[i], query(2, a[i]-1));
    }
    cout << query(3, n) << endl;
}
