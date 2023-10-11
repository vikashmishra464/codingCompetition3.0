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
node* even_odd(node* &head) {
  if (!head || !head->next) {
        return head;
    }

    node* evenHead = nullptr;
    node* evenTail = nullptr;
    node* oddHead = nullptr;
    node* oddTail = nullptr;

    node* current = head;

    while (current) {
        if (current->val % 2 == 0) {
            if (!evenHead) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            if (!oddHead) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }

    if (evenTail) {
        evenTail->next = oddHead;
    }

    if (oddTail) {
        oddTail->next = nullptr;
    }

    return evenHead ? evenHead : oddHead;
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
  head=even_odd(head);
  cout << "NEW LL : ";
  display(head);

  return 0;
}
