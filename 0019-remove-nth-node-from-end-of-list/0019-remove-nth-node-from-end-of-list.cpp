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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;

        int sz = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            temp = temp->next;
            sz++;
        }
        
        if(sz == n) return head->next;

        int toFind = sz - n;
        int i = 1;

        ListNode* prev = head;
        while(i < toFind){
            prev = prev->next;
            i++;
        }
        prev->next = prev->next->next;

        return head;
    }
};