#include <cmath>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        int sum = 0;
        int digitNumber = 0;
        int x = n;

        if(n == 0) return true;

        while(x > 0){
            x = x / 10;
            digitNumber++;
        }

        x = n;
        while(x > 0){
            sum = sum + pow(x % 10, digitNumber);
            x = x / 10;
        }

        return sum == n;
    }
};