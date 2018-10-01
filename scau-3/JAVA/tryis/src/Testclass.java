import java.util.HashMap;
import java.util.Map;

class abc {
    int a;
    double b;
}

public class Testclass {
    public static void main(String[] args) {
        Map<String, abc> a = new HashMap<>();

        abc b = new abc();

        a.put("1234", b);

        a.put("234", b);

        System.out.println(a.get("1234"));
        System.out.println(a.get("234"));
    }
}
