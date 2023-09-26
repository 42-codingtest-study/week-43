import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ2164 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		Queue<Integer> queue = new LinkedList<>();

		for (int i = 1; i <= N; i++) {
			queue.add(i);
		}

		/**
		 * 먼저 뺀 것은 버리고, 그 다음에 뺀 것은 다시 위에 올리는 것
		 */
		while (queue.size() != 1) { // 카드가 한 장 남았을 때, 멈춘다.
			queue.poll(); // 먼저 뺀 것은 버리고
			queue.add(queue.poll()); // 그 다음에 뺀 것은 다시 위에 올린다.
		}

		bw.write(queue.peek() + "\n");
		bw.flush();
		bw.close();
	}
}
