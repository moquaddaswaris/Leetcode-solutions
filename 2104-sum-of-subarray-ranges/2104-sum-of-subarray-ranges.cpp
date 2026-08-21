class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        // previous and next smaller element
        vector<int> prevSmallest(n);
        vector<int> nextSmallest(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (st.empty()) prevSmallest[i] = -1;
            else prevSmallest[i] = st.top();

            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) nextSmallest[i] = n;
            else nextSmallest[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }

        // previous and next largest Element
        vector<int> prevLargest(n);
        vector<int> nextLargest(n);
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()) prevLargest[i] = -1;
            else prevLargest[i] = st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()) nextLargest[i] = n;
            else nextLargest[i] = st.top();
            st.push(i);
        }

        long long minSum = 0;
        long long maxSum = 0;
        for (int i = 0; i < n; i++) {
            long long leftMin = i - prevSmallest[i];
            long long rightMin = nextSmallest[i] - i;
            minSum += nums[i] * leftMin * rightMin;

            long long leftMax = i - prevLargest[i];
            long long rightMax = nextLargest[i] - i;
            maxSum += nums[i] * leftMax * rightMax;
        }
        return maxSum - minSum;
    }
};