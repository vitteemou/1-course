#include <iostream>

using namespace std;

int main()
{

	int n;
	cout << "Enter n" << endl;
	cin >> n;

	double x;
	cout << "Enter x" << endl;
	cin >> x;

	double a = 1;  // accumulator

	double s1 = 0;  // sum #1
	double p1 = 1;  // product #1

	int fact = 1;   // factorial
	double d = 1;

	double s2 = 0;  // sum #1 
	double p2 = 1;  // product #2

	double res;    // result

	_asm
	{
		mov ecx, 1
			inc n
			fld p2

		begin_ :

		cmp ecx, n //counter
			je exit_

			fld a
			fmul x
			fstp a     // a *= x

			fld s1
			fadd a
			fstp s1     // s1 += a

			mov eax, fact
			imul ecx
			mov fact, eax  //fact *= ecx

			fld s1
			fidiv fact
			fstp d      // d = s1/fact

			fld p1
			fmul d
			fstp p1    // p1 *= d

			fld s2
			fadd p1
			fstp s2    // s2 += p1

			fld p2
			fmul s2
			fst p2    // p2 += s2

			inc ecx
			jmp begin_

		exit_ :
		fstp res
	}

	cout << res << endl;

	return 0;

}
