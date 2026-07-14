class Solution {
public:
    bool isPalindrome(string s) {
        for (char &c : s) {
            c = tolower(c);
        }

        // remove non-alphanumeric characters
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);   // remove if NOT alphanumeric
        }), s.end());

        // check palindrome
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
};
