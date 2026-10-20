class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            graph[u].push_back({v, price});
        }

        vector<int>dist(n, INT_MAX);
        dist[src] = 0;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, src});

        while(!q.empty()){
            auto [stops, cost, node] = q.front();
            q.pop();

            if(stops > k){
                continue;
            }

            for(auto edge : graph[node]){
                int next = edge.first;
                int price = edge.second;

                int newCost = cost + price;

                if(newCost < dist[next]){
                    dist[next] = newCost;
                    q.push({stops + 1, newCost, next});
                }
            }
        }        
        
        return dist[dst] == INT_MAX? -1 : dist[dst];
    }
};