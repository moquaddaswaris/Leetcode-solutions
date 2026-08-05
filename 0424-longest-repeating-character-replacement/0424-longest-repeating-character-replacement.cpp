class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int length = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);
        while(right<s.size()){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int windowSize = right - left + 1;
            if(windowSize - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }

            length = max(length, right - left + 1);
            right++;
        }

        return length;
    }
};