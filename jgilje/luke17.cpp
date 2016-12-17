#include <iostream>

#include <algorithm>
#include <vector>
#include <set>

struct coord {
    int x = 0;
    int y = 0;

    bool operator==(const coord& rhs) const {
        return (x == rhs.x) && (y == rhs.y);
    }
    bool operator!=(const coord& rhs) const {
        return !operator==(rhs);
    }

    std::size_t distance(const coord& to) const {
        return static_cast<std::size_t>(std::abs(to.x - x)) +
               static_cast<std::size_t>(std::abs(to.y - y));
    }
};

struct wormhole {
    coord enter;
    coord exit;
};

// source: https://www.quora.com/What-is-the-most-simple-efficient-C++-code-for-Dijkstras-shortest-path-algorithm
struct edge { std::size_t to, length; };

std::size_t dijkstra(const std::vector<std::vector<edge>> &graph, std::size_t source, std::size_t target) {
    std::vector<std::size_t> min_distance(graph.size(), std::numeric_limits<std::size_t>::max());
    min_distance[source] = 0;
    std::set<std::pair<std::size_t, std::size_t>> active_vertices;
    active_vertices.insert({0, source});

    while (!active_vertices.empty()) {
        std::size_t where = active_vertices.begin()->second;
        if (where == target) return min_distance[where];
        active_vertices.erase( active_vertices.begin() );
        for (auto ed : graph[where])
            if (min_distance[ed.to] > min_distance[where] + ed.length) {
                active_vertices.erase( { min_distance[ed.to], ed.to } );
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert( { min_distance[ed.to], ed.to } );
            }
    }

    return std::numeric_limits<int>::max();
}

int main() {
    std::vector<wormhole> wormholes;
    wormholes.push_back({{0, 0}, {0, 0}});
    wormholes.push_back({{14519,47295}, {54910,18357}});
    wormholes.push_back({{45202,1108}, {9617,37834}});
    wormholes.push_back({{34172,74888}, {38215,50481}});
    wormholes.push_back({{4027,98283}, {83695,63613}});
    wormholes.push_back({{41187,8287}, {94719,64497}});
    wormholes.push_back({{49969,28072}, {21579,16713}});
    wormholes.push_back({{96264,65077}, {17247,22643}});
    wormholes.push_back({{41952,229}, {88333,84187}});
    wormholes.push_back({{7527,68937}, {22294,31187}});
    wormholes.push_back({{8800,49312}, {11296,83909}});
    wormholes.push_back({{88405,32174}, {54748,58082}});
    wormholes.push_back({{99999, 99999}, {99999, 99999}});

    std::vector<std::vector<edge>> graph(wormholes.size());
    for (std::size_t i = 0; i < wormholes.size(); i++) {
        for (std::size_t j = 0; j < wormholes.size(); j++) {
            if (i == j) {
                continue;
            }

            graph[i].push_back({j, wormholes[i].exit.distance(wormholes[j].enter)});
        }
    }
    std::cout << dijkstra(graph, 0, graph.size() - 1) << std::endl;

    return 0;
}
