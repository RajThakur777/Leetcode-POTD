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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;

        while(temp != nullptr){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        sort(ans.begin() , ans.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        for(int i=0; i<ans.size(); i++){
            ListNode* newNode = new ListNode(ans[i]);
            curr->next = newNode;
            curr = curr->next;
        }
        return dummy->next;
    }
};