#include<bits/stdc++.h>
using namespace std;
int lis(vector<int> v) {
    vector<int> res;

    if (v.size() > 0) {
        res.push_back(v[0]);
    }

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > res.back()) {
            res.push_back(v[i]);
        } else {
            int id =lower_bound(res.begin(), res.end(), v[i]) - res.begin();
            res[id]=v[i];
    }
    }
    return res.size();

}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
int main(){
    int n1,n2;
    cout<<"Enter the size of Array1 : ";
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the size of Array2 : ";
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    cout<<"Arr1 : ";
    display(arr1,n1);
    cout<<"Arr2 : ";
    display(arr2,n2);
    vector<int>temp; 
    for (int i=0;i<n1;i++){
        if(binary_search (arr2,arr2+n2, arr1[i])){
            temp.push_back(arr1[i]);
            }
    }
    int res= n1+n2-(2*lis(temp));
    cout<<"Result : ";
    cout<<res;


}

