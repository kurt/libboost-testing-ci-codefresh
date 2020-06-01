# bash

g++ --coverage -o executables/test-run test-cases.c test.c -lboost_unit_test_framework
./executables/test-run --log_level=all -log_format=JUNIT >test-results/jutest_results -output_format=XML >test-results/ctest_results.xml
gcov test-cases.c
mv *.gcov gcov/
mv *.gcda gcov/
mv *.gcno gcov/
lcov --directory ./gcov/ --capture --output-file lcov/testout
genhtml lcov/testout --output-directory html

