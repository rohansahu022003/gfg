class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& inStack,
             stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = 1;
        inStack[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, inStack, st, adj)) return true;
            } else if (inStack[it]) {
                return true; // cycle detected
            }
        }

        st.push(node);
        inStack[node] = 0;
        return false;
    }

public:
    string findOrder(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26); // graph of chars
        vector<int> present(26, 0); // mark used chars

        // Mark all characters that appear
        for (auto& w : words) {
            for (char c : w) present[c - 'a'] = 1;
        }

        // Build graph edges
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            // Invalid case: prefix issue
            if (s1.size() > s2.size() && s1.substr(0, len) == s2) {
                return "";
            }

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // Topological sort using DFS
        vector<int> vis(26, 0), inStack(26, 0);
        stack<int> st;

        for (int i = 0; i < 26; i++) {
            if (present[i] && !vis[i]) {
                if (dfs(i, vis, inStack, st, adj)) return ""; // cycle detected
            }
        }

        string order = "";
        while (!st.empty()) {
            order.push_back(st.top() + 'a');
            st.pop();
        }

        return order;
    }
};