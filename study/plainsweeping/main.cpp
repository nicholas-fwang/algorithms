#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// x1 < x2, y1 < y2
struct Rectangle {
    int x1, y1, x2, y2;
};

int unionArea(const vector<Rectangle>& rects)
{
    if(rects.empty()) return 0;
    // 이벤트 정보 : (x좌표, 직사각형의 오른쪽 x좌표/왼쪽 x좌표, 사각형의 번호)
    typedef pair<int, pair<int, int>> Event;
    vector<Event> events;
    // 직사각형들의 y좌표 저장
    vector<int> ys;
    
    for(int i=0; i<rects.size(); i++) {
        // 직사각형의 y좌표를 ys에 저장한다
        ys.push_back(rects[i].y1);
        ys.push_back(rects[i].y2);
        // 직사각형의 x좌표가 작은거는 1, 큰거는 -1
        events.push_back(Event(rects[i].x1, make_pair(1, i)));
        events.push_back(Event(rects[i].x2, make_pair(-1, i)));
    }
    
    // 전체 직사각형들의 y좌표를 오름차순으로 정렬
    sort(ys.begin(), ys.end());
    // unique : iterator에서 중복된 부분을 뒤로보내고 중복되지 않은 부분을 앞으로 보낸뒤 중복되는 지점의 시작주소를 반환한다
    // erase : 첫번째 인자부터 두번째 인자까지 iterator를 삭제한다
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    // x좌표로 오름차순 정렬
    sort(events.begin(), events.end());
    int ret = 0;
    
    // count는 0으로 초기화된 ys.size()-1개의 원소를 갖는다
    vector<int> count(ys.size()-1, 0);
    for(int i=0; i<events.size(); i++) {
        // x좌표
        int x = events[i].first;
        // x좌표가 직사각형의 오른쪽 or 왼쪽인지
        int delta = events[i].second.first;
        // 직사각형의 번호
        int rectangle = events[i].second.second;
        
        // 이 직사각형의 y좌표
        int y1 = rects[rectangle].y1;
        int y2 = rects[rectangle].y2;
        
        // 이 직사각형을 기준으로 모든 y좌표를 보면서 y좌표가 직사각형의 y축 안에 있는지 확인한다
        for(int j=0; j<ys.size(); j++) {
            if(y1 <= ys[j] && ys[j] < y2) {
                // 안에 있으면 count에 delta를 더한다
                count[j] += delta;
            }
        }
        
        // cutLength 어디에서 자를지 저장
        // cutLength를 계산한다
        int cutLength = 0;
        for(int j=0; j<ys.size()-1; j++) {
            if(count[j] > 0) {
                cutLength += ys[j+1] - ys[j];
            }
        }
        
        // 다음이벤트의 x좌표 - x는 cutLength한 부분의 가로길이가 된다
        if(i+1 < events.size()) {
            ret += cutLength * (events[i+1].first - x);
        }
    }
    return ret;
}