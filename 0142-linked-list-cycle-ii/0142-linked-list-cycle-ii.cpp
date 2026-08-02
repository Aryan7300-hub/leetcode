/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        //int index = -1;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){

                ListNode* newNode = head;

                while(slow!=newNode){
                    slow = slow->next;
                    newNode = newNode->next;
                }

                return newNode;
            }
        }
        return NULL;
    }
};