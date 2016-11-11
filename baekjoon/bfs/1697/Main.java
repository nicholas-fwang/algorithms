import java.util.*;

class Main {
    static ArrayList<ArrayList<Integer> > adj;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        adj = new ArrayList<ArrayList<Integer> >();
        
        int l = n>k?n+2:k+2;
        for(int i=0; i<l; i++) {
            adj.add(new ArrayList<Integer>());
        }
        for(int i=0; i<l; i++) {
            if(i+1<l) adj.get(i).add(i+1);
            if(i-1>=0) adj.get(i).add(i-1);
            if(i*2<l) adj.get(i).add(i*2);
        }
        
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(n);
        int dist[] = new int[adj.size()];
        Arrays.fill(dist, -1);
        dist[n] = 0;
        while(!q.isEmpty()) {
            int here = q.peek();
            q.remove();
            
            for(int i=0; i<adj.get(here).size(); i++) {
                int there = adj.get(here).get(i);
                if(dist[there] == -1) {
                    dist[there] = dist[here]+1;
                    q.add(there);
                }
            }
        }
        System.out.println(dist[k]);
    }
}