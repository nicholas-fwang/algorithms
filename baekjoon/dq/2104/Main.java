import java.util.*;

class Main {
    public static int N;
    public static long map[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new long[N];
        for(int i=0; i<N; i++) {
            map[i] = sc.nextLong();
        }
        System.out.println(solve(0,N-1));
    }
    
    public static long solve(int left, int right) {
        if(left == right) return map[right]*map[right];
        
        int mid = (left+right)/2;
        long ret =  max(solve(left, mid), solve(mid+1, right));
        
        int lo = mid;
        int hi = mid+1;
        long height = min(map[lo], map[hi]);
        long width = map[lo]+map[hi];
        ret = max(ret, height*width);
        while(left < lo || hi < right) {
            if(hi < right && (lo == left || map[lo-1]<map[hi+1])) {
                ++hi;
                height = min(height, map[hi]);
                width += map[hi];
            } else {
                --lo;
                height = min(height, map[lo]);
                width += map[lo];
            }
            
            ret = max(ret, height*width);
        }
        return ret;
    }
    
    public static long min(long a, long b) {
        return a>b?b:a;
    }
    
    public static long max(long a, long b) {
        return a>b?a:b;
    }
}