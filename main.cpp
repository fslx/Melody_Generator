#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

const std::vector<std::string> note_template = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const std::vector<int> major_intervals = {2, 2, 1, 2, 2, 2, 1};
const std::vector<int> minor_intervals = {2, 1, 2, 2, 1, 2, 2}; 
const std::vector<std::string> rythm_patterns = {"quarter", "half", "whole"};

std::string getRandomElement(const std::vector<std::string> &vec) {
    return vec[rand() % vec.size()];
}

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

// return a new melody based on a scale chosen from the generateScale() method
void generateMelody(const std::vector<std::string> &scale, int length) { 
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

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0))); 
    std::string key, root;
    std::cout << "Enter the key (Major or minor): ";
    std::cin >> key;

    std::cout << "Enter a root note (C, C#, D, D#...): ";
    std::cin >> root;

    // checks whetever or not the input root-note is valid.
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

    generateMelody(scale, 8);

    return 0;
}


