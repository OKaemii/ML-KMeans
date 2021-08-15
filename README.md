# K-Means cluster
The K-means algorithm is an iterative 2-step expectation-maximisation algorithm. The Expectation Step, and Maximisation Step are run repeatedly until no additional changes occur; this algorithm ensures that the square of the error metric will always decrease on every step (until convergence is achieved).

The specification and input.csv found in `test/input.csv` were provided by and found on Audio Analytic's coding exercise.

### Expectation Step

In the expectation step each input data point is assigned to the closest cluster centroid measured using the Euclidian distance metric.

### Maximisation Step

In the maximisation step the total error metric is minimised by adjusting the cluster centroids to the centre of the data points assigned to it. The new centroid of the cluster should be found by computing the mean of the point coordinates in each dimension.

### Convergence

Convergence of the solution is achieved when the expectation step does not change the assignment of any data points; this can also be detected by checking if the total error metric does not change from the previous iteration.

## Details
Given a text file containing comma separated 2D points, each number being a floating point number with one point specified per line,
this program will perform an unsupervised clustering for K=5 clusters, the initialisation of the cluster centres are as follows:

| Cluster Name  | X | Y |
| --- | --- | --- |
| Adam | -0.357 | -0.253 |
| Bob | -0.055 | 4.392 |
| Charley | 2.674 | -0.001 |
| David | 1.044 | -1.251 |
| Edward | -1.495 | -0.090 |


## Build
Windows 7/8/10
```
gcc -std=c99 kmeans.c -o output.exe
```

GNU/Linux using gcc
```
gcc -std=c99 kmeans.c -o output
```

Make
```
CC=gcc
CFLAGS=-std=c99
OBJ=kmeans.c
EXE=kmeans

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE)
```
