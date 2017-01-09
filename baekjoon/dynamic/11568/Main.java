import java.util.*;

class Main {
    static int N;
    static int cache[];
    static int map[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        cache = new int[1001];
        map = new int[1001];
        for(int i=0; i<=1000; i++) Arrays.fill(cache, -1);
        
        N = sc.nextInt();
        for(int i=1; i<=N; i++) {
            map[i] = sc.nextInt();
        }
        System.out.println(solve(0));
    }
    
    public static int solve(int n) {
        if(cache[n] != -1) return cache[n];
        
        cache[n] = 0;
        for(int i=n+1; i<=N; i++) {
            if(map[i] > map[n]) {
                cache[n] = max(cache[n], solve(i)+1);
            }
        }
        return cache[n];
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
}