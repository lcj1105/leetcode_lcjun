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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
        	return head;
        ListNode* cur = head;
        ListNode* temp = head->next;

        while(temp){
        	if(cur->val == temp->val){
        		cur->next = temp->next;
        		temp = cur->next;
        	}
        	else{
        		cur = temp;
        		temp = cur->next;
        	}
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
        	return head;
        ListNode *pNode = head;
        while(pNode->next != NULL){
        	if(pNode->val == pNode->next->val)
        		pNode->next = pNode->next->next;
        	else
        		pNode = pNode->next;
        }
        return head;
    }
};