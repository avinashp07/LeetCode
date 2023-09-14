class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, vector<vector<int>>& graph, int n,vector<int>& curr)
    {
        curr.push_back(i);
        if(i==n-1)
        {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        for(int j = 0; j < graph[i].size(); j++)
        {
            dfs(graph[i][j],graph,n,curr);
        }
        curr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> curr;
        dfs(0,graph,n,curr);
        return ans;
    }
};