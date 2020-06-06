#!/bin/bash

set -e

if [[ ! -d ./vcpkg ]]; then
	git clone https://github.com/Microsoft/vcpkg.git
fi

cd vcpkg
git pull
./bootstrap-vcpkg.sh -disableMetrics
cp ../config/cmake/triplets/* triplets/community/.
./vcpkg install --clean-after-build abseil:x64-linux-libcxx
./vcpkg install --clean-after-build benchmark:x64-linux-libcxx
./vcpkg install --clean-after-build catch2:x64-linux-libcxx
./vcpkg install --clean-after-build fmt:x64-linux-libcxx
./vcpkg install --clean-after-build gsl-lite:x64-linux-libcxx
./vcpkg install --clean-after-build range-v3:x64-linux-libcxx
cd ..
sed -i 's#/import/kamen/1/cs6771#${workspaceFolder}#' .vscode/cmake-kits.json
