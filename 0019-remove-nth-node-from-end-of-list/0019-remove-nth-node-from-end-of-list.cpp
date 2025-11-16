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

        int nodes = cntOfNodes(head);

        int deleteNode = nodes - n + 1;

        if(deleteNode == 1) {
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
            
            return head;
        }
        else if(deleteNode == nodes) {
            ListNode* temp = head;

            while(temp->next->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nullptr;

            return head;
        }
        else {
            int nodeNumber = deleteNode - 1;

            ListNode* temp = head;

            while(nodeNumber != 1) {
                nodeNumber--;
                temp = temp->next;
            }
            temp->next = temp->next->next;

            return head;
        }
    }
};