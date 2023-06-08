### [Cycle Detection in a Singly Linked List](https://www.codingninjas.com/codestudio/problems/cycle-detection-in-a-singly-linked-list_8230683?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force Approach:
```cpp
#include<bits/stdc++.h>

bool detectCycle(Node *head)
{
	//	Write your code here
    unordered_set<Node *> st;
    Node * temp = head;
    while(temp){
        if(st.count(temp)) return true;
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
```

#### Floyd's Cycle Detection Algorithm:
```cpp
#include<bits/stdc++.h>

bool detectCycle(Node *head)
{
    Node * slow = head, * fast = head;
    
    while(1){
        if(!slow || !fast || !fast->next) return false; //no cycle
        slow = slow->next;
        fast = fast ->next->next;
        if(slow == fast) return true; //cycle
    }

    return false;
}
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
```