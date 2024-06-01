#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

const std::vector<std::string> major_scale = {"C", "D", "E", "F", "G", "A", "B"};
const std::vector<std::string> minor_scale = {"A", "B", "C", "D", "E", "F", "G"};
const std::vector<std::string> rythm_patterns = {"quarter", "half", "whole"};

std::string getRandomElement(const std::vector<std::string> &vec) {
	return vec[rand() % vec.size()];
}

void generateMelody(const std::vector<std::string& vec) {
	std::vector<std::pair<std::string, std::string>> melody;
	for(int i = 0; i < length; i++) {
		std::string note = getRandomElement(scale);
		std::string rythm = getRandomElement(rythm_patterns);
		melody.push_back({note, rythm});
	}

	for(const auto& pair : melody) {
		std::cout << pair.first << " (" << pair.second << ")" << " "; 
	}
	std::cout << std::endl;
}

int main() {

	srand(static_cast<unsigned int>(time(0)));
	std::string input;
	std::cout << "Enter the key (Major or minor): ";
	std::cin >> input;

	if(input == "major" || input == "major") {
		generateMelody(major_scale, 8); // eight notes melody generated!
	} else if(input == "minor" || input == "Minor") {
 		generateMelody(minor_scale, 8);
	} else {
		std::cout << "Invalid input!" << std::endl;
	}

	return 0;
}


