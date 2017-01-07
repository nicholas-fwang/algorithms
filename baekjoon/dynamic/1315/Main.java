import java.util.*;

class Main {
    static int N;
    static int cache[][];
    static int psum[][], qsum[][];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        cache = new int[1001][1001];
        psum = new int[1001][1001];
        qsum = new int[1001][1001];
        for(int i=0; i<=1000; i++) {
            Arrays.fill(cache[i], -1);
            Arrays.fill(psum[i], 0);
            Arrays.fill(qsum[i], 0);
        }
        
        N = sc.nextInt();
        for(int i=0; i<N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            
            for(int j=a; j<=1000; j++) {
                for(int k=1; k<=1000; k++) {
                    psum[j][k]+=c;
                    qsum[j][k]++;
                }
            }
            for(int j=1; j<=1000; j++) {
                for(int k=b; k<=1000; k++) {
                    psum[j][k]+=c;
                    qsum[j][k]++;
                }
            }
            for(int j=a; j<=1000; j++) {
                for(int k=b; k<=1000; k++) {
                    psum[j][k]-=c;
                    qsum[j][k]--;
                }
            }
        }
        System.out.println(solve(1,1));
    }
    
    public static int solve(int st, int in) {
        if(cache[st][in] != -1) return cache[st][in];
        int ret = qsum[st][in];
        int cptr = psum[st][in]-st-in+2;
        for(int i=0; i<=cptr; i++) {
            int cstr = min(1000, st+i);
            int cint = min(1000, in+cptr-i);
            if(qsum[cstr][cint] == qsum[st][in]) continue;
            ret = max(ret, solve(cstr, cint));
        }
        
        return cache[st][in] = ret;
    }
    
    public static int min(int a, int b) {
        return a>b?b:a;
    }
    
    public static int max(int a, int b) {
        return a>b?a:b;
    }
}