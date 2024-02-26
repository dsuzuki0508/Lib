#include <bits/stdc++.h>

class FordFulkerson{
  std::vector<std::map<long long,long long>> mEdge;
  void resize(unsigned long long n);
public:
  FordFulkerson(){}
  FordFulkerson(long long n):FordFulkerson(){resize(n);}
  void add_edge(long long from, long long to, long long cap);
  long long max_flow(long long s, long long t);
};
void FordFulkerson::resize(unsigned long long n){
  if(mEdge.size() < n )mEdge.resize(n);
}
void FordFulkerson::add_edge(long long from, long long to, long long cap){
  resize(std::max(from, to)+1);
  mEdge[from][to]=cap;
}
long long FordFulkerson::max_flow(long long s, long long t){
  resize(std::max(s,t)+1);
  std::vector<std::map<long long,long long>> edge = mEdge;
  std::vector<bool> visited(edge.size(), false);
  const long long INF = std::numeric_limits<long long>::max();

  auto dfs = [&](auto dfs, long long node, long long flow) -> long long{
    if(node == t){
      return flow;
    }
    visited[node]=true;
    
    long long ret = 0;
    for(const auto& e:edge[node]){
      auto [to, cap] = e;
      if(cap==0)continue;
      if(visited[to])continue;
      ret = dfs(dfs, to, std::min(flow, cap));
      if(ret!=0){
	edge[node][to]-=ret;
	edge[to][node]+=ret;
	break;
      }
    }
    
    return ret;
  };

  long long ret = 0;
  while(1){
    visited.assign(edge.size(), false);
    long long flow = dfs(dfs, s, INF);
    if(flow==0)break;
    ret+=flow;
  }
  return ret;
}
