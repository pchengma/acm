// LeetCode: 11. Container With Most Water (Medium)
class Solution {
public:
    int maxArea(vector<int> &height) {
        // leftmost line
        int left = 0;
        // rightmost line
        int right = height.size() - 1;

        // container area
        int area = 0;

        // Greedy strategy: current area is the max area which is the best choice of current (right - left)
        // Decrease (right - left) and increase bottleneck line to find possible larger area (locally optimal solution)
        // Each time, replace the max area if new area is larger
        // Terminate when reaching the same line
        while (left < right) {
            // Get shorter line:
            if (height[left] < height[right]) {
                // Get max area:
                area = max(area, (right - left) * height[left]);
                // If left line is shorter, then move right to find a higher left line for a larger area:
                ++left;
            } else {
                // Get max area
                area = max(area, (right - left) * height[right]);
                // If right line is shorter, then move left to find a higher right line for a larger area:
                --right;
            }
        }

        return area;
    }
};