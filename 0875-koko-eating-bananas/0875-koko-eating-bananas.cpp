class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //range of the eating banana speed
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low<=high){
            int mid = (low+high)/2;

            //total hours to eat all the bananas with the speed of k or mid
            long long totalHours = 0;
            for(int pile: piles){
                totalHours += (pile + mid - 1)/mid;
            }

            if(totalHours <= h) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};