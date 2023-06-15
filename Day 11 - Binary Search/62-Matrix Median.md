### [Matrix Median](https://www.codingninjas.com/codestudio/problems/matrix-median_8230735?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force Approach
```cpp
#include<algorithm>

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> mat_array;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) mat_array.push_back(matrix[i][j]);
    }
    sort(mat_array.begin(), mat_array.end());
    return mat_array[(n*m)/2];
}
/*
TC: O(N*M*log(N*M))
SC: O(N*M)
*/
```

#### Optimized Approach
```cpp
#include<algorithm>

int countSmaller(vector<int> &arr, int num){
    int l = 0, h = arr.size()-1;
    while(l <= h){
        int mid = (l + (h-l)/2);
        if(arr[mid] > num){
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    return l; // return the index of the first element greater than num
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int l = 1, h = 1e5;

    while(l <= h){
        int mid = (l + (h-l)/2); 
        int smallerCount = 0; // count of elements smaller than mid
        for(auto row: matrix) 
            smallerCount += countSmaller(row, mid);
        if(smallerCount <= (n*m)/2) l = mid+1; // if smallerCount <= (n*m)/2, search in the right half
        else h = mid-1; // if smallerCount > (n*m)/2, search in the left half
    }

    return l;
}
/*
TC: O(N*log(M)*log(1e5))
SC: O(1)
*/
```

### Better Approach
```cpp
#include<algorithm>

int countSmaller(vector<int> &arr, int num){
    int l = 0, h = arr.size()-1;
    while(l <= h){
        int mid = (l + (h-l)/2);
        if(arr[mid] > num){
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int maxi = matrix[0][0];
    for(auto r: matrix){
        for(auto i: r) maxi = max(i, maxi);
    }
    int l = 1, h = maxi;

    while(l <= h){
        int mid = (l + (h-l)/2);
        int smallerCount = 0;
        for(auto row: matrix) 
            smallerCount += countSmaller(row, mid);
        if(smallerCount <= (n*m)/2) l = mid+1;
        else h = mid-1;
    }

    return l;
}
/*
TC: O(N*log(M)*log(maxi) + N*M)
SC: O(1)
*/
```