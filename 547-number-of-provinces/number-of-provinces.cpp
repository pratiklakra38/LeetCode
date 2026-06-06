class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected,
             vector<int>& visited, int& count) {
        visited[node] = 1;
        count++;
        for (int neigh = 0; neigh < isConnected.size(); neigh++) {
            if (isConnected[node][neigh] == 1 && !visited[neigh]) {
                dfs(neigh, isConnected, visited, count);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int prov = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int count = 0;
                dfs(i, isConnected, visited, count);
                prov++;
            }
        }
        return prov;
    }
};