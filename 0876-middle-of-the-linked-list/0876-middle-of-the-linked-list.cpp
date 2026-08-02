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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        ListNode* ans = head;
        while(temp && temp->next){
            count++;
            temp = temp->next;
        }
        int k = (count%2 != 0)? (count/2)+1 : count/2;
        for(int i =0; i<k; i++){
            ans = ans->next;
        }
        return ans;
    }
};