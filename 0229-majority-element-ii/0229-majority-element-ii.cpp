class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int elem1 = 0, elem2 = 0,
        count1 = 0, count2 = 0;
        
        for(int num: nums){
            if(num == elem1) count1 ++;
            else if(num == elem2) count2++;

            else if(count1 == 0){
                elem1 = num;
                count1 = 1;
            }
            else if(count2 == 0){
                elem2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        // manual checking the counts.
        count1 = 0;
        count2 = 0;
        for(int num: nums){
            if(num == elem1) count1++;
            else if(num == elem2) count2++;
        }
        
        if(count1 > nums.size()/3) ans.push_back(elem1);
        if(count2 > nums.size()/3) ans.push_back(elem2);

        return ans;
    }
};