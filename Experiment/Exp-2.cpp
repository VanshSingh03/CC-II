#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;

    int n = nums.size();

    // Sorting the array
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
        // Skiping duplicate elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                long long sum = (long long)nums[i] +
                                nums[j] +
                                nums[left] +
                                nums[right];

                if (sum == target)
                {
                    result.push_back(
                    {
                        nums[i],
                        nums[j],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    while (left < right &&
                           nums[left] == nums[left - 1])
                        left++;

                    while (left < right &&
                           nums[right] == nums[right + 1])
                        right--;
                }

                else if (sum < target)
                {
                    left++;
                }

                else
                {
                    right--;
                }
            }
        }
    }

    return result;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;

    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> ans = fourSum(nums, target);

    if (ans.empty())
    {
        cout << "\nNo quadruplets found.";
    }
    else
    {
        cout << "\nUnique Quadruplets are:\n";

        for (auto quad : ans)
        {
            cout << "[ ";

            for (int x : quad)
                cout << x << " ";

            cout << "]" << endl;
        }
    }

    return 0;
}
