all : main.cpp 
	gcc -g -Wall -Werror -o main main.cpp 
clean : $(RM) main