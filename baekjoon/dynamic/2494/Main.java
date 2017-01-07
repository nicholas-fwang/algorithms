import java.util.*;

class Main {
    static int N;
    static int S[], O[];
    static int cache[][], choices[][], values[][];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        S = new int[10001];
        O = new int[10001];
        cache = new int[10001][10];
        choices = new int[10001][10];
        values = new int[10001][10];
        for(int i=0; i<=10000; i++) {
            Arrays.fill(cache[i], -1);
            Arrays.fill(choices[i], 0);
            Arrays.fill(values[i], 0);
        }
        N = sc.nextInt();
        sc.nextLine();
        String s,o;
        s = sc.nextLine();
        o = sc.nextLine();
        for(int i=0; i<s.length(); i++) {
            S[i] = s.charAt(i)-'0';
            O[i] = o.charAt(i)-'0';
        }
        System.out.println(solve(0,0));
        trace(0,0);
    }
    
    public static int solve(int n, int k) {
        if(n == N) return 0;
        if(cache[n][k] != -1) return cache[n][k];
        int ret;
        int cur = (S[n]+k)%10;
        int o = O[n];
        int left = (o-cur+10)%10;
        int right = (cur-o+10)%10;
        int leftRet = solve(n+1, (k+left)%10)+left;
        int rightRet = solve(n+1, k)+right;
        if(leftRet < rightRet) {
            ret = leftRet;
            choices[n][k] = (k+left)%10;
            values[n][k] = left;
        } else {
            ret = rightRet;
            choices[n][k] = k;
            values[n][k] = -right;
        }
        return cache[n][k] = ret;
    }
    
    public static void trace(int n, int k) {
        if(n == N) return ;
        if(values[n][k] == 0) {
            trace(n+1, k);
        } else {
            System.out.printf("%d %d\n", n+1, values[n][k]);
            trace(n+1, choices[n][k]);
        }
    }
}