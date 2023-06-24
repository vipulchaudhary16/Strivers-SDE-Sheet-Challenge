### [Maximum XOR With an Element From Array](https://www.codingninjas.com/studio/problems/maximum-xor-with-an-element-from-array_8230839?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node*child[2];
    Node(int data){
        this->data = data;
        for(int i = 0;i<2;i++){
            child[i] = NULL;
        }
    }
};

class Trie{
    public:
    Node *root;
    Trie(){
        root = new Node('\0');
    }
    void insert(int num){  
        Node *prev = root;
        for(int i = 31;i>=0;i--){ 
            int bit = (num>>i)&1;
            Node*child;
            if(prev->child[bit]== NULL){
                child = new Node(bit);
                prev->child[bit] = child; 
            }
            else{
                child = prev->child[bit];
            }
            prev = child;
        }
    }

    int find_max(int num){
        int val = 0;
        Node *prev = root;
        for(int i = 31;i>=0;i--){
            int bit = (num>>i)&1;
            Node *child;
            if (bit & 1){
                if(prev->child[0]){ 
                    child = prev->child[0];/
                    val = val |(1<<i); 
                }
                else{
                    child = prev->child[1];
                }
            } 
            else{ // bit is 0
                if(prev->child[1]){
                    child = prev->child[1];
                    val = val |(1<<i);
                }
                else{
                    child = prev->child[0];
                }
            }
            prev = child;
        }
        return val;
    }
};



vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie t;
	sort(arr.begin(),arr.end());
	vector<pair<int,pair<int,int>>> offlineQuery;
	int q = queries.size();
	for(int i = 0;i<q;i++){
		offlineQuery.push_back({queries[i][1],{queries[i][0],i}}); 
	}
	sort(offlineQuery.begin(),offlineQuery.end());
	vector<int>ans(q,0); 

	int idx = 0;
	for(int i = 0;i<offlineQuery.size();i++){
		int ai = offlineQuery[i].first;
		int xi = offlineQuery[i].second.first;
		int qindex = offlineQuery[i].second.second;
		while(idx<arr.size() && arr[idx]<=ai){
			t.insert(arr[idx]);
			idx++; 
		}
        if(idx == 0){
            ans[qindex] = -1;
        }
        else{
            ans[qindex] = t.find_max(xi); 
        }
	}
	return ans;
}

```