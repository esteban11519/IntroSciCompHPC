CPP_FILES = $(wildcard *.cpp)

MAIN = main
MAIN_CPP = $(MAIN).cpp
MAIN_OUT = $(MAIN).out

FSANITIZE = -fsanitize=address,undefined
STD_VERSION = -std=c++17
COMPILER_FLAGS = -g -Wall
OPTIMIZATION_FLAGS=-O3 -fopenmp
CPP_COMPILER = g++
MATRIZ_SIZE = 20
SEED = 1

.PHONY : run
run : $(MAIN_OUT)
	OMP_NUM_THREADS=2 ./$(MAIN_OUT) $(MATRIZ_SIZE) $(SEED)

$(MAIN_OUT) : $(CPP_FILES) Makefile
	$(CPP_COMPILER) $(OPTIMIZATION_FLAGS) $(COMPILER_FLAGS) $(STD_VERSION) $(FSANITIZE) $(CPP_FILES) -o $(MAIN_OUT)



# Some descriptions
# fsanitize : help to check the code https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html
# std : cpp standar 
# -g : give the line number when a error pass
# -Wall : Give some warnings
# -O3 : Optimizations levels https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
# -fopenmp : Threads in eigen library
# OMP_NUM_THREADS : How many threads you need 
