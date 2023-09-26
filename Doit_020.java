import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

// 병합 정렬을 학습하자
public class Doit_020 {

    private static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    private static int getPartition(int[] arr, int left, int right) {
        if (left + 1 == right) {
            if (arr[left] > arr[right]) {
                swap(arr, left, right);
            }
            return right;
        }

        int mid = (left + right) / 2;
        swap(arr, left, mid);
        int pivot = arr[left];
        int start = left + 1;
        int end = right;

        while (start <= end) {
            while (pivot < arr[end] && end > 0) {
                end--;
            }
            while (/*start < end*/ start < arr.length - 1 && arr[start] < pivot) {
                start++;
            }
            if (start <= end) {
                swap(arr, start++, end--);
            }
        }
        arr[left] = arr[end];
        arr[end] = pivot;
        return (end);
    }

    public static void quickSort(int[] arr, int left, int right, int K) {
        int partition = getPartition(arr, left, right);

        if (partition == K - 1) {
            return;
        }  else if (partition < K - 1) {
            quickSort(arr, partition +  1, right, K);
        } else {
            quickSort(arr, left, partition - 1, K);
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int idx = 0; idx < N; idx++) {
            arr[idx] = Integer.parseInt(st.nextToken());
        }

        quickSort(arr, 0, N-1, K);
        bw.write(String.valueOf(arr[K - 1]));
        bw.flush();
        bw.close();

    }
}
