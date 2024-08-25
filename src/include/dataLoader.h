#ifndef UTILS_H
#define UTILS_H

void loadSignLanguageData(const char* trainFile, const char* testFile,
    double **trainingImages, int *trainingLabels,
    double **testImages, int *testLabels,
    int trainingSize, int testSize);

#endif
