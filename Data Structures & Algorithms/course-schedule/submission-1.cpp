class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        int finished = 0;
        vector<int> indegree(numCourses,0);

        for(int i=0;i<prerequisites.size();i++){
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];

            mp[bi].push_back(ai);
            indegree[ai]+=1;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            finished += 1;

            vector<int> children = mp[node];
            for(int i=0;i<children.size();i++){
                indegree[children[i]]--;
                if(indegree[children[i]] == 0){
                    q.push(children[i]);
                }
            }
        }

        return finished == numCourses;
    }
};
