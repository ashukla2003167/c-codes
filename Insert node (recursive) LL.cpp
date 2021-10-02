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

void print(Node *head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int length(Node *head){
    Node *temp = head;
    if(temp->next==NULL){
        return 1;
    }
    temp = temp->next;
    return 1+ length(temp);
}

Node *insertAtRecursively(Node* head ,int i,int data){
    Node *Newnode = new Node(data);
    if(head == NULL){
        return head;
    }
    if(i==0){
    Newnode->next = head;
    head = Newnode;
    return head;
    }
    if(i==length(head)){
        int c=0;
        Node *temp = head;
        while(c<i-1){
            temp = temp->next;
            c++;
        }
        temp->next = Newnode;
        temp = temp->next;
        return head;
    }
    Node *x =  insertAtRecursively(head->next,i-1,data);
    head->next = x;
    return head;
}

int main(){
    Node *head = takeinput();
    int i,data;
    cin>>i>>data;
    Node *h = insertAtRecursively(head, i, data);
    print(h);
}
