/*
k-Means Algorithm

This program performs the k-means clustering task as specified by AA.

Author: Fahad Hafiz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

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
  return sqrtf(SQR(A.x - B.x) + SQR(A.y - B.y));
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
  float errorMetric = 0.f;
  float prevMetric = -1.f;

  // initialise centroids -- given
  struct Point centroids[5] = {
    // Adam
    { 0, -0.357f, -0.253f },
    // Bob
    { 1, -0.055f, 4.392f },
    // Charley
    { 2, 2.674f, -0.001f },
    // David
    { 3, 1.044f, -1.251f },
    // Edward
    { 4, -1.495f, -0.090f } };

  while ((maxIters-- > 0) && (errorMetric != prevMetric))
  {
    prevMetric = errorMetric;
    errorMetric = 0.f;

    // to update centroids
    int counters[N_POINTS] = { 0, 0, 0, 0, 0 };
    struct Point newCentroids[N_POINTS] = { 0, 0, 0, 0, 0 };

    // assign all points to their closest centroid
    for (int i = 0; i < dataSize; ++i)
    {
      float minDistance = FLT_MAX;

      // for each point, find the nearest centroid c_j
      for (int j = 0; j < N_POINTS; ++j)
      {
        // distance of point to a centroid
        float distance = calcDistance(centroids[j], dataset[i]);

        if (distance < minDistance)
        {
          minDistance = distance;
          dataset[i].clusterID = j;
        }
      }

      // add the co-ords to those of the new centroid
      newCentroids[dataset[i].clusterID].x += dataset[i].x;
      newCentroids[dataset[i].clusterID].y += dataset[i].y;

      // increment total points for the cluster
      ++counters[dataset[i].clusterID];

      // update error metric
      errorMetric += minDistance;
    }

    // re-calculate centroids
    for (int j = 0; j < N_POINTS; ++j)
    {
      // do not re-calculate centroids for empty clusters
      if (counters[j] > 0)
      {
        centroids[j].x = newCentroids[j].x / (float)counters[j];
        centroids[j].y = newCentroids[j].y / (float)counters[j];
      }
    }
  }

  return errorMetric;
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

  struct Point* dataset = (struct Point*)malloc(sizeof(struct Point) * MAX_SIZE);

  int dataSize = 0;
  char lineBuffer[128];
  while (fgets(lineBuffer, sizeof(lineBuffer), fdata))
  {
    char* token = strtok(lineBuffer, ",");
    if (token)
    {
      dataset[dataSize].x = (float)atof(token);
      dataset[dataSize].y = (float)atof(strtok(NULL, ","));
      ++dataSize;
    }
  }
  fclose(fdata);

  struct Point* resizedDataset = realloc(dataset, sizeof(struct Point) * dataSize);
  if (resizedDataset)
  {
    dataset = resizedDataset;
  }

  if ((fdata=fopen("OUTPUT.TXT", "wb+")) == NULL)
  {
    printf("Unable to open file.\n");
    exit(2);
  }

  fprintf(fdata, "error = %.3f\n", kMeans(dataset, dataSize, MAX_ITERS));
  for (int i = 0; i < dataSize; ++i)
  {
    switch (dataset[i].clusterID)
    {
    case 0:
      fprintf(fdata, "Adam\n");
      break;
    case 1:
      fprintf(fdata, "Bob\n");
      break;
    case 2:
      fprintf(fdata, "Charley\n");
      break;
    case 3:
      fprintf(fdata, "David\n");
      break;
    case 4:
      fprintf(fdata, "Edward\n");
      break;
    default:
      break;
    }
  }

  fclose(fdata);
  free(dataset);
  return 0;
}
