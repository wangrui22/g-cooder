OBJ = \
build_in_parser.o custom_parser.o parser.o 
HEADERS = \
build_in_parser.h custom_parser.h parser.h 
CC = gcc
CXX = g++
TARGET = goodcoder
BASEFLAGS = -g -D_DEBUG=1 -std=c++11
CFLAGS = ${BASEFLAGS} 
LDFLAGS = ${BASEFLAGS}

all: ${TARGET}
${TARGET}: ${OBJ}
	${CXX} ${LDFLAGS} -o ${TARGET} main.cpp ${OBJ} -I/usr/local/include/google/ -L/usr/local/lib/ -lgtest -lgtest_main -lgmock -lgmock_main -lpthread
clean:
	rm -f *.o ${TARGET}

%.o: %.cpp ${HEADERS}
	${CXX} ${CFLAGS} -c $< -o $@
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@