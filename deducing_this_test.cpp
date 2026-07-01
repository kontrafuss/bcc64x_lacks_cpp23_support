//---------------------------------------------------------------------------

#include <iostream>

#pragma hdrstop

#include "deducing_this_test.h"
//---------------------------------------------------------------------------



std::ostream& operator << (std::ostream& out, const MySet& set)
{
	std::string sep {};
	for (auto i : set._content)
	{
		out << sep << i;
		if (sep.empty()) sep = ", ";
	}
    return out;
}


void deducing_this_test()
{
	auto s = MySet {}.Add(4).Add(8).Add(10);
	std::cout << s << '\n';
}

#pragma package(smart_init)
