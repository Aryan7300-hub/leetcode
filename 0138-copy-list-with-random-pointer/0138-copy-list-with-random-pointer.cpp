/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        Node* temp = head;
        while(temp){  // Insert copy Node in between
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){ // Connect Random pointers
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }else{
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* curr = dummy;
        temp = head;

        while(temp){
            curr->next = temp->next;
            temp->next = temp->next->next;
            curr = curr->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};