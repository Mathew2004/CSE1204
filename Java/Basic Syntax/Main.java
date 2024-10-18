import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new Scanner object
        // System.out.print(5+8);
        // Scanner scanner = new Scanner(System.in);
        // Variables
        // int number = 5;
        // float points = 5.65f;
        // String name = "Evangel";
        // boolean flag = true;

        // System.out.print(name+ " "+ points+ " " + number);

        // Get Input from user
        Scanner myObj = new Scanner(System.in); // Create a Scanner object
        System.out.println("Enter username");

        String userName = myObj.nextLine(); // Read user input
        System.out.println("Username is: " + userName); // Output user input
        

    }
}
