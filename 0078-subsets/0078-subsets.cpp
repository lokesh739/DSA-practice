class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        int subset=1<<n;
        for(int num=0;num<subset;num++){
            vector<int> ll;
            for(int i=0;i<n;i++){
                if(num&(1<<i)){
                    ll.push_back(nums[i]);
                }
            }
            ans.push_back(ll);
        }
        return ans;
    }
};