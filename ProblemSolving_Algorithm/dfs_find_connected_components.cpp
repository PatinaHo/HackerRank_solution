/* Subdomain: Graph Theory
 * Problem: Roads and libraries
 */


#include <bits/stdc++.h>
#include <vector>
using namespace std;

// vector<string> split_string(string);
int find_connected_components(vector<int> adj[], int num_city, bool visited[]);
void dfs(vector<int> adj[], int start_point, bool visited[]);
void intialize(bool visited[],int n);

/**************** Complete the roadsAndLibraries function below. ****************/



/* Use DFS to compute the number of connected subgraph */
int find_connected_components(vector<int> adj[], int num_city, bool visited[]){
// 要用到的變數, 沒傳進去就是拿不到, 例如 bool visited
    long num_components = 0;
    for(int i = 1; i <= num_city; i++){
        if (visited[i] == 0){
            dfs(adj, i, visited);
            num_components += 1;
        }
    }
    return num_components;
}

void dfs(vector<int> adj[], int start_point, bool visited[]){
    visited[start_point] = 1;
    for(int j = 0; j < adj[start_point].size(); j++){
        if( visited[adj[start_point][j]] == 0 )
            dfs(adj, adj[start_point][j], visited);
    }
}

void intialize(bool visited[],int n)
{
    for(int i=0;i<n+1;i++)
        visited[i]=false;
}

/************************  Answer area over  ************************/

int main(){
//    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n, m;
        long c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;
        vector<int> adj[n + 1]; // square bracket: n+1個vector串成的array,不是一個vector!
        bool visited[n + 1];
        long num_components = 0;
        
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            adj[city_1].push_back(city_2); // 在第city_1個vector多push一個數字進去
            adj[city_2].push_back(city_1); // 不用寫雙層vector
        }
        
        if(c_lib > c_road){
            intialize(visited,n);
            for(int i = 1; i <= n; i++){
                if (visited[i] == 0){
                    dfs(adj, i, visited);
                    num_components += 1;
                }
            }
            cout << c_lib * num_components + c_road * (n - num_components) << endl;
        }
        else
            cout <<  c_lib * n << endl;
    }

    return 0;
}

// vector<string> split_string(string input_string) {
//     string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
//         return x == y and x == ' ';
//     });

//     input_string.erase(new_end, input_string.end());

//     while (input_string[input_string.length() - 1] == ' ') {
//         input_string.pop_back();
//     }

//     vector<string> splits;
//     char delimiter = ' ';

//     size_t i = 0;
//     size_t pos = input_string.find(delimiter);

//     while (pos != string::npos) {
//         splits.push_back(input_string.substr(i, pos - i));

//         i = pos + 1;
//         pos = input_string.find(delimiter, i);
//     }

//     splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

//     return splits;
// }