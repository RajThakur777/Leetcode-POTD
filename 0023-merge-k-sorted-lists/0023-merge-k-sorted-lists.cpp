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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        priority_queue<int , vector<int> , greater<int>> pq;

        for(int i=0; i<n; i++){
            ListNode* curr = lists[i];

            while(curr != nullptr){
                pq.push(curr->val);
                curr = curr->next;
            }
        }

        ListNode* head = new ListNode(-1);
        ListNode* prev = head;

        while(!pq.empty()){
            ListNode* newNode = new ListNode(pq.top());
            pq.pop();

            prev->next = newNode;
            prev = newNode;
        }
        return head->next;
    }
};