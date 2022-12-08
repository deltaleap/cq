main: main.c
	gcc -Wall -g -ggdb -fsanitize=address -o main main.c cq.c

clean:
	rm main