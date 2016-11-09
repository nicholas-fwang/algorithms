import java.util.*;

class Main {
    
    static int n,m;
    static int friends[][];
    static int taken[];
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc = 0; tc < testCase; tc++) {
            n = sc.nextInt();
            m = sc.nextInt();
            friends = new int[n][n];
            for(int i=0; i<n; i++) {
                Arrays.fill(friends[i], -1);    
            }
            
            taken = new int[n];
            Arrays.fill(taken, -1);
            for(int i=0; i<m; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                friends[a][b] = 1;
                friends[b][a] = 1;
            }
            System.out.println(solve());
        }
    }
    
    public static int solve() {
        int f = -1;
        for(int i=0; i<n; i++) {
            if(taken[i] == -1) {
                f = i;
                break;
            }
        }
        
        if(f == -1) return 1;
        int ret = 0;
        for(int i=f+1; i<n; i++) {
            if(taken[i] == -1 && friends[f][i] == 1) {
                taken[f] = taken[i] = 1;
                ret += solve();
                taken[f] = taken[i] = -1;
            }
        }
        return ret;
    }
}