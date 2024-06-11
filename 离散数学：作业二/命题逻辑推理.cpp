#include <iostream>
using namespace std;

int main()
{
	int A, B, C, D, E;
	for (A = 0; A <= 1; A++)
		for (B = 0; B <= 1; B++)
			for (C = 0; C <= 1; C++)
				for (D = 0; D <= 1; D++)
					for (E = 0; E <= 1; E++)
						if ((A || B) && (!A || C) && (!D || E) && (D || !C) && !E)
							cout << "A=" << A << ',' << "B=" << B;
	return 0;
}
