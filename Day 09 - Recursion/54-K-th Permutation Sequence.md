### [K-th Permutation Sequence](https://www.codingninjas.com/codestudio/problems/k-th-permutation-sequence_8230822?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
string kthPermutation(int n, int k) {
    vector<int> numbers;
    int fact = 1; //there will be n! possible permutation
    for(int i = 1; i < n; i++){
        fact *= i;
        numbers.push_back(i); 
    }
    numbers.push_back(n); 
    k -= 1;
    string ans = "";
    
    while(true){
        ans += to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + k/fact); //remove the number from the list
        if (numbers.size() == 0) break; //if all numbers are used, break
        k %= fact;  //update k
        fact /= numbers.size();  //update fact
    }
    
    return ans;
}
/*
TC: O(n^2)
SC: O(n)
*/

```