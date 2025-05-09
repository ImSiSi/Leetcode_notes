#include<iostream>
using std::cout;
using std::endl;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {
    };
};

ListNode* reverse(ListNode* pre,ListNode* cur){
    if(cur == nullptr)
        return pre;
    ListNode* temp = cur->next;
    cur->next = pre;
    return reverse(cur, temp);
}
class Solution{
    public:
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};

int main(){
    ListNode* node1= new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3), *node4 = new ListNode(4), *node5 = new ListNode(5);
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 5;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution ans;
    node1 = ans.reverseList(node1);
    while(node1 != nullptr){
        cout<<node1->val;
        node1 = node1->next;
    }
    return 0;
}