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
        int carry = 0;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;

        while(temp1 != nullptr && temp2 != nullptr) {
            int sum = temp1->val + temp2->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            t->next = newNode;
            carry = (sum / 10);
            t = newNode;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }   

        if(temp1 != nullptr) {
            while(temp1 != nullptr) {
                int sum = temp1->val + carry;
                ListNode* newNode = new ListNode(sum % 10);
                carry = (sum / 10);

                t->next = newNode;
                t = newNode;

                temp1 = temp1->next;
            }

            if(carry > 0) {
                t->next = new ListNode(carry);
                t = t->next;
            }
        }
        else if(temp2 != nullptr) {
            while(temp2 != nullptr) {
                int sum = temp2->val + carry;
                ListNode* newNode = new ListNode(sum % 10);
                carry = (sum / 10);

                t->next = newNode;
                t = newNode;

                temp2 = temp2->next;
            }

            if(carry > 0) {
                t->next = new ListNode(carry);
                t = t->next;
            }
        }
        else {
            if(carry > 0) {
                t->next = new ListNode(carry);
                t = t->next;
            }
        }

        return dummy->next;
    }
};