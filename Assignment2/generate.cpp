#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include<algorithm>
using namespace std;
std::vector<int> generateRandomNumbers(int amount, int min, int max) {
    std::random_device rd;  // Seed for the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator
    std::uniform_int_distribution<int> distribution(min, max); // Uniform distribution between min and max

    std::vector<int> randomNumbers;
    randomNumbers.reserve(amount);

    for (int i = 0; i < amount; ++i) {
        int randomNum = distribution(gen);
        randomNumbers.push_back(randomNum);
    }

    return randomNumbers;
}

int main() {
    int amount = 100000; // Number of random numbers to generate
    int minRange = 1000; // Minimum value of the range
    int maxRange = 10000; // Maximum value of the range

    std::vector<int> randomNumbers = generateRandomNumbers(amount, minRange, maxRange);
    sort(randomNumbers.begin(), randomNumbers.end());
    std::fstream myFile;
    myFile.open("out.txt", ios::out);
    for (const auto& num : randomNumbers) {
        myFile << num << " ";
    }
    myFile.close();

    return 0;
}
