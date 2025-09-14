#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//this is the clasical way which everyone can think off
/*class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int i=0;
        while(temp != NULL){
            temp = temp->next;
            i++;
        }

        if(i%2 != 0){
            int odd = (i+1)/2;
            ListNode* temp1 = head;
            for(int i=0; i<odd-1; i++){
                temp1 = temp1->next;
            }
            return temp1;
        }
        else{
            int even = i/2 + 1;
            ListNode* temp2 = head;
            for(int i=0; i<even-1; i++){
                temp2 = temp2->next;
            }
            return temp2;
        }
    }
};
*/
 //but there is an another way called SLOW FAST POINTER approch
class Solution{
public:
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};