#pragma once

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"

class SearchModel : public Model {

  public:
    class Node : public Model::Node {
      public:
        int index;
        Node * parent = nullptr;
        float h_value = std::numeric_limits<float>::max();
        float g_value = 0.0;
        bool visited = false;
        std::vector<Node *> neighbors;

        void FindNeighbors();
        float distance(Node other) {
            return std::sqrt(std::pow((x - other.x), 2) + std::pow((y - other.y), 2));
        }

        Node(){}
        Node(int idx, SearchModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model) { index = idx; }

      private:
        Node * FindNeighbor(std::vector<int> node_indices);
        SearchModel * parent_model = nullptr;
    };


    SearchModel(const std::vector<std::byte> &xml, float start_x, float start_y, float end_x, float end_y);

    auto &SNodes() { return m_Nodes; }

    Node start_node;
    Node end_node;
    std::vector<Node> path;
    
  private:
    void CalculateHValues();
    void CreateNodeToRoadHashmap();
    Node &FindClosestNode(float x, float y);
    std::unordered_map<int, std::vector<const Model::Road *>> node_to_road;
    std::vector<Node> m_Nodes;
};
