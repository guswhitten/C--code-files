/******************************************************************************
This file uses stacks, queues, and the io-stream to accept a string from a user, 
and return whether or not that string is identical forwards and backwards (aka, a palindrome). 


*******************************************************************************/
#include <iostream> //provides cin, cout
#include <cstdlib>
#include <stack> //provides stack
#include <queue> //provides queue
#include <string> //provides string
#include <cctype> //provides function isalpha()

using namespace std;

//function declarations
string Stack(const string& phrase);
string Queue(const string& phrase);

//main function to engage with user
int main()
{
    string str;
    cout << "Enter your suspected palindrome word/phrase: "; //prompts user for a suspected palindrome
    getline(cin, str);               //stores user response in string str
    string sResult = Stack(str);    //calls stack function and stores result as string
    cout << endl;
    string qResult = Queue(str);    //calls queue function and stores result as string
    cout << endl;
    if (sResult == qResult)         //compares reversed string to forward string
    {
        cout << "Yes, that's a palindrome\n"; //if results are equal
    }
    else
    {
        cout << "Nope, not a palindrome\n";   //if results are not equal
    }
    return 0;
}

string Stack(const string& phrase) //takes string parameter, reverses order of letters, returns reversed string
{
    stack<char> s; //creates stack of char type
    string::size_type i; 
    char next;
    string result;
    for (i = 0; i < phrase.length( ); ++i) //iterates thru length of user's phrase
    {
        next = phrase[i];
        if (isalpha(next))  //only add current item to stack if it is alphabetic character
            s.push(next);  
    }
    while (!s.empty())      //iterate thru stack until empty
    {
        result.push_back(s.top()); //adds top char of stack to end of string result
        cout << s.top();           //also prints to screen top char of stack
        s.pop();                   //removes top char of stack
    }
    return result;              //returns reversed string without spaces
}

string Queue(const string& phrase)
{
    queue<char> q; //creates queue of char type
    string result;
    string::size_type j;
    char c;
    for (j = 0; j < phrase.length( ); ++j) //iterates through length of phrase
    {
        c = phrase[j];
        if (isalpha(c)) //adds current item to queue only if it is an alphabetic character
            q.push(c);
    }
    while (!q.empty()) //iterates thru queue until empty
    {
        result.push_back(q.front()); //adds char at front of queue to end of string result
        cout << q.front();          //also prints char at front of queue to screen
        q.pop();                    //removes char at front of queue
    }
    return result;                  //returns string without spaces
}


/*                  TEST CASES

Enter your suspected palindrome word/phrase: racecar is mom si racecar                                                                                                               
racecarismomsiracecar                                                                                                                                                                
racecarismomsiracecar                                                                                                                                                                
Yes, that's a palindrome 

Enter your suspected palindrome word/phrase: pop 98492 toot 3+-= pop                                                                                                                 
poptootpop                                                                                                                                                                           
poptootpop                                                                                                                                                                           
Yes, that's a palindrome

*/






