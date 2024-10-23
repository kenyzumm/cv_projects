#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

#define N 4


void showBoard(int arr[N][N])
{
    cout << "-----------------" << endl; 
    for(int i=0; i<N; i++)
    {
        cout << "| ";
        for(int j=0; j<N; j++)
            cout << arr[i][j] << " | ";
        cout << endl << "-----------------" << endl;
    }
}
bool generateNumber(int arr[N][N])
{   
    vector<int> free;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(arr[i][j] == 0)
            {
                free.push_back(i);
                free.push_back(j);
            }
        }
    }
    if(free.size() == 0)
        return false;
    srand((unsigned) time(NULL));
    int random = rand();
    random = random % (free.size()/2);
    arr[free[2*random]][free[2*random+1]] = 2;
    return true;
}
bool moveUp(int arr[N][N])
{
    bool isPossible = false;
    for(int j=0; j<N; j++)
    {
        for(int i=0; i<N; i++)
        {
            for(int k=i+1; k<N; k++)
            {
                if(arr[i][j] == arr[k][j])
                {
                    arr[i][j] *= 2;
                    arr[k][j] = 0;
                    isPossible = true;

                }
                if(arr[i][j] == 0)
                {
                    if(arr[k][j] != 0)
                    {
                        arr[i][j] = arr[k][j];
                        arr[k][j] = 0;
                        isPossible = true;
                    }
                }
            }
        }
    }
    return isPossible;
}
bool moveDown(int arr[N][N])
{
    bool isPossible = false;
    for(int j=N-1; j>=0; j--)
    {
        for(int i=N-1; i>=0; i--)
        {
            for(int k=i-1; k>=0; k--)
            {
                if(arr[i][j] == arr[k][j])
                {
                    arr[i][j] *= 2;
                    arr[k][j] = 0;
                    isPossible = true;

                }
                if(arr[i][j] == 0)
                {
                    if(arr[k][j] != 0)
                    {
                        arr[i][j] = arr[k][j];
                        arr[k][j] = 0;
                        isPossible = true;
                    }
                }
            }
        }
    }
    return isPossible;
}
bool moveLeft(int arr[N][N])
{
    bool isPossible = false;
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=j+1; k<N; k++)
            {
                if(arr[i][j] == arr[i][k])
                {
                    arr[i][j] *= 2;
                    arr[i][k] = 0;
                    isPossible = true;

                }
                if(arr[i][j] == 0)
                {
                    if(arr[i][k] != 0)
                    {
                        arr[i][j] = arr[i][k];
                        arr[i][k] = 0;
                        isPossible = true;
                    }
                }
            }
        }
    }
    return isPossible;
}
bool moveRight(int arr[N][N])
{
    bool isPossible = false;
    for(int i=N-1; i>=0; i--)
    {
        for(int j=N-1; j>=0; j--)
        {
            for(int k=j-1; k>=0; k--)
            {
                if(arr[i][j] == arr[i][k])
                {
                    arr[i][j] *= 2;
                    arr[i][k] = 0;
                    isPossible = true;

                }
                if(arr[i][j] == 0)
                {
                    if(arr[i][k] != 0)
                    {
                        arr[i][j] = arr[i][k];
                        arr[i][k] = 0;
                        isPossible = true;
                    }
                }
            }
        }
    }
    return isPossible;
}
bool canMove(int arr [N][N])
{
    
}
bool move(int arr[N][N])
{
        system("clear");
        showBoard(arr);
        cout << "Podaj ruch: ";
        char x;
        cin >> x;

        switch(x)
        {
            case 'w':
                if(moveUp(arr))
                    move(arr);
                
                break;
            case 'a':
                moveLeft(arr);
                break;
            case 's':
                moveDown(arr);
                break;
            case 'd':
                moveRight(arr);
                break;
            default:
                cout << "Uzywaj wasd do poruszania liczbami";
                break;
        }
}

bool play(int arr[N][N])
{
    while(generateNumber(arr))
        move(arr);
}

int main()
{
    int arr[N][N] = 
    {
        {0,0,0,0,},
        {0,0,0,0,},
        {0,0,0,0,},
        {0,0,0,0,}
    };
    if(play(arr)==false)
    {
        system("clear");
        cout << "Koniec";
    }
    return 0;
}