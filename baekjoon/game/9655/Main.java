import java.util.*;

class Main {
    static int cache[];
    static int N;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        cache = new int[1001];
        Arrays.fill(cache, -1);
        N = sc.nextInt();
        String ret = (play(N)==0?"SK":"CY");
        System.out.println(ret);
    }
    
    public static int play(int n) {
        if(cache[n] != -1) return cache[n];
        cache[n] = 0;
        if(n-3>0) {
            if(play(n-3) == 0) {
                cache[n] = 1;
            }
        } else if(n-1>0) {
            if(play(n-1) == 0) {
                cache[n] = 1;
            }
        }
        return cache[n];
    }
}