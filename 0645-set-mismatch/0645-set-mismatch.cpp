class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans(2);
        
        map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]-1]++;
        }
         for(int i=0;i<n;i++){
            if(mpp[i]==0){
                ans[1]=i+1;
            }
            if(mpp[i]==2){
                ans[0]=i+1;
            }
        }
        return ans;
    }
};