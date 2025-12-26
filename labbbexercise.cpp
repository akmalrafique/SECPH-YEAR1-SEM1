#include<iostream>
using namespace std;
int main(){
    int num,number,digit,sum=0;
    cout<<"enter an integer number: ";
    cin>>num;
    number=num;

   while (number > 0) {
        digit=number % 10;
        cout<<digit;
        number /= 10;
        sum+=digit; 

        if (number > 0)
            cout<< " + ";
    }
    cout<<"="<<sum<<endl;
    
    if(sum%2==0)
    cout<<sum<<"is even number";
    else
    cout<<sum<<"is odd number";

    if(sum%4==0&&sum%5==0){
        cout<<" and multiples od 4 and 5"<<endl;
    }
    else if(sum%4==0)
    cout<<"& multiples of 4"<<endl;
    else if(sum%5==0)
    cout<<"& multiples of 5";


    return 0;

}