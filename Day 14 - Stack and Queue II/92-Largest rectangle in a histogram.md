### [Largest rectangle in a histogram](https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_8230792?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### Brute force

```cpp
 int largestRectangle(vector < int > & heights) {
  int n = heights.size();
  int maxArea = 0;

  for (int i = 0; i < n; i++) {
    int minHeight = heights[i];

    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, heights[j]);
      int width = j - i + 1;
      int area = width * minHeight;
      maxArea = max(maxArea, area);
    }
  }

  return maxArea;
 }
 /*
  TC: O(n^2)
  SC: O(1)
  */
```

#### optimized

```cpp
#include<stack>

 int largestRectangle(vector < int > & heights) {
  int n = heights.size();
  stack < int > st;
  int leftsmall[n], rightsmall[n];
  for (int i = 0; i < n; i++) {
    while (!st.empty() && heights[st.top()] >= heights[i]) {
      st.pop();
    }
    if (st.empty())
      leftsmall[i] = 0;
    else
      leftsmall[i] = st.top() + 1;
    st.push(i);
  }
  while (!st.empty())
    st.pop();

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && heights[st.top()] >= heights[i])
      st.pop();

    if (st.empty())
      rightsmall[i] = n - 1;
    else
      rightsmall[i] = st.top() - 1;

    st.push(i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
  }
  return ans;
 }
/*
TC: O(n)
SC: O(n)
*/
```
