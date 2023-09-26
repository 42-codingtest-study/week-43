import java.io.*;
import java.util.Arrays;

public class BOJ1377 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		Num[] arr = new Num[N];
		for (int i = 0; i < N; i++) {
			arr[i] = new Num(Integer.parseInt(br.readLine()), i);
		}

		mergeSort(arr);

		int maxMove = Integer.MIN_VALUE;

		/**
		 * 각 인덱스를 기준으로 버블소트를 진행했을 때, 단 한 번이라도 swap이 일어난 인덱스의 갯수를 구하는 것이다. 이 문제는 버블소트로 푼다면 시간이
		 * 부족하기 때문에, "버블 소트에서 swap이 한 번 이상 일어난 인덱스의 갯수는 머지 소트에서 가장 많이 움직인 요소의 움직인 거리와 같다."라는 성질을 사용한다.
		 * 인덱스가 얼마나 일어났는지 알아내기 위해서 class를 사용해 해당 값의 인덱스를 저장하고, 마지막에 정렬된 결과에서 몇 칸을 이동했는지 차를 구하여 가장 많이
		 * 움직인 거리를 찾는다.
		 */
		for (int i = 0; i < arr.length; i++) {
			if (arr[i].idx - i > maxMove) {
				maxMove = arr[i].idx - i;
			}
		}

		bw.write(maxMove + 1 + "\n");
		bw.flush();
		bw.close();
	}

	static void mergeSort(Num[] arr) {
		if (arr == null || arr.length <= 1) {
			return;
		}
		int mid = arr.length / 2;
		Num[] leftArr = Arrays.copyOfRange(arr, 0, mid);
		Num[] rightArr = Arrays.copyOfRange(arr, mid, arr.length);

		mergeSort(leftArr);
		mergeSort(rightArr);

		merge(arr, leftArr, rightArr);
	}

	static void merge(Num[] arr, Num[] leftArr, Num[] rightArr) {
		int i = 0, l = 0, r = 0;

		while (l < leftArr.length && r < rightArr.length) {
			if (leftArr[l].val <= rightArr[r].val) arr[i++] = leftArr[l++];
			else arr[i++] = rightArr[r++];
		}

		while (l < leftArr.length) {
			arr[i++] = leftArr[l++];
		}

		while (r < rightArr.length) {
			arr[i++] = rightArr[r++];
		}
	}

	static class Num {
		int val;
		int idx;

		public Num(int val, int idx) {
			this.val = val;
			this.idx = idx;
		}
	}

}
