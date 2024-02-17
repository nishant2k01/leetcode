class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> ump;
        for(auto it:arr) ump[it]++; 
        vector<pair<int,int>> ele;

        for(auto it:ump){
            ele.push_back({it.second,it.first});
        }

        sort(ele.begin(),ele.end()); 
        
        int ans=ump.size(); 

        for(auto it:ele){
            int freq=it.first; 
            if(freq<=k){
                k-=freq;
                ans--;
            }
            else{   
                k=0;
                break;
            }
        }
        return ans;
    }
};