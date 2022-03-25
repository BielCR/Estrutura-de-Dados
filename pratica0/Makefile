all: main.o 
	@gcc main.o -o programa
prototipo0.o: main.c
	@gcc main.c -c
run:
	@./programa < $(RUNCODES_INPUT) > $(RUNCODES_OUTPUT)
