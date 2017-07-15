CC=gcc
H5CC=h5cc

all: testRepro testRepro2 testRepro3

testRepro.o: testRepro.c
	$(CC) -o $@ -c $<
testRepro2.o: testRepro2.c
	$(CC) -o $@ -c $<
testRepro3.o: testRepro3.c
	$(CC) -o $@ -c $<
reproject.o: reproject.c
	$(CC) -o $@ -c $<
io.o: io.c
	$(H5CC) -o $@ -c $<
testRepro: testRepro.o reproject.o
	$(CC) -o ../$@ $+ -lm
testRepro2: testRepro2.o reproject.o
	$(CC) -o ../$@ $+ -lm
testRepro3: testRepro3.o reproject.o
	$(CC) -o ../$@ $+ -lm

clean:
	rm *.o ../testRepro ../testRepro2 ../testRepro3
