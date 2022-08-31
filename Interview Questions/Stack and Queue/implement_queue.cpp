#include <iostream>
using namespace std;

int queue[100], n = 100, front = - 1, rear = - 1;
void push(int _val) {
   int val = _val;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1)
      front = 0;
      rear++;
      queue[rear] = val;
   }
}
void pop() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      front++;;
   }
}
void frontt() {
   if (front == - 1 || front > rear)
   cout<<"Queue is empty"<<endl;
   else {
      cout << queue[front] << endl;
   }
}
int main() {
   push(10);
   push(20);
   frontt();
   push(25);
   frontt();
   pop();
   frontt();
   pop();
   frontt();
   pop();
   frontt();
}