import java.util.*;

class Main {
    public static double cache[][];
    public static boolean memo[][];
    public static ArrayList<Integer> adj[];
    public static int N,D,T;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            N = sc.nextInt();
            D = sc.nextInt();
            int p = sc.nextInt();
            
            adj = new ArrayList[N+1];
            cache = new double[N+1][D+1];
            for(int i=0; i<=N; i++) {
                adj[i] = new ArrayList<Integer>();
            }
            
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    int n = sc.nextInt();
                    if(n == 1) adj[i].add(j);
                }
            }
            
            int t = sc.nextInt();
            for(int i=0; i<t; i++) {
                T = sc.nextInt();
                memo = new boolean[N+1][D+1];
                System.out.printf("%.8f ", solve(p,0));
            }
            System.out.println();
        }
    }
    
    public static double solve(int n, int d) {
        if(d == D) return n == T ? 1 : 0;
        
        if(memo[n][d]) return cache[n][d];
        
        memo[n][d] = true;
        cache[n][d] = 0;
        
        int p = adj[n].size();
        for(int i=0; i<p; i++) {
            int there = adj[n].get(i);
            cache[n][d] += (double)1/p*(solve(there,d+1));
        }
        return cache[n][d];
    }
}