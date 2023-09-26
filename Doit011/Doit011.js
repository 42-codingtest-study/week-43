//문제: Doit011
//0. 문제 이해 : 1부터 순서대로 스택에 넣는다. 입력 숫자를 뽑을려면 push 를 해야할지 pop을 해야할지를 +,-로 표시하자 , 걍 안되는 입력값이면 no출력
//1. 시간 복잡도 확인: 2초 -> 2억 연산 n < 100,000 연산횟수는 부족함 없다.
//2. 적용 알고리즘 확인: 스택과 구현
//3. 맞는 자료구조 확인: 배열로 stack
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    let n = +input.shift();
    const stack = [];
    //로직 구현 -> 어디까지 입력했는지 확인할 check를 가진상태로 입력값과 stack의 탑을 계속 비교한다.
    // 1. 입력값이 stack의 탑보다 큰 경우 -> check+1~입력값까지 stack에 넣고 pop한번
    // 2. 입력값 == stack의 탑 -> pop
    // 3. 입력값 < stack의 탑 -> No 출력
    let answer = "";
    let check = 1;
    for (let i = 0; i < n; i++) {
        while (check <= +input[i]) {
            stack.push(check);
            check++;
            answer += "+\n";
        }
        if (stack[stack.length - 1] === +input[i]) {
            stack.pop();
            answer += "-\n";
        } else {
            answer = "NO";
            break;
        }
    }

    console.log(answer.trim());
}
