class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target){
    //Brute force solution T.C = O(n^2)
    //     for(int i = 0; i < nums.size(); i++){
    //         for(int j = i + 1; j < nums.size(); j++){
    //             if(nums[i] + nums[j] == target){
    //                 return {i, j};
    //             }
    //         }
    //     }
    //     return {};

    map<int, int> valMap;
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        int first = nums[i];
        int second = target-first;

        if(valMap.find(second)!=valMap.end()){
            ans.push_back(i);
            ans.push_back(valMap[second]);
            break;
        }

        valMap[first] = i; //Add value to the hashmap
    }
    return ans;
    }
};
