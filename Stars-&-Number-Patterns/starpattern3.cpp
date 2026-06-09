#include<iostream>
using namespace std;
int main(){
    for(int i=1;i<=5;i++){ //row count
        for(int j=1;j<=5-i;j++){ //space count
            cout<<" ";
        }
        for(int k=1;k<=i;k++){ //star count
            cout<<"*";
        }
        cout<<endl;
    }
     return 0;
}