#include <asm-generic/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/network.h"
#include "include/dataLoader.h"
#include <omp.h>

#define TRAINING_SAMPLES 27455
#define TEST_SAMPLES 7172
#define INPUT_SIZE 784
#define HIDDEN_SIZE 128
#define OUTPUT_SIZE 24
#define EPOCHS 10
#define LEARNING_RATE 0.005

double calculateAccuracy(NeuralNetwork *nn, double **images, int *labels, int numSamples) {
    int correct = 0;
    double hiddenLayer[HIDDEN_SIZE];
    double outputLayer[OUTPUT_SIZE];

    for (int i = 0; i < numSamples; i++) {
        forwardPropagation(nn, images[i], hiddenLayer, outputLayer);
        int predictedLabel = 0;
        double maxOutput = outputLayer[0];
        for (int j = 1; j < OUTPUT_SIZE; j++) {
            if (outputLayer[j] > maxOutput) {
                maxOutput = outputLayer[j];
                predictedLabel = j;
            }
        }
        if (predictedLabel == labels[i]) {
            correct++;
        }
    }

    return (double)correct / numSamples;
}

void generateSubmission(NeuralNetwork *nn, double **testImages, int numSamples, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for submission.\n");
        return;
    }

    fprintf(file, "Id,Label\n");

    double hiddenLayer[HIDDEN_SIZE];
    double outputLayer[OUTPUT_SIZE];

    for (int i = 0; i < numSamples; i++) {
        forwardPropagation(nn, testImages[i], hiddenLayer, outputLayer);
        int predictedLabel = 0;
        double maxOutput = outputLayer[0];
        for (int j = 1; j < OUTPUT_SIZE; j++) {
            if (outputLayer[j] > maxOutput) {
                maxOutput = outputLayer[j];
                predictedLabel = j;
            }
        }
        fprintf(file, "%d,%d\n", i, predictedLabel);
    }

    fclose(file);
    printf("Submission file generated: %s\n", filename);
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    srand(time(NULL));

    // Allocate memory
    double **trainingImages = (double **)malloc(TRAINING_SAMPLES * sizeof(double *));
    int *trainingLabels = (int *)malloc(TRAINING_SAMPLES * sizeof(int));
    double **testImages = (double **)malloc(TEST_SAMPLES * sizeof(double *));
    int *testLabels = (int *)malloc(TEST_SAMPLES * sizeof(int));

    for (int i = 0; i < TRAINING_SAMPLES; i++) {
        trainingImages[i] = (double *)malloc(INPUT_SIZE * sizeof(double));
    }
    for (int i = 0; i < TEST_SAMPLES; i++) {
        testImages[i] = (double *)malloc(INPUT_SIZE * sizeof(double));
    }

    printf("Memory allocated...\n");

    // Load data
    loadSignLanguageData("dataset/sign_mnist_train.csv", "dataset/sign_mnist_test.csv", trainingImages, trainingLabels, testImages, testLabels, TRAINING_SAMPLES, TEST_SAMPLES);
    printf("Data loaded, creating neural network...\n");

    // Create and train neural network
    NeuralNetwork *nn = createNeuralNetwork(INPUT_SIZE, HIDDEN_SIZE, OUTPUT_SIZE);
    printf("Neural network created, starting training...\n");
    trainNetwork(nn, trainingImages, trainingLabels, TRAINING_SAMPLES, EPOCHS, LEARNING_RATE);
    printf("Training complete.\n");

    // Calculate and print accuracies
    double trainingAccuracy = calculateAccuracy(nn, trainingImages, trainingLabels, TRAINING_SAMPLES);
    printf("Training accuracy: %.2f%%\n", trainingAccuracy * 100);

    double testAccuracy = calculateAccuracy(nn, testImages, testLabels, TEST_SAMPLES);
    printf("Test accuracy: %.2f%%\n", testAccuracy * 100);

    // Generate submission file
    generateSubmission(nn, testImages, TEST_SAMPLES, "sign_language_submission.csv");

    // Free memory
    freeNeuralNetwork(nn);
    for (int i = 0; i < TRAINING_SAMPLES; i++) {
        free(trainingImages[i]);
    }
    for (int i = 0; i < TEST_SAMPLES; i++) {
        free(testImages[i]);
    }
    free(trainingImages);
    free(trainingLabels);
    free(testImages);
    free(testLabels);

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed_time = (end.tv_sec - start.tv_sec) +
    (end.tv_nsec - start.tv_nsec) / 1E9;

    double time_in_minutes = elapsed_time / 60;

    printf("Elapsed time in minutes: %f\n", time_in_minutes);

    return 0;
}
