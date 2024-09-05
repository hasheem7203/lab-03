#include <iostream>
using namespace std;
bool isblocksafe(int arr[][5], int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Maze(int arr[][5], int x, int y, int n, int solArr[][5])
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }
    if (isblocksafe(arr, x, y, n))
    { // check if the block is safe
        solArr[x][y] = 1;
        if (Maze(arr, x + 1, y, n, solArr))
        { // move in right
            return true;
        }
        if (Maze(arr, x, y + 1, n, solArr))
        { // move downwards
            return true;
        }
        solArr[x][y] = 0; // backtrack if cannot get to end
        return false;
    }
}
int main()
{
    int arr[5][5] = {{1, 0, 1, 0, 1},
                     {1, 1, 1, 1, 1},
                     {0, 1, 0, 1, 0},
                     {1, 0, 0, 1, 1},
                     {1, 1, 1, 0, 1}};
    int solArr[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (Maze(arr, 0, 0, 5, solArr))
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
