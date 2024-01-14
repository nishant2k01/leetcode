class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size()!= s2.size())return false;
        vector<int>freqw1(26,0),freqw2(26,0);
        vector<int>countw1(26,0),countw2(26,0);
        for(char c : s1)
        {
            freqw1[c-'a']++;
            countw1[c-'a'] = 1 ;
        }
        for(char c : s2)
        {
            freqw2[c-'a']++;
            countw2[c-'a'] = 1 ;
        }
        sort(freqw2.begin(),freqw2.end());
        sort(freqw1.begin(),freqw1.end());
        if(freqw1 == freqw2 &&countw1 == countw2 )return true;
        else{
            return false;
        }
    }
};