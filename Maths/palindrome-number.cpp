// problem: check if a given number is palindrome number or not
// all single digit numbers are palindromes

#include <iostream>

using namespace std; 

bool isPalindrome(int n){
    int x = n;
    int num = 0;
    while(x!=0)
    {
        num = num*10 + x%10;
        x = x/10;
    }
    return num==n;
}

int main()
{
    int n ;
    cin>> n;
    bool ans;
    if (isPalindrome(n))
        cout<<n<<" : is a palindrome.";
    else
        cout<<n<<" : is not a palindrome.";
    
    return 0;
}