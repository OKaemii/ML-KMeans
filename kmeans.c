/*
k-Means Algorithm

This program performs the k-means clustering task as specified by AA.

Author: Fahad Hafiz
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITERS 1000
#define MAX_SIZE 16384
#define N_POINTS 5

#define SQR(x) ((x) * (x))

struct Point
{
	int clusterID; // the cluster to which it belongs
	float x;
	float y;
};

/*
Returns the Euclidean distance between two points.

struct Point a -- the first point
struct Point b -- the second point
*/
float calcDistance(struct Point A, struct Point B)
{
	// ((A.x - B.x)^2 + SQR(A.y - B.y)^2)^0.5
  return 0f;
}

/*
Performs the k-means clustering algorithm on the given dataset and returns the k-means error metric.
This error metric is the sum of the distance from each point to the centroid of the cluster to which it is assigned.

struct Point* dataset -- the array of points to cluster
int dataSize -- the number of points in the given array
int maxIters -- the maximum number of iterations of the algorithm to perform
*/
float kMeans(struct Point* dataset, int dataSize, int maxIters)
{
	// initialise centroids
		// to update centroids
		// assign all points to their closest centroid
			// for each point, find the nearest centroid c_j
			// add the co-ords to those of the new centroid
			// increment total points for the cluster
			// update error metric
		// re-calculate centroids
			// do not re-calculate centroids for empty clusters
	return 0f;
}

// Takes as parameters a path to an input file containing point data.
int main(int argc, char* argv[])
{
  FILE* fdata;

	if (argc == 2)
	{
		fdata = fopen(argv[1], "r");
	}
	else
	{
		// entered an invalid number of arguments
		// use default
		fdata = fopen("input.csv", "r");
	}

	if (fdata == NULL)
	{
		perror("Error opening file.\n");
		exit(1);
	}

	// init array to contain point data from input.csv

	// populate array with correct data

	// run k-means, and output data
	return 0;
}
