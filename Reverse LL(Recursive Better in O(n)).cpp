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

class Pair{
    public:
    Node * head;
    Node * tail;

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
  

Pair reverseLL_2(Node *head){
    if(head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallOutput = reverseLL_2(head->next);
    smallOutput.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallOutput.head;
    ans.tail = head;
    return ans;
}

int main(){
    Node *head = takeinput();
    Pair ans = reverseLL_2(head);
    print(ans.head);    
}