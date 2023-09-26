//문제: Doit015
//0. 문제 이해 : 오름차순 정렬
//1. 시간 복잡도 확인: 1초 -> 1억 연산 제한 1000개 -> O(N^2) -> 100만
//2. 적용 알고리즘 확인: 버블정렬을 써보자!
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    let n = input.shift();
    const arr = input.map(Number);
    const swap = (arr, j) => {
        let tmp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;
    };
    for (let i = n - 1; i >= 0; i--) {
        for (let j = n - 1; j; j--) {
            if (arr[j] < arr[j - 1]) swap(arr, j);
        }
    }
    console.log(arr.join("\n"));
}
