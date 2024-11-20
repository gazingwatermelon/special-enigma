class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(k>n) return ans;

        priority_queue<int> pq1;
        priority_queue<int> pq2;

        for(int i=0; i<k-1; i++){
            pq1.push(nums[i]);
        }
        
        for(int i=0; i<n-k+1; i++){
            pq1.push(nums[i+k-1]);
            ans.push_back(pq1.top());
            pq2.push(nums[i]);

            while(!pq2.empty() && pq1.top()==pq2.top()){
                pq1.pop(); pq2.pop();

            }
        }

        return ans;
    }
};