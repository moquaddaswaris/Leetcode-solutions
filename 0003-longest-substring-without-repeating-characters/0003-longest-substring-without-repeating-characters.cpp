class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int length = 0;

        unordered_set<char> st;
        while (right<s.size()) {
            if (st.find(s[right]) == st.end()){
                st.insert(s[right]);
                length = max(length, right - left + 1);
                right++;
            }
            else {
                st.erase(s[left]);
                left++;
            }
        }

        return length;
    }
};