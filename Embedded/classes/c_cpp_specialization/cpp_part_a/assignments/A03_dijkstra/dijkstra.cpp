#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <random>
#include <ctime>

class Graph {
private:
    int V_count, E_count;
    std::vector<std::vector<std::pair<int, double>>> adj_list;

public:
    Graph(int vertices) : V_count(vertices), E_count(0) {
        adj_list.resize(vertices);
    }

    void add_edge(int u, int v, double weight) {
        adj_list[u].push_back({v, weight});
        adj_list[v].push_back({u, weight});
        E_count++;
    }

    bool adjacent(int u, int v) {
        for (auto& neighbor : adj_list[u])
            if (neighbor.first == v) return true;
        return false;
    }

    std::vector<int> neighbors(int u) const {
        std::vector<int> result;
        for (auto& neighbor : adj_list[u])
            result.push_back(neighbor.first);
        return result;
    }

    double get_edge_value(int u, int v) const {
        for (auto& neighbor : adj_list[u])
            if (neighbor.first == v) return neighbor.second;
        return std::numeric_limits<double>::infinity();
    }

    void generate_random_graph(double density, double min_dist, double max_dist) {
        std::default_random_engine rng(static_cast<unsigned>(time(nullptr)));
        std::uniform_real_distribution<double> prob(0.0, 1.0);
        std::uniform_real_distribution<double> dist(min_dist, max_dist);

        for (int i = 0; i < V_count; ++i) {
            for (int j = i + 1; j < V_count; ++j) {
                if (prob(rng) < density) {
                    double d = dist(rng);
                    add_edge(i, j, d);
                }
            }
        }
    }

    int V() const { return V_count; }
    int E() const { return E_count; }
};

class ShortestPath {
private:
    const Graph& graph;
    int vertices;

public:
    ShortestPath(const Graph& g) : graph(g), vertices(g.V()) {}

    double path_size(int source, int target) {
        std::vector<double> dist(vertices, std::numeric_limits<double>::infinity());
        std::vector<bool> visited(vertices, false);

        using P = std::pair<double, int>;
        std::priority_queue<P, std::vector<P>, std::greater<>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (int v : graph.neighbors(u)) {
                double weight = graph.get_edge_value(u, v);
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[target];
    }
};

void run_simulation(double density, int nodes, double min_d, double max_d) {
    Graph g(nodes);
    g.generate_random_graph(density, min_d, max_d);

    ShortestPath sp(g);
    double total = 0;
    int count = 0;

    for (int i = 1; i < nodes; ++i) {
        double length = sp.path_size(0, i); // from node 1 (index 0)
        if (length != std::numeric_limits<double>::infinity()) {
            total += length;
            count++;
        }
    }

    std::cout << "Density: " << density * 100 << "%\n";
    std::cout << "Average path length from node 1: ";
    if (count == 0) std::cout << "N/A (no paths found)\n\n";
    else std::cout << total / count << "\n\n";
}

int main() {
    const int nodes = 50;
    const double min_d = 1.0, max_d = 10.0;

    run_simulation(0.2, nodes, min_d, max_d);
    run_simulation(0.4, nodes, min_d, max_d);

    return 0;
}
