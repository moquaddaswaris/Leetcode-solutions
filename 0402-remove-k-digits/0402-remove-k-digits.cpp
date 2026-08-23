class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        if(k >= num.size()) return "0";
        for (char ch: num){
            int digit = ch - '0';
            while(!st.empty() && k!=0 && digit<st.top()){
                st.pop();
                k--;
            }

            st.push(digit);
        }
        while(k!=0){
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        //remove leading zeros
        int i = 0;
        while (i<ans.size() && ans[i] == '0'){
            i++;
        }
        ans = ans.substr(i);

        if(ans.empty()) return "0";
        return ans;
    }
};