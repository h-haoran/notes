/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
// class Solution {
// public:
//     void insert(vector<int>& vec, int val) {
//         if (vec.size() == 0) {
//             vec.push_back(val);
//             return;
//         }
//         int i = 0;
//         while (i < vec.size() && vec[i] < val) {
//             i++;
//         }
//         if (i >= vec.size() || vec[i] != val) {
//             vec.insert(vec.begin()+i, val);
//         }
//     }
//     void dfs(vector<vector<int>>&G, vector<vector<int>>&ancestors, vector<bool>& visited, vector<int>& path, int n) {
//         for (int p: path) {
//             insert(ancestors[p], n);
//         }
//         if (!visited[n]) {
//             path.push_back(n);
//             for (int nei: G[n]) {
//                 dfs(G, ancestors, visited, path, nei);
//             }
//             path.pop_back();
//             visited[n] = true;
//         } else {
//             for (int p: path) {
//                 for (int an: ancestors[n]) {
//                     insert(ancestors[p], an);
//                 }
//             }
//         }
      
//     }
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> G(n);
//         vector<vector<int>> ancestors(n);
//         vector<bool> visited(n, false);
//         vector<int> path;
//         for (auto edge: edges) {
//             G[edge[1]].push_back(edge[0]);
//         }
//         for (int i = 0; i < n; i++) {
//             dfs(G, ancestors, visited, path, i);
//         }
       
//         return ancestors;
//     }
// };
class Solution {
public:
    void dfs(int i, int u, vector<bool> &vis) {
        for (auto &v : graph[u]) {
            if (!vis[v]) { /* 标记访问过的节点, 并将i加入v的结果中 */
                vis[v] = true;
                ans[v].push_back(i);
                dfs(i, v, vis);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph = vector<vector<int>>(n);
        ans = vector<vector<int>>(n);

        for (auto &edge : edges) { /* 建邻接表 */
            graph[edge[0]].push_back(edge[1]);
        }
        for (int i = 0; i < n; i++) { /* DFS遍历节点 */
            vector<bool> vis(n);
            dfs(i, i, vis);
        }
        return ans;
    }
private:
    vector<vector<int>> graph, ans;
    int n;
};

// @lc code=end

