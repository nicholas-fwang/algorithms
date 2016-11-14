import java.util.*;

class Main {
    static String[] map;
    static int n,m;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();
        map = new String[n];
        for(int i=0; i<n; i++) {
            map[i] = sc.nextLine();
        }
        int ret = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int tmp;
                if(map[i].charAt(j) == 'L') {
                    tmp = bfs(i,j);
                    if(tmp > ret) ret = tmp;
                }
            }
        }
        System.out.println(ret);
    }
    
    public static int bfs(int row, int col) {
        int ret = 0;
        int [][] dist = new int[n][m];
        for(int i=0; i<n; i++) Arrays.fill(dist[i], -1);
        dist[row][col] = 0;
        Queue<Integer> qr = new LinkedList<Integer>();
        Queue<Integer> qc = new LinkedList<Integer>();
        
        qr.add(row);
        qc.add(col);
        
        while(!qr.isEmpty()) {
            int hereRow = qr.peek();
            int hereCol = qc.peek();
            qr.remove(); qc.remove();
            
            if(dist[hereRow][hereCol] > ret) ret = dist[hereRow][hereCol];
            
            for(int i=0; i<4; i++) {
                int nextRow = hereRow + dy[i];
                int nextCol = hereCol + dx[i];
                
                if(inRange(nextRow, nextCol) && map[nextRow].charAt(nextCol) == 'L' && dist[nextRow][nextCol] == -1) {
                    dist[nextRow][nextCol] = dist[hereRow][hereCol] + 1;
                    qr.add(nextRow);
                    qc.add(nextCol);
                }
            }
        }
        return ret;
    }
    
    public static boolean inRange(int row, int col) {
        return row >= 0 && row < n && col >=0 && col < m;
    }
}