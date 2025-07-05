CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11
GCOV = -fprofile-arcs -ftest-coverage

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    CLIBS=-lcheck -lm -lsubunit
endif

ifeq ($(UNAME_S), Darwin)
    CLIBS=-lcheck -lm
endif

all: s21_matrix.a

clean:
	@rm -rf *.o *.gcno *.gcda *.gcov *.a test logs

s21_matrix.a: clean s21_matrix.o
	@$(CC) $(CFLAGS) -c s21_matrix.c
	@ar rcs s21_matrix.a s21_matrix.o

s21_matrix.o: s21_matrix.c
	@$(CC) $(CFLAGS) -c s21_matrix.c

test: s21_matrix.a
	@rm -rf test
	@$(CC) $(CFLAGS) $(GCOV) test.c s21_matrix.c $(CLIBS) -o test
	@./test

test_memory:
	rm -rf test
	@make test
	# valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-exitcode=1 ./test
	valgrind --tool=memcheck --leak-check=yes ./test

gcov_report: test
	@rm -rf test-test.gcda test-test.gcno
	@mkdir logs
	@gcovr --html-self-contained --html-details -o logs/report.html
	@echo "Building report..."
	@open logs/report.html
