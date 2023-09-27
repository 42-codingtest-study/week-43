import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class BOJ17298 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		int[] ansArr = new int[N];
		int[] inputNums = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		ArrayList<Num> nums = new ArrayList<>();

		for (int i = 0; i < inputNums.length; i++) {
			nums.add(new Num(inputNums[i], i));
		}
		int idx = 0;
		Stack<Num> stack = new Stack<>();

		stack.push(nums.get(0));

		// while (stack.size() != 0 && idx < inputNums.length) {
		while (idx < inputNums.length) {
			/**
			 * 오큰수를 찾았을 때, 스택에 있던 값의 원래 인덱스에 오큰수 값을 위치시켜야 하므로 Num 클래스에 값의 원래 인덱스를 저장한다.
			 */
			while (!stack.isEmpty() && stack.peek().val < inputNums[idx]) {
				Num poppedNum = stack.pop();
				ansArr[poppedNum.idx] = inputNums[idx];
			}
			stack.push(new Num(inputNums[idx], idx));
			idx++;
		}

		/**
		 * 아직 스택에 값이 남아있다면, 오큰수를 못 찾았다는 소리이므로 해당 값의 인덱스에 -1값을 대입한다.
		 */
		for (Num num : stack) {
			ansArr[num.idx] = -1;
		}

		for (int num : ansArr) {
			bw.write(num + " ");
		}
		bw.flush();
		bw.close();
	}

	/**
	 * 오큰수를 찾아서 스택에 원래 있던 값을 빼는 것은 편하지만, 그 수의 원래 위치에 오큰수를 넣어야한다.
	 * 그러므로 클래스를 따로 만들어 해당 값의 원래 인덱스 값을 저장한다.
	 */
	static class Num {
		int val;
		int idx;

		public Num(int val, int idx) {
			this.val = val;
			this.idx = idx;
		}
	}
}
