//---------------------------------------------------------------------------

#include <generator>
#include <iostream>

#pragma hdrstop

#include "generator_test.h"
//---------------------------------------------------------------------------

std::generator<int> fib()
{
	int a = 1;
	int b = 1;

	while(true)
	{
		co_yield a;
		a = std::exchange(b, a+b);
	}
}

void generator_test()
{
	for (int f : fib())
	{
		std::cout << f << '\n';
        if (f > 1000) break;
	}
}

/* Expected output:

1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597

*/


#pragma package(smart_init)
