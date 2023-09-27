//문제: Doit016
//0. 문제 이해 : 버블 정렬에서 swap이 일어나지 않은 첫 for 문의 횟수
//1. 시간 복잡도 확인: 2초->2억연산 n = 500,000 O(N^2)-> 시간초과 즉 버블정렬을 쓸 수 없다?!
//2. 적용 알고리즘 확인: 버블 정렬을 하지 않고 swap이 일어나지 않은 횟수를 구하려면 ... 다른 방법 생각해봤는데 생각안남 -> 인덱스 차이가 가장 큰 부분 + 1이 swap
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    let n = input.shift();
    const arr = [];
    input.forEach((e, idx) => {
        arr.push([+e, idx]);
    });
    arr.sort((a, b) => a[0] - b[0]);
    arr.map((e, idx) => {
        e[1] -= idx;
    });
    arr.sort((a, b) => b[1] - a[1]);
    console.log(arr[0][1] + 1);
}
