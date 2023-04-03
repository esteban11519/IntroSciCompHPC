#MAIN_CPP=$(wildcard *.cpp)
MAIN=main
MAIN_OUT=$(MAIN).out
MAIN_CPP=$(MAIN).cpp

# Makefile
MAKEFILE=Makefile

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
HIGH=10000
# Tamaño de la muestra
N=1000
# Repetición de cada muestra
n=30

# Figuras
FIGURA = figura
FIGURA_BARRAS_ERROR = $(FIGURA)_media_nxm_barras_error.pdf
FIGURA_DESVIACION = $(FIGURA)_desviacion_nxm.pdf
FIGURA_MEDIA = $(FIGURA)_media_nxm.pdf
FIGURA_PY = $(FIGURA).py 

# Compiladores
CPP_COMPILER=g++
PY_EXE=python3
## ARGV : ARGV="filas columnas" se coloca al ajecutar el makefile ej: gmake ARGV="3 4"  
# https://stackoverflow.com/questions/2214575/passing-arguments-to-make-run

# Sanitizer
FLAGS_SANITIZE= -fsanitize=address -fsanitize=leak -fsanitize=pointer-compare -fsanitize=pointer-subtract  -fsanitize=undefined

all : $(FIGURA_BARRAS_ERROR) $(FIGURA_MEDIA) $(FIGURA_DESVIACION) 

$(FIGURA_BARRAS_ERROR) : $(FIGURA_PY) $(RESULTS)
	$(PY_EXE) $< $(RESULTS) $@ $(FIGURA_DESVIACION) $(FIGURA_MEDIA) $(n)

$(FIGURA_DESVIACION) : $(FIGURA_PY) $(RESULTS)
	$(PY_EXE) $< $(RESULTS) $(FIGURA_BARRAS_ERROR) $@ $(FIGURA_MEDIA) $(n)

$(FIGURA_MEDIA) : $(FIGURA_PY) $(RESULTS)
	$(PY_EXE) $< $(RESULTS) $(FIGURA_BARRAS_ERROR) $(FIGURA_DESVIACION) $@ $(n)


$(RESULTS) : $(MAIN_AUX_OUT) $(MAIN_OUT) $(MAKEFILE)
	./$(MAIN_AUX_OUT) "./$(MAIN_OUT)" $@ $(LOW) $(HIGH) $(N) $(n)

$(MAIN_AUX_OUT) : $(MAIN_AUX_CPP)
	$(CPP_COMPILER) $< -o $@

$(MAIN_OUT) : $(MAIN_CPP)
	$(CPP_COMPILER) $< -o $@


## figuras : realiza las figuras
.PHONY : figuras
figuras:
	$(PY_EXE) $(FIGURA_PY) $(RESULTS) $(FIGURA_BARRAS_ERROR) $(FIGURA_DESVIACION) $(FIGURA_MEDIA) $(n)


## data : se crean los datos
.PHONY : data
data:
	$(CPP_COMPILER) $(MAIN_AUX_CPP) -o $(MAIN_AUX_OUT)
	./$(MAIN_AUX_OUT) "./$(MAIN_OUT)" $(RESULTS) $(LOW) $(HIGH) $(N) $(n)


## run : Compila y se ejecuta
.PHONY : run
run:
	$(CPP_COMPILER) $(MAIN_CPP) -o $(MAIN_OUT)
	./$(MAIN_OUT) $(ARGV)


## debugging : Se realiza el debugging
.PHONY : debugging
debugging:
	$(CPP_COMPILER) $(MAIN_CPP) -o $(MAIN_OUT)
	gdb $(MAIN_OUT) $(ARGV)

## sanitizer: Aplica algunos sanitazers preseleccionados y corre el programa
.PHONY : sanitizer
sanitizer: 
	$(CPP_COMPILER) $(MAIN_CPP) -o $(MAIN_OUT) $(FLAGS_SANITIZE)
	./$(MAIN_OUT) $(ARGV)

## clean : Borra los archivos autogenerados
.PHONY : clean
clean : 
	rm -f *.out
	rm -f *.pdf
	rm -f *.txt

## help : Descripción de todas las opciones disponibles
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $<

# Bibliografía
# [1] «Automation and Make». https://swcarpentry.github.io/make-novice/ (accedido 24 de febrero de 2023).
