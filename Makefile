all:
	@g++ calc.cpp -o calc
	@./calc

run:
	@./calc

clean:
	@rm calc