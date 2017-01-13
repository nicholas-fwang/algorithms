import java.util.*;

class Main {
    static int N;
    static int cache[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        cache = new int[1001];
        Arrays.fill(cache, -1);
        
        N = sc.nextInt();
        String ret = (play(N)==0?"CY":"SK");
        System.out.println(ret);
    }
    
    public static int play(int n) {
        
        int ret = cache[n];
        if(ret != -1) return ret;
        ret = 0;
        
        if(n-3>0 && play(n-3) == 0) ret = 1;
        if(n-1>0 && play(n-1) == 0) ret = 1;
        
        return cache[n] = ret;
    }
}