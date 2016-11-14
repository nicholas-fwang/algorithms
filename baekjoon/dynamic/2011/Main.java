import java.util.*;

class Main {
    static final int DIVIDE = 1000000;
    static String s;
    static int[] cache;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.nextLine();
        cache = new int[5001];
        Arrays.fill(cache, -1);
        System.out.println(solve(0)%DIVIDE);
    }
    
    public static int solve(int n) {
        if(n == s.length()) return 1;
        
        if(cache[n] != -1) return cache[n];
        cache[n] = 0;
        
        if(s.charAt(n) > '0') cache[n] += solve(n+1)%DIVIDE;
        if(n+1 < s.length()) {
            int tmp = (s.charAt(n)-'0')*10 + s.charAt(n+1)-'0';
            if(tmp >= 10 && tmp <= 26) cache[n] += solve(n+2)%DIVIDE;
        }
        return cache[n];
    }
}