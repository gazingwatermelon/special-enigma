class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string refer = accounts[i][j];
                for(int l = i+1; l<n; l++){
                    for(int k=1; k<accounts[l].size(); k++){
                        if(refer ==  accounts[l][k]){
                            adj[i].push_back(l);
                            adj[l].push_back(i);
                        }
                    }
                }
            }
        }
        // cout<<\num = \<<n<<endl;

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<adj[i].size(); j++){
        //         cout<<adj[i][j]<<\ \;
        //     }
        //     cout<<endl;
        // }

        vector<vector<string>> ans;

        vector<int> visited(n, 0);

        for(int i=0; i<n; i++){
            queue<int> q;
            vector<string> holds;
            if(visited[i]==0){
                q.push(i);
                holds.push_back(accounts[i][0]);
                visited[i] = 1;
            }
            else continue;
            set<string> st;
            while(!q.empty()){
                int loc = q.front();
                q.pop();
                for(int j=1; j<accounts[loc].size(); j++){
                    st.insert(accounts[loc][j]);
                }

                for(auto it : adj[loc]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }

            vector<string> comb;
            for(auto it : st){
                comb.push_back(it);
            }
            sort(comb.begin(), comb.end());
            for(int a=0; a<comb.size(); a++){
                holds.push_back(comb[a]);
            }

            ans.push_back(holds);
        }

        return ans;
    }
};