//Mbaliyethemba Shangase
//SHNMBA004
//19 August 2019

#include <vector>

#ifndef GRAPH_H
#define GRAPH_H

class graph{
	private:
		std::vector<std::vector<int>> pnt;
		std::vector<std::vector<double>> cl1, cl2, cl3;
		std::vector<double> cen1, cen2, cen3;
		std::vector<double> dis1, dis2, dis3;
		
	public:
		graph();
		~graph();
		void set_pnt(std::vector<std::vector<int>>);
		void set_clust1(std::vector<std::vector<double>>);
		void set_clust2(std::vector<std::vector<double>>);
		void set_clust3(std::vector<std::vector<double>>);
		void set_cent1(std::vector<double>);
		void set_cent2(std::vector<double>);
		void set_cent3(std::vector<double>);
		void set_dist1(std::vector<double>);
		void set_dist2(std::vector<double>);
		void set_dist3(std::vector<double>);
		void to_string();
		double distance(std::vector<int>, std::vector<double>);
		void load_distance();
		std::vector<std::vector<double>> min_distance();
		void cluster(std::vector<std::vector<double>>);
		void centroid();
	};
#endif
