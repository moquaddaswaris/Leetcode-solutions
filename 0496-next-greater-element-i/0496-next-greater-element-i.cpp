class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> mp;
        stack<int> st;

        // nums1 value -> index
        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                int idx = mp[st.top()];
                ans[idx] = num;
                st.pop();
            }

            // Only push elements that exist in nums1
            if (mp.find(num) != mp.end()) {
                st.push(num);
            }
        }

        return ans;
    }
};