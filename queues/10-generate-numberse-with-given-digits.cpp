// given a number n print first n numbers in increasing order such that numbers contain digits from a given set

#include <iostream>
#include <queue>
#include <string>

using namespace std; 


// time comp : O(totalDigits * totalNumbersNeeded)
void printNumbers(int digits[], int totalDigits, int n)
{
    queue<int> q;
    for(int i = 0; i < totalDigits; i++)
    {
        q.push(digits[i]);
    }

    int curr ;
    for(int i = 0; i < n; i++)
    {
        curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(int j = 0; j <totalDigits; j++)
            q.push(curr*10 + digits[j]);
    }
    cout<<endl;
}

// if numbers are large we can use string 

void printNumbers2(int digits[], int totalDigits, int n)
{
    string curr ;
    queue<string> q;
    for(int i = 0; i < totalDigits; i++)
        q.push(to_string(digits[i]));

    for (int i = 0; i < n; i++)
    {
        curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(int i=0;i<totalDigits;i++)
            q.push(curr + to_string(digits[i]));
    }
    cout<<endl;
    


}

int main()
{

    // int digits[] = {1,2,3,4,5};
    // int digits[] = {8,9};
    // int digits[] = {5,6};
    int digits[] = {4,6,8,9};
    int totalDigits = sizeof(digits)/sizeof(digits[0]);
    cout<<"How many numbers do you want to print?"<<endl;
    int n;
    cin >> n;

    printNumbers(digits, totalDigits, n);
    printNumbers2(digits, totalDigits, n);
    
    return 0;
}