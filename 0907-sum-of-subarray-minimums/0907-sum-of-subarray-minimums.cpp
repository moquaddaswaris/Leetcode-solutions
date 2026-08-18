class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const long long MOD = 1e9 + 7;

        vector<int> prev(n);
        vector<int> next(n);

        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            st.push(i);
        }

        // Calculate contribution
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            long long contribution = (arr[i] * left % MOD) * right % MOD;
            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};