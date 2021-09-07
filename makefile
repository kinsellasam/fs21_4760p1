CC := gcc
CFLAGS := -Wall -Werror

all: driver

driver : main.o header.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c header.h
	$CC $(CFLAGS) -c $<

header.o: header.c header.h
	$CC $(CFLAGS) -c $<

clean:
	rm -f driver main.o header.o
