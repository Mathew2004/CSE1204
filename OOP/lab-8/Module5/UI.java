interface AI {
    public void PrintA();
}

interface BI {
    public void PrintB();
}

interface CI {
    public void PrintC();
}

class A implements AI {

    public void PrintA() {
        System.out.println("Inside PrintA()");
    }
}

class B extends A implements BI {
    public void PrintB() {
        System.out.println("Inside PrintB()");
    }
}

class C extends B implements CI {
    public void PrintC() {
        System.out.println("Inside PrintC()");
    }
}

public class UI {
    public static void main(String[] args) {
        C c = new C();
        c.PrintA();
        c.PrintB();
        c.PrintC();
    }
}