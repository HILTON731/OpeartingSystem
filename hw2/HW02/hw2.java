package HW2;

import java.util.Scanner;

public class hw2{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        Thread t = new Thread(new thread_prime(num));
        t.start();
    }
}
class thread_prime implements Runnable{
    static int num;
    public thread_prime(Object num){
        thread_prime.num = (int) num;
    }
    @Override
    public void run() {

        for(int i = 1;i <= thread_prime.num;i++){
            int check = 0;
            for(int j = i; j > 0;j--){
                if(i % j == 0){
                    check++;
                }
            }
            if(check == 2)
                System.out.printf("%d ", i);
        }
    }
}
