### [Count Inversions](https://www.codingninjas.com/codestudio/problems/count-inversions_8230680?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

void merge(long long * arr, long long temp[], int left, int mid, int right, int &ans){
    int i = left;
    int j = mid;
    int k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            // here we are adding the number of elements that are remaining in the left subarray
            ans = ans + (mid - i); // this is the only line that is different from merge sort
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
}

void mergeSort(long long * arr, long long temp[], int left, int right, int &ans){
    if(left < right){
        int mid = (right+left)/2;
        mergeSort(arr,temp, left, mid, ans);
        mergeSort(arr,temp, mid+1, right, ans);
        merge(arr, temp , left, mid+1, right, ans);
    }
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int ans = 0;
    long long  temp[n];
    mergeSort(arr, temp, 0, n-1, ans);
    return ans;

    /*
    TC: O(nlogn)
    SC: O(n)
    */
}
```