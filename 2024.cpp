#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define N 4

//wyswietlenie tablicy
void showBoard(int arr[N][N])
{
    cout << "-----------------------------" << endl; 
    for(int i=0; i<N; i++)
    {
        cout << "| ";
        for(int j=0; j<N; j++)
            cout << setw(4) << arr[i][j] << " | ";
        cout << endl << "-----------------------------" << endl;
    }
}

//losowanie miejsca, w ktorym ma pojawic sie 2
bool generateNumber(int arr[N][N])
{   
    vector<int> free;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(arr[i][j] == 0)
            {
                free.push_back(i);
                free.push_back(j);
            }
    if(free.size() == 0)
        return false;
    srand((unsigned) time(NULL));
    int random = rand();
    random = random % (free.size()/2);
    arr[free[2*random]][free[2*random+1]] = 2;
    return true;
}

//poruszanie w gore
bool moveUp(int arr[N][N])
{
    bool isPossible = false;
    for(int j=0; j<N; j++)
        for(int i=0; i<N; i++)
            for(int k=i+1; k<N; k++)
                if(arr[i][j] == 0 && arr[k][j] != 0)
                {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                    isPossible = true;
                }
    for(int j=0; j<N; j++)
        for(int i=0; i<N; i++)
            for(int k=i+1; k<N; k++)
                if(k==i+1 && arr[i][j] == arr[k][j])
                {
                    arr[i][j] *= 2;
                    arr[k][j] =0;
                    isPossible = true;
                }
    for(int j=0; j<N; j++)
        for(int i=0; i<N; i++)
            for(int k=i+1; k<N; k++)
                if(arr[i][j] == 0 && arr[k][j] != 0)
                {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                    isPossible = true;
                }
    return isPossible;
}

//poruszanie w dol
bool moveDown(int arr[N][N])
{
    bool isPossible = false;
    for(int j=N-1; j>=0; j--)
        for(int i=N-1; i>=0; i--)
            for(int k=i-1; k>=0; k--)
                if(arr[i][j] == 0 && arr[k][j] != 0)
                {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                    isPossible = true;
                }
    for(int j=N-1; j>=0; j--)
        for(int i=N-1; i>=0; i--)
            for(int k=i-1; k>=0; k--)
                if(k==i-1 && arr[i][j] == arr[k][j])
                {
                    arr[i][j] *= 2;
                    arr[k][j] =0;
                    isPossible = true;
                }
    for(int j=N-1; j>=0; j--)
        for(int i=N-1; i>=0; i--)
            for(int k=i-1; k>=0; k--)
                if(arr[i][j] == 0 && arr[k][j] != 0)
                {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                    isPossible = true;
                }
    return isPossible;
}

//poruszanie w lewo
bool moveLeft(int arr[N][N])
{
    bool isPossible = false;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=j+1; k<N; k++)
                if(arr[i][j] == 0 && arr[i][k] != 0)
                {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                    isPossible = true;
                }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=j+1; k<N; k++)
                if(k==j+1 && arr[i][j] == arr[i][k])
                {
                    arr[i][j] *= 2;
                    arr[i][k] =0;
                    isPossible = true;
                }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=j+1; k<N; k++)
                if(arr[i][j] == 0 && arr[i][k] != 0)
                {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                    isPossible = true;
                }
    return isPossible;
}

//poruszanie w prawo
bool moveRight(int arr[N][N])
{
    bool isPossible = false;
    for(int i=N-1; i>=0; i--)
        for(int j=N-1; j>=0; j--)
            for(int k=j-1; k>=0; k--)
                if(arr[i][j] == 0 && arr[i][k] != 0)
                {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                    isPossible = true;
                }
    for(int i=N-1; i>=0; i--)
        for(int j=N-1; j>=0; j--)
            for(int k=j-1; k>=0; k--)
                if(k==j-1 && arr[i][j] == arr[i][k])
                {
                    arr[i][j] *= 2;
                    arr[i][k] =0;
                    isPossible = true;
                }
    for(int i=N-1; i>=0; i--)
        for(int j=N-1; j>=0; j--)
            for(int k=j-1; k>=0; k--)
                if(arr[i][j] == 0 && arr[i][k] != 0)
                {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                    isPossible = true;
                }
    return isPossible;
}
//sprawdzenie czy mozliwy jest jakikolwiek ruch dla uzytkownika
bool isPossible(int arr[N][N])
{
    //jesli wystepuje 0, to mozliwy jest ruch
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(arr[i][j] == 0)
                return true;

    //jesli sasiadujace komorki maja taka sama wartosc, to mozliwy jest ruch
    for(int i=0; i<N; i++)
        for(int j=1; j<N; j++)
            if(arr[i][j] == arr[i][j-1])
                return true;
    for(int j=0; j<N; j++)
        for(int i=1; i<N; i++)
            if(arr[i][j] == arr[i-1][j])
                return true;
            
    return false;
}
bool move(int arr[N][N])
{
    if(isPossible(arr))
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
                {
                    generateNumber(arr);
                    move(arr);
                }
                else
                    move(arr);
                break;
            case 'a':
                if(moveLeft(arr))
                {
                    generateNumber(arr);
                    move(arr);
                }
                else
                    move(arr);
                break;
            case 's':
                if(moveDown(arr))
                {
                    generateNumber(arr);
                    move(arr);
                }
                else
                    move(arr);
                break;
            case 'd':
                if(moveRight(arr))
                {
                    generateNumber(arr);
                    move(arr);
                }
                else
                    move(arr);
        }
    }
    return false;
}

bool play(int arr[N][N])
{
    generateNumber(arr);
    generateNumber(arr);
    move(arr);
    return false;
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
   /*int arr[N][N] = 
    {
        {2,4,2,4,},
        {4,2,4,2,},
        {2,64,32,16,},
        {4,16,0,0,}
    };*/
    if(play(arr)==false)
    {
        system("clear");
        cout << "Koniec";
    }
    return 0;
}