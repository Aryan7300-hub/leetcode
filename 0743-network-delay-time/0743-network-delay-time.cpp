class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for(auto& time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            graph[u].push_back({v, w});
        }

        vector<int> dist(n+1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [distance, node] = pq.top();
            pq.pop();

            if(distance > dist[node]){
                continue;
            }

            for(auto [neighbor, weight] : graph[node]){
                int newDistance = distance + weight;

                if(newDistance < dist[neighbor]){
                    dist[neighbor] = newDistance;
                    pq.push({newDistance, neighbor});
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i <=  n; i++){
            if(dist[i] == INT_MAX)
                return -1;
            
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};