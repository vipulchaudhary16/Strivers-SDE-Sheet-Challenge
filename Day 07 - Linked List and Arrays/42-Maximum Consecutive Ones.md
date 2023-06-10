### [Maximum Consecutive Ones](https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_8230736?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
int longestSubSeg(vector<int> arr , int n, int k) {
    int i=0,j=0;
    for(i=0;i<n;i++){
        if(arr[i]==0) k--;
        if(k<0 && arr[j++]==0)k++;
    }
    return i-j;
    /*
    TC: O(n)
    SC: O(1)
}
```