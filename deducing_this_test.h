//---------------------------------------------------------------------------

#ifndef deducing_this_testH
#define deducing_this_testH

#include <vector>
#include <ostream>
//---------------------------------------------------------------------------

void deducing_this_test();

class MySet
{
public:
	template <typename Self>
	MySet Add(this Self&& self, int elem)
	{
		MySet result = []<typename T>(T&& obj) -> MySet
		{
			if constexpr (std::is_rvalue_reference_v<T&&>)
				return std::move(obj);
			else
				return obj;
		}(std::forward<Self>(self));

		result._content.push_back(elem);
		return result;
	}

	friend std::ostream& operator << (std::ostream&, const MySet& set);

private:
	std::vector<int> _content;
};


#endif
