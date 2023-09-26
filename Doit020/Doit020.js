//문제: Doit020
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const n = input.shift();
    const arr = input.map(Number);
    let sorted = Array(n);

    const merge = (low, high) => {
        if (low === high) return;
        let mid = Math.floor((low + high) / 2);
        merge(low, mid);
        merge(mid + 1, high);
        // 병합
        let i = low;
        let j = mid + 1;
        for (let k = low; k <= high; k++) {
            // j>high 면 이미 정렬된 상태로 순서대로 삽입
            // arri<arrj 면 순서대로 삽입
            if (j > high || (i <= mid && arr[i] <= arr[j])) {
                sorted[k] = arr[i++];
            } else {
                // swap
                sorted[k] = arr[j++];
                // arrj 뒤로 이동
            }
        }
        // 정렬 반영
        for (let k = low; k <= high; k++) {
            arr[k] = sorted[k];
        }
    };

    merge(0, n - 1);
    console.log(sorted.join("\n"));
}
