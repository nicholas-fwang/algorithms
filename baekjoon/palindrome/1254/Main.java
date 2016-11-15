import java.util.*;

class Main {
    
    static String s;
    static String tmp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.nextLine();
        tmp = s;
        if(isPal(tmp.length()-1)) {
            System.out.println(tmp.length());
        } else {
            for(int i=0; i<s.length(); i++) {
                tmp = s;
                for(int j=i; j>=0; j--) {
                    tmp += s.charAt(j);
                }
                if(isPal(tmp.length()-1)) {
                    System.out.println(tmp.length());
                    return ;
                }
            }
        }
    }
    
    public static boolean isPal(int end) {
        int start = 0;
        while(start < end) {
            if(tmp.charAt(start) != tmp.charAt(end)) {
                return false;    
            }
            start++;
            end--;
        }
        return true;
    }
}