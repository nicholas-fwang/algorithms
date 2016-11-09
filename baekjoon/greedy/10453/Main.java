import java.util.*;

class Main {
    
    static StringBuilder a,b;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        sc.nextLine();
        for(int tc=0; tc<testCase; tc++) {
            String[] tmp = sc.nextLine().split(" ");
            a = new StringBuilder(tmp[0]);
            b = new StringBuilder(tmp[1]);
            int ret = 0;
            for(int i=0; i<a.length(); i++) {
                if(a.charAt(i) != b.charAt(i)) {
                    for(int j=i+1; j<a.length(); j++) {
                        if(a.charAt(j) == b.charAt(i)) {
                            ret += j-i;
                            swap(i, j);
                            break;
                        }
                    }
                }
            }
            System.out.println(ret);
        }
    }
    
    public static void swap(int i, int j) {
        if(a.charAt(i) == 'a') {
            a.setCharAt(i, 'b');
            a.setCharAt(j, 'a');
        } else {
            a.setCharAt(i, 'a');
            a.setCharAt(j, 'b');
        }
    }
}