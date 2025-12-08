#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
struct Edge {
  int a;
  int b;
  double dist;

  Edge(int A, int B, double D) : a(A), b(B), dist(D) {}
};
struct Junction {
  int x, y, z;

  Junction(int X, int Y, int Z) : x(X), y(Y), z(Z) {}
  Junction() = default;

  double Distance(const Junction &b) const {
    long dx = (long)x - b.x;
    long dy = (long)y - b.y;
    long dz = (long)z - b.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
  }
};
struct DSU {
  std::vector<int> parent;
  std::vector<int> size;

  DSU(int n) {
    parent.resize(n);
    size.assign(n, 1);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int Find(int x) {
    if (parent[x] != x)
      parent[x] = Find(parent[x]);
    return parent[x];
  }

  bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b)
      return false;
    if (size[a] < size[b])
      std::swap(a, b);
    parent[b] = a;
    size[a] += size[b];
    return true;
  }
};

class Solve {
public:
  // std::string Final = "";
  //
  // Solve(std::vector<std::string> &Object) {
  //   std::vector<Junction> Points;
  //   long long sum = 1;
  //   for (int i = 0; i < Object.size(); i++) {
  //     std::stringstream Number(Object[i]);
  //     Junction Temp;
  //     std::string token;
  //
  //     std::getline(Number, token, ',');
  //     Temp.x = std::stoi(token);
  //     std::getline(Number, token, ',');
  //     Temp.y = std::stoi(token);
  //     std::getline(Number, token, ',');
  //     Temp.z = std::stoi(token);
  //
  //     Points.push_back(Temp);
  //   }
  //
  //   std::vector<Edge> Edges;
  //   for (int i = 0; i < Points.size(); i++) {
  //     for (int j = i + 1; j < Points.size(); j++) {
  //       double CurrentDistance = Points[i].Distance(Points[j]);
  //       Edges.push_back({i, j, CurrentDistance});
  //     }
  //   }
  //
  //   std::sort(Edges.begin(), Edges.end(),
  //             [](const Edge &A, const Edge &B) { return A.dist < B.dist; });
  //
  //   DSU dsu(Points.size());
  //   int count = 0;
  //   for (auto &e : Edges) {
  //     if (count == 1000)
  //       break;
  //     dsu.Union(e.a, e.b);
  //     count++;
  //   }
  //   std::unordered_map<int, int> Map;
  //   for (int i = 0; i < Points.size(); i++)
  //     Map[dsu.Find(i)]++;
  //   std::vector<int> Sizes;
  //   for (auto &p : Map)
  //     Sizes.push_back(p.second);
  //   std::sort(Sizes.begin(), Sizes.end(), std::greater<int>());
  //   for (int e = 0; e < Sizes.size() && e < 3; e++)
  //     sum *= Sizes[e];
  //
  //   Final = std::to_string(sum);
  // }
  std::string Final;
  Solve(std::vector<std::string> &Object) {
    std::vector<Junction> Points;
    for (int i = 0; i < (int)Object.size(); i++) {
      std::stringstream Number(Object[i]);
      Junction Temp;
      std::string token;

      std::getline(Number, token, ',');
      Temp.x = std::stoi(token);
      std::getline(Number, token, ',');
      Temp.y = std::stoi(token);
      std::getline(Number, token, ',');
      Temp.z = std::stoi(token);

      Points.push_back(Temp);
    }

    std::vector<Edge> Edges;
    for (int i = 0; i < (int)Points.size(); i++) {
      for (int j = i + 1; j < (int)Points.size(); j++) {
        double CurrentDistance = Points[i].Distance(Points[j]);
        Edges.push_back(Edge(i, j, CurrentDistance));
      }
    }

    std::sort(Edges.begin(), Edges.end(),
              [](const Edge &A, const Edge &B) { return A.dist < B.dist; });

    DSU dsu((int)Points.size());
    int components = (int)Points.size();
    long long sum = 0;

    for (auto &e : Edges) {
      if (dsu.Union(e.a, e.b)) {
        components--;
        if (components == 1) {
          sum = 1LL * Points[e.a].x * Points[e.b].x;
          break;
        }
      }
    }

    Final = std::to_string(sum);
  }
};
