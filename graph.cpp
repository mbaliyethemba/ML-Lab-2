//Mbaliyethemba Shangase
//SHNMBA004
//19 August 2019

#include "math.h"
#include "graph.h"
#include <iostream>
#include <algorithm>
#include <limits>

graph::graph(){}

graph::~graph(){}

void graph::set_pnt(std::vector<std::vector<int>> points){
	this->pnt = points;
}

void graph::set_clust1(std::vector<std::vector<double>> clust1){
	this->cl1 = clust1;
}

void graph::set_clust2(std::vector<std::vector<double>> clust2){
	this->cl2 = clust2;
}

void graph::set_clust3(std::vector<std::vector<double>> clust3){
	this->cl3 = clust3;
}
