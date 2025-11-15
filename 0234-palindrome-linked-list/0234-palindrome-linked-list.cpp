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

    ListNode* reverse(ListNode* node) {
        ListNode* curr = node;
        ListNode* prev = nullptr;

        while(curr != nullptr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        //find mid
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse second half
        ListNode* newHead = reverse(slow->next);

        //compare
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != nullptr) {
            if(first->val != second->val) {
                reverse(newHead);
                return false;
            }
            else {
                first = first->next;
                second = second->next;
            }
        }
        return true;
    }
};