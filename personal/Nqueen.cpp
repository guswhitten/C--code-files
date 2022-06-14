/*************************************************************
 * Solve N-Queen Problem using Recursion
 * For this assignment, write a C++ program that prints a 
 * possible solution of the N-queens problem for a given 
 * positive value of N. In the N-queens problem, the goal is 
 * to place N queens on an N-by-N chess board so that no two 
 * queens are on the same row, column, or diagonal.
 * 
 *************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 8
using namespace std;
 
/* print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout<<board[i][j]<<"  ";
        cout<<endl;
    }
}
 
/* check if a queen can be placed on board[row][col]*/
bool isSafe(int board[N][N], int row, int col)
{
    for (int i = 0; i < N; i++) 
    {
        if ((board[row][i] == 1) || (board[i][col] == 1))//checks row & col for other queens
        {               
            return false; 
        }
        if ((row-i >= 0) && (col-i >= 0))               //checks NW diagonal
        {
            if (board[row-i][col-i] == 1) 
            {
                return false; 
            }
        }
        if ((col-i >= 0) && (row+i < N))                //checks SW diagonal
        {
            if (board[row+i][col-i] == 1) 
            {
                return false; 
            }
        }
        if ((row+i < N) && (col+i < N))                 //checks SE diagonal
        {
            if (board[row+i][col+i] == 1) 
            {
                return false; 
            }
        }
        if ((col+i < N) && (row-i >= 0))                //checks NE diagonal
        {
            if (board[row-i][col+i] == 1) 
            {
                return false; 
            }
        }
    }
    return true;
}

/*solve N Queen problem*/
bool solver(int board[N][N], int col)
{
    if (col >= N)                       //found solution if column equals N
        return true;
    if (col < 0)                        //no solution if column becomes less than 0
        return false;
    for (int i = 0; i < N; i++)         //iterates thru every row of column
    {
        if (isSafe(board,i,col))        //checks current cell for queen attacks
        {
            board[i][col] = 1;          //makes tentative assignment
            if (solver(board, col +1))  //if next column works too, move on
            {
                return true;
            }
            board[i][col] = 0;          //otherwise, remove assignment
        }
    }
    solver(board, col -1);              //and try again
}
 
/* solves the N Queen problem using Backtracking.*/
bool solveNQ()
{
    int board[N][N] = {0};
    solver(board, 0);
    printSolution(board);
    return true;
}
 
// Main
int main()
{
    solveNQ();
    return 0;
}
