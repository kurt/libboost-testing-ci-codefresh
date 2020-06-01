# bash

g++ --coverage -o executables/test-run test-cases.c test.c -lboost_unit_test_framework
./executables/test-run --log_level=all -log_format=JUNIT >test-results/jutest_results -output_format=XML >test-results/ctest_results.xml > /dev/null
./executables/test-run --log_level=error output_format=HRF >test-results/failed_results.txt
gcov test-cases.c > /dev/null
mv *.gcov gcov/
mv *.gcda gcov/
mv *.gcno gcov/
lcov --directory ./gcov/ --capture --output-file lcov/testout > /dev/null
genhtml lcov/testout --output-directory html > /dev/null
firefox ./html/index.html
