// 그래프의 인접 리스트 표현
vector<vector<int> > adj;

// discovered[i] = i번 정점의 발견 순서
// finished[i]=dfs(i)가 종료했으면 1, 아니면 0
vector<int> discovered, finished;

// 지금까지 발견한 정점의 수
int counter;

void dfs2(int here) {
    discovered[here] = couter++;
    // 모든 인접 리스트를 순회한다.
    for(int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        cout << "(" << here < "," << there << ") is a ";
        
        //아직 방문한적이 없다면 방문한다 : 트리간선
        if(discovered[there] == -1) {
            cout << "three edge" << endl;
            dfs2(there);
        }
        //만약 there가 here보다 늦게 발견됐다면 there는 here의 후손이다 : 순방향
        else if(discovered[here] < discovered[there]) {
            cout << "forward edge" << endl;
        }
        // 만약 dfs2(there)가 아직 종료하지 않았다면 there는 here의 선조다 : 역방향
        else if(finished[there] == 0) {
            cout << "back edge" << endl;
        }
        // 이 외의 경우 : 교차간선
        else {
            cout << "cross edge" << endl;
        }
    }
    finished[here] = 1;
}