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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        if(list1 == NULL)
            return list2;

        if(list2 == NULL)
            return list1;

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while(p1 && p2){
            if(p1->val <= p2->val){
                dummy->next = p1;
                dummy = dummy->next;
                p1 = p1->next;
            }
            else{
                dummy->next = p2;
                dummy = dummy->next;
                p2 = p2->next;
            }
        }
        if(p1){
            dummy->next = p1;
        }
         if(p2){
            dummy->next = p2;
        }
        return temp->next;
    }
};