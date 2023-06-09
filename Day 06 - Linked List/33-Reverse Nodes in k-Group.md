### [Reverse Nodes in k-Group](https://www.codingninjas.com/codestudio/problems/reverse-nodes-in-k-group_8230709?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

// return head of reversed LL, next node of current node, tail of reversed LL
vector<Node*> reverseGroupOfK(Node* head,int k){
  if(!head) //if head is null
    return {NULL, NULL, NULL};

  if(!head->next) return {head,NULL,head}; //if only one node is present

  Node* temp = NULL; //to store the head of reversed LL
  Node* tail = head; //to store the tail of reversed LL
  Node* next = NULL; //to store the next node of current node

  //reverse k nodes
  for(int i = k; i>=1 and head ; i--)
  {
    next = head->next;
    head->next = temp;
    temp = head;
    head = next;
  }

  return {temp, next, tail};
}



Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(!head || !head->next)return head;

    Node* dummy = new Node(-1);
    Node* ans = dummy;
	  Node* temp = head; //to store the head of current LL

    for(int i = 0; i < n; i++)
    {
      if(b[i] == 0){
        continue;
      }

      vector<Node*> p;
      //temp will ne null if we have reached the end of LL
      if(temp) //if temp is not null
        p = reverseGroupOfK(temp,b[i]);
      else break;

      //p has head of reversed LL at 0, next node of current node 1, tail of reversed LL 2
      dummy->next = p[0]; //head of reversed LL
      temp = p[1];
      dummy = p[2];
    }

    if(temp)dummy->next = temp;
    return ans->next;

    /*
    Time Complexity: O(N * max(b[i])) 
    Space Complexity: O(3)
    */
}
```

### [LeetCode - Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(!head or !head->next) return head;

      ListNode* dummy = new ListNode(-1); //dummy node which will point to head
      dummy->next = head;

      //find length of LL
      int len=0;
      ListNode* temp = head;
      while(temp) len++, temp = temp->next;

      ListNode * pre = dummy; //pre will point to the node before the active part
      ListNode * headOfActivePart = NULL; //head of active part of LL
      ListNode * next = NULL; //next node of current node

      //reverse k nodes
      while(len >= k){
        headOfActivePart = pre->next; //head of active part of LL
        next = headOfActivePart->next; //next node of current node

        for(int i = 1; i < k; i++){
          headOfActivePart->next = next->next; //head of active part will point to next of next node
          next->next = pre->next; //next node will point to the node before the active part
          pre->next = next; //pre will point to next node
          next = headOfActivePart->next; //next node will be the next node of current node
        }
        pre = headOfActivePart; //pre will point to the node before the active part
        len -= k;
      }

      return dummy->next;
    }
};
```
