# Variables
# SIZE = 1200000000
SIZE = 1200

SIZES = 1000 2000 3000
# PROCESS = 1 2 3 4 5 6 7 8
PROCESS = 1 2 3 4
# Outputs

DATA_1_2 = data_1_2
DATA_3 = data_3

# Files
CPP_FILES = $(wildcard *.cpp)

MAIN = main
MAIN_OUT = $(MAIN).out

CONFIG_MK = config.mk 

# Results

RES_1 = S
RES_1_PDF = $(RES_1).pdf
RES_1_PY = $(RES_1).py

RES_2 = E
RES_2_PDF = $(RES_2).pdf
RES_2_PY = $(RES_2).py

RES_3 = Delta
RES_3_PDF = $(RES_3).pdf
RES_3_PY = $(RES_3).py

# Compilers
COM_CPP = mpic++
COM_PY = python3
STD_VER = -std=c++17

# RUNs
RUN_CPP = mpirun

# Compiler flags
WAR_FLAG = -Wall -Wextra
ADD_FLAG = -g

# Sanitizers
SAN_FLAG = -fsanitize=address,leak,pointer-compare,pointer-subtract,undefined
SAN_FLAG_PAR = -fsanitize=thread
