#FILES_CPP=$(wildcard *.cpp)
FILES_CPP=main.cpp
MAIN=main
MAIN_OUT=$(MAIN).out

# Auxiliares
MAIN_AUX=main_severals_chrono
MAIN_AUX_CPP=$(MAIN_AUX).cpp
MAIN_AUX_OUT=$(MAIN_AUX).out

# Resultados
RESULTS=results.txt

# Parámetros
# Límite inferior distribución uniforme
LOW=10 
# Límite superior distribución uniforme
HIGH=30
# Tamaño de la muestra
N=10
# Repetición de cada muestra
n=3

# Compiladores
CPP_COMPILER=g++

## ARGV : ARGV="filas columnas" se coloca al ajecutar el makefile ej: gmake ARGV="3 4"  
# https://stackoverflow.com/questions/2214575/passing-arguments-to-make-run

# Sanitizer
FLAGS_SANITIZE= -fsanitize=address -fsanitize=leak -fsanitize=pointer-compare -fsanitize=pointer-subtract  -fsanitize=undefined

## Por defecto compila todo y produce el ejecutable MAIN_OUT
$(MAIN_OUT) : $(FILES_CPP)
	$(CPP_COMPILER) $^ -o $@


## data : se crean los datos
.PHONY : data
data:
	$(CPP_COMPILER) $(MAIN_AUX_CPP) -o $(MAIN_AUX_OUT)
	./$(MAIN_AUX_OUT) "./$(MAIN_OUT)" $(RESULTS) $(LOW) $(HIGH) $(N) $(n)


## run : Compila y se ejecuta
.PHONY : run
run:
	$(CPP_COMPILER) $(FILES_CPP) -o $(MAIN_OUT)
	./$(MAIN_OUT) $(ARGV)


## debugging : Se realiza el debugging
.PHONY : debugging
debugging:
	$(CPP_COMPILER) $(FILES_CPP) -o $(MAIN_OUT)
	gdb $(MAIN_OUT) $(ARGV)

## sanitizer: Aplica algunos sanitazers preseleccionados y corre el programa
.PHONY : sanitizer
sanitizer: 
	$(CPP_COMPILER) $(FILES_CPP) -o $(MAIN_OUT) $(FLAGS_SANITIZE)
	./$(MAIN_OUT) $(ARGV)

## clean : Borra los archivos autogenerados
.PHONY : clean
clean : 
	rm *.out

## help : Descripción de todas las opciones disponibles
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $<

# Bibliografía
# [1] «Automation and Make». https://swcarpentry.github.io/make-novice/ (accedido 24 de febrero de 2023).
