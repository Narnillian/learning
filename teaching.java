public class Main {
    /**
     * Learning program created to quickly teach little FireHawks how to code Java
     * @param args
     */
    public static void main(String[] args) {
        int integer1 = 12;
        
        ExampleClass object = new ExampleClass(99);
        
        System.out.println(object.integer1);
        // System.out.println(object.integer2);

        object.integer1 = 39;
        System.out.println(object.integer1);
        // object.integer2 = 39;
        // System.out.println(object.integer2);

        object.setInt2(671);
        // System.out.println(object.integer2);

		State myState = State.A;
		System.out.println(myState);
		System.out.println(State.A);
    }
}

public class ExampleClass {
    public int integer1 = 2;
    private int integer2;
    public double decimal = integer1 + 0.6682;
    // double decimal2 = integer2 + 0.6682;
    
    // if (decimal == 13) {
    //     System.out.println("It's true!");
    // }

    // integer2 = 17;

    public ExampleClass(int value) {
        if (decimal == 13) {
            System.out.println("It's true!");
        }

        integer2 = value;
    }

    public void setInt2(int value) {
        integer2 = value;
    }

    private int example() {
        return 6;
    }
}

public enum State {
    A,
    B,
    C
}
