#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"
#include "generateRandom.h"

using namespace std; 


// requires 2 traversal
// time comp : O(n) 
void nthFromEnd(Node * head, int n)
{
    if(head == NULL)
    {
        cout<<"linked list is empty"<<endl;
        return;
    }
    int len = 0;
    Node * curr = head;
    while(curr != NULL){
        len++;
        curr = curr->next;
    }
    if(len < n)
    {
        cout<<n<<" is greater than than length of list"<<endl;
        return ;
    }
    curr = head;
    for(int i=1 ;i<len-n+1 ;i++)
        curr = curr->next;
    cout<<"value of "<<n<<"th node from end is "<< curr->data<<endl;
}

// 1 traversal
// time comp : O(n) 

void nthFromEnd2(Node *head, int n)
{
    if(head == NULL)
    {
        cout<<"linked list is empty"<<endl;
        return;
    }
    Node * slow = head;
    Node *fast = head;
    for(int i=0 ; i<n ; i++)
    {
        if(fast == NULL)
        {
            cout<<n<<" is greater than than length of list"<<endl;
            return ;
        }
        fast = fast->next;
    }

    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    cout<<"value of "<<n<<"th node from end is "<< slow->data<<endl;
    

}

int main()
{
    int n;
    cout <<"enter size of linked list" << endl;
    cin >> n;
    srand(time(0));
    Node *head = NULL;
    while (n > 0)
    {
        head = insertBegin(head, getRandom(1, 200));
        n--;
    }    
    traverseLinkedList(head);

    int k ;
    cout << " enter position from end" << endl;
    cin >> k;
    nthFromEnd(head, k);
    nthFromEnd2(head, k);


    return 0;
}