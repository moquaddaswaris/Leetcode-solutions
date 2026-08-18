class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        //sorting the array in descending order
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double maxTime = 0;

        //eg. cars = {
        //     {10, 12.5},
        //     {8, 15.2},
        //     {3, 20.0}
        // };
        for (auto& car : cars) {
            double time = car.second;
            if (time > maxTime) {
                fleets++;
                maxTime = time;
            }
        }

        return fleets;
    }
};