import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

// 계수 정렬을 학습하자
public class Doit_022 {

    private static int[] countArr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        countArr = new int[10000 + 1];

        for (int idx = 0; idx < N; idx++) {
            countArr[Integer.parseInt(br.readLine())]++;
        }

        for (int idx = 0; idx <= 10000; idx++) {
            while (countArr[idx] != 0) {
                bw.write(String.valueOf(idx));
                bw.newLine();
                countArr[idx]--;
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}