cxx_library(
	TARGET word_ladder
	FILENAME word_ladder.cpp
	LINK range-v3 absl::flat_hash_set
)

cxx_library(
	TARGET lexicon
	FILENAME lexicon.cpp
	LINK range-v3 absl::flat_hash_set
)
