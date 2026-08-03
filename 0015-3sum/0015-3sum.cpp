class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i]>0) break;
            else if(i>0 && nums[i]==nums[i-1]) continue; //If the value is same as previos value so we continue the loop to avoid the duplicates

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    //Avoiding dupliactes
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[j] == nums[j-1]) k--;
                }
            }
        }

        return ans;
    }
};
