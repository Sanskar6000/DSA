//Using Class
#include <bits/stdc++.h>
using namespace std;
 
class Node {
  public: 
  int data;
  Node* next;
 
  Node() {
    data = 0;
    next = NULL;
  }
 
  Node(int data) {
    this -> data = data;
    this -> next = NULL;
  }
};
 
class LinkedList {
  Node* head;
  public:
 
  LinkedList() {
    head = NULL;
  }
 
  void reverse() {
    Node* curr = head, *prev = NULL, *nxt;
 
    while(curr) {
      nxt = curr -> next;
      curr -> next = prev;
      prev = curr;
      curr = nxt;
    }
    head = prev;
  }
 
  /****/
  void insert(int val) {
    Node* temp = new Node(val);
    temp -> next = head;
    head = temp;
  }
 
  void print() {
    Node* temp = head;
    while(temp) {
      cout << temp -> data << " ";
      temp = temp -> next;
    }
  }
};
 
// Node* reverse() {
 
// }
 
int main() 
{
     LinkedList ll;
     ll.insert(5);
     ll.insert(7);
     ll.insert(8);
     ll.insert(6);
 
     ll.print();
 
     ll.reverse();
     cout << "\n";
 
     ll.print();
}