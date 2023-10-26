#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
   int val;
   Node* next;
   
   Node() {
       this -> val = 0;
       this -> next = NULL;
   }
   
   Node(int val) {
       this -> val = val;
       this -> next = NULL;
   }
};

class LinkedList {
  private:
  Node* head, *curr;
  
  public:
  
  LinkedList() {
      this -> head = NULL;
      this -> curr = NULL;
  }
  
  void insertNode(int data) {
      if(head == NULL) {
          head = new Node(data);
          curr = head;
      }
      else {
          curr -> next = new Node(data);
          curr = curr -> next;
      }
  }
  
  void printList() {
      Node* temp = head;
      while(temp != NULL) {
          cout << temp -> val << ' ';
          temp = temp -> next;
      }
  }
  
  void reverseList() {
      if(head == NULL)  return;
      
      Node* prev = NULL, *curr = head, *nxt = head -> next;
      
      while(nxt != NULL) {
          curr -> next = precev;
          prev = curr;
          curr = nxt;
          nxt = nxt -> next;
      }

      curr -> next = prev;
      head = curr;
  }
};


int main()
{
    LinkedList ll;
    
    ll.insertNode(5);
    ll.insertNode(6);
    ll.insertNode(7);
    ll.insertNode(8);
    
    ll.printList();
    cout << '\n';
    ll.reverseList();
    
    ll.printList();
}
