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
class Solution {
    
    
    bool find(node* head, vector<int>& nums){
        bool a1=false,a2=false;
        for(int i=0;i<nums.size();i++){
            if (head->val ==nums[i]){
                a1=true;
            }
            if (head->next->val ==nums[i]){
                a2=true;
            }
        }
        if (a1 && !a2){
            return true;
        }
        else{
            return false;
        }
    }
public:
    int numComponents(node* head, vector<int>& nums) {
        int a=0;
        while (head->next){
            if(find(head,nums)){
                a++;
            }
            head=head->next;
        }
    
    for(int i=0;i<nums.size();i++){
            if (head->val ==nums[i]){
                a++;
            }
    }
    return a;
    }
};

int main(){
    node* head = nullptr;
    int n, x;

    cout << "Enter linked list values (-1 to stop): ";
    while (cin >> x && x != -1) {
        insert(head, x);
    }

    cout << "Enter the number of elements in the array nums: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter elements of the array nums: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    int components = solution.numComponents(head, nums);

    cout << "Number of connected components: " << components << endl;

    // Free memory by deleting the linked list
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}