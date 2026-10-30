class Solution {
    vector<int> output;
    vector<int> indexed;
    vector<vector<int>> adj;

    void dfs(int node) {
        output.push_back(node);
        indexed[node]--;
        for(int nei : adj[node]) {
            indexed[nei]--;
            if(indexed[nei] == 0) {
                dfs(nei);
            }

            
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        indexed.assign(numCourses, 0);
        adj.assign(numCourses, vector<int>{});

        for(auto& pre : prerequisites){
            indexed[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        
        for( int i = 0; i < numCourses; i++){
            if(indexed[i] == 0) {
                dfs(i);
            }
        }

        if (output.size() != numCourses) { return {};}
        return output;

    }
};
