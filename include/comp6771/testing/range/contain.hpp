// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#ifndef AMCXX_TESTING_RANGE_CONTAIN_HPP
#define AMCXX_TESTING_RANGE_CONTAIN_HPP

#include <string>
#include <utility>
#include <vector>

namespace testing {
	inline auto contain(std::vector<std::string> const& expected) {
		return [&expected](std::vector<std::string> const& ladder) { return ladder == expected; };
	}
} // namespace testing

#endif // AMCXX_TESTING_RANGE_CONTAIN_HPP
