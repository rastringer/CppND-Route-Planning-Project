#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
	float GetDistance() { return distance; }

	void AStarSearch();

  private:
	void AddNeighbors(RouteModel::Node* current_node);
	// Distance calculation heuristic (for this project, Eucledian distance
	// to the end_node
	float CalculateHValue(RouteModel::Node *node);
	// Since no more operations on the nodes (vector will be used to print the path to the map, 
	// no need for a pointer in the vector
	std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *);
	RouteModel &m_Model;
	RouteModel::Node * start_node;
	RouteModel::Node * end_node;
	float distance;
	std::vector<RouteModel::Node*> open_list;
	RouteModel::Node *NextNode();
};
