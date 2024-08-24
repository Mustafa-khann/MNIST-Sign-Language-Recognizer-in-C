build:
	gcc -o mnist_recognizer src/main.c -Iinclude -Llib -lmnist -lm
