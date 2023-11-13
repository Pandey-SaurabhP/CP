#include<iostream>

using namespace std;

bool palindrome(int n){
    int a=n;
    int b=n;
    int c=0;
    int ld;

    while(b!=0){
         ld=b%10;
         c=(c*10)+ld;
         b=b/10;
    }

    if(a==c){
        return true;
    }

    return false;
}



int main()
{
    int n;
    cin>>n;
    cout<<palindrome(n);

    return 0;
}
