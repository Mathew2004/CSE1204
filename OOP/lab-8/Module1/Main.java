// package lab-8.Module1;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] ax = new int[4];
        ax = getArray();
        System.out.println(Arrays.toString(ax));
    }

    public static int[] getArray(){
        return (new int[] {2,3,4});
    }
}
