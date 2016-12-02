import java.util.*;

class Main {
    public static final int oo = 0x3f3f3f3f;
    public static int N;
    public static int [] map;
    public static int [][] cache;
    public static int [] psum;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            N = sc.nextInt();
            cache = new int[N+1][N+1];
            for(int i=0; i<=N; i++) Arrays.fill(cache[i], -1);
            map = new int[N+1];
            for(int i=0; i<N; i++) map[i] = sc.nextInt();
            psum = new int[N+1];
            psum[0] = 0;
            for(int i=1; i<=N; i++) psum[i] = psum[i-1]+map[i-1];
            
            System.out.println(solve(0,N-1));
        }
    }
    
    public static int solve(int left, int right) {
        if(left == right) return 0;
        
        if(cache[left][right] != -1) return cache[left][right];
        cache[left][right] = oo;
        
        for(int i=left; i<right; i++) {
            cache[left][right] = min(cache[left][right], solve(left, i)+solve(i+1, right)+psum[right+1]-psum[left]);
        }
        return cache[left][right];
    }
    
    public static int min(int a, int b) {
        return a>b?b:a;
    }
}