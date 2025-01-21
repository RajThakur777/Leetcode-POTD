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

    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }    

    ListNode* getKthNode(ListNode* head , int k){
        ListNode* temp = head;
        k--;

        while(temp != nullptr && k > 0){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) { 
        ListNode* temp = head;
        ListNode* prevNode;

        while(temp != nullptr){
            ListNode* kth = getKthNode(temp , k);

            if(kth == nullptr){
                if(prevNode)  prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kth->next;
            kth->next = nullptr;

            reverseLinkedList(temp);

            if(temp == head){
                head = kth;
            }
            else {
                prevNode->next = kth;
            }

            prevNode = temp;
            temp = nextNode;
        }  
        return head;
    }
};