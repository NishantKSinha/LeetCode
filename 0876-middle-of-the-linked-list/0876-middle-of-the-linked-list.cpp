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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head ;
        }
        ListNode *temp = head ;
        ListNode *prev = NULL;
         ListNode *curr = NULL;
        int k =0;
        int count = 0 ;
        
        while(temp != NULL){
            temp = temp -> next ;
            count ++ ;
        }
       int position = count / 2;
       ListNode *temp2 =head ;

        while( k < position ){
            curr = temp2 -> next ;
            temp2 -> next = prev ;
            temp2 = curr; 
            prev = temp2 ;
            k++;
        }
        return prev;

        
    }
};