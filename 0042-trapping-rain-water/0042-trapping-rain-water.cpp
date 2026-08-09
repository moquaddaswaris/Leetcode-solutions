class Solution {
public:
    int trap(vector<int>& height) {
        int leftWall = 0;
        int rightWall = 0;
        int rainUnit = 0;

        vector<int> maxL(height.size(), 0);
        vector<int> maxR(height.size(), 0);

        for (int i = 0; i < height.size(); i++) {
            int j = height.size() - i - 1;

            maxL[i] = leftWall;
            maxR[j] = rightWall;

            leftWall = max(leftWall, height[i]);
            rightWall = max(rightWall, height[j]);
        }

        for (int i = 0; i < height.size(); i++) {
            int waterPotential = min(maxL[i], maxR[i]);
            rainUnit +=  max(0, waterPotential - height[i]);
        }

        return rainUnit;
    }
};