#include<iostream>
using namespace std;
int main()
{
    int num=0,sum=0;
    cout<< "Enter integer number to add: "<<endl;
    cout<< "When you finished entering number. Input a non int number / end of file value (ctrl + z) to get the result of addition."<<endl;
    while(cin>> num)
    {
        sum+=num;
    }
    cout<< "The summation of inputed numbers is: "<< sum<< "."<<endl;
    return 0;
}
