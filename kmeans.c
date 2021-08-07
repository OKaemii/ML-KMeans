/*
k-Means Algorithm

This program performs the k-means clustering task as specified by AA.

Author: Fahad Hafiz
*/

#include <stdio.h>
#include <stdlib.h>

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
}
