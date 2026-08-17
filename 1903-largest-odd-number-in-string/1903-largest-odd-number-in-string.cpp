class Solution {
public:
    string largestOddNumber(string num) {
        string s = "";
        while (!num.empty()) {
            if ((num.back() - '0') % 2 != 0) {
                s = num;
                break;
            } else {
                num.pop_back();
            }
        }
        return s;
    }
};