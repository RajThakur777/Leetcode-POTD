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

    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* next;

        while(temp != nullptr){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = reverse(l1);
        ListNode* second = reverse(l2);

        ListNode* temp1 = first;
        ListNode* temp2 = second;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int carry = 0;

         while(temp1 != nullptr || temp2 != nullptr || carry > 0){
            int sum = carry;

            if(temp1 != nullptr){
                sum += temp1->val;
            }
            if(temp2 != nullptr){
                sum += temp2->val;
            }

            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;

            carry = sum / 10;

            if(temp1 != nullptr){
                temp1 = temp1->next;
            }

            if(temp2 != nullptr){
                temp2 = temp2->next;
            }
        }
        ListNode* res = reverse(dummy->next);

        ListNode* ans = res;
        while(ans != nullptr && ans->val == 0){
            ans = ans->next;
        }
        
        if(ans){
            return ans;
        }
        return new ListNode(0);
    }
};