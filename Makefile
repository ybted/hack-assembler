all:	assembler
assembler:	main.cpp
	g++ main.cpp -o assembler.exe 

.PHONY:
clean: 
	rm *.o
