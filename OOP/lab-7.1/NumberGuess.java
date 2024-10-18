import java.util.Scanner;


public class NumberGuess {
    public static void main(String[] args) {
        // Take input
        Scanner scanner = new Scanner(System.in);
        System.out.println("Guess a number between 1 and 100");
        int guess=0; 
        

        // Random Number
        int number = (int) (Math.random() * 100) + 1;
        while(number != guess){
            guess = scanner.nextInt();
            if(number > guess){
                System.out.println("Too low, Increase Number!");
            }else{
                System.out.println("Too high, Decrease Number!");
            }
        }
        scanner.close();
        System.out.println("Winnn! conggoooo");
       
    }
}
