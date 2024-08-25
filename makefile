build:
gcc -fopenmp src/main.c src/neuralNetwork.c src/utils.c -o sign_language_recognizer -lm
