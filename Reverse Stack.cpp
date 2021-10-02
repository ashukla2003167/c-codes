#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &s1){
    if(s1.size()==0 || s1.size()==1)
    return;
    int x = s1.top();
    s1.pop();
    reverseStack(s1);
    stack<int> s2;
    while(!s1.empty()){
        int a = s1.top();
        s1.pop();
        s2.push(a);
    }
    s1.push(x);
    while(!s2.empty()){
        int a = s2.top();
        s2.pop();
        s1.push(a);
    }
}

int main() {
    stack<int> s;
    int c;
    cin>>c;
    int i=0;
    int data;
    while(i<c){
        cin>>data;
        s.push(data);
        i++;
    }
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
