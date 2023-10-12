#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int x) : val(x),next(NULL){}
};
void insert(node* &head,int x){
    node *n= new node(x);
    if (head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while (temp->next){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<temp->val<<endl;

}
void first_last(node* &head){
    node* slow=head;
    node* fast=head->next;
    while (fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    node* first=head;
    node* second=slow->next;
    slow->next=nullptr;
    node* pre=nullptr;
    node* current=second;
    node* nxtptr;
    while (current){
        nxtptr=current->next;
        current->next=pre;
        pre=current;
        current=nxtptr; 
    }
    second=pre;
    while (second){
        node* temp1=first->next;
        node* temp2=second->next;
        first->next=second;
        second->next=temp1;
        first=temp1;
        second=temp2;
    }
}
        
int main() {
  int n;
  node* head = NULL;
  cout << "Enter no of nodes: " << endl;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int n;
    cin >> n;
    insert(head, n);
  }
  cout << "OLD LL : ";
  display(head);
  first_last(head);
  cout << "NEW LL : ";
  display(head);

  return 0;
        
}