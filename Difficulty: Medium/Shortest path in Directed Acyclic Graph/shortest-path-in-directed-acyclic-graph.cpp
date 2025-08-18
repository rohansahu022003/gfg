// User function Template for C++
class Solution {
private:
    void topo(int node, stack<int>& st, vector<vector<pair<int,int>>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                topo(it.first, st, adj, vis);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }

        stack<int> st;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                topo(i, st, adj, vis);
            }
        }

        // Distance array
        vector<int> shortest(V, INT_MAX);
        shortest[0] = 0; // source is 0

        // Process nodes in topo order
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(shortest[node] != INT_MAX){ // only relax if node is reachable
                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    if(shortest[v] > shortest[node] + wt){
                        shortest[v] = shortest[node] + wt;
                    }
                }
            }
        }

        // Replace INF with -1
        for(int i = 0; i < V; i++){
            if(shortest[i] == INT_MAX) shortest[i] = -1;
        }

        return shortest;
    }
};
