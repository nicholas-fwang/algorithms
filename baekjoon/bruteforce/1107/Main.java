import java.util.*;

class Main {
    public static int o, N;
    public static boolean[] map;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        o = sc.nextInt();
        N = sc.nextInt();
        map = new boolean[10];
        Arrays.fill(map, false);
        for(int i=0; i<N; i++) {
            int tmp;
            tmp = sc.nextInt();
            map[tmp] = true;
        }
        
        int ret = abs(o-100);
        for(int i=0; i<=1000000; i++) {
            int p = possible(i);
            if(p >= 1) {
                ret = min(ret, abs(o-i)+p);
            }
        }
        System.out.println(ret);
    }
    
    public static int possible(int n) {
        int ret = 0;
        if(n == 0) return map[0] ? 0 : 1;
        while(n > 0) {
            ret++;
            if(map[n%10]) return 0;
            n /= 10;
        }
        return ret;
    }
    
    public static int min(int a, int b) {
        return a>b?b:a;
    }
    
    public static int abs(int n) {
        return n >= 0 ? n : -n;
    }
}