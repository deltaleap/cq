main: main.c
	gcc -Wall -g -ggdb -fsanitize=address -o main main.c

clean:
	rm main