class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Bucket where index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        // Place numbers into their frequency bucket
        for (auto &x : freq) {
            bucket[x.second].push_back(x.first);
        }

        vector<int> ans;

        // Traverse buckets from highest frequency to lowest
        for (int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};