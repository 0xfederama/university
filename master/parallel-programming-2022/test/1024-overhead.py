import subprocess

# Get the number of CPU cores
import os
cores = os.cpu_count()
print("Running with max", cores, "workers.\n")

# Functions to plot
x = list(range(1, cores+1))
y_seq = []
y_std_overhead = []
y_ff_overhead  = []
y_std_expected = []
y_ff_expected = []

# Run the code sequentially
best_seq = float('inf')
print("Running the sequential version\n")
for _ in range(10):
    # Run always with the same seed to have the same matrix
    result = subprocess.getoutput(f'./bin/jacobi_seq 1024 1 1')
    tokenized = result.split()
    best_seq = min(best_seq, float(tokenized[1]))
y_seq = [best_seq] * len(x)

# Run the code on a matrix 1024x1024 with growing number of workers
print("Running the parallel versions")
for nw in x:
    print("Running with", nw, "workers")
    # Run jacobi for 10 times each iteration and get the average
    avg_std_overhead = 0
    avg_ff_overhead  = 0
    for _ in range(10):
        # Run always with the same seed to have the same matrix
        result = subprocess.getoutput(f'./bin/jacobi_overhead 1024 1 {nw}')
        tokenized = result.split()
        avg_std_overhead += float(tokenized[1])
        avg_ff_overhead  += float(tokenized[4])
    avg_std_overhead /= 10
    avg_ff_overhead /= 10
    y_std_overhead.append(avg_std_overhead)
    y_ff_overhead.append(avg_ff_overhead)
    y_std_expected.append(best_seq / nw + avg_std_overhead)
    y_ff_expected.append(best_seq / nw + avg_ff_overhead)

# Write results to file and read them
with open("./test/results/1024-overhead.txt", "w+") as f:
    f.write("Workers: ")
    f.write(str(x))
    f.write("\nSequential:\n")
    f.write(str(y_seq))
    f.write("\nSTD threads overhead:\n")
    f.write(str(y_std_overhead))
    f.write("\nFastFlow overhead:\n")
    f.write(str(y_ff_overhead))
    f.write("\nSTD threads expected times:\n")
    f.write(str(y_std_expected))
    f.write("\nFastFlow expected times:\n")
    f.write(str(y_ff_expected))
with open("./test/results/1024-overhead.txt", "r") as f:
    print(f.read())
