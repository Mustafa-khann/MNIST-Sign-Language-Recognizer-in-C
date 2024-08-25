# MNIST Sign Language Recognizer in C

Welcome to the **MNIST Sign Language Recognizer in C**! This project utilizes the power of neural networks to recognize American Sign Language (ASL) gestures from images using the MNIST dataset, all implemented in C.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Overview

The MNIST Sign Language Recognizer is a machine learning project that applies a neural network model to identify ASL signs from images. By leveraging the MNIST-like dataset specifically tailored for sign language digits, this project demonstrates how classical machine learning techniques can be implemented efficiently using the C programming language.

## Features

- **Neural Network Implementation**: A simple feedforward neural network for image classification.
- **Handwritten Digit Recognition**: Specially designed for recognizing digits in ASL.
- **Performance**: Optimized to run efficiently in C, suitable for embedded systems.
- **Modularity**: Code is organized into modular components for easy understanding and extension.

## Installation

### Prerequisites

- C compiler (e.g., `gcc`)
- Make utility (`make`)
- Git (for cloning the repository)

### Steps

1. **Clone the repository**:
    ```bash
    git clone https://github.com/Mustafa-khann/MNIST-Sign-Language-Recognizer-in-C.git
    cd MNIST-Sign-Language-Recognizer-in-C
    ```

2. **Build the project**:
    ```bash
    make
    ```

3. **Download the Dataset**: Place the MNIST-like sign language dataset in the `data/` directory. Ensure the data is in the correct format as expected by the codebase.

## Usage

Once the project is built and the dataset is in place, you can run the recognizer with:

```bash
./sign_language_recognizer
```

### Options
* Modify the source code to adjust parameters such as learning rate, number of epochs, etc.
* The current implementation uses a simple neural network architecture; feel free to expand and experiment with different models.

### Project Structure
* **src/**: Contains the source code files.
* **include/**: Header files defining functions and structures.
* **data/**: Directory where the MNIST-like dataset should be placed.
* **bin/**: Compiled binaries.
* **Makefile**: Script for building the project.

### Contributing
Contributions are welcome! If you have ideas to improve the project, whether through optimizing the existing code or adding new features, feel free to fork the repository and submit a pull request. Please ensure your contributions align with the overall project goals and adhere to the existing coding style.

### Steps to Contribute
1. Fork the repository.
2. Create a new branch: `git checkout -b feature-branch-name`
3. Make your changes.
4. Commit your changes: `git commit -m 'Description of changes'`
5. Push to the branch: `git push origin feature-branch-name`
6. Open a pull request.

### License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Acknowledgements
* **MNIST Dataset**: Thanks to Yann LeCun and others who have made the MNIST dataset widely available for educational and research purposes.
* **Inspiration**: This project was inspired by the need to make machine learning accessible and understandable through a practical application in C.
