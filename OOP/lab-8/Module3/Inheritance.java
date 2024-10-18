// package lab-8.Module3;

class A {
    int ax;

    public A() {
        ax = 0;
        System.out.println("Inside Constructor A()");
    }

    public A(int x) {
        ax = x;
        System.out.println("Inside Parameterized Constructor A(int x)");
    }

    // int getX(){
    // return (ax+10);
    // }
    public void Display() {
        System.out.println("In Display A() ax = " + ax);
    }
}

class B extends A {
    private int bx;

    public B() {
        bx = 0;
        System.out.println("Inside Constructor B()");
    }

    public B(int x, int y) {
        super(10);
        bx = y;
        System.out.println("Inside Parameter Constructor B()");
    }

    public void Display() {
        super.Display();
        System.out.println("In Display of B() ax=" + ax + " bx = " + bx);
    }
}

public class Inheritance {
    public static void main(String[] args) {
        B b = new B(10, 20);
        b.Display();

    }
}
