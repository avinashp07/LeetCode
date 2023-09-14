class Solution {
public:
    bool dfs(map<int,vector<int>>& adjList,int i, int destination, vector<bool>& visited)
    {
        if(i==destination) return true;
        if(visited[i]) return false;
        visited[i] = true;
        for(int j = 0; j < adjList[i].size() ; j++)
        {
            if(dfs(adjList,adjList[i][j],destination,visited)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int,vector<int>> adjList;
        vector<bool> visited(n+1,false);
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int x = edges[i][0];
            int y =edges[i][1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        return dfs(adjList,source,destination,visited);
    }
};