import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 병합정렬의 특징을 통해 버블 정렬의 swap 횟수를 구하자
public class Doit_021 {
    private static int[] arr;
    private static int[] tmp;
    private static long result;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[N];
        tmp = new int[N];
        for (int idx = 0; idx < N; idx++) {
            arr[idx] = Integer.parseInt(st.nextToken());
        }

        result = 0;
        mergeSort(0, N - 1);
        System.out.println(result);
    }
    private static void mergeSort(int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(start, mid);
            mergeSort(mid + 1, end);
            merge(start, mid, end);
        }
    }
    private static void merge(int start, int mid, int end) {
        int index = start;
        int pointer1 = start;
        int pointer2 = mid + 1;
        while (pointer1 <= mid && pointer2 <= end) {
            if (arr[pointer1] <= arr[pointer2]) {
                tmp[index] = arr[pointer1];
                pointer1++;
            } else {
                tmp[index] = arr[pointer2];
                result += pointer2 - index;
                pointer2++;
            }
            index++;
        }
        while (pointer1 <= mid) {
            tmp[index] = arr[pointer1];
            index++;
            pointer1++;
        }
        while (pointer2 <= end) {
            tmp[index] = arr[pointer2];
            index++;
            pointer2++;
        }
        for (int i = start; i <= end; i++) {
            arr[i] = tmp[i];
        }
    }
}