class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int left = 0;
        // int right = 0;
        // int length = 0;

        // unordered_set<char> st;
        // while (right<s.size()){
        //     if (st.find(s[right]) == st.end()){
        //         st.insert(s[right]);
        //         length = max(length, right - left + 1);
        //         right++;
        //     }
        //     else {
        //         st.erase(s[left]);
        //         left++;
        //     }
        // }

        // return length;

        //More efficient solution
        vector<int> last(256, -1);
        int left = 0;
        int length = 0;

        for(int right = 0; right < s.size(); right++) {
            if(last[s[right]] >= left) {
                left = last[s[right]] + 1;
            }

            last[s[right]] = right;
            length = max(length, right - left + 1);
        }

        return length;
    }
};