FILES_CPP=$(wildcard *.cpp)
MAIN=main
MAIN_OUT=$(MAIN).out
CPP_COMPILER=g++
## ARGV : ARGV="filas columnas" se coloca al ajecutar el makefile ej: gmake ARGV="3 4"  
# https://stackoverflow.com/questions/2214575/passing-arguments-to-make-run

# Sanitizer
FLAGS_SANITIZE= -fsanitize=address -fsanitize=leak -fsanitize=pointer-compare -fsanitize=pointer-subtract  -fsanitize=undefined

## Por defecto compila todo y ejecuta todos los archivos cpp
$(MAIN_OUT) : $(FILES_CPP)
	$(CPP_COMPILER) $^ -o $@
	./$@ $(ARGV)

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
