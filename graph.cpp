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

void graph::set_cent1(std::vector<double> cent1){
	this->cen1 = cent1;
}

void graph::set_cent2(std::vector<double> cent2){
	this->cen2 = cent2;
}

void graph::set_cent3(std::vector<double> cent3){
	this->cen3 = cent3;
}

void graph::set_dist1(std::vector<double> dist1){
	this->dis1 = dist1;
}

void graph::set_dist2(std::vector<double> dist2){
	this->dis2 = dist2;
}

void graph::set_dist3(std::vector<double> dist3){
	this->dis3 = dist3;
}

void graph::to_string(){
    std::cout << "data" << '\n';
    for (size_t i = 0; i < this->pnt.size(); i++) {
		for (size_t j = 0; j < this->pnt[i].size(); j++) {
			std::cout << this->pnt[i][j] << ' ';
			}
		std::cout << '\n';
	}

    std::cout << "cluster1" << '\n';
    for (size_t i = 0; i < this->cl1.size(); i++) {
		for (size_t j = 0; j < this->cl1[i].size(); j++) {
			std::cout << this->cl1[i][j] << ' ';
			}
		std::cout << '\n';
	}

    std::cout << "cluster2" << '\n';
    for (size_t i = 0; i < this->cl2.size(); i++) {
		for (size_t j = 0; j < this->cl2[i].size(); j++) {
			std::cout << this->cl2[i][j] << ' ';
		}
		std::cout << '\n';
	}

    std::cout << "cluster3" << '\n';
    for (size_t i = 0; i < this->cl3.size(); i++) {
		for (size_t j = 0; j < this->cl3[i].size(); j++) {
			std::cout << this->cl3[i][j] << ' ';
		}
		std::cout << '\n';
	}

    std::cout << "distance1" << '\n';
    for (size_t i = 0; i < this->dis1.size(); i++) {
		std::cout << this->dis1[i] << '\n';
    }

    std::cout << "distance2" << '\n';
    for (size_t i = 0; i < this->dis2.size(); i++) {
		std::cout << this->dis2[i] << '\n';
    }

    std::cout << "distance3" << '\n';
    for (size_t i = 0; i < this->dis3.size(); i++) {
		std::cout << this->dis3[i] << '\n';
    }

    std::cout << "centroid1" << '\n';
    std::cout << this->cen1[0] << ' ' << this->cen1[1] << '\n';

    std::cout << "centroid2" << '\n';
    std::cout << this->cen2[0] << ' ' << this->cen2[1] << '\n';

    std::cout << "centroid3" << '\n';
    std::cout << this->cen3[0] << ' ' << this->cen3[1] << '\n';

  }

double graph::distance(std::vector<int> p1, std::vector<double> p2){
	return sqrt(pow(p1[0]-p2[0], 2.0) + pow(p1[1]-p2[1], 2.0));
}

void graph::load_distance(){
	for (size_t i = 0; i < this->pnt.size(); i++){
		this->dis1[i] = distance(this->pnt[i], this->cen1);
		this->dis2[i] = distance(this->pnt[i], this->cen2);
		this->dis3[i] = distance(this->pnt[i], this->cen3);
	}
}

std::vector<std::vector<double>> graph::min_distance(){
	std::vector<std::vector<double>> a;
	double index = 0;
	double min_distance = std::numeric_limits<double>::max();
	for (size_t i = 0; i < this->dis1.size(); i++){
		min_distance = std::min(min_distance, this->dis1[i]);
		min_distance = std::min(min_distance, this->dis2[i]);
		min_distance = std::min(min_distance, this->dis3[i]);
		
		if(this->dis1[i] == min_distance){
			index = 1;
		}
		
		if(this->dis2[i] == min_distance){
			index = 2;
		}
		
		if(this->dis3[i] == min_distance){
			index = 3;
		}
		
		std::vector<double> b;
		b = {min_distance, index};
		a.push_back(b);
		min_distance = std::numeric_limits<double>::max();
	}
	return a;
}

void graph::cluster(std::vector<std::vector<double>> c){
	this->cl1.clear();
	this->cl2.clear();
	this->cl3.clear();
	std::vector<double> d;
	for (size_t i = 0; i < c.size(); i++) {
		d.clear();
		if (c[i][1]==1) {
			d.push_back(this->pnt[i][0]);
			d.push_back(this->pnt[i][1]);
			this->cl1.push_back(d);
		}
		if (c[i][1]==2) {
			d.push_back(this->pnt[i][0]);
			d.push_back(this->pnt[i][1]);
			this->cl2.push_back(d);
		}
		if (c[i][1]==3) {
			d.push_back(this->pnt[i][0]);
			d.push_back(this->pnt[i][1]);
			this->cl3.push_back(d);
		}
	}
	std::cout << "group cluster 1" << '\n';
	for (size_t i = 0; i < this->cl1.size(); i++) {
		for (size_t j = 0; j < this->cl1[i].size(); j++) {
			std::cout << this->cl1[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
	std::cout << "group cluster 2" << '\n';
	for (size_t i = 0; i < this->cl2.size(); i++) {
		for (size_t j = 0; j < this->cl2[i].size(); j++) {
			std::cout << this->cl2[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
	std::cout << "group cluster 3" << '\n';
	for (size_t i = 0; i < this->cl3.size(); i++) {
		for (size_t j = 0; j < this->cl3[i].size(); j++) {
			std::cout << this->cl3[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void graph::centroid(){
	double column, row = 0;
	row=0;
	column=0;
	
	for (size_t i = 0; i < this->cl1.size(); i++) {
		column += this->cl1[i][1];
		row += this->cl1[i][0];
	}
	
	if (this->cl1.size()==0) {
		this->cen1[0]=0;
		this->cen1[1]=0;
	}
	else{
		this->cen1[0] = row / this->cl1.size();
		this->cen1[1] = column / this->cl1.size();
	}
	std::cout << "centroid 1" << '\n';
	for (size_t i = 0; i < this->cen1.size(); i++) {
		std::cout << this->cen1[i] << ' ';
	}
	std::cout << '\n';
	
	row = 0;
	column = 0;
	for (size_t i = 0; i < this->cl2.size(); i++) {
		column+=this->cl2[i][1];
		row+=this->cl2[i][0];
	}
	this->cen2[0]=row/this->cl2.size();
	this->cen2[1]=column/this->cl2.size();
	std::cout << "centroid 2" << '\n';
	for (size_t i = 0; i < this->cen2.size(); i++) {
		std::cout << this->cen2[i] << ' ';
	}
	std::cout << '\n';
	
	row=0;
	column=0;
	for (size_t i = 0; i < this->cl3.size(); i++) {
		column+=this->cl3[i][1];
		row+=this->cl3[i][0];
	}
	if (this->cl3.size()==0) {
		this->cen3[0]=0;
		this->cen3[1]=0;
	}
	else{
		this->cen3[0]=row/this->cl3.size();
		this->cen3[1]=column/this->cl3.size();
	}
	std::cout << "centroid 3" << '\n';
	for (size_t i = 0; i < this->cen3.size(); i++) {
		std::cout << this->cen3[i] << ' ';
	}
	std::cout << '\n';
}
