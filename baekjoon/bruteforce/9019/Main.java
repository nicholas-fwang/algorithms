/**
 * time over
 **/
import java.util.*;

class Main {
    static final String ch = "DSLR";
    static int a,b;
    
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            a = sc.nextInt();
            b = sc.nextInt();
            
            Queue<Integer> q = new LinkedList<Integer>();
            
            int[][] parent = new int[10001][2];
            for(int i=0; i<10001; i++) {
                Arrays.fill(parent[i], -1);
            }
            
            parent[a][0] = a;
            parent[a][1] = -1;
            q.add(a);
            
            while(!q.isEmpty()) {
                int here = q.peek();
                q.remove();
                
                if(here == b) break;
                for(int i=0; i<4; i++) {
                    int there = operate(here, i);
                    if(parent[there][0] == -1) {
                        parent[there][0] = here;
                        parent[there][1] = i;
                        q.add(there);
                    }
                }
            }
            
            int n;
            List<Character> ret = new ArrayList<Character>();
            while(a != b) {
                n = parent[b][1];
                ret.add(ch.charAt(n));
                b = parent[b][0];
            }
            Collections.reverse(ret);
            for(int i=0; i<ret.size(); i++) {
                System.out.print(ret.get(i));
            }
        }
    }
    
    public static int operate(int n, int op) {
        switch(op) {
            case 0:
                n = (n*2)%10000;
                break;
            case 1:
                if(n == 0) n = 9999; 
                else n--;
                break;
            case 2:
                n = (n*10)%10000 + (n/1000);
                break;
            case 3:
                n = n/10 + (n%10)*1000;
                break;
            default :
                break;
        }
        return n;
    }
}