/**
 * testRepro.c
 * Authors: Yizhao Gao <ygao29@illinois.edu>
 * Date: {07/17/2017}
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <hdf5.h>
#include <sys/time.h>
#include "reproject.h"
#include "io.h"

int main(int argc, char ** argv) {

	char* file_path = "/projects/TDataFus/kent/temp/40-orbit-file/Jun15.2/TERRA_BF_L1B_O69365_F000_V000.h5";
	hid_t file;
	if(0 > (file = af_open(file_path))) {
		printf("File not found\n");
		exit(1);
	}

	int nCellMODIS;
	int nCellMISR;

	double * MISR_Lat = get_misr_lat(file, "L", &nCellMISR);
	double * MISR_Lon = get_misr_long(file, "L", &nCellMISR);

	double * MISR_Rad;

	double * MODIS_Lat = get_modis_lat(file, "_1KM", "EV_1KM_RefSB", &nCellMODIS); 
	double * MODIS_Lon = get_modis_long(file, "_1KM", "EV_1KM_RefSB", &nCellMODIS);

	printf("MISR CELLS: %d\n, MODIS CELLS: %d\n", nCellMISR, nCellMODIS);

	double * MODIS_Rad_Out;

	int * tarNNSouID;

	//MISR TO MODIS NN
	
	double ** p_MISR_Lat = &MISR_Lat;
	double ** p_MISR_Lon = &MISR_Lon;

	tarNNSouID = (int *)malloc(sizeof(int) * nCellMODIS);

	//Finding nearest points
	//nearestNeighbor(p_MISR_Lat, p_MISR_Lon, nCellMISR, MODIS_Lat, MODIS_Lon, tarNNSouID, nCellMODIS, 1000);
	nearestNeighbor(p_MISR_Lat, p_MISR_Lon, nCellMISR, MODIS_Lat, MODIS_Lon, tarNNSouID, NULL, nCellMODIS, 1000);

	MISR_Lat = * p_MISR_Lat;
	MISR_Lon = * p_MISR_Lon;

	free(MISR_Lat);
	free(MISR_Lon);


	free(MODIS_Lat);
	free(MODIS_Lon);

	MISR_Rad = get_misr_rad(file, "AN", "L", "Blue_Radiance", &nCellMISR);
	
	MODIS_Rad_Out = (double *)malloc(sizeof(double) * nCellMODIS);
	
	nnInterpolate(MISR_Rad, MODIS_Rad_Out, tarNNSouID, nCellMODIS);

	
	free(MISR_Rad);
	free(MODIS_Rad_Out);

	free(tarNNSouID);




	herr_t ret = af_close(file);


	return 0;
}
