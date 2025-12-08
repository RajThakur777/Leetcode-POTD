/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int Len(ListNode* head) {
        int cnt = 0;

        ListNode* temp = head;

        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        int lenA = Len(headA);
        int lenB = Len(headB);

        if(lenA < lenB) {
            ListNode* l2 = headB;

            int extra = lenB - lenA;

            while(extra--) {
                l2 = l2->next;
            }

            ListNode* l1 = headA;

            while(l1 != nullptr && l2 != nullptr) {
                if(l1 == l2) {
                    return l1;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            return nullptr;
        }
        else if(lenA > lenB) {
            ListNode* l1 = headA;

            int extra = lenA - lenB;

            while(extra--) {
                l1 = l1->next;
            }

            ListNode* l2 = headB;

            while(l1 != nullptr && l2 != nullptr) {
                if(l1 == l2) {
                    return l1;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            return nullptr;
        }
        else {
            ListNode* l1 = headA;
            ListNode* l2 = headB;

            while(l1 != nullptr && l2 != nullptr) {
                if(l1 == l2) {
                    return l1;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            return nullptr;
        }
    }
};