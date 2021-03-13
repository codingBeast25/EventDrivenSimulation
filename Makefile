CC=clang++
CFLAGS=--std=c++11
all : main test clean
objects = Arrival.o Bursts.o TimeOut.o Simulation.o Queue.o PriorityQueue.o ListItem.o Node.o Event.o Process.o  StartCpu.o CompleteCpu.o StartIo.o CompleteIo.o Exit.o ParentQueue.o 

# this rule will build A2 as the executable from the object files
main: A2main.o $(objects)
	$(CC) $(CFLAGS) -o A2 $< $(objects)

test: Test.o $(objects)
	$(CC) $(CFLAGS) -o runTest $< $(objects)

# this rule will build a .o file from a .cpp file. 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean :
	rm *.o
