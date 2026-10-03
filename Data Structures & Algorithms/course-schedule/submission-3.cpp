class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<prerequisites.size();i++){
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];

            mp[bi].push_back(ai);
            indegree[ai] += 1;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int finished = 0;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            finished += 1;

            vector<int> children = mp[f];
            for(int i=0;i<children.size();i++){
                indegree[children[i]] -= 1;
                if(indegree[children[i]] == 0){
                    q.push(children[i]);
                }
            }
        }
        return finished == numCourses;
    }
};
