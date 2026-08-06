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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int c = 0;
        
        while(l1 || l2 || c!=0){
            
            int sum = c;
            if(l1){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2 = l2->next;
            }

            c = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }
        curr->next = NULL;
        ListNode* result = reverse(dummy->next);

        return result;

    }
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};