#include <iostream>
using namespace std;
//test
#define N 9

void printBoard(int arr[N][N]) {
	for (int i = 0; i <= 8; i++){
		for (int j = 0; j <= 8; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

bool isRowSafe(int arr[N][N], int row, int num) {
	for(int col = 0; col<N; col++) {
		if (arr[row][col] == num)
			return false;
	}
	return true;
}

bool isColSafe(int arr[N][N], int col, int num) {
	for (int row = 0; row < N; row++) {
		if (arr[row][col] == num)
			return false;
	}
	return true;
}

bool isBoxSafe(int arr[N][N], int sRow, int sCol, int num) {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++) {
			if (arr[sRow + row][sCol + col] == num)
				return false;
		}
	return true;
}

bool isSafe(int arr[N][N], int row, int col, int num) {
	return	isRowSafe(arr, row, num) &&
			isColSafe(arr, col, num) &&
			isBoxSafe(arr, row - row % 3, col - col % 3, num);
}

bool solve(int arr[N][N]) {
	int row, col;
	bool isEmpty = false;

	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if (arr[row][col] == 0) {
				isEmpty = true;
				break;
			}
		}
		if(isEmpty)
			break;
	}
	if (!isEmpty)
		return true;

	for (int num = 1; num <= 9; num++) {
		if (isSafe(arr, row, col, num)) {

			arr[row][col] = num;
			if (solve(arr)) {
				return true;
			}
			arr[row][col] = 0;
		}
	}	
	return false;
}


int main() {
	int arr[N][N] = {
		{6,8,5, 1,3,0, 0,4,7},
		{7,0,0, 0,0,0, 0,1,0},
		{0,1,0, 7,6,4, 0,5,0},

		{9,0,0, 0,7,0, 5,0,4},
		{8,0,1, 0,0,9, 0,7,2},
		{4,0,3, 0,0,6, 0,0,0},

		{0,0,0, 4,2,7, 3,9,0},
		{0,4,0, 9,0,0, 0,6,8},
		{1,0,7, 0,0,0, 4,4,0} };
	
	if(solve(arr))
		printBoard(arr);
	else
		cout << "Brak rozwiazan :(";
	return 0;
}