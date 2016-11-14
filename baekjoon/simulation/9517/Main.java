import java.util.*;

class Main {
    
    public static final int timeover = 210;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int time = 0;
        int first = sc.nextInt();
        int n = sc.nextInt();
        for(int i=0; i<n; i++) {
            int a = sc.nextInt();
            char b = sc.next().charAt(0);
            time += a;
            if(time >= timeover) {
                System.out.println(first);
                return ;
            }
            if(b == 'T') first = (first+1==9 ? 1 : first+1);
        }
    }
}