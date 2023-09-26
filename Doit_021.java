import java.io.*;
import java.util.Arrays;

public class BOJ1517 {

	static long sum = 0L;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		int[] inputNums = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
//		System.out.println(Arrays.toString(inputNums));
		mergeSort(inputNums);
//		System.out.println(Arrays.toString(inputNums));
		bw.write(sum + "\n");
		bw.flush();
		bw.close();
	}

	static void mergeSort(int[] inputNums) {
		if (inputNums == null || inputNums.length <= 1) {
			return;
		}

		int mid = inputNums.length / 2;
		int[] leftArr = Arrays.copyOfRange(inputNums, 0, mid);
		int[] rightArr = Arrays.copyOfRange(inputNums, mid, inputNums.length);

		mergeSort(leftArr);
		mergeSort(rightArr);

		merge(inputNums, leftArr, rightArr);
	}

	static void merge(int[] inputNums, int[] leftArr, int[] rightArr) {
		int i = 0, l = 0, r = 0;

		while (l < leftArr.length && r < rightArr.length) {
			if (leftArr[l] <= rightArr[r]) {
				inputNums[i++] = leftArr[l++];
			} else {
				/**
				 * leftArr에 있는 원소가 rightArr에 있는 원소보다 크다면 값의 순서가 바뀐다. 그러므로 이 조건에서만 머지소트에서 swap이 일어난다고 볼 수 있다.
				 * leftArr의 길이 중에서 l의 위치를 뺀 나머지 칸들이 해당 인덱스가 이동한 횟수이므로, 이를 축적한다.
				 */
				inputNums[i++] = rightArr[r++];
				sum += leftArr.length - l;
			}
//			System.out.println(sum);
		}

		while (l < leftArr.length) {
			inputNums[i++] = leftArr[l++];
		}

		while (r < rightArr.length) {
			inputNums[i++] = rightArr[r++];
		}
	}
}
