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

    int cntOfNodes(ListNode* head) {
        int cnt = 0;

        ListNode* temp = head;

        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        int totalNodes = cntOfNodes(head);

        if(n == totalNodes) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        else if(n == 1) {
            ListNode* temp = head;

            while(temp->next->next != nullptr) {
                temp = temp->next;
            }

            temp->next = nullptr;

            return head;
        }
        else {
            int startNode = totalNodes - n;

            ListNode* temp = head;

            while(temp != nullptr) {
                startNode--;

                if(startNode == 0) {
                    break;
                }

                temp = temp->next;
            }

            ListNode* f = temp->next;
            temp->next = temp->next->next;
            delete f;

            return head;
        }
    }
};