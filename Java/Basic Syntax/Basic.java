import java.util.Scanner;
import java.lang.Math;

public class Basic{
    public static void main(String[] args) {
        
        int guess =  (int) (Math.random()*100);
        Scanner obj = new Scanner(System.in);

        System.out.println("Enter a Number -> ");
        int attemps = 0;
        while (true) {  
            int number = obj.nextInt();
            // System.out.println(guess);
    
            if(number>guess){
                System.out.println("Decrease the Number");
            }
            else if(number < guess) {
                System.out.println("Increase The number");
            }
            else{
                System.out.println("Congratulations! You have Won the Game. Total Attemps "+ attemps + "\n");
                break;
            }     
            attemps++;      
        }

        obj.close();
       

    }
}