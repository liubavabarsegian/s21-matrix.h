NAME = s21_matrix.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRCS=	*.c
TEST_SRC=	tests/tests.c
TEST_FLAGS_LINUX=  -lcheck -lm -lsubunit -lpthread
TEST_FLAGS= -lcheck -lm -lpthread
GCOV_FLAGS = -ftest-coverage -fprofile-arcs
UNAME_S = $(shell uname -s)
all: ${NAME}

${NAME}:
	$(CC) $(CFLAGS) -c ${SRCS}
	ar rc ${NAME} *.o
	ranlib ${NAME}
	rm *.o

test:
ifeq ($(UNAME_S), Linux)
	make rebuild
	$(CC) $(CFLAGS) -c ${TEST_SRC}
	$(CC) $(CFLAGS) *.o ${NAME} ${TEST_FLAGS_LINUX}  -o test
	./test
else
	make rebuild
	$(CC) $(CFLAGS) -c ${TEST_SRC}	
	$(CC) $(CFLAGS) *.o ${NAME} ${TEST_FLAGS} -o test
	./test
endif

gcov_report:
ifeq ($(UNAME_S), Linux)
	$(CC) $(CFLAGS) -c ${TEST_SRC}
	$(CC)  $(CFLAGS) $(GCOV_FLAGS) -c ${SRCS}
	$(CC)  $(CFLAGS) $(GCOV_FLAGS) *.o $(TEST_FLAGS_LINUX) -o test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html
else
	$(CC) $(CFLAGS) -c ${TEST_SRC}
	$(CC)  $(CFLAGS) $(GCOV_FLAGS) -c ${SRCS}
	$(CC)  $(CFLAGS) $(GCOV_FLAGS) *.o $(TEST_FLAGS) -o test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html
endif

style: 
	clang-format --style=google *.c *.h tests/*.c -n

correct_style: 
	clang-format --style=google *.c *.h tests/*.c -i

clean:
	rm -rf *.o *.a test test_linux *.gcno *.gcda *.info report

rebuild : clean all