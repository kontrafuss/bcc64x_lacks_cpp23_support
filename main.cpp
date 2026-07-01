#include <iostream>
#include <tchar.h>

#include "generator_test.h"
#include "deducing_this_test.h"
#include "ranges_test.h"

int _tmain(int argc, _TCHAR* argv[])
{
    generator_test();
    deducing_this_test();
    ranges_test();
}
