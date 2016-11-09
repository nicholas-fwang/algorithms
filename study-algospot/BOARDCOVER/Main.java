import java.util.*;

class Main {   
    static final int[][][] c = {
        { {0,0},{0,1},{1,0} },
        { {0,0},{0,1},{1,1} },
        { {0,0},{1,0},{1,1} },
        { {0,0},{1,0},{1,-1} }
    };
    static String board[];
    static int h,w;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        sc.nextLine();
        for(int tc = 0; tc<testCase; tc++) {
            h = sc.nextInt();
            w = sc.nextInt();
            sc.nextLine();
            board = new String[h];
            for(int i=0; i<h; i++) {
                board[i] = sc.nextLine();
            }
            int ret = solve();
            System.out.println(ret);
        }
    }
    
    public static int solve() {
        int row = -1;
        int col = -1;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(board[i].charAt(j) == '.') {
                    row = i;
                    col = j;
                    break;
                }    
            }
            if(row != -1) break;
        }
        if(row == -1 && col == -1) return 1;
        int ret = 0;
        for(int i=0; i<4; i++) {
            if(isAvailable(row,col,i)) {
                for(int j=0; j<3; j++) {
                    int nextRow = row + c[i][j][0];
                    int nextCol = col + c[i][j][1];
                    StringBuilder builder = new StringBuilder(board[nextRow]);
                    builder.setCharAt(nextCol, '#');
                    board[nextRow] = builder.toString();
                }
                ret += solve();
                for(int j=0; j<3; j++) {
                    int nextRow = row + c[i][j][0];
                    int nextCol = col + c[i][j][1];
                    StringBuilder builder = new StringBuilder(board[nextRow]);
                    builder.setCharAt(nextCol, '.');
                    board[nextRow] = builder.toString();
                }
            }
        }
        return ret;
    }
    
    public static boolean isAvailable(int row, int col, int cnt) {
        for(int i=0; i<3; i++) {
            int nextRow = row + c[cnt][i][0];
            int nextCol = col + c[cnt][i][1];
            if(nextRow >= 0 && nextRow < h && nextCol >= 0 && nextCol < w && board[nextRow].charAt(nextCol) == '.') {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
}