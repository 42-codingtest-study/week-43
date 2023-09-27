import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;

public class BOJ11286 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		int count = 0;

		/**
		 * 우선순위 큐는 추가되는 요소에 대해 계속 정렬을 진행하여 그 상태를 유지하고 있기 때문에, 어떻게 우선순위 큐를 정렬시킬 것인지가 매우 중요하다.
		 * 정렬 상태를 Comparator로 설정할 수 있다. 다음의 Comparator는 절댓값을 비교하고, 그 후에 절댓값이 같다면 작은 값이 앞으로 오게 하는 로직이다.
		 */
		Comparator<Integer> comparator = new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				int abs = Integer.compare(Math.abs(o1), Math.abs(o2));
				return abs != 0 ? abs : Integer.compare(o1, o2);
			}
		};

		PriorityQueue<Integer> queue = new PriorityQueue<>(comparator);

		for (int i = 0; i < N; i++) {
			int inputNum = Integer.parseInt(br.readLine());

			if (inputNum != 0) {
				queue.add(inputNum);
			} else {
				if (!queue.isEmpty()) {
					bw.write(queue.poll() + "\n");
				} else {
					bw.write("0\n");
				}
			}
//			System.out.println(queue);
		}

//		System.out.println();
		bw.flush();
		bw.close();
	}
}
