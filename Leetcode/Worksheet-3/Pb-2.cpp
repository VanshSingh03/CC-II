#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();

    vector<int> left(n);
    vector<int> right(n);

    stack<int> st;

    // Previous Smaller Element
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            st.pop();
        }

        if(st.empty())
            left[i]=-1;
        else
            left[i]=st.top();

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    // Next Smaller Element
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            st.pop();
        }

        if(st.empty())
            right[i]=n;
        else
            right[i]=st.top();

        st.push(i);
    }

    int maxArea=0;

    for(int i=0;i<n;i++)
    {
        int width=right[i]-left[i]-1;

        int area=width*heights[i];

        maxArea=max(maxArea,area);
    }

    return maxArea;
}

int main()
{
    int n;

    cout<<"Enter number of bars: ";
    cin>>n;

    vector<int> heights(n);

    cout<<"Enter heights:\n";

    for(int i=0;i<n;i++)
        cin>>heights[i];

    cout<<"\nLargest Rectangle Area = "
        <<largestRectangleArea(heights);

    return 0;
}
