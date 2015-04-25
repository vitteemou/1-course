#include <iostream>

using namespace std;

int main()
{
	int numb;
	cout << "Enter the number" << endl;
	cin >> numb;

	int i = 2;
	int divAmount  // amount of divisors
	int degCount;  // counter of degrees

	_asm
	{
            mov ecx, 1

	    beg_:
		   cmp numb, 1
		   je end_

		   mov degCount, 0

	    while_beg :
		    mov eax, numb
		    cdq
		    div i

		    cmp edx, 0
		    jne plus_

		    inc degCount
		    mov numb, eax
		    jmp while_beg

	    plus_ :
		    inc degCount
		    mov eax, degCount
		    imul ecx, eax
		    inc i
		    jmp beg_

	    end_ :
		    mov divAmount, ecx
	
	}

	cout << "Amount of divisors of the number: " << divAmount << endl;

	return 0;
}
