#include <algorithm>
#include <iterator>
#include <iostream>
#include <queue>
#include <string>

#include "absl/container/flat_hash_map.h"
#include "comp6771/word_ladder.hpp"
#include "range/v3/algorithm.hpp"
#include "range/v3/range.hpp"
#include "range/v3/view.hpp"


namespace word_ladder {

	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            absl::flat_hash_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>> {

	   auto const word_length = from.size();

		if (to.length() != word_length) {
			return {};
		}
		if (from == to){
		return {{from, to}};
		}

		// auto filtered_lexicon = absl::flat_hash_set<std::string>{};
		auto same_length = [word_length](std::string const& lex) { return lex.length() == word_length; };
		// std::copy_if(lexicon.begin(),
		//              lexicon.end(),
		//              std::inserter(filtered_lexicon, filtered_lexicon.end()),
		//              [word_length](std::string const& lex) { return lex.length() == word_length; });

		auto filtered_lexicon = lexicon | ranges::views::filter(same_length) | ranges::to<absl::flat_hash_set<std::string>>;
		// if (!filtered_lexicon.contains(from) or !filtered_lexicon.contains(to)) {
		// 	return {};
		// }

		auto observed_lexicon = absl::flat_hash_map<std::string, unsigned long>{};
		auto ladder_queue = std::queue<std::vector<std::string>>{};
		auto result_ladders = std::vector<std::vector<std::string>>{};

		auto ladder = std::vector<std::string>{from};
		ladder_queue.push(ladder);

		auto curr_size = static_cast<unsigned long>(0);
		// auto result_size = static_cast<unsigned long>(0);;
		auto result_flag = false;
		observed_lexicon[from] = curr_size;
		curr_size++;

		while(!ladder_queue.empty()){
			ladder = ladder_queue.front();
			while(!ladder_queue.empty() and ladder_queue.front().size() <= curr_size){
				ladder = ladder_queue.front();
				ladder_queue.pop();

				auto const word = ladder.back();
				for(auto pos = static_cast<unsigned long>(0); pos < word_length; pos++){
					auto new_word = word;
					for(auto c = 'a'; c <= 'z'; c++){
						auto new_ladder = ladder;
						new_word[pos] = c;
						new_ladder.push_back(new_word);

						if(new_word == to){
							result_ladders.push_back(new_ladder);

							result_flag = true;
							continue;
						}
						if(filtered_lexicon.find(new_word) == filtered_lexicon.end()){
							continue;
						}

						// If new_word present in lexicons, check if previously observed
						// If NOT observed, add it to the map. Else check if its in the same level. Else reject.
						if(observed_lexicon.find(new_word) == observed_lexicon.end()){
							observed_lexicon[new_word] = curr_size;
						} else if(observed_lexicon[new_word] < curr_size){
							continue;
						}
						ladder_queue.push(new_ladder);
					}
				}
			}
			if(result_flag){
				break;
			}
			curr_size++;
		}

		ranges::sort(result_ladders);
		return result_ladders;
	}
} // namespace word_ladder
