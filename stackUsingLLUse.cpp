#include<iostream>
using namespace std;
#include "stackUsingLL.cpp"

int main(){
Stack<int> s;
s.push(10);
s.push(20);
s.push(30);
cout<<s.top()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.Size()<<endl;
cout<<s.isEmpty()<<endl;

}
