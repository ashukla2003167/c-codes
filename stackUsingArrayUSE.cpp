#include<iostream>
using namespace std;
#include "StackUsingArray.cpp"

int main(){
stackUsingArray<char> s;
s.push('a');
s.push('b');
s.push('c');
s.push('d');
s.push('e');

cout<<s.top()<<endl;
s.pop();
s.pop();
cout<<s.pop()<<endl;
cout<<s.isEmpty()<<endl;
cout<<s.size()<<endl;


}
