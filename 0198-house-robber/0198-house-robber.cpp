class Solution {
public:
    int rob(vector<int>& nums) {
        int maxi = INT_MIN;
        int n=nums.size();
        vector<int>ans(n,0);
        if(n==1) return nums[0];
       
        ans[0]=nums[0];
        ans[1]=(max(nums[0],nums[1]));
    
        for(int i=2;i<n;i++){
            maxi=max(ans[i-1],nums[i]+ans[i-2]);
            ans[i]=maxi;
        }
        return ans[n-1];
    }
};
