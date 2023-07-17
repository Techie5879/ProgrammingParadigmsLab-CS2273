#include <bits/stdc++.h>


class Graph {
 public:
  Graph() = default;

  void addEdge(int u, int v) {
    adj_list_[u].push_back(v);
    adj_list_[v].push_back(u);
  }

  Graph subGraph(const std::vector<int>& nodes) const {
    Graph result;
    for (int node : nodes) {
      for (int neighbor : adj_list_.at(node)) {
        if (std::find(nodes.begin(), nodes.end(), neighbor) != nodes.end()) {
          result.addEdge(node, neighbor);
        }
      }
    }
    return result;
  }

  Graph unionWith(const Graph& other) const {
    Graph result(*this);
    for (const auto& [node, neighbors] : other.adj_list_) {
      for (int neighbor : neighbors) {
        result.addEdge(node, neighbor);
      }
    }
    return result;
  }

  Graph intersectionWith(const Graph& other) const {
    Graph result;
    for (const auto& [node, neighbors] : adj_list_) {
      for (int neighbor : neighbors) {
        if (other.adj_list_.count(node) &&
            std::find(other.adj_list_.at(node).begin(),
                      other.adj_list_.at(node).end(),
                      neighbor) != other.adj_list_.at(node).end()) {
          result.addEdge(node, neighbor);
        }
      }
    }
    return result;
  }

  bool isDisconnected(int node) const {
    return adj_list_.count(node) == 0;
  }

  int degree(int node) const {
    return adj_list_.count(node) ? adj_list_.at(node).size() : 0;
  }

  bool isReachable(int u, int v) const {
    std::vector<bool> visited(adj_list_.size(), false);
    std::vector<int> queue;
    queue.push_back(u);
    visited[u] = true;

    while (!queue.empty()) {
      int node = queue.front();
      queue.erase(queue.begin());
      for (int neighbor : adj_list_.at(node)) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          queue.push_back(neighbor);
        }
      }
    }

    return visited[v];
  }

 private:
  std::unordered_map<int, std::vector<int>> adj_list_;
};

int main() {
  Graph g;

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  std::cout << "Degree of node 0: " << g.degree(0) << std::endl;
  std::cout << "Degree of node 3: " << g.degree(3) << std::endl;
  std::cout << "Degree of node 4: " << g.degree(4) << std::endl;

  std::cout << "Is node 0 disconnected? " << g.isDisconnected(0) << std::endl;
  std::cout << "Is node 4 disconnected? " << g.isDisconnected(4) << std::endl;

  std::cout << "Is there a path from 0 to 3? " << g.isReachable(0, 3)
            << std::endl;
  std::cout << "Is there a path from 3 to 0? " << g.isReachable(3, 0)
            << std::endl;

  std::vector<int> sub_graph_nodes = {0, 1};
  Graph sub_graph = g.subGraph(sub_graph_nodes);

  std::cout << "Degree of node 0 in sub graph: " << sub_graph.degree(0)
            << std::endl;
  std::cout << "Degree of node 2 in sub graph: " << sub_graph.degree(2)
            << std::endl;

  Graph g2;
  g2.addEdge(1, 2);
  g2.addEdge(3, 4);

  Graph union_graph = g.unionWith(g2);
  std::cout << "Degree of node 0 in union graph: " << union_graph.degree(0)
            << std::endl;
  std::cout << "Degree of node 4 in union graph: " << union_graph.degree(4)
            << std::endl;

  Graph intersection_graph = g.intersectionWith(g2);
  std::cout << "Degree of node 0 in intersection graph: "
            << intersection_graph.degree(0) << std::endl;
  std::cout << "Degree of node 4 in intersection graph: "
            << intersection_graph.degree(4) << std::endl;

  return 0;
}