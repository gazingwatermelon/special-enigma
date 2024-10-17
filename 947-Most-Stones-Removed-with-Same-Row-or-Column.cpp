class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(auto it : adj[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }

        int count = 0;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                q.push(i);
                visited[i] = 1;
                count++;
            }

            while(!q.empty()){
                int val = q.front();
                q.pop();
                for(auto it : adj[val]){
                    if(visited[it]==0){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }

        return n-count;
    }
};