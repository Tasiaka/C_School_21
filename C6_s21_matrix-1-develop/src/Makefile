CC = gcc
GCOV_FLAGS = -Wall -Werror -Wextra -fprofile-arcs -ftest-coverage 
CFLAGS = -Wall -Werror -Wextra -std=c11
LDFLAGS = -lcheck -lm -lpthread

SRC_DIR = functions
TEST_DIR = tests

ifeq ($(shell uname -s),Linux)
	LDFLAGS =-lcheck  -lcheck_pic -lsubunit -lm -lrt -lpthread
endif
ifeq ($(shell uname -s),Darwin)
	LDFLAGS =-lcheck 
endif

SRC = $(wildcard $(SRC_DIR)/*/*.c)
OBJ_GCOV = $(SRC:.c=.o)
OBJ = $(SRC:.c=.o)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)

.PHONY: all, test, gcov_report, style, clean, s21_matrix.a

all: s21_matrix.a 

clean:
	rm -f s21_matrix.a $(TEST_OBJ) test *.gc* ./$(TEST_DIR)/*.gc* *.o *.info */*.o
	rm -rf report
	
s21_matrix.a: libr
	ar rcs s21_matrix.a *.o
	rm -f *.o
	ranlib s21_matrix.a

test:gcov_make $(TEST_OBJ) 
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage  $(TEST_DIR)/*.o *.o -o test $(LDFLAGS) 
	./test
	rm -f *.o *.gc* 

test_gcov: $(TEST_OBJ) gcov_make
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage  *.o $(TEST_DIR)/*.o -o test $(LDFLAGS)  
	./test


gcov_report: $(TEST_OBJ) test_gcov
	gcov $(TEST_OBJ:.o=.c)
	lcov -c -d . -o coverage.info
	genhtml coverage.info --output-directory report
	open report/index.html
	rm -f *.o *.gc*

gcov_make:
	$(CC) $(GCOV_FLAGS) -c $(SRC_DIR)/*.c 

libr:
	$(CC) $(CFLAGS) -c $(SRC_DIR)/*.c 

cppchecker:
	cppcheck --enable=all --suppress=missingIncludeSystem  $(SRC_DIR)/*.c s21_decimal.h s21_addition.h $(TEST_DIR)/*.c $(TEST_DIR)/testiks.h 

style:
	clang-format -i --style=Google $(SRC_DIR)/*.c *.h $(TEST_DIR)/*.c $(TEST_DIR)/*.h

valgrind:
	gcc $(SRC_DIR)/*.c $(TEST_DIR)/*.c -lcheck -lsubunit -lm
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=res_leak.txt ./a.out
	grep -e ERROR res_leak.txt
	rm -rf *.gcda
