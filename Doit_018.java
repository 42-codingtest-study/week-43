import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 삽입 정렬과 합 배열을 함께 적용하자
public class Doit_018 {

    private static int[] intArr;
    private static int[] sumArr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        intArr = new int[N];
        sumArr = new int[N];
        for (int idx = 0; idx < N; idx++) {
            intArr[idx] = Integer.parseInt(st.nextToken());
        }

        int sum = 0;
        int min;
        for (int idx = 0; idx < N; idx++) {
            min = idx;
            for (int jdx = idx + 1; jdx < N; jdx++) {
                if (intArr[min] > intArr[jdx])
                    min = jdx;
            }
            if (intArr[idx] > intArr[min]) {
                int tmp = intArr[idx];
                intArr[idx] = intArr[min];
                intArr[min] = tmp;
            }
            if (idx == 0) sumArr[idx] = intArr[idx];
            else sumArr[idx] = sumArr[idx - 1] + intArr[idx];
            sum += sumArr[idx];
        }
        System.out.println(sum);
    }
}