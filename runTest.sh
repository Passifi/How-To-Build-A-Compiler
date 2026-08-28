#!/bin/bash

pushd ./scripts > /dev/null || exit 1

python3 test.py 2>&1 | tee test1.txt

popd > /dev/null
