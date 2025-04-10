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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int sz = 0;

        while(temp != nullptr){
            sz++;
            temp = temp->next;
        }
        
        temp = head;
        if(sz == 1){
            return temp->next;
        }
        
        int n = (sz / 2) - 1;
        for(int i=0; i<n; i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};