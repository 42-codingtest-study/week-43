//문제: Doit018
//0. 문제 이해 : 정렬 후 누적합
//1. 시간 복잡도 확인: 1초 ->1억연산 n:1000 세제곱은 안된다~ 이말이야
//2. 적용 알고리즘 확인: 정렬 (근데 삽입정렬 써보자)
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
solution(input);
function solution(input) {
    let n = +input[0];
    const arr = input[1].split(" ").map(Number);
    //삽입정렬 써보자
    for (let i = 1; i < n; i++) {
        let distance = 0;
        for (let j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) distance++;
        }
        let tmp = arr.splice(i, 1);
        arr.splice(i - distance, 0, tmp[0]);
    }
    sum_arr = [arr[0]];
    for (let i = 0; i < n - 1; i++) {
        sum_arr.push(sum_arr[i] + arr[i + 1]);
    }
    let l = sum_arr.reduce((acc, cur) => acc + cur, 0);
    console.log(l);
}
