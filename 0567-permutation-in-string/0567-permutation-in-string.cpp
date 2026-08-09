class Solution {
public:
    bool checkInclusion(string s1, string s2){
        if (s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int windowSize = s1.size();

        for(char ch: s1){
            freq1[ch -'a']++;
        }
        for (int i=0; i<windowSize; i++) {
            freq2[s2[i] -'a']++;
        }

        if (freq1 == freq2) return true;
        
        for (int right = windowSize; right < s2.size(); right++) {
            freq2[s2[right] - 'a']++;
            freq2[s2[right - windowSize] - 'a']--;

            if (freq1 == freq2) return true;
        }

        return false;
    }
};