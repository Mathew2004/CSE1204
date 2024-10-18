package SOP;

public class Test1 {
    public void Display() {
        System.out.println("Display method in Test1");
    }
    private void privateDisplay(){
        System.out.println("Private Display in Test1");
    }

    public static void main(String[] args){
        // Test2.main(null);

        Test1 obj1 = new Test1();
        obj1.Display();

        Test2 obj2 = new Test2();
        obj2.Display();
    }
}
