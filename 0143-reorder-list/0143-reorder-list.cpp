/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reverse from middle+1
        ListNode* curr = slow->next;
        ListNode* prev = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //reorder List
        slow->next = NULL;
        ListNode* left = head;
        ListNode* right = prev;

        while(right){
            ListNode* lnext = left->next;
            ListNode* rnext = right->next;

            left->next = right;
            right->next = lnext;

            left = lnext;
            right = rnext;
        }
    }
};