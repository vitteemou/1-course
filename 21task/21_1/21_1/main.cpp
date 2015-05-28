//To find the last inclusion of the element in string
# include <iostream>

using namespace std;

int strLength(char * s)
{
	int res = 0;
	_asm
	{
		cld
			mov edi, s
			mov esi, edi
			mov ecx, 0ffffffffh
			xor al, al
			repne scasb

			sub edi, esi
			dec edi
			mov res, edi
	}

	return res;
}

int main()
{
	char s1[100];
	cout << "Enter the string" << endl;
	cin >> s1;

	int len = strLength(s1);

	char symb;
	cout << "Enter the symbol" << endl;
	cin >> symb;

	int myIndex; // index of the symbol

	_asm
	{
		    mov ecx, len // string length
			mov al, symb
			lea edi, s1
			mov esi, edi

			add edi, ecx
			dec edi
			inc ecx
			std

			repne scasb // scanning of the string
			jecxz not_found // symbol wasn't found

			sub edi, esi
			inc edi // because edi points to the next symbol
			mov myIndex, edi

		not_found :
		    cld
	}

	cout << myIndex << endl;
	return 0;
}