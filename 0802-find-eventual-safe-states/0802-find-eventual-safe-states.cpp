class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);

        for(int node = 0; node < n; node++){
            for(int neighbor : graph[node]){
                reverseGraph[neighbor].push_back(node);
                indegree[node]++;
            }
        }

        queue<int>q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<bool> safe(n, false);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe[node] = true;

            for(int prev : reverseGraph[node]){
                indegree[prev]--;

                if(indegree[prev] == 0)
                    q.push(prev);
            }
        }

        vector<int> result;

        for(int i = 0; i < n; i++){
            if(safe[i])
                result.push_back(i);
        }

        return result;
    }
};