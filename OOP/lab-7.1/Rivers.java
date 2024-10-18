import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Rivers {
    public static void main(String[] args) {
        // Step i) Create an ArrayList for rivers and add five rivers
        ArrayList<String> rivers = new ArrayList<>();
        rivers.add("Nile");
        rivers.add("Amazon");
        rivers.add("Yangtze");
        rivers.add("Mississippi");
        rivers.add("Ganges");

        // Step ii) Display all rivers
        System.out.println("All rivers: " + rivers);

        // Step iii) Print the 3rd river
        System.out.println("The 3rd river is: " + rivers.get(2));

        // Step iv) Search for a river
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the name of the river to search: ");
        String searchRiver = scanner.nextLine();
        if (rivers.contains(searchRiver)) {
            System.out.println(searchRiver + " is in the list.");
        } else {
            System.out.println(searchRiver + " is not in the list.");
        }

        // Step v) Find the position (index) of a particular river
        System.out.println("Enter the name of the river to find its position: ");
        String positionRiver = scanner.nextLine();
        int index = rivers.indexOf(positionRiver);
        if (index != -1) {
            System.out.println("The position of " + positionRiver + " is: " + index);
        } else {
            System.out.println(positionRiver + " is not in the list.");
        }

        // Step vi) Remove a particular river
        System.out.println("Enter the name of the river to remove: ");
        String removeRiver = scanner.nextLine();
        if (rivers.remove(removeRiver)) {
            System.out.println(removeRiver + " has been removed.");
        } else {
            System.out.println(removeRiver + " is not in the list.");
        }

        // Display rivers after removal
        System.out.println("Rivers after removal: " + rivers);

        // Step vii) Sort the rivers
        Collections.sort(rivers);
        System.out.println("Sorted rivers: " + rivers);

        // Step viii) Remove all rivers
        rivers.clear();
        System.out.println("All rivers removed. List is now: " + rivers);
        
        scanner.close();
    }
}
