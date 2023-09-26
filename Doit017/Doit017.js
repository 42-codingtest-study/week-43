//문제: Doit017
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);

function solution(input) {
    const arr = input[0].split("").map(Number);
    const min_idx = (arr) => {
        let tmp = 10;
        let idx = -1;
        for (let i = 0; i < arr.length; i++) {
            if (arr[i] < tmp) {
                tmp = arr[i];
                idx = i;
            }
        }
        return idx;
    };
    const swap = (arr, min_idx, idx) => {
        let tmp = arr[min_idx];
        arr[min_idx] = arr[idx];
        arr[idx] = tmp;
    };

    for (let i = input[0].length; i > 1; i--) {
        swap(arr, min_idx(arr.slice(0, i)), i - 1);
    }
    console.log(arr.join(""));
}
