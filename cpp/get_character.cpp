#include <algorithm>
#include <random>
#include <string>
#include <sstream>

// obtain a seed from a random_device for random number generator
std::random_device seed;
std::minstd_rand rng(seed());

std::string shufflePhrase(const std::string &phrase) {
    std::string shuffledPhrase = nullptr;
    std::string underscores = nullptr;
    std::stringstream ss(phrase);
    std::string word = nullptr;

    while (ss >> word) {

        // <algorithm> has a nice shuffle function that works on all iterable types
        std::shuffle(word.begin(), word.end(), rng);
        shuffledPhrase += word + ' ';

        // Add an underscore and space for each letter in the word
        for (const auto &letter : word) {
            underscores += "_ ";
        }
        underscores += ' ';
    }

    // Combine our shuffled phrase and underscores. We strip off the last 2 spaces.
    return shuffledPhrase + underscores.substr(0, underscores.size() - 2);
}