import java.util.*;

class Main {
    public static int N;
    public static int cache[][];
    public static String s1,s2;
    
    public static void main(String[] args) {
        cache = new int[1001][1001];
        for(int i=0; i<=1000; i++) Arrays.fill(cache[i], -1);
        Scanner sc = new Scanner(System.in);
        s1 = sc.nextLine();
//        sc.nextLine();
        s2 = sc.nextLine();
//        sc.nextLine();
        System.out.println(solve(0,0));
    }
    
    public static int solve(int c1, int c2) {
        if(s1.length() == c1 || s2.length() == c2) {
            return 0;
        }
        
        if(cache[c1][c2] != -1) return cache[c1][c2];
        cache[c1][c2] = 0;
        
        if(s1.charAt(c1) == s2.charAt(c2)) {
            cache[c1][c2] = max(cache[c1][c2], solve(c1+1,c2+1)+1);
        } else {
            cache[c1][c2] = max(cache[c1][c2], solve(c1+1, c2));
            cache[c1][c2] = max(cache[c1][c2], solve(c1, c2+1));
        }
        return cache[c1][c2];
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
}