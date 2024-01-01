class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        // Initialize two pointers i and j to iterate on g and s
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            // If the size of the cookie is greater than or equal to the child's greed,
            // assign the cookie to the child and move both pointers
            if (g[i] <= s[j]) {
                count++;
                i++;
            }
            // Move the cookie pointer to the next cookie, regardless of assignment
            j++;
        }
        return count;
    }
};