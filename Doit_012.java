import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Doit_012 {

    private static int[] inputArr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        Stack<Integer> stack = new Stack<>();

        inputArr = new int[n];

        for (int idx = 0; idx < n; idx++) {
            inputArr[idx] = Integer.parseInt(st.nextToken());
        }

        // stack 의 특징과 index 를 저장하는 스킬을 활용
        for (int idx = 0; idx < n; idx++) {
            while (!stack.isEmpty() && inputArr[stack.peek()] < inputArr[idx])
                inputArr[stack.pop()] = inputArr[idx];
            stack.push(idx);
        }

        while (!stack.isEmpty()) {
            inputArr[stack.pop()] = -1;
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            sb.append(inputArr[i]).append(' ');
        }

        System.out.println(sb);
    }
}