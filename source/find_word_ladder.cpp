#include <iostream>

#include "comp6771/word_ladder.hpp"

auto main() -> int {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");
	auto const ladders = word_ladder::generate("awake", "sleep", english_lexicon);

	for (auto const& ladder : ladders) {
		for (auto const& word : ladder) {
			std::cout << word << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "No. of Ladders: " << ladders.size() << '\n';

	return 1;
}