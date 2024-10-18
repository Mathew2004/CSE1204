// package lab-8.Module4;

abstract class Test1 {
    abstract void Display();

    void Show() {
        System.out.println("This is Show method in abstract class test1");
    }
}

class Test2 extends Test1 {
    @Override
    void Display() {
        System.out.println("THis is Display method implemented in class Test2");
    }
}

public class Abstract {
    public static void main(String[] args) {
        Test2 obj = new Test2();
        obj.Display();
        obj.Show();
    }
}
