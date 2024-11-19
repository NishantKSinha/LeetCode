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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1,head); //means we are putting head on next todummynodewecanalso use head instead of head1
        ListNode* prev = dummy;
        ListNode* head1 = dummy->next;
        
        while(head1 != NULL){
            
            if(head1->next != NULL && head1->val == head1->next->val){
                while(head1->next != NULL && head1->val == head1->next->val){
                    head1= head1->next;
                }
                prev->next = head1->next;
                head1= head1-> next;
            }
            else{
                prev = prev->next;
                head1= head1->next;
            }
            
        }
        return dummy->next;
    }
};