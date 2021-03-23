# Author: Mackenzie Broughton
# Makefile for Frequency Calculator
# March 6, 2020

CCC = g++ 
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

all : freqCalc
freqCalc : freqCalc.o
	$(CCC) $(CCCFLAGS) $^ -o $@


%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

clean :
	rm -f *.o *~ *% *# .#*

clean-all : clean
	rm -f freqCalc
