/**
 * reproject.c
 * Authors: Yizhao Gao <ygao29@illinois.edu>
 * Date: {07/14/2017}
 */


#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

int * pointIndexOnLat(double ** plat, double ** plon,  int * oriID, int *pcount, int nBlockY) {

	double *lat = *plat;
	double *lon = *plon;
	int count = *pcount;

	double blockR = M_PI/nBlockY;

	int * index;
	int * pointsInB;
	
	double * newLon;
	double * newLat;

	if(NULL == (index = (int *)malloc(sizeof(int) * (nBlockY + 1))))
	{
		printf("ERROR: Out of memory at line %d in file %s\n", __LINE__, __FILE__);
		exit(1);
	}

	if(NULL == (pointsInB = (int *)malloc(sizeof(int) * nBlockY)))
	{
		printf("ERROR: Out of memory at line %d in file %s\n", __LINE__, __FILE__);
		exit(1);
	}

	for(int i = 0; i < nBlockY; i++)
	{
		pointsInB[i] = 0;
	}

	int blockID;
		
	for(int i = 0; i < count; i++) {
	
		blockID = (int)((lat[i] + M_PI/2) / blockR);
		
		if(blockID >= 0 && blockID < nBlockY) {
			pointsInB[blockID] ++;
		}
	}

	index[0] = 0;
	for(int i = 1; i < nBlockY + 1; i++) {
		index[i] = index[i - 1] + pointsInB[i - 1];
	}

	if(NULL == (newLon = (double *)malloc(sizeof(double) * index[nBlockY]))) {
		printf("ERROR: Out of memory at line %d in file %s\n", __LINE__, __FILE__);
		exit(1);
	} 
	if(NULL == (newLat = (double *)malloc(sizeof(double) * index[nBlockY]))) {
		printf("ERROR: Out of memory at line %d in file %s\n", __LINE__, __FILE__);
		exit(1);
	}
	
	pointsInB[0] = 0;
	for(int i = 1; i < nBlockY; i++) {
		pointsInB[i] = index[i];
	}
	
	for(int i = 0; i < count; i++) {
		
		blockID = (int)((lat[i] + M_PI/2) / blockR);
		if(blockID >= 0 && blockID < nBlockY) {
			newLon[pointsInB[blockID]] = lon[i];
			newLat[pointsInB[blockID]] = lat[i];
			oriID[pointsInB[blockID]] = i;
			pointsInB[blockID] ++;
	
		}
	}
	


	free(pointsInB);
	free(lon);
	free(lat);

	count = index[nBlockY];
	*pcount = count;
	*plon = newLon;
	*plat = newLat;

//	printf("%0x\n", lat);

	return index;
}

//Finding the nearest neiboring point's ID 
void nearestNeighbor(double ** psouLat, double ** psouLon, int nSou, double * tarLat, double * tarLon, int * tarNNSouID, int nTar, double maxR) {

	//printf("%0x\n", souLat);
	double * souLat = *psouLat;
	double * souLon = *psouLon;

	const double earthRadius = 6367444;
	double radius = maxR / earthRadius;
	int nBlockY = M_PI / radius;

	double blockR = M_PI / nBlockY;
	

	for(int i = 0; i < nSou; i++) {
		souLat[i] = souLat[i] * M_PI / 180;
		souLon[i] = souLon[i] * M_PI / 180;
	}

	for(int i = 0; i < nTar; i++) {
		tarLat[i] = tarLat[i] * M_PI / 180;
		tarLon[i] = tarLon[i] * M_PI / 180;
	}

	int * souID;
	if(NULL == (souID = (int *)malloc(sizeof(double) * nSou))) {
		printf("ERROR: Out of memory at line %d in file %s\n", __LINE__, __FILE__);
		exit(1);
	}
	int * pnSou;
	pnSou = &nSou;
	int * souIndex = pointIndexOnLat(psouLat, psouLon, souID, pnSou, nBlockY);
	nSou = * pnSou;
	souLat = *psouLat;
	souLon = *psouLon;

	double tLat, tLon;
	double sLat, sLon;
	int blockID;
	int startBlock, endBlock;

	double pDis;	
	double nnDis;
	int nnSouID;

	for(int i = 0; i < nTar; i ++) {

		tLat = tarLat[i];
		tLon = tarLon[i];

		blockID = (tLat + M_PI / 2) / blockR;
		startBlock = blockID - 1;
		endBlock = blockID + 1;

		if(startBlock < 0) {
			startBlock = 0;
		}
		if(endBlock > nBlockY - 1) {
			endBlock = nBlockY - 1;
		}

		nnDis = -1;
		
		for(int j = souIndex[startBlock]; j < souIndex[endBlock+1]; j++) {
			
			sLat = souLat[j];
			sLon = souLon[j];

			pDis = acos(sin(tLat) * sin(sLat) + cos(tLat) * cos(sLat) * cos(tLon - sLon));
				
			if((nnDis < 0 || nnDis > pDis) && pDis <= radius) {
				nnDis = pDis;
				nnSouID = souID[j];
			}
				
		}

		if(nnDis < 0) {
			tarNNSouID[i] = -1;
		}
		else {
			tarNNSouID[i] = nnSouID;
		}
	
		 
	}
	
	return;	
}


void nnInterpolate(double * souVal, double * tarVal, int * tarNNSouID, int nTar) {

	int nnSouID;

	for(int i = 0; i < nTar; i++) {
		nnSouID = tarNNSouID[i];
		if(nnSouID < 0) {
			tarVal[i] = -999;
		}
		else {
			tarVal[i] = souVal[nnSouID];
		}
	}
}

void summaryInterpolate(double * souVal, int * souNNTarID, int nSou, double * tarVal, int * nSouPixels, int nTar) {

	for(int i = 0; i < nTar; i++) {
	
		tarVal[i] = 0;
		nSouPixels[i] = 0;
	}

	int nnTarID;
	for(int i = 0; i < nSou; i++) {
		
		nnTarID = souNNTarID[i];
		if(nnTarID > 0 && souVal[i] >= 0) {
			tarVal[nnTarID] += souVal[i];
			nSouPixels[nnTarID] ++;	
		}
	}


	for(int i = 0; i < nTar; i++) {
	
		if(nSouPixels[i] > 0) {
			tarVal[i] = tarVal[i] / nSouPixels[i];
		}
		else {
			tarVal[i] = -999;
		}
	}

}
