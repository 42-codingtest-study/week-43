import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// N^2 정렬을 삽입 정렬로 학습하자
public class Doit_017 {

    private static int[] intArr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strNumber = new String(br.readLine());

        generateArr(strNumber);

        Doit_017 insertSortPrinter = new Doit_017();

        insertSortPrinter.sortinsert();
        insertSortPrinter.printResult();
    }

    private void printResult() {
        for (int idx = 0; idx < intArr.length; idx++) {
            System.out.print(intArr[idx]);
        }
    }

    private void sortinsert() {
        int max;
        for (int idx = 0; idx < intArr.length - 1; idx++) {
            max = idx;
            for (int jdx = idx + 1; jdx < intArr.length; jdx++) {
                if (intArr[max] < intArr[jdx])
                    max = jdx;
            }
            if (intArr[max] > intArr[idx]) {
                int tmp = intArr[idx];
                intArr[idx] = intArr[max];
                intArr[max] = tmp;
            }
        }
    }

    private static void generateArr(String strNumber) {
        intArr = new int[strNumber.length()];
        for (int idx = 0; idx < strNumber.length(); idx++) {
            intArr[idx] = Integer.parseInt(strNumber.substring(idx, idx+1));
        }
    }
}