#include "graph.h"
#include <iostream>


int main(int argc, char const *argv[]) {
  graph g;
  g.set_pnt(
    {
      {2, 10},
      {2, 5},
      {8, 4},
      {5, 8},
      {7, 5},
      {6, 4},
      {1, 2},
      {4, 9}
    }
  );

  g.set_clust1(
    {
      {2, 10},
      {2, 5},
      {8, 4}
    }
  );

  g.set_clust2(
    {
      {5, 8},
      {7, 5},
      {6, 4}
    }
  );

  g.set_clust3(
    {
      {1, 2},
      {4, 9}
    }
  );

  g.set_dist1(
    {
      0, 0, 0, 0, 0, 0, 0, 0
    }
  );

  g.set_dist2(
    {
      0, 0, 0, 0, 0, 0, 0, 0
    }
  );

  g.set_dist3(
    {
      0, 0, 0, 0, 0, 0, 0, 0
    }
  );

  g.set_cent1(
    {
      3.0, 9.5
    }
  );

  g.set_cent2(
    {
      6.5, 5.25
    }
  );

  g.set_cent3(
    {
      1.5, 3.5
    }
  );
  
  std::ofstream myfile;
  myfile.open("out.txt");
  if(myfile.is_open()){

  for (size_t i = 1; i < 5; i++) {
    std::cout << "iteration" << ' ' << i;
    std::cout << '\n';

    g.load_distance();

    // g.to_string();

    g.cluster(g.min_distance());

    g.centroid();
  }
  return 0;
}
}
