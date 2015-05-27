//9) В матрице поменять местами столбцы с заданными номерами.
#include <iostream>

using namespace std;

int main()
{
	const int n = 3; // amount of strings
	const int m = 4; // amount of colomns

	int A[n][m];
	int B[n][m];

	cout << "Enter the elements of matrix" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
		   cin >> A[i][j];
		   B[i][j] = A[i][j];
		}

	cout << endl;

	int c1; //column 1
	int c2; //column 2
	cout << "Enter the numbers of the columns" << endl;
	cin >> c1 >> c2;

	__asm
	{
		    dec c1
			dec c2

			mov ecx, 0// i – номер текущей строки A
			xor ebx, ebx

		begin_ :

		    mov eax, m
			mul ecx
			push eax   // keeping of the product i*m

			add eax, c1
			mov esi, eax  // esi =(i*m + c1)
			mov edi, A[esi * 4]  // edi = A[i][c1]

			pop eax
			add eax, c2
			mov ebx, eax  // ebx =(i*m + c2)
			mov B[ebx * 4], edi  //B[i][c2] = A[i][c1]

			mov eax, A[ebx * 4]
			mov B[esi * 4], eax

			inc ecx // to the next string of the matrix

			cmp ecx, n
			jl begin_
	}

	cout << "New matrix" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << B[i][j] << ' ';
		cout << endl;
	}

	return 0;
}