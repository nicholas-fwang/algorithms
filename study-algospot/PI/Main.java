import java.util.*;

class Main {
    public static final int oo = 0x3f3f3f3f;
    public static String s;
    public static int [] cache;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        sc.nextLine();
        for(int tc=0; tc<testCase; tc++) {
            s = sc.nextLine();
            cache = new int[s.length()+1];
            Arrays.fill(cache, -1);
            System.out.println(solve(0));
        }
    }
    
    public static int solve(int n) {
        if(n == s.length()) return 0;
        
        if(cache[n] != -1) return cache[n];
        cache[n] = oo;
        
        for(int i=3; i<=5; i++) {
            if(n+i<=s.length())
                cache[n] = min(cache[n], solve(n+i)+calc(n,i));
        }
        return cache[n];
    }
    
    public static int min(int a, int b) {
        return a>b?b:a;
    }
    
    public static int calc(int start, int offset) {
        String m;
        m = s.substring(start, start+offset);
        boolean find = true;
        
        for(int i=0; i<m.length()-1; i++) {
            if(m.charAt(i) != m.charAt(i+1)) {
                find = false;
                break;
            }
        }
        if(find) return 1;
        find = true;
        
        int d = m.charAt(0)-m.charAt(1);
        for(int i=0; i<m.length()-1; i++) {
            if(m.charAt(i)-m.charAt(i+1) != d) {
                find = false;
                break;
            }
        }
        
        if(find && abs(d) == 1) {
            return 2;
        }
        find = true;
        
        for(int i=0; i<m.length(); i++) {
            if(m.charAt(i%2) != m.charAt(i)) {
                find = false;
                break;
            }
        }
        if(find) return 4;
        find = true;
        for(int i=0; i<m.length()-1; i++) {
            if(m.charAt(i)-m.charAt(i+1) != d) {
                find = false;
                break;
            }
        }
        if(find) return 5;
        return 10;  
    }
    
    public static int abs(int d) {
        return (d > 0 ? d : -d);
    }
}