class Solution {
public:
    bool isPalindrome(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++; j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0; i<s.size(); ++i){
            for(int j=i; j<s.size(); ++j){
                if(isPalindrome(s.substr(i,j-i+1))){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};