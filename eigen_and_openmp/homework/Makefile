include config.mk

.PHONY: all
all : $(RES_1_PDF)

$(RES_1_PDF) : $(RES_1_PY)  $(RES_1)_O$(lastword $(OPT_LEV)).txt 
	$(COM_PY) $< $(patsubst %,$(RES_1)_O%.txt,$(OPT_LEV)) $(RES_1)

$(RES_1)_O$(lastword $(OPT_LEV)).txt : $(CPP_FILES) $(CONFIG_MK)
	for level in $(OPT_LEV); \
	do $(COM_CPP) -O$$level $(STD_VER) $(ADD_FLAG) $(WAR_FLAG) $(SAN_FLAG) $(CPP_FILES) -o $(MAIN_OUT);\
		for size in $(N);\
		do echo -n "$$size , "; ./$(MAIN_OUT) $$size $(SAMPLES);\
		done > $(RES_1)_O$$level.txt;\
	done

.PHONY : compile_and_run
compile_and_run:
	$(COM_CPP) $(ADD_FLAG) $(WAR_FLAG) $(SAN_FLAG) $(CPP_FILES) -o $(MAIN_OUT)
	./$(MAIN_OUT) $(N)


## Bibliography
# https://stackoverflow.com/questions/1490949/how-to-write-loop-in-a-makefile
# lastword, patsubst: https://www.gnu.org/software/make/manual/html_node/Text-Functions.html
