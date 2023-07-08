### [Maximum Path Sum Between Two Leaves](https://www.codingninjas.com/studio/problems/maximum-path-sum-between-two-leaves_8230713?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
long long int solve(TreeNode<int> *root, long long int &maxi) {
    if (!root) return 0;

    long long int ls = max((long long int) 0, solve(root->left, maxi));
    long long int rs = max((long long int) 0, solve(root->right, maxi));
    long long int currSum = root->val + ls + rs;
    
    maxi = max(maxi, currSum);
    return root->val + max(ls, rs);
}

long long int findMaxSumPath(TreeNode<int> *root) {
    if(!root) return -1;
    if(!root->left || !root->right) return -1;
    long long int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
}

```