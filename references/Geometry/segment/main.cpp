// 두 선분(ab, cd)이 서로 접촉하는지 여부를 반환한다.
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
  // ccw(a,b,c) > 0 선분 ab의 반시계 방향에 c가 있다.
  // ab > 0 : 선분 ab의 반시계 방향에 c,d가 모두 있던가 시계 방향에 모두 있다.
  // ab < 0 : 선분 ab를 기준으로 서로 반대쪽에 c, d가 있다.
  // ab == 0 : ab와 c 또는 d가 한 직선상에 있다.
  double ab = ccw(a, b, c) * ccw(a, b, d);
  double cd = ccw(c, d, a) * ccw(c, d, b);

  // 두 선분이 한 직선상에 있거나 끝점이 겹치는 경우(b와 c점이 같다면 ab도 0이고 cd도 0이다)
  if(ab == 0 && cd == 0) {
    // b가 더 멀리 있는 점
    if(b < a) swap(a, b);
    // d가 더 멀리 있는 점
    if(d < c) swap(c, d);
    // 같은 직선일 경우 : 더 가까이있는 c보다 더 멀리 있는 b가 더 작다 --> 같은 직선인데 안 만난다. --> !true
    // 끝점이 겹치는 경우 : 겹쳐있다면 가까운점-먼점 일건데 이 경우에는 아래 조건은 무조건 둘다 false가 나온다 --> !false
    return !(b < c || d < a);
  }
  // 둘 다 0보다 작다 : 서로의 점이 반대 쪽에 있어서 두 선분은 만난다.
  // 하나는 0이고 하나는 0보다 작다 : 접촉해있다.
  return ab <= 0 && cd <= 0;
}
