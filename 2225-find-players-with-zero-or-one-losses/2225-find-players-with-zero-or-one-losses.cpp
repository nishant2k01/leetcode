class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>res;
        vector<int>win,lost;
        map<int,pair<int,int>>maps;
        for(auto &k:matches){
            maps[k[0]].first++;
            maps[k[1]].second++;
        }
        for(auto &k:maps){
            if(k.second.second==0){
                win.push_back(k.first);
            }else if(k.second.second==1)
                lost.push_back(k.first);
        }
        sort(win.begin(),win.end());
        sort(lost.begin(),lost.end());
        res.push_back(win);
        res.push_back(lost);

        return res;
    }
};