//문제: Doit019
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [n, k] = input[0].split(" ").map(Number);
    const arr = input[1].split(" ").map(Number);

    const quick = (low, high) => {
        if (low >= high) return;
        const pivot = arr[Math.floor((low + high) / 2)];
        const partition = suntaek(low, high, pivot);
        quick(low, partition - 1);
        quick(partition, high);

        return arr[k - 1];
    };
    const swap = (arr, a, b) => {
        let tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    };
    const suntaek = (low, high, pivot) => {
        while (low <= high) {
            while (arr[low] < pivot) low++;
            while (arr[high] > pivot) high--;
            if (low <= high) {
                swap(arr, low, high);
                low++;
                high--;
            }
        }
        return low;
    };

    console.log(quick(0, n - 1));
}
