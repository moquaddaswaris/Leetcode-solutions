class Solution {
public:
    bool isAnagram(string s, string t) {
        
    if(s.length()!=t.length()){
        return false;
    }
    else{
        vector<int> count(26,0); //Create a list of alphabets and increase the count when found

        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++; //Increase the count array at given position
            count[t[i]-'a']--; //Decrease the count array at given position
        }

        for(int i : count){
            if(i!=0){
                return false;
            }
        }
        return true;

    }
}
};