tokenize: tokenizer.o main.o history.o



	gcc -o tokenize tokenizer.o main.o history.o



history.o: history.h history.c



tokenizer.o: tokenizer.h tokenizer.c



main.o: main.c



run:

	./tokenize



clean:

	rm -f *.o tokenize
