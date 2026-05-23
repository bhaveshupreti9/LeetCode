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
    ListNode* findkth(ListNode* temp,int k){
        k--;
        while(temp != NULL && k >0){
            temp = temp -> next;
            k--;
        }
        return temp;
    }
    ListNode* reverselist(ListNode* head){
        ListNode* temp  = head;
        ListNode* previ = NULL;
        while(temp != NULL){
            ListNode* front = temp -> next;
            temp -> next = previ;
            previ = temp;
            temp = front;
        }
        return previ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(temp != NULL){
            ListNode* kthnode = findkth(temp,k);
            if(kthnode == NULL){
                if(prev)prev -> next = temp;
                break;
            }
            ListNode* nextnode = kthnode -> next;
            kthnode -> next = NULL;
            reverselist(temp);
            if(temp == head){
                head = kthnode;
            }
            else prev -> next = kthnode;
            prev = temp;
            temp = nextnode;
        }
        return head;
    }
};