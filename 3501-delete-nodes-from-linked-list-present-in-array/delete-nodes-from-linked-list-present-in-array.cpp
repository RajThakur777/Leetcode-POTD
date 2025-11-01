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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;

        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }

        ListNode* temp = head;

        ListNode* ans = new ListNode(-1);
        ListNode* p = ans;

        while(temp != nullptr) {
            if(st.find(temp->val) != st.end()) {
                temp = temp->next;
            }
            else {
                p->next = new ListNode(temp->val);
                p = p->next;
                temp = temp->next;
            }
        }
        return ans->next;
    }
};