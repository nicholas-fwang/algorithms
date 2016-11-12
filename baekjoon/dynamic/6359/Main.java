import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for(int tc=0; tc<testCase; tc++) {
            int n = sc.nextInt();
            int ret = 1;
            for(int i=2; i<=n; i++) {
                if(i*i <= n) ret++;
            }
            System.out.println(ret);
        }
    }
}