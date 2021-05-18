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
    int min(stack<int>&A,stack<int>&B)
    {
        return A.size()<=B.size()? A.size():B.size();
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>A;
        stack<int>B;
        stack<int>C;
        while(l1!=NULL)
        {
        A.push(l1->val);
            l1=l1->next;
        }
         while(l2!=NULL)
        {
        B.push(l2->val);
            l2=l2->next;
        }
        int size;
        size=min(A,B);
        int reminder=0,newstack=0,sum=0;
        int alast,blast;
        while(size!=0)
        {
            alast=A.top();
            blast=B.top();
           A.pop();
          B.pop(); 
            sum=blast+alast+reminder;
            reminder=sum/10;
            newstack=sum%10;
            C.push(newstack);
            size--;
        }
        if(B.empty())
        {
            while(!A.empty())
            {
                alast=A.top();
                A.pop();
                sum=alast+reminder;
            reminder=sum/10;
            newstack=sum%10;
            C.push(newstack);
            }
        }
        else
        {
            while(!B.empty())
            {
                blast=B.top();
                B.pop();
                sum=blast+reminder;
            reminder=sum/10;
            newstack=sum%10;
            C.push(newstack);
            }
        }
        if(reminder!=0)
        {
            C.push(reminder);
        }
         ListNode* result=new ListNode(C.top());
        C.pop();
        ListNode *game=result;
        while(!C.empty())
        {
            game->next=new ListNode(C.top());
        C.pop();
            game=game->next;
        }
        
        return result;
    }
};
