CC=gcc -g
AR=ar -rcs
OBJECTS_MAIN1=main1.o
OBJECTS_LIB1 = isort.o
OBJECTS_MAIN2=main2.o
OBJECTS_LIB2 = txfind.o
FLAGS= -Wall -fPIC

all: isorts isortd mains isort finds findd mains2 txtfind
mains: $(OBJECTS_MAIN1) libmyisort.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN1) libmyisort.a
isort: $(OBJECTS_MAIN1) libmyisort.so
	$(CC) $(FLAGS) -o isort $(OBJECTS_MAIN1) ./libmyisort.so
isorts: libmyisort.a
libmyisort.a: $(OBJECTS_LIB1) isort.h
	$(AR) libmyisort.a $(OBJECTS_LIB1)
iisortd: libmyisort.so
libmyisort.so: $(OBJECTS_LIB1) isort.h
	$(CC) -shared -o libmyisort.so $(OBJECTS_LIB1)
main1.o: main1.c
	$(CC) $(FLAGS) -c main1.c
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c
mains2: $(OBJECTS_MAIN2) libmytxfind.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN2) libmytxfind.a
txtfind: $(OBJECTS_MAIN2) libmytxfind.so
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIN2) ./libmytxfind.so
finds: libmytxfind.a
libmytxfind.a: $(OBJECTS_LIB2) txfind.h
	$(AR) libmytxfind.a $(OBJECTS_LIB2)
findd: libmytxfind.so
libmytxfind.so: $(OBJECTS_LIB2) txfind.h
	$(CC) -shared -o libmytxfind.so $(OBJECTS_LIB2)
main2.o: main2.c
	$(CC) $(FLAGS) -c main2.c
txfind.o: txfind.c txfind.h
	$(CC) $(FLAGS) -c txfind.c

.PHONY: clean all isorts isortd finds findd

clean:
	rm -f *.o *.a *.so mains isort mains2 txtfind