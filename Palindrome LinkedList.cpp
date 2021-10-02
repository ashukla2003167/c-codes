#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node *takeinput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newnode = new Node(data);
        if(head ==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail=tail->next;            
        }
        cin>>data;
    }
    return head;
}
Node * midPoint(Node * head){
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print(Node *head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *reverseLL(Node *head){
    if(head == NULL || head->next == NULL)
    return head;
   Node * h1 = reverseLL(head->next);
   Node * temp = h1;
   while(temp->next != NULL){
       temp = temp->next;
   }
   temp->next = head;
   head->next = NULL;
    return h1;  
}
  
bool checkPalindromeLL(Node * head){
Node * mp = midPoint(head);
Node * l2 = reverseLL(mp->next);
mp->next = NULL;
Node *l1 = head;
while(l1->next!=NULL && l2->next!=NULL){
    if(l1->data == l2->data)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    else {
        return false;
        break;
    }
}
if(l1->next==NULL && l2->next == NULL){
    if(l1->data==l2->data)
    return true;
    else
    return false;
}
else if(l1->next->next == NULL && l2->next== NULL)
{

    if(l1->data == l2->data)
    return true;
    else
    return false;
}
else
return false;

}

int main(){
    Node *head = takeinput();
    cout<<checkPalindromeLL(head)<<endl;;
    
}