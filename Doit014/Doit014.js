//문제: Doit014
//0. 문제 이해 : 프라라라라라라라ㅏ라랄라라ㅏ라라ㅏㅏㅏㅏ
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

class AbsMinHeap {
    constructor() {
        this.heap = [null];
    }
    compare(a, b) {
        if (Math.abs(a) !== Math.abs(b)) return Math.abs(a) > Math.abs(b);
        return a > b;
    } // 이게 핵심 이거빼고 나머지 최소힙이랑 같음 꼬우면 설명해드릴게요 어쩌라고요
    heap_push(value) {
        // 아래에서 위로
        this.heap.push(value);
        let currentIndex = this.heap.length - 1;
        let parentIndex = Math.floor(currentIndex / 2);
        while (
            parentIndex !== 0 &&
            this.compare(this.heap[parentIndex], value)
        ) {
            const temp = this.heap[parentIndex];
            this.heap[parentIndex] = this.heap[currentIndex];
            this.heap[currentIndex] = temp;
            currentIndex = parentIndex;
            parentIndex = Math.floor(currentIndex / 2);
        }
    }
    heap_pop() {
        if (this.heap.length === 2) return this.heap.pop(); // 루트 정점만 남은 경우
        // 위에서 아래로
        let returnValue = this.heap[1];
        this.heap[1] = this.heap.pop();
        let currentIndex = 1;
        let leftIndex = 2;
        let rightIndex = 3;
        while (
            this.compare(this.heap[currentIndex], this.heap[leftIndex]) ||
            this.compare(this.heap[currentIndex], this.heap[rightIndex])
        ) {
            const temp = this.heap[currentIndex];
            if (this.compare(this.heap[leftIndex], this.heap[rightIndex])) {
                this.heap[currentIndex] = this.heap[rightIndex];
                this.heap[rightIndex] = temp;
                currentIndex = rightIndex;
            } else {
                this.heap[currentIndex] = this.heap[leftIndex];
                this.heap[leftIndex] = temp;
                currentIndex = leftIndex;
            }
            leftIndex = currentIndex * 2;
            rightIndex = leftIndex + 1;
        }
        return returnValue;
    }
    heap_return() {
        return this.heap;
    }
}

solution(input);
function solution(input) {
    const absMinHeap = new AbsMinHeap();
    let n = input.shift();
    let answer = "";
    input.forEach((e) => {
        if (e === "0") {
            if (absMinHeap.heap.length === 1) {
                answer += "0\n";
            } else {
                answer += absMinHeap.heap_pop() ?? 0;
                answer += "\n";
            }
        } else {
            absMinHeap.heap_push(+e);
        }
    });
    console.log(answer.trim());
}
