class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //vector<int> answer(n, 1); //[1,1,...]
    
        // for(int i=1;i<n;i++){
        //     answer[i] = answer[i-1]*nums[i-1];
        // }

        // int suffix = 1;
        // for (int i=n-1; i>= 0; i--) {
        //     answer[i] *= suffix;
        //     suffix *= nums[i];
        // }

        //Better solution.
        int n = nums.size();
        vector<int> left(n, 1);
        for(int i=1; i<n; i++){
            left[i] = left[i - 1] * nums[i - 1];
        }

        vector<int> right(n, 1);
        for(int i=n-2; i>=0; i--){
            right[i] = right[i + 1] * nums[i + 1];
        }

        vector<int> answer(n);
        for(int i=0;i<n;i++){
            answer[i] = left[i]*right[i];
        }
        return answer;
    }
};