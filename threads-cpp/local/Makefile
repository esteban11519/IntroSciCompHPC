include config.mk

%.pdf : %.py $(patsubst %,$(DATA)_parallel_%.dat,$(PARALLEL))
	$(COM_PY) $^ $@


$(DATA)_parallel_$(lastword $(PARALLEL)).dat : $(MAIN_OUT) 
	for par in $(PARALLEL); \
	do;\
		for thr in $(THREADS);\
		do echo -n "$$thr , "; ./$(MAIN_OUT) $$thr $$par;\
		done > $(DATA)_parallel_$$par.dat;\
	done


$(MAIN_OUT) : $(CPP_FILES) $(CONFIG_MK)
	$(COM_CPP) $(ADD_FLAG)  $(STD_VER) $(CPP_FILES) -o $@ $(INC_FLAG)


.PHONY : clean

clean :
	rm -rf *.pdf
	rm -rf *.dat
	rm -rf *.out


## Bibliography
# https://stackoverflow.com/questions/1490949/how-to-write-loop-in-a-makefile
# lastword, patsubst: https://www.gnu.org/software/make/manual/html_node/Text-Functions.html
