class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> depth;
    vector<vector<int>> parent;
    vector<vector<int>> Q;
    set<int> W;
    int n;
    int sq_pow = 25;
    void dfs(int node, int par=-1, int d=0){
        depth[node] = d;
        parent[0][node] = par;
        for(auto child_pr: adj[node]){
            int child_nd = child_pr.first;
            int wt = child_pr.second;
            if(child_nd == par) continue;
            for(auto w: W){
                if(w == wt)
                    Q[w][child_nd] = Q[w][node] +1;
                else
                    Q[w][child_nd] = Q[w][node];
            }
            dfs(child_nd, node, d+1);
        }
    }
    void built(){
        dfs(0);
        for(int i=1;i<sq_pow;i++){
            for(int j=0;j<n;j++){
                if(parent[i-1][j]!=-1)
                    parent[i][j] = parent[i-1][parent[i-1][j]];
            }
        }

    }
    int LCA(int u, int v){
        if(depth[u]<depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int i=sq_pow-1;i>=0;i--){
            if((1<<i) & diff){
                u = parent[i][u];
            }
        }
        if(u == v) return u;
        for(int i =sq_pow-1;i>=0;i--){
            if(parent[i][u]!=parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
    int countOne(int u, int v, int lca, int w){
        return Q[w][u] + Q[w][v] - 2*Q[w][lca];
    }
    vector<int> minOperationsQueries(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = N;
        adj.resize(n);
        depth.resize(n,0);
        parent.resize(sq_pow, vector<int> (n,-1));
        Q.resize(27, vector<int> (n,0));
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            W.insert(wt);
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        built();
        vector<int> ans;
        for(auto q: queries){
            int u = q[0];
            int v = q[1];
            int lca = LCA(u, v);
            int mx_edge = depth[u] + depth[v] - 2*depth[lca];
            int mn_ans = mx_edge;
            for(auto w: W){
                mn_ans = min(mn_ans, mx_edge - countOne(u,v,lca,w));
            }
            ans.push_back(mn_ans);
        }
        return ans;
    }
};