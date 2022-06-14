#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
    int size = 2; //size of initial memory block allocated
    double userInput; //for user input of grade
    double* grades = new double[size]; //pointer to partially filled dynamic array
    double total = 0;
    int counter = 0; //tracks how many grades in dynamic array
    cout << "input grade: ";
    cin >> userInput;
    while (userInput >= 0) //iterates while user's input is positive
    {
        int size1 = size + 1; //size of new array is one larger than old one
        double *grades1 = new double[size1]; //pointer to dynamic array of one size larger
        for (int i = 0; i < counter; i++)
        {
            grades1[i] = grades[i]; //transfers values from smaller array to larger
        }
        grades1[counter] = userInput; //next open index becomes user's most recent input
        delete [ ] grades; //deletes old array 
        grades = grades1; //directs old pointer to new allocated memory
        size = size1; //changes size variable to updated size
        cout << "input grade: ";
        cin >> userInput;
        counter++; //number of items in array has increased by 1
    }
    cout << "\nStudents Grades:\n";
    for (int i = 0; i < counter; i++) //iterate thru length of dynamic array
    {
        cout << "Student " << i + 1 << "'s grade: " << grades[i] << endl;
        total += grades[i]; //keeps tally of total of all student's grades
    }
    cout << "Average of all grades is " << total/counter << endl; //prints average
    return 0;
}
//
