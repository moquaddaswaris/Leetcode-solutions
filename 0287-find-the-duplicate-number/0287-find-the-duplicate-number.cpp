class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        //tortoise algo using an imaginary LL
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        //find the start point of the cycle
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};