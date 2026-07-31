#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
{
    vector<pair<int, int>> engineers;

    // Storing (efficiency, speed)
    for (int i = 0; i < n; i++)
    {
        engineers.push_back({efficiency[i], speed[i]});
    }

    // efficiency in descending order
    sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());

    priority_queue<int, vector<int>, greater<int>> minHeap;

    long long speedSum = 0;
    long long maxPerformance = 0;

    for (auto engineer : engineers)
    {
        int currentEfficiency = engineer.first;
        int currentSpeed = engineer.second;

        // If team size exceeds k, removeing engineer
        if (minHeap.size() == k)
        {
            speedSum -= minHeap.top();
            minHeap.pop();
        }

        // Adding new engineer
        minHeap.push(currentSpeed);
        speedSum += currentSpeed;

        // Calculating performance
        long long performance = speedSum * currentEfficiency;

        if (performance > maxPerformance)
            maxPerformance = performance;
    }

    return maxPerformance;
}

int main()
{
    int n;

    cout << "Enter number of engineers: ";
    cin >> n;

    vector<int> speed(n), efficiency(n);

    cout << "\nEnter speed of each engineer:\n";
    for (int i = 0; i < n; i++)
        cin >> speed[i];

    cout << "\nEnter efficiency of each engineer:\n";
    for (int i = 0; i < n; i++)
        cin >> efficiency[i];

    int k;

    cout << "\nEnter maximum team size (k): ";
    cin >> k;

    long long answer = maxPerformance(n, speed, efficiency, k);

    cout << "\nMaximum Team Performance = " << answer << endl;

    return 0;
}