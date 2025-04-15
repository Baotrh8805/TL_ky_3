
import java.lang.Math;

class String 123 {
    public static void main(String[] args) {
        String st = "abcde", st1 = "abc", st3 = "", st4 = "";
        System.out.println(st.charAt(1)); // b
        System.out.println(st.startsWith("b")); // false
        System.out.println(st.endsWith("b")); // false
        System.out.println(st.indexOf("e")); // 4
        System.out.println(st.equals(st1)); // false
        System.out.println(st.toUpperCase()); // ABCDE

        int m = 9;
        System.out.println(Math.sqrt(m)); // 3.0

        StringBuffer st2 = new StringBuffer("mnp").append("888");
        System.out.println(st2); // mnp888

        st3 = new StringBuffer(st2).reverse().toString();
        System.out.println(st3); // 888pnm

        st4 = new StringBuilder(st2).reverse().toString();
        System.out.println(st4); // 888pnm

        String word = "Hello You!!!!";
        StringBuilder str = new StringBuilder(word);
        str.reverse();
        System.out.println(str); // !!!!uoy olleH

        String test = "abc.def.123";
        if (test.contains(".")) {
            String[] output = test.split("\\.");
            System.out.println(output[0]); // abc
            System.out.println(output[1]); // def
            System.out.println(output[2]); // 123
        } else {
            throw new IllegalArgumentException(test + " - invalid format!");
        }
    }
}
