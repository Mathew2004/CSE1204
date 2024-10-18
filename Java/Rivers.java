import java.util.Scanner;

public class Rivers {
    
    public void AddFiveRivers(){
        Scanner obj = new Scanner(System.in);
        // river = new String[];
        for(int i=0; i<4; i++){
            System.out.println("Enter a River -> ");
            String x = obj.nextLine();
            river[i] = x;
        }
        obj.close();
    }
    public void DisplayRivers(){
        for(int i=0; i<5; i++) {
            System.out.println(river[i] + "\n");
        }
    }

    public static void main(String[] args) {
        // String[] riversToAdd = {"padma","megna","jamuna"};
        // Rivers.AddFiveRivers(&riversToAdd);
        Rivers R = new Rivers();
        R.AddFiveRivers();
        // R.DisplayRivers();
    }
}
