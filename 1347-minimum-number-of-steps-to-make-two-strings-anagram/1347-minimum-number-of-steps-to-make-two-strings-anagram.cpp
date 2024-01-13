class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sArr(26, 0);
        vector<int> tArr(26, 0);

        for (char ch : s) sArr[ch - 'a']++;
        for (char ch : t) tArr[ch - 'a']++;

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (sArr[i] > 0) {
                if (sArr[i] > tArr[i]) ans += sArr[i] - tArr[i];
            }
        }
        return ans;
    }
};