class Solution {
public: 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(const string &str : strs){
            string key = str;
            sort(key.begin(), key.end()); //sort the value for key

            mp[key].push_back(str);
        }

        for (const auto &x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};