OBJS = build_in_parser.o custom_parser.o parser.o 
CC = g++
TARGET = goodcoder
CFLAGS += -g -std=c++11 -Wall
DEFS = -D BOOST_LOG_DYN_LINK

LDIR = -L/usr/local/lib/
LIBS = -lpthread -lgtest -lgtest_main -lgmock -lgmock_main -lboost_log_setup -lboost_log
INCPATH = -I/usr/local/include/ -I/usr/local/include/google/

$(TARGET): $(OBJS) parser_test.cpp
	$(CC) $(CFLAGS) $(DEFS) -o $(TARGET) parser_test.cpp $(OBJS) $(LDIR) $(LIBS) $(INCPATH)
$(OBJS):%.o:%.cpp %.h
	$(CC) $(CFLAGS) $(DEFS) -c  $< -o $@ $(INCLUDE) 

PHONY.: clean
clean:
	rm -f *.o $(TARGET)
