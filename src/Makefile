CC=gcc
H5CC=h5cc
OMPFLAGS = -g -fopenmp

all: testBlock testRepro testRepro2 testRepro3 testReproHDF5

testBlock.o: testBlock.c
	$(CC) -o $@ -c $<
testRepro.o: testRepro.c
	$(CC) -o $@ -c $<
testRepro2.o: testRepro2.c
	$(CC) -o $@ -c $<
testRepro3.o: testRepro3.c
	$(CC) -o $@ -c $<
testReproHDF5.o: testReproHDF5.c
	$(H5CC) -c $< -o $@ 
reproject.o: reproject.c
	$(CC) -o $@ -c $<
io.o: io.c
	$(H5CC) -c $< -o $@
testBlock: testBlock.o reproject.o
	$(CC) -o ../$@ $+ -lm
testRepro: testRepro.o reproject.o
	$(CC) -o ../$@ $+ -lm
testRepro2: testRepro2.o reproject.o
	$(CC) -o ../$@ $+ -lm
testRepro3: testRepro3.o reproject.o
	$(CC) -o ../$@ $+ -lm
testReproHDF5: testReproHDF5.o reproject.o io.o
	$(H5CC) -o ../$@ $+ -lm

clean:
	rm *.o ../testBlock ../testRepro ../testRepro2 ../testRepro3 ../testReproHDF5
