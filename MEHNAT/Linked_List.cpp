#include<bits/stdc++.h>
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

void insert(Node* &head, int val) {
  Node* temp = new Node(val);
  temp -> next = head;
  head = temp;
}

void print(Node* &head) {
  Node* temp = head;
  while(temp) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << "\n";
}

Node* reverse(Node* &head) {
  Node* curr = head, *prev = NULL, *nxt;
  
  while(curr) {
    nxt = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = nxt;
  }
  cout << "head data " << head -> data << "\n";
  head = prev;
  
  return head;
}

int middle(Node* &head) {
  Node* fast = head, *slow = head;
  while(fast -> next != NULL && fast -> next -> next != NULL) {
    slow = slow -> next;
    fast = fast -> next -> next;
  }
  
  return slow -> data;
}

//Recursive O(N) -> space
Node* reverseKGroup(Node* &head, int k) {
    
        //Check
        Node* dummy = head;
        for(int i = 0; i < k; i++) {
            if(dummy == NULL) return head;
            dummy = dummy -> next;
        }    
        
        Node* curr = head, *prev = NULL, *nxt = NULL;
        for(int i = 0; i < k; i++) {
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        
        head -> next = reverseKGroup(curr, k);
        
        return prev;
}



int main() {
  Node* head = new Node(5);
  insert(head, 4);
  insert(head, 8);
  insert(head, 6);
  insert(head, 3);
  insert(head, 7);
  
  print(head);
  
  Node* r = reverse(head);
  print(r);

  cout << "Middle Element: " << middle(head) << "\n";
  
  
}