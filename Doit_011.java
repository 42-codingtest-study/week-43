import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Doit_011 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int std = 1;

        // stack 특징을 활용하여 정렬을 구현해보자
        for (int idx = 0; idx < n; idx++) {
            int num = Integer.parseInt(br.readLine());

            if (num >= std) {
                while (num >= std) {
                    stack.push(std++);
                    sb.append("+\n");
                }
                stack.pop();
                sb.append("-\n");
            } else {
                if (stack.peek() != num) {
                    System.out.println("NO");
                    return ;
                } else {
                    stack.pop();
                    sb.append("-\n");
                }
            }
        }
        System.out.println(sb.toString());

    }

}
