#include <iostream>
#include <vector>

using namespace std ;

int main() {
    
    int n;
    
    cout<<"Enter no of elements : ";
    cin>>n;
    
    vector<int>elements(n);
    
    cout<<"Enter the elements :";
    for(int i=0;i<n;i++){
        cin>>elements[i] ;
    }
    for (int i =n-1;i>=0;i--){
        
        if (elements[i]<9){
            elements[i]++;
            break;
        }
        else {
            elements[i]=0;
        }
    }
    
    if (elements[0]==0){
        cout<<"result :1";
        
        for(int i=0;i<n;i++){
            
            cout<<"0";
        }
    }
    
    else{
        cout<<"result :";
        for (int i=0;i<n;i++){
            cout<<elements[i]<<" ";
        }
    }
    
    return 0;
}