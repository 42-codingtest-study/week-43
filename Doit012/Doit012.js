//문제: Doit012
//0. 문제 이해 : 배열 내 숫자 당 오른쪽에 있는 자기 보다 큰 수들 중에 가장 왼쪽에 있는 수 찾기
//1. 시간 복잡도 확인: 1초 -> 1억연산, 100만 개면 n^2 시 1억 넘는다.
//2. 적용 알고리즘 확인: stack을 사용한 구현
//3. 맞는 자료구조 확인: 배열 쓴 stack
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    let n = +input.shift();
    const arr = input[0].split(" ").map(Number);
    // 구현 원리 -> stack이 비어있거나 맨 위의 값보다 입력값이 작다면 stack에 인덱스 추가
    // stack 탑 보다 입력값이 크다면 정답 배열에 stack.pop에 해당하는 인덱스에 입력값으로 저장 후 stack에 인덱스 추가
    const idx_stack = []; // 인덱스 저장 stack
    const result_arr = Array.from({ length: n }, () => -1);
    arr.forEach((e, idx) => {
        if (!idx_stack.length || arr[idx_stack[idx_stack.length - 1]] >= e)
            idx_stack.push(idx);
        else {
            while (arr[idx_stack[idx_stack.length - 1]] < e)
                result_arr[idx_stack.pop()] = e;
            idx_stack.push(idx);
        }
    });
    console.log(result_arr.join(" "));
}
