#!/bin/bash

echo "C:"
make && ./build/main "$1"

echo

echo "Python:"
python ./src/main.py "$1"

echo

echo "Rust:"
cargo run "$1"
