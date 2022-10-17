# Jacobi parallel method

### Compile
- `make all` - build the code with all rules listed below to build every executable
- `make prod` - build the code with default parameters to run all its versions
- `make debug` - build the code with debug purposes, so that it prints the matrices created and their solutions
- `make overhead` - build the code to find the overhead of the parallel versions
- `make seq` - build the code to run only the sequential version
- `make std` - build the code to run only the standard threads version
- `make ff` - build the code to run only the FastFlow version
- `make par` - build the code to run both parallel versions
- `make clean` - remove the old executable

### Run
Run with `./jacobi <matrix-size> <seed> <nw>` to create a random matrix with seed `seed` and `nw` number of workers.

To run the test simply run `./test.sh` or the Python files singularly, and copy the results in `plot.py` to plot them into graphs.