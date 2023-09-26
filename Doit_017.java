import java.io.*;
import java.util.Arrays;

public class BOJ1427 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		char[] inputNum = br.readLine().toCharArray();
		int[] nums = new int[inputNum.length];

		for (int i = 0; i < inputNum.length; i++) {
			nums[i] = inputNum[i] - '0';
		}

		selectionSort(nums);

		for (int i = nums.length - 1; i >= 0; i--) {
			bw.write(String.valueOf(nums[i]));
		}
		bw.flush();
		bw.close();
	}

	/**
	 * 각 인덱스를 for문으로 돌면서 해당 인덱스를 기준으로 오른쪽 방향에 자신보다 작은 값이 있으면, 그 값을 minIdx로 대체하고 해당 값과 기준 값을 바꾼다.
	 * 가장 작은 값을 선택하여 swap하는 것이므로 선택정렬이다.
	 */
	static void selectionSort(int[] nums) {
		for (int i = 0; i < nums.length - 1; i++) {
			int minIdx = i;

			for (int j = i + 1; j < nums.length; j++) {
				if (nums[j] < nums[minIdx]) minIdx = j;
			}

			int tmp = nums[i];
			nums[i] = nums[minIdx];
			nums[minIdx] = tmp;
		}
	}
}
