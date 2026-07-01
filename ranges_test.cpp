//---------------------------------------------------------------------------

#include <ranges>
#include <iostream>

#pragma hdrstop

#include "ranges_test.h"
//---------------------------------------------------------------------------

void ranges_test()
{
	using namespace std::views;

	auto chess_fields = cartesian_product(
		iota('A') | take(8),
		iota(1)   | take(8) )
		| std::views::transform([](auto t) {
			auto [x, y] = t;
			return std::string(1, x) + std::to_string(y);
		});

	for (auto field : chess_fields)
        std::cout << field << '\n';
}

/* Expected output:

A1
A2
A3
A4
A5
A6
A7
A8
B1
B2
B3
...

*/

#pragma package(smart_init)
