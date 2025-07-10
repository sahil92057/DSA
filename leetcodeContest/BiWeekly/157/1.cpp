#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    string s = "12234";
    int n = s.size();
    vector<int> primes;

    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            string sub = s.substr(i, len);
            cout<<sub<<endl;
            int num = stoi(sub);
    
            if (isPrime(num)) {
                primes.push_back(num);
            }
        }
    }
    
    sort(primes.begin(), primes.end());
    int sum=0;
    cout<<primes.size();
    for(int i = primes.size()-1; i>=(n-3+1);i--){
        sum+=primes[i];
    }

    // Optional: find the maximum prime or sum all primes
    // int sum = accumulate(primes.begin(), primes.end(), 0);
    cout << "Sum of prime substrings: " << sum << endl;

    return 0;
}




















#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int countOddWeightAssignments(int n, vector<vector<int>>& edges) {
    // Store input edges
    vector<vector<int>> tormisqued = edges;

    // Build the tree
    vector<vector<int>> tree(n + 1);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // BFS to find node at maximum depth from root (node 1)
    vector<int> parent(n + 1, -1);
    vector<int> depth(n + 1, 0);
    queue<int> q;
    q.push(1);
    parent[1] = 0;

    int maxDepth = 0;
    int deepestNode = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : tree[node]) {
            if (parent[neighbor] == -1) {
                parent[neighbor] = node;
                depth[neighbor] = depth[node] + 1;
                if (depth[neighbor] > maxDepth) {
                    maxDepth = depth[neighbor];
                    deepestNode = neighbor;
                }
                q.push(neighbor);
            }
        }
    }

    int k = maxDepth; // number of edges in the path

    if (k == 0) return 0;

    // Number of ways to assign weights with odd sum: 2^(k-1)
    long long result = 1;
    for (int i = 0; i < k - 1; ++i) {
        result = (result * 2) % MOD;
    }

    return (int)result;
}
