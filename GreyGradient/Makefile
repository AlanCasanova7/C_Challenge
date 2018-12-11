CC=clang
CPPCHECK=C:\Program Files\Cppcheck\cppcheck.exe
CFLAGS=-Wall -Werror -Iinclude -Wno-pragma-pack
LDFLAGS=-L. -lSDL2
BINARY=main
BINARY_TESTS=main_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

main.exe: main.o math.o greyscale.o
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

main_tests.exe: tests.o math.o
	$(CC) -o $(BINARY_TESTS) $(LDFLAGS) $^
	./$(BINARY_TESTS)

tests.o: tests.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

math.o: math.c math.h
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^

greyscale.o: greyscale.c greyscale.h
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^