import java.util.*;

class Main {
    static final int dy[] = {1,-1,0,0};
    static final int dx[] = {0,0,1,-1};
    static int r,c;
    static String board[];
    static boolean alphabet[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        sc.nextLine();
        board = new String[r];
        alphabet = new boolean[26];
        Arrays.fill(alphabet, false);
        for(int i=0; i<r; i++) {
            board[i] = sc.nextLine();
        }
        
        System.out.println(solve(0,0));
    }
    
    public static int solve(int row, int col) {
        if(!inRange(row, col)) {
            return 0;
        } else if(alphabet[board[row].charAt(col)-'A']) {
            return 0;
        }
        
        int ret = 1;
        alphabet[board[row].charAt(col)-'A'] = true;
        for(int i=0; i<4; i++) {
            int nextRow = row + dy[i];
            int nextCol = col + dx[i];
            ret = Math.max(ret, solve(nextRow, nextCol)+1);
        }
        alphabet[board[row].charAt(col)-'A'] = false;
        return ret;
    }
    
    public static boolean inRange(int row, int col) {
        return row>=0 && row<r && col>=0 && col<c;
    }
}