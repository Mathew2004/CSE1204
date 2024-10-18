class A{
    private int ax;
    public A(int x){
        ax = x;
    }
    class B{
        private int bx;
        public B(int x){
            bx = x;
        }

        public void Display(){
            System.out.print(ax+bx);
        }
    }
}

public class Test{
    public static void main(String[] args) {
        // A a(2);
        // a.Display();
        A a = new A(1);
        A.B b = a.new B(2);
        b.Display();

        
    }
}