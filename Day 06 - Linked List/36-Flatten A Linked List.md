### [Flatten A Linked List](https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_8230827?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
Node * merge2_LL(Node *a, Node *b){
  Node * temp = new Node(0);
  Node * res = temp;
  
  while(a and b){
      if(a -> data < b -> data){ //if a is smaller
          temp -> child = a;
          a = a -> child;
      } else { //if b is smaller
          temp -> child = b;
          b = b -> child; 
      }
      temp = temp -> child;
  }
      
  if(a) temp -> child = a; 
  else temp -> child = b;
  return res -> child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL) return head;
	Node* root = head->next;
	head->next = NULL;
	root = flattenLinkedList(root);
	head = merge2_LL(head, root);
	return head;
  /*
  Time Complexity: O(N)
  Space Complexity: O(1)
  */
}
```