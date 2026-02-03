// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node*temp,*even=0,*odd=0,*evenTail=0,*oddTail=0;
        temp=head;
        
        while(temp!=0){
            if(temp->data%2==0&&even==0){
                even=temp;
                evenTail=temp;
            }
            else if(temp->data%2!=0&&odd==0){
                odd=temp;
                oddTail=temp;
            }
            else if(temp->data%2==0){
                evenTail->next=temp;
                evenTail=temp;
            }else{
                oddTail->next=temp;
                oddTail=temp;
            }
            temp=temp->next;
        }
        
       if(evenTail) evenTail->next=odd;
       if(oddTail) oddTail->next=0;
        
        return (even==0)?odd:even;
    }
};