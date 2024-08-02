#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

// Definer konstanter for note template og intervaller
const std::vector<std::string> note_template = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const std::vector<int> major_intervals = {2, 2, 1, 2, 2, 2, 1};
const std::vector<int> minor_intervals = {2, 1, 2, 2, 1, 2, 2}; // Korrigert lengden
const std::vector<std::string> rythm_patterns = {"quarter", "half", "whole"};

// Funksjon for å hente et tilfeldig element fra en vektor
std::string getRandomElement(const std::vector<std::string> &vec) {
    return vec[rand() % vec.size()];
}

// Funksjon for å generere en skala basert på rot og intervaller
std::vector<std::string> generateScale(const std::string &root, const std::vector<int> &intervals) {
    std::vector<std::string> scale;
    int start = std::find(note_template.begin(), note_template.end(), root) - note_template.begin();
    scale.push_back(note_template[start]);
    for (int interval : intervals) {
        start = (start + interval) % note_template.size();
        scale.push_back(note_template[start]);
    }
    return scale;
}

// Funksjon for å generere en melodi basert på en skala
void generateMelody(const std::vector<std::string> &scale, int length) { // Korrigert parameter-type
    std::vector<std::pair<std::string, std::string>> melody;
    for (int i = 0; i < length; i++) {
        std::string note = getRandomElement(scale);
        std::string rythm = getRandomElement(rythm_patterns);
        melody.push_back({note, rythm});
    }

    for (const auto &pair : melody) {
        std::cout << pair.first << " (" << pair.second << ")" << " "; 
    }
    std::cout << std::endl;
}

// Hovedfunksjon for programmet
int main() {
    srand(static_cast<unsigned int>(time(0))); // Initier random seed
    std::string key, root;
    std::cout << "Enter the key (Major or minor): ";
    std::cin >> key;

    std::cout << "Enter a root note (C, C#, D, D#...): ";
    std::cin >> root;

    // Sjekk om rot-noten er gyldig
    if (std::find(note_template.begin(), note_template.end(), root) == note_template.end()) {
        std::cout << "Invalid root note!" << std::endl;
        return 1;
    }

    std::vector<std::string> scale;
    if (key == "Major" || key == "major") {
        scale = generateScale(root, major_intervals);
    } else if (key == "Minor" || key == "minor") {
        scale = generateScale(root, minor_intervals);
    } else {
        std::cout << "Invalid key selected!" << std::endl;
        return 1;
    }

    // Generer melodi
    generateMelody(scale, 8);

    return 0;
}


