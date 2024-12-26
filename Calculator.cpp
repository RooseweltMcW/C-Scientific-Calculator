#include<vector>
#include<iostream>
#include<map>
using namespace std;

template <typename T> T calculate(T x,T y)
{
    int choice=0;
    cout<<"Enter Option : 1 - Add , 2 - Sub , 3 - Multiply , 4 - Division : ";
    cin>>choice;
    switch (choice)
    {
    case 1:return x+y;break;
    case 2:return x-y;break;
    case 3:return x*y;break;
    case 4:if (y != 0)
                return x / y;
            else {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
    default:cout<<"Not Valid";break;
    }

}

int main(){
    int Number1,Number2;
    cout<<"Enter number 1:";
    cin>>Number1;
    cout<<"Enter number 2:";
    cin>>Number2;
    int result=calculate(Number1,Number2);
    cout<<"Result = "<<result<<endl;
}