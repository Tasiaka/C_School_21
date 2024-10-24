CC=gcc -std=c11
LFLAGS=-Wall -Wextra -Werror
FLAG_COV=--coverage

S21_FUNC_TESTS_C=tests/*_test.c
S21_FUNC_TESTS_O=objects/*_test.o

OS=$(shell uname -s)

ifeq ($(OS),Linux)
	TEST_LIBS =-lcheck -lm -lsubunit
else
	TEST_LIBS =-lcheck
endif

all: gcov_report

s21_math.a:
	$(CC) $(CFLAGS) -c s21_math.c
	ar rc s21_math.a *.o
	ranlib s21_math.a

test: s21_math.a
	$(CC) -c $(CFLAGS) $(S21_FUNC_TESTS_C) tests/main.c
	mkdir -p objects/
	mv *.o *.a objects/
	ar rc objects/s21_func_tests.a $(S21_FUNC_TESTS_O)
	ranlib objects/s21_func_tests.a
	$(CC) $(LFLAGS) $(FLAG_COV) -o s21_math objects/s21_math.a objects/s21_func_tests.a s21_math.c objects/main.o $(TEST_LIBS)
	./s21_math

gcov_report: test
	gcov ./s21_math
	lcov -c -d . -o gcov.info
	genhtml gcov.info -o gcov_report
	open gcov_report/index.html

format:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c *.h tests/*.c tests/*.h
	@clang-format -n *.c *.h tests/*.c tests/*.h
	@rm .clang-format

clean:
	rm -rf gcov_report/
	rm -rf objects/
	rm -f *.info s21_math
	rm -f *.gcda *.gcno *.gcov

rebuild: clean all
