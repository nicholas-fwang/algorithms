import java.util.*;

class Main {
    
    static ArrayList<ArrayList<Integer> > adj;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        int l = n>k?n+2:k+2;
        adj = new ArrayList<ArrayList<Integer> >();
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
        int [][] dist = new int[l][2];
        for(int i=0; i<l; i++) {
            dist[i][0] = -1;
            dist[i][1] = 0;
        }
        dist[n][0] = 0;
        dist[n][1] = 1;
        while(!q.isEmpty()) {
            int here = q.peek();
            q.remove();
            
            for(int i=0; i<adj.get(here).size(); i++) {
                int there = adj.get(here).get(i);
                if(dist[there][0] == -1) {
                    dist[there][0] = dist[here][0] + 1;
                    dist[there][1]++;
                    q.add(there);
                } else if(dist[there][0] == dist[here][0]+1) {
                    dist[there][1]++;
                    q.add(there);
                }
            }
        }
        
        System.out.println(dist[k][0] + "\n" + dist[k][1]);
    }
}