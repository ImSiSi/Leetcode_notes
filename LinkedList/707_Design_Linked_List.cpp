#include<iostream>
using std::cout;
class MyLinkedList {
    public:
        struct ListNode{
            int val;
            ListNode *next;
            ListNode(int val):val(val), next(nullptr){};
        };
        MyLinkedList() {
            dummyhead = new ListNode(0);
            size = 0;
        }
        
        int get(int index) {
            if(index > size-1)
                return -1;
            ListNode* cur = dummyhead;
            int length = -1;
            while(cur != nullptr){
                cur = cur->next;
                length ++;
                if(length == index){
                    return cur->val;
                }
            }
            return 0;
        }
        
        void addAtHead(int val) {
            ListNode* head = new ListNode(val);
            head->next = dummyhead->next;
            dummyhead->next = head;
            size++;
        }
        
        void addAtTail(int val) {
            ListNode* cur = dummyhead;
            while(cur->next != nullptr){
                cur = cur->next;
            }
            ListNode* temp = new ListNode(val);
            cur->next = temp;
            size++;
        }
        
        void addAtIndex(int index, int val) {
            if(index <= size ){
                ListNode* cur = dummyhead;
                int length = -1;
                if(index == size){
                    this->addAtTail(val);
                }
                else{
                    while(cur->next != nullptr){
                        if(index == length+1){
                            ListNode* temp = new ListNode(val);
                            temp->next = cur->next;
                            cur->next = temp;
                            size++;
                            break;
                        }
                        length++;
                        cur = cur->next;
                    }
                }
            }
        }
        
        void deleteAtIndex(int index) {
            if(index < size){
                ListNode* cur = dummyhead;
                int length = -1;
                while(cur->next != nullptr){
                    if(length+1 == index){
                        ListNode* temp;
                        temp = cur->next;
                        cur->next = temp->next;
                        delete temp;
                        size --;
                        break;
                    }
                    cur = cur->next;
                    length++;
                }
            }
        }
        int getsize(){
            return size;
        }
    private:
        ListNode *dummyhead;
        int size;
};
    

int main(){
    MyLinkedList* list = new MyLinkedList();
    list->addAtHead(7);
    //7 size=1
    list->addAtHead(2);
    //2-7 size=2
    list->addAtHead(1);
    //1-2-7 size=3
    list->addAtIndex(3,0);
    //1-2-7-0 size = 4
    list->deleteAtIndex(2);
    //1-2-0 size =3
    list->addAtHead(6);
    //6-1-2-0 size=4
    list->addAtTail(4);
    //6-1-2-0-4 size =5
    int size =list->getsize();
    cout<<"size="<<size<<"   ";
    for(int i=0;i<size;i++){
        cout<<list->get(i);
    }
    int a = list->get(4);
    cout<<"a="<<a;
    return 0; 
}