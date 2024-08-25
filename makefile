build:
gcc -fopenmp src/main.c src/network.c src/dataLoader.c -o sign_language_recognizer -lm
