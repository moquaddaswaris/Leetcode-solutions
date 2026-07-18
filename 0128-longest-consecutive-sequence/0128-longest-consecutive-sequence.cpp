class Solution {
public:
    bool linearSearch(vector<int>& nums, int target) {
        for (int x : nums) {
            if (x == target)
                return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums){
    //Brute force 
    //     int n = nums.size();
    //     int longest = 0;

    //     for(int i=0; i<n; i++){
    //         int current = nums[i];
    //         int count = 1;

    //         while(linearSearch(nums, current + 1)){
    //             current++;
    //             count++;
    //         }

    //         longest = max(longest,count);
    //     }

    //     return longest;

    //Optimal solution
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for(int val: st){
            if(!st.count(val-1)){
                int current = val;
                int length = 1;

                while(st.count(current + 1)){
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};