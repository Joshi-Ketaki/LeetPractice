/*
1. detect cycle - there should be no cycle -- topological sort
2. all components should be connected --check if edges == n-1

261. Graph Valid Tree
Solved
Medium
Topics
Companies
Hint

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

Example 1:

Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true

Example 2:

Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false

 

Constraints:

    1 <= n <= 2000
    0 <= edges.length <= 5000
    edges[i].length == 2
    0 <= ai, bi < n
    ai != bi
    There are no self-loops or repeated edges.


*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        //vector<int> visited(n,0);
        //if(edges.size() > n-1) return false;
        if(edges.size() != n-1) return false;
        int rootFlag = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            //for(int j = 0; j < edges[0].size(); j++)
            //{
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            //}
        }
        // chekc if there is an island
        // and remiaing nodes form a graph but there is a cycle
        // in that case the below for will never enter if and 
        // indegree of cycle nodes will be greater than 1, returning false 
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 1)
                q.push(i);
        }

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            //if(visited[curr] == 0) {
            //visited[curr] = 1;
            indegree[curr]--;
            //}
            //else 
            //    return false;
            for(auto it: adj[curr]){
                indegree[it]--;
                if(indegree[it] == 1)
                    q.push(it);
            }
        }
        for(int i=0; i < n; i++)
        {
            if(indegree[i] > 0) return false;
        }
        return true;

        }
    };
