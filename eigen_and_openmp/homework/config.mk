# Variables
# N = 10 50 100 200 500 1000 2000 3000 4000
OPT_LEV = 0 3
N = 100 200
SAMPLES = 5

# Outputs

DATA = data
DATA_DAT = $(DATA).dat

# Files
CPP_FILES = $(wildcard *.cpp)

MAIN = main
MAIN_OUT = $(MAIN).out

CONFIG_MK = config.mk 

# data/problem increases (correction according to class 2023 04 21 Introduction to HPC) 
RES_1 = weak_scaling
RES_1_PDF = $(RES_1).pdf
RES_1_PY = $(RES_1).py

# Change the processors number (correction according to class 2023 04 21 Introduction to HPC)  
RES_2 = strong_scaling
RES_2_PDF = $(RES_2).pdf
RES_2_PY = $(RES_2).py


# Compilers
COM_CPP = g++
COM_PY = python3
STD_VER = -std=c++17

# Compiler flags
SAN_FLAG = -fsanitize=address,leak,pointer-compare,pointer-subtract,undefined
WAR_FLAG = -Wall
ADD_FLAG = -g

