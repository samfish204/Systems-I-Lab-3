/* Copyright 2020
* Samuel Fisher
* Lab3
* CSE278 - Section B
* Professor Vendome
* September 7, 2020
* This program allows the user to specify a file to read from, 
* and a file to write to from the command line. The program then 
* takes the input file and computes the sum, average, minimum, and maximum
* numbers that were in the file. It then writes these to the output file. 
*/ 
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <climits>

int computeSum(std::vector<int> nums) {
    int sum = 0;
    int i;

    for (i = 0; i < nums.size(); i++) {
        sum = sum + nums[i];
    }

    return sum;
}

double computeAverage(std::vector<int> nums) {
    double average = 0.0;
    double sum = 0;
    int i;

    for (i = 0; i < nums.size(); i++) {
        sum = sum + nums[i];
    }
    average = sum / nums.size();
    return average;
}

int computeMax(std::vector<int> nums) {
    int max = INT_MIN;
    int i;

    for (i = 0; i < nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int computeMin(std::vector<int> nums) {
    int min = INT_MAX;
    int i;

    for (i = 0; i < nums.size(); i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    return min;
}

void printResult(std::ostream& out, int sum, int min, double average, int max) {
    /* Write the sum, average, min, and max to file
     * Output file should be:
     *      Sum: [sum]
     *      Min: [min]    
     *      Average: [average]
     *      Max: [max]
     *
     * The brackets [] represent the actual numerical value
     */
    out << "Sum: " << sum << std::endl;
    out << "Min: " << min << std::endl;
    out << "Average: " << average << std::endl;
    out << "Max: " << max << std::endl;
}

int main(int argc, char *argv[]) {
    // Verify the correct number of arguments
    if ( argc < 3 || argc > 3 ) {
        // If the arguments were not specified,
        // then print to std::cerr and return
        std::cerr << "Specify input and output files" << "\n";
        return 0;
    }

    // Create streams with command line arguments
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    // Check streams were successfully created
    if ( !input.good() || !output.good() ) {
        // If the stream was unsuccessful,
        // then print to std::cerr and return 0
        std::cerr << "Error opening input or output streams" << "\n";
        return 0;
    }

    // Read input file to some data structure
    std::vector<int> numArray;
    int num;
    while ( input >> num ) {
        numArray.push_back(num);
    }
    input.close();

    // Compute the sum, average, min, max
    int sum = computeSum(numArray);
    double average = computeAverage(numArray);
    int min = computeMin(numArray);
    int max = computeMax(numArray); 

    // Display results -- DO NOT MODIFY BELOW THIS LINE
    printResult(output, sum, min, average, max);
    printResult(std::cout, sum, min, average, max);
}
