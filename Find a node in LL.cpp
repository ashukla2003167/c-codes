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

int findNode(Node *head, int x){
    Node *temp = head;
    int c = 0;
    while(temp!=NULL){
        if(temp->data == x){
            return c;
            break;
        }
        temp = temp->next;
        c++;
    }
    return -1;
}

int main(){
    Node *head = takeinput();
    int x;
    cin>>x;
    cout<< findNode(head, x);
}