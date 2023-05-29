include config.mk

all : $(patsubst %.py, %.pdf, $(wildcard *.py))

$(RES_3_PDF) : $(RES_3_PY) $(DATA_3).dat
	$(COM_PY) $^ $@

$(RES_2_PDF) : $(RES_2_PY)  $(DATA_1_2).dat 
	$(COM_PY) $^ $@

$(RES_1_PDF) : $(RES_1_PY) $(DATA_1_2).dat 
	$(COM_PY) $^ $@

$(DATA_3).dat : $(MAIN_OUT) 
	for siz in $(SIZES); \
	do $(RUN_CPP) -np 4 $(MAIN_OUT) $$siz;\
	done > $@

$(DATA_1_2).dat : $(MAIN_OUT) 
	for pro in $(PROCESS); \
	do echo -n "$$pro " >&2; $(RUN_CPP) -np $$pro $(MAIN_OUT) $(SIZE);\
	done 2> $@


$(MAIN_OUT) : $(CPP_FILES) $(CONFIG_MK)
	$(COM_CPP) $(ADD_FLAG) $(WAR_FLAG)  $(STD_VER) $(CPP_FILES) -o $@


.PHONY : compile_parallel
compile_parallel:
	$(COM_CPP) $(ADD_FLAG) $(WAR_FLAG) $(STD_VER) $(SAN_FLAG_PAR) $(CPP_FILES) -o $(MAIN_OUT)

.PHONY : compile_serial
compile_serial:
	g++ $(ADD_FLAG) $(WAR_FLAG) $(SAN_FLAG) $(STD_VER) $(CPP_FILES) -o $(MAIN_OUT)


.PHONY : clean

clean :
	rm -rf *.pdf
	rm -rf *.dat
	rm -rf *.out


## Bibliography
# https://stackoverflow.com/questions/1490949/how-to-write-loop-in-a-makefile
# lastword, patsubst: https://www.gnu.org/software/make/manual/html_node/Text-Functions.html
