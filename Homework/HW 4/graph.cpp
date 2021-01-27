#include "graph.hpp"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>

#include "edge.hpp"
#include "node.hpp"

// Complete this
bool Graph::hasTripletClique() const {
  if (nodes_.size() < 3) return false;
  
  // To do
    for(auto it : nodes_) {
      Node* node = it.second;
      
      for(auto it2 : node->getNeighbors()) {
        Node* node2 = it2;
        
        for(auto it3 : nodes_) {
          if(it3.second != node && it3.second != node2) {
            Node* node3 = it3.second;
              
              if(node3->getNeighbors().empty() == false && node3->getNeighbors().find(node) != node3->getNeighbors().end() && node3->getNeighbors().find(node2) != node3->getNeighbors().end()) {
                return true;
          } 
        }
      }
    }
  }

  return false;
}

// Complete this
bool Graph::isConnected() const {
  std::list<Node*> temp;
  Node* first = nodes_.begin() -> second;
  temp.push_back(first);
  first -> setVisited(true);
  
  while(!temp.empty() ) {
    Node* curr = temp.front();
    temp.pop_front();
    
    for(auto i : nodes_) {
      if(i.second -> isVisited() == false) {
        return false;
      }
    }

    for(auto i : curr->getNeighbors()) {
      
      if(!i -> isVisited()) {
        i -> setVisited(true);
        temp.push_back(i);
      }
    }
  }
  
  return true;
}



// Complete this
double Graph::getMinDistance(const std::string &nid1,
                             const std::string &nid2) const {
  
  assert(nodes_.size() >= 2);  // Must have at least 2 nodes
  typedef std::pair<double, Node*> dist;
  
  std::priority_queue<dist, std::vector<dist>, std::greater<dist>> min_heap;
  std::unordered_map<Node*, double> nodeList;
  
  Node* initial = nodes_.find(nid1) -> second;
  Node* destination = nodes_.find(nid2) -> second;


  for(auto i : nodes_) {
    i.second -> setVisited(false); 
    
    if(i.second == initial) { 
      dist curr(0.0, initial);
      nodeList.emplace(initial, 0.0);
      min_heap.push(curr);
    }

    nodeList.emplace(i.second, std::numeric_limits<double>::infinity());
  }
  
  if(initial == nullptr && destination == nullptr) {
    return std::numeric_limits<double>::infinity();
  }

  double shortestDist; 
  shortestDist = nodeList.find(destination)->second;

  return shortestDist;
}

// Optional: complete this
double Graph::getLongestSimplePath() const {
  assert(nodes_.size() >= 1);  // Must have at least 1 node
  // To do
  return 0.0;
}

Graph::Graph(bool directed) : directed_(directed){};

Graph::~Graph() {
  for (Edge *edge : edges_) delete edge;
  edges_.clear();
  for (auto it : nodes_) delete it.second;
  nodes_.clear();
}

bool Graph::isDirected() const {
  return directed_;
}

bool Graph::addNode(const std::string &nid) {
  Node *node = new Node(nid);
  bool inserted = nodes_.emplace(nid, node).second;
  if (!inserted) delete node;
  return inserted;
}

bool Graph::addEdge(const std::string &nid1, const std::string &nid2,
                    double weight) {
  auto it1 = nodes_.find(nid1);
  auto it2 = nodes_.find(nid2);
  if (it1 == nodes_.end() || it2 == nodes_.end()) return false;

  Node *node1 = it1->second;
  Node *node2 = it2->second;

  Edge *edge1 = new Edge(node2, weight);
  node1->addEdge(edge1);
  edges_.insert(edge1);
  if (!directed_) {
    Edge *edge2 = new Edge(node1, weight);
    node2->addEdge(edge2);
    edges_.insert(edge2);
  }
  return true;
}

std::string Graph::toString(const std::string &delimiter) const {
  std::vector<std::string> nids;
  nids.reserve(nodes_.size());
  for (auto it : nodes_) nids.push_back(it.first);
  std::sort(nids.begin(), nids.end());

  std::stringstream ss;
  // Iterate each node
  for (size_t i = 0; i < nids.size(); i++) {
    if (i > 0) ss << delimiter;
    ss << nids[i] << ": [";
    Node *node = nodes_.find(nids[i])->second;
    bool first = true;
    for (Node *neighbor : node->getNeighbors()) {
      if (first) {
        ss << neighbor->getID();
        first = false;
      } else {
        ss << ", " << neighbor->getID();
      }
    }
    ss << "]";
  }
  return ss.str();
}

void Graph::printGraph() const { std::cout << toString() << std::endl; }