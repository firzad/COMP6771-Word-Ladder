// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "comp6771/word_ladder.hpp"

#include <fstream>
#include <stdexcept>
#include <string>

#include "absl/container/flat_hash_set.h"
#include "range/v3/range/conversion.hpp"
#include "range/v3/view/common.hpp"
#include "range/v3/view/istream.hpp"

namespace word_ladder {
	auto read_lexicon(std::string const& path) -> absl::flat_hash_set<std::string> {
		auto in = std::ifstream(path.data());
		if (not in) {
			throw std::runtime_error("Unable to open file.");
		}

		auto interim = ranges::istream_view<std::string>(in) | ranges::views::common;
		return absl::flat_hash_set<std::string>(ranges::begin(interim), ranges::end(interim));
	}
} // namespace word_ladder
