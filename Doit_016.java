import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 버블 정렬의 특징을 활용하여 nlogn 을 통해 버블 정렬의 swap event 횟수(내부 for 문 횟수)를 구한다
public class Doit_016 {
    private static int[] arr;
    private static int[] indexArr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        arr = new int[N];
        indexArr = new int[1000001];
        for (int idx = 0; idx < N; idx++) {
            arr[idx] = Integer.parseInt(br.readLine());
            indexArr[arr[idx]] = idx;
        }

        Arrays.sort(arr);

        int max = 0;
        for (int idx = 0; idx < N; idx++) {
            int distance = indexArr[arr[idx]] - idx;
            if (max < distance)
                max = distance;
        }
        System.out.println(max + 1);
    }
}