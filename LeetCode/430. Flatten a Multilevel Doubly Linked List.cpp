#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        Node * curr = head;

        while(curr != NULL){
            if(curr->child != NULL){
                Node * n_next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;

                while(curr->next != NULL){
                curr = curr->next;
                }

                if(n_next != NULL){
                    curr->next = n_next;
                    n_next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};