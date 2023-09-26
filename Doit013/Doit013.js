//문제: Doit013
//0. 문제 이해 : 1~N 카드 (1이 맨위) 중 제일 맨 위 버리고 다음 맨 위 아래로 내리기 -> 마지막 남는 카드는?
//1. 시간 복잡도 확인: 2초 -> 2억 연산 n->50만 n^2은 안된다 nlogn 까지 ok
//2. 적용 알고리즘 확인: 오기 생겨서 수학적 규칙 찾아보려다가 포기, 덱을 통한 추가 삭제 반복
//3. 맞는 자료구조 확인: 연결리스트를 이용한 queue
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

class Queue {
    constructor() {
        this.arr = [];
        this.head = 0;
        this.tail = 0;
    }

    push_back(item) {
        this.arr[this.tail++] = item;
    }
    pop_front() {
        if (this.head >= this.tail) {
            return null;
        } else {
            const result = this.arr[this.head++];
            return result;
        }
    }

    isEmpty() {
        return this.head >= this.tail;
    }
}

// let start = new Date();
solution(input);
// let end = new Date();
// console.log(end - start);
// js 시간 복잡 확인 방법 ㅋ
function solution(input) {
    let n = +input[0];
    const queue = new Queue();
    for (let i = 1; i <= n; i++) {
        queue.push_back(i);
    }
    while (queue.tail - queue.head !== 1) {
        queue.pop_front();
        queue.push_back(queue.pop_front());
    }
    console.log(queue.arr[queue.head]);
}
