#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// finding the largest rectangle area
int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();
    int maxArea = 0;

    // taking the smallest bar
    for (int i = 0; i < n; i++)
    {
        int left = i;
        int right = i;

        // towards left
        while (left > 0 && heights[left - 1] >= heights[i])
        {
            left--;
        }

        // towards right
        while (right < n - 1 && heights[right + 1] >= heights[i])
        {
            right++;
        }

        // Calculating width and area
        int width = right - left + 1;
        int area = heights[i] * width;

        // find maximum area
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{
    int n;

    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights of bars:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    int result = largestRectangleArea(heights);

    cout << "\nLargest Rectangle Area = " << result << endl;

    return 0;
}