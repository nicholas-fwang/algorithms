import java.util.*;

class Main {
    static final int[] dx = {0,1,0,-1,1,1,-1,-1};
    static final int[] dy = {1,0,-1,0,1,-1,1,-1};
    static String board[];
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        sc.nextLine();
        board = new String[5];
        for(int test = 0; test < testCase; test++) {
            for(int i=0; i<5; i++) {
                board[i] = sc.nextLine();
            }
            int words = sc.nextInt();
            sc.nextLine();
            for(int i=0; i<words; i++) {
                String word = sc.nextLine();
                boolean find = false;
                for(int j=0; j<5; j++) {
                    for(int k=0; k<5; k++) {
                        if(board[j].charAt(k) == word.charAt(0) && solve(j,k,word,0)) {
                            find = true;
                            System.out.println(word + " YES");
                            break;
                        } 
                    }
                    if(find) break;
                }
                if(!find) System.out.println(word + " NO");
            }
        }
    }
    
    public static boolean solve(int row, int col, String word, int cnt) {
        if(cnt == word.length()-1) {
            return true;
        }
        
        boolean ret = false;
        for(int i=0; i<8; i++) {
            int nextRow = row + dx[i];
            int nextCol = col + dy[i];
            if(inRange(nextRow, nextCol) && board[nextRow].charAt(nextCol) == word.charAt(cnt+1)) {
                ret = solve(nextRow, nextCol, word, cnt+1);
            }
        }
        
        return ret;
    }
    
    public static boolean inRange(int row, int col) {
        return row >= 0 && row < 5 && col >= 0 && col < 5;
    }
}