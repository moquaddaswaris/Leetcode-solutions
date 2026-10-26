class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;

        for(int num: nums){
            if(num==1){
                count++;
                maxCount = max(count, maxCount);
            }
            else if(num==0) count = 0;
        }

        return maxCount;
    }
};