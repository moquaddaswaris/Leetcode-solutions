class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> divisors;

        int x = num;
        for(int i=1; i<=num/2; i++){
            if(num%i == 0) divisors.push_back(i);
        }

        int sum = 0;
        for(int num: divisors) sum += num;
        return sum == num;
    }
};