//문제: Doit022
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:  계수 정렬로 풀어보자!
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    let n = +input.shift();
    let answer = "";
    const arr = Array.from({ length: 10001 }, () => 0);
    input.forEach((e) => {
        arr[+e] += 1;
    });
    console.log(arr);
    arr.forEach((e, idx) => {
        if (e) {
            for (let i = 0; i < e; i++) {
                answer += `${idx}\n`;
            }
        }
    });
    console.log(answer.trim());
}
