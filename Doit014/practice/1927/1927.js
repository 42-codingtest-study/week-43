//문제: 1927
//0. 문제 이해 : 우선순위 큐를 이해하기 위한 연습문제, 최소 힙

// 우선순위 큐란?
// 자료구조중 queue는 first in 을 out 하고 stack은 last in 을 out 한다.
// 하지만 우선순위 큐는 특정 조건(우선순위)을 가진 놈을 out 한다.
// 이를 위해 나온 자료구조가 heap
// heap이란?
// 완전 이진트리에 일종으로 우선순위 큐를 위해만들어진 알고리즘
// 여러개의 값들중 최댓값이나 최솟값 (우선순위)를 빨리 찾기 위해 만들어짐
// 반정렬상태 (느슨한 정렬)을 유지한다.
// -> 큰값이 상위에 있고 작은값이 하위에 있다 정도
// 힙트리는 중복값을 허용한다.

// 힙에서의 부모노드 자식노드의 관계
// 왼쪽 자식노드 index = 부모 index * 2
// 오른쪽 자식노드 index = 부모 index * 2 + 1
// 부모노드 index = 자식 index / 2

// 부모 자식의 크기 연산을 통해 while(swap(부모, 자식))을 진행한다.
// 시간 복잡도 -> 삽입,삭제 : O(logN) 개꿀인데?

//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:

class MinHeap {
    constructor() {
        this.heap = [null];
    }
    heap_push(value) {
        // 아래에서 위로
        this.heap.push(value);
        let currentIndex = this.heap.length - 1;
        let parentIndex = Math.floor(currentIndex / 2);
        while (parentIndex !== 0 && this.heap[parentIndex] > value) {
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
            this.heap[currentIndex] > this.heap[leftIndex] ||
            this.heap[currentIndex] > this.heap[rightIndex]
        ) {
            const temp = this.heap[currentIndex];
            if (this.heap[leftIndex] > this.heap[rightIndex]) {
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

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const minHeap = new MinHeap();
    let n = input.shift();
    let answer = "";
    input.forEach((e) => {
        if (e === "0") {
            if (minHeap.heap.length === 1) {
                answer += "0\n";
            } else {
                answer += minHeap.heap_pop() ?? 0;
                answer += "\n";
            }
        } else {
            minHeap.heap_push(+e);
        }
    });
    console.log(answer.trim());
}
