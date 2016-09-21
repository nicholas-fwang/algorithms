#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > adj;
vector<string> graph[26][26];
vector<int> indegree, outdegree;

void makeGraph(const vector<string>& words);
vector<int> getEulerTrailOrCircuit();
void getEulerCircuit(int here, vector<int>& circuit);
bool checkEuler();
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        scanf("%d", &n);
        vector<string> words;
        for(int i=0; i<n; i++) {
            string word;
            cin >> word;
            words.push_back(word);
        }
        makeGraph(words);
        if(!checkEuler()) {
            printf("IMPOSSIBLE\n");    
            return 0;
        }
        vector<int> circuit = getEulerTrailOrCircuit();
        
        if(circuit.size() != words.size() +1) {
            printf("IMPOSSIBLE\n");    
            return 0;
        }
        reverse(circuit.begin(), circuit.end());
        string ret;
        for(int i=1; i<circuit.size(); i++) {
            int a = circuit[i-1], b = circuit[i];
            if(ret.size()) ret += " ";
            ret += graph[a][b].back();
            graph[a][b].pop_back();
        }
        cout << ret << endl;    
    }
    return 0;
}

void makeGraph(const vector<string>& words)
{
    for(int i=0; i<26; i++) {
        for(int j=0; j<26; j++) {
            graph[i][j].clear();
        }
    }
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    indegree = vector<int>(26, 0);
    outdegree = vector<int>(26, 0);
    for(int i=0; i<words.size(); i++) {
        int from = words[i][0] - 'a';
        int to = words[i][words[i].size() -1] - 'a';
        graph[from][to].push_back(words[i]);
        adj[from][to]++;
        outdegree[from]++;
        indegree[to]++;
    }
}

bool checkEuler()
{
    int plus1=0, minus1=0;
    for(int i=0; i<26; i++) {
        int delta = outdegree[i] - indegree[i];
        if(delta < -1 || delta > 1) return false;
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }
    
    return ((plus1 == 0 && minus1 == 0) || 
            (plus1 == 1 && minus1 == 1));
}

vector<int> getEulerTrailOrCircuit()
{
    vector<int> circuit;
    for(int i=0; i<26; i++) {
        if(outdegree[i] == indegree[i]+1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    
    for(int i=0; i<26; i++) {
        if(outdegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;
}

void getEulerCircuit(int here, vector<int>& circuit)
{
    for(int i=0; i<adj.size(); i++) {
        while(adj[here][i] > 0) {
            adj[here][i]--;
            getEulerCircuit(i, circuit);
        }
    }
    circuit.push_back(here);
}