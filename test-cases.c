
/*
g++ --coverage -o executables/test-run test-cases.c test.c -lboost_unit_test_framework
./executables/test-run --log_level=all --output_format=XML >test-results/ctest_results.xml
gcov test-cases.c
mv *.gcov gcov/
mv *.gcda gcov/
mv *.gcno gcov/
lcov --directory ./gcov/ --capture --output-file lcov/testout
genhtml lcov/testout --output-directory html
*/


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE NewC
#include <boost/test/unit_test.hpp>
#include "Header_Test.h"


BOOST_AUTO_TEST_CASE(subtractTest){
	BOOST_CHECK(subtract(3,3)==0);
}

BOOST_AUTO_TEST_CASE(call_subtractTest){
	BOOST_CHECK(call_subtract()==-1);
}

BOOST_AUTO_TEST_CASE(conditionalTest){
	printf("Running Conditional Tests...\n");
	BOOST_CHECK(conditional(1)==1);
	BOOST_CHECK(conditional(0)==1);
	BOOST_CHECK(conditional(10)==0);
	BOOST_CHECK(conditional(-10)==0);
}

BOOST_AUTO_TEST_CASE(newFunctionTest){
	BOOST_CHECK(func()==24);
}


BOOST_AUTO_TEST_SUITE(OtherTests)
BOOST_AUTO_TEST_CASE(thisTest){
	float f=981;
	float m=100;
	float a=9.81;
	BOOST_CHECK(f==round(m*a));
	printf("%f\n",(float)m*a); //this is 981.000061 - there is corruption
}
BOOST_AUTO_TEST_SUITE_END()
