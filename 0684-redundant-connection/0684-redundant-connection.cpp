class Solution {
public:
    vector<int>par;
    vector<int>rank;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        par.resize(n+1);
        rank.resize(n+1, 1);

        for(int i = 0; i < n; i++){
            par[i] = i;
        }

        for(auto edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];

            if(!unionR(n1, n2)){
                return {n1, n2};
            }
        }

        return {};
    }
private:
    bool unionR(int n1, int n2){
        int p1 = find(n1);
        int p2 = find(n2);

        if(p1 == p2)
            return false;

        if(rank[p1] > rank[p2]){
            par[p2] = p1;
            rank[p2] += rank[p1];
        }else{
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        
        return true;
    }
    int find(int n){
        if(par[n] == n)
            return n;

        return par[n] = find(par[n]);
    }
};