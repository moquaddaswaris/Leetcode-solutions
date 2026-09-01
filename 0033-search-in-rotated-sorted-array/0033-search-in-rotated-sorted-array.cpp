class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left<=right){
            int mid = (right+left)/2;
            if(nums[mid]==target) return mid;

            //you are at left sorted portion
            if(nums[left] <= nums[mid]){
                if(nums[left]<=target && target<nums[mid]) right = mid-1;
                else left = mid+1;
            }
            //you are at right sorted portion
            else{
                if(nums[mid]<target && target<=nums[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};