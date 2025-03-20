CC = g++
CFLAGS = -Wall -g

all: p4

p4: radix_bucket.o
	$(CC) $(CFLAGS) -o p4 radix_bucket.o

radix_bucket.o: radix_bucket.cpp
	$(CC) $(CFLAGS) -c radix_bucket.cpp

clean:
	rm -f *.o p4
