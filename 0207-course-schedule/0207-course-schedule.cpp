class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>graph(numCourses);
       vector<int> indegree(numCourses);

       for(auto& edge : prerequisites){
            int course = edge[0];
            int prerequisite = edge[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
       }

       queue<int>q;

       for(int i = 0; i< numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
       }

       int count = 0;

       while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;

            for(int next : graph[course]){
                indegree[next]--;

                if(indegree[next] == 0)
                    q.push(next);
            }
       }

        return count == numCourses;
    }
};