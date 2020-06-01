# bash

g++ --coverage -o test-run test-cases.c test.c -lboost_unit_test_framework
./test-run --log_level=all  --output_format=XML >c2test_results.xml > /dev/null # --log_format=JUNIT >test-results/jutest_results
gcov test-cases.c > /dev/null
lcov --directory . --capture --output-file lcov/testout > /dev/null
genhtml lcov/testout --output-directory html > /dev/null


mv *_results.* test-results/ > /dev/null
mv *.gcov gcov/ > /dev/null
mv *.gcda gcov/ > /dev/null
mv *.gcno gcov/ > /dev/null
mv test-run executables/
./executables/test-run --log_level=error --output_format=HRF >failed_results.txt >>errors.txt
firefox ./html/index.html
