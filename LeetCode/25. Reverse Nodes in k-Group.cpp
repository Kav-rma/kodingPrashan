#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count=0;
        
        //check if k nodes exist.
        while(count<k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            count++;
        }

        //recursive call for rest of the list.
        ListNode* prevNode = reverseKGroup(temp,k);

        temp = head;
        count = 0;

        while(count<k){
            ListNode* n_next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = n_next;
            count++;
        }

        return prevNode;
    }
};