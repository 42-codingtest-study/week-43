import java.io.*;
import java.util.ArrayList;
import java.util.Stack;

public class BOJ1874 {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		int[] inputNums = new int[n];
		int count = 0;
		Stack<Integer> stack = new Stack<>();

		for (int i = 0; i < n; i++) {
			inputNums[i] = Integer.parseInt(br.readLine());
		}

		for (int i = 0; i < n; i++) {
			stack.push(i + 1);
			sb.append("+\n");

			/**
			 * count를 증가시키면서 inputNums의 값에 순차적으로 접근한다. 값을 찾는다면 pop!
			 */
			while (!stack.isEmpty() && stack.peek() == inputNums[count]) {
				stack.pop();
				count++;
				sb.append("-\n");
			}
		}

//		System.out.println(stack);

		/**
		 * for문을 n번 돌려서 모든 수를 push했음에도, 그 과정 중에 pop되지 않은 수가 있다면, 입력이 조건에 맞지 않다는 것이므로 NO!
		 */
		if (!stack.isEmpty()) {
			bw.write("NO\n");
		} else {
			bw.write(sb.toString());
		}
//		System.out.println(stack);
		bw.flush();
		bw.close();
	}
}
