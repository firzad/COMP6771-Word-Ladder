// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#ifndef AMCXX_TESTING_RANGE_ALL_UNIQUE_HPP
#define AMCXX_TESTING_RANGE_ALL_UNIQUE_HPP

#include <string>
#include <vector>

#include "range/v3/iterator.hpp"
#include "range/v3/view/unique.hpp"

namespace testing {
	inline auto all_unique(std::vector<std::string> const& ladders) -> bool {
		return ranges::distance(ladders) == ranges::distance(ranges::views::unique(ladders));
	}
} // namespace testing

#endif // AMCXX_TESTING_RANGE_ALL_UNIQUE_HPP
