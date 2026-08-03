class Solution {
public:
    int solve(vector<int>& heights, int left, int right) {
        if (left > right)
            return 0;

        int minIndex = left;

        for (int i = left; i <= right; i++) {
            if (heights[i] < heights[minIndex])
                minIndex = i;
        }

        int area = heights[minIndex] * (right - left + 1);

        int leftArea = solve(heights, left, minIndex - 1);
        int rightArea = solve(heights, minIndex + 1, right);

        return max(area, max(leftArea, rightArea));
    }

    int largestRectangleArea(vector<int>& heights) {
        return solve(heights, 0, heights.size() - 1);
    }
};