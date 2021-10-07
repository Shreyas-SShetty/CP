// Returns output vector. if output.size() != n then no topo
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
