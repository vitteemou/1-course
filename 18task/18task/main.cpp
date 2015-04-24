#include <iostream>

using namespace std;

int main()
{
	int numb;
	cout << "Enter the number" << endl;
	cin >> numb;

	int i = 2;
	int arr[1000];
	int j = 0;
	int divAmount = 1;  // amount of divisors
	int degCount = 0;   // counter of degrees

	_asm
	{

	  beg_ :
		   cmp numb, 1
		   je end_

		   mov degCount, 0

		   mov eax, numb
		   mov ebx, i
		   div ebx

	  /////////

	   while_beg :	   
		   cmp edx, 0
		   jne iplus_

		   mov numb, eax
		   inc degCount
		   jmp while_beg

	  /////////
	       
	  mov arr[esi], degCount
	  inc esi

	  iplus_ :
		   inc i
		   jmp beg_

	  end_ :
		   mov j, esi

			   //////////for//////
		 mov eax, 1
	         mov ecx, j 
		 dec j
		 mov esi, j 

	 for_beg : 
		   inc arr[esi]
		   mul arr[esi]
		   dec esi 

		   loop for_beg
		   mov divAmount, eax
	}

	cout << "Amount of divisors of the number: " << divAmount << endl;

	system("PAUSE");
	return 0;
}
