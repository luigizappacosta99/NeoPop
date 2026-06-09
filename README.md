# neopop Project

## Overview
The neopop project is a simple application that generates a random 5x5 map and outputs the fertility of each pixel based on its biome. The application is structured with separate source and header files for better organization and maintainability.

## Project Structure
```
neopop
├── srcs
│   ├── main.cc        # Contains the main function for generating the map
│   ├── map.cpp        # Implementation of the map class
│   └── pixel.cpp      # Implementation of the pixel class
├── include
│   ├── map.h          # Declaration of the map class
│   └── pixel.h        # Declaration of the pixel class
├── tests
│   └── test_main.cc   # Test cases for the application
├── Makefile           # Build instructions for the project
├── .gitignore         # Files and directories to ignore by Git
└── README.md          # Documentation for the project
```

## Setup Instructions
1. **Clone the Repository**
   ```bash
   git clone <repository-url>
   cd neopop
   ```

2. **Build the Project**
   Use the provided Makefile to compile the project:
   ```bash
   make
   ```

3. **Run the Application**
   After building, you can run the application with:
   ```bash
   ./neopop
   ```

## Usage
The application will generate a random 5x5 map and print the fertility of each pixel based on its biome. The biomes include Forest, Desert, Plains, Mountain, and Ocean, each with different properties.

## Testing
To run the tests, ensure you have the test files set up in the `tests` directory and compile them using the Makefile. You can add specific test cases in `test_main.cc` to validate the functionality of the `map` and `pixel` classes.

## Contributing
Feel free to submit issues or pull requests for any improvements or bug fixes.