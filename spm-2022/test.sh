#!/bin/bash

echo "Compiling from source"
make

echo ""
echo "Running 1024 test"
python3 ./test/1024.py

echo ""
echo "Running 5120 test"
python3 ./test/5120.py

echo ""
echo "Running 10240 test"
python3 ./test/10240.py

echo ""
echo "Running 1024-overhead test"
python3 ./test/1024-overhead.py

echo ""
echo "Running matrix test"
python3 ./test/matrix.py
