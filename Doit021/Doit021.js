//문제: Doit021
//0. 문제 이해 : 버블 소트에서 swap한 횟수 구하기
// 근데 문제는 시간 복잡도가 터짐 그럼 어캄? swap이 의미하는걸 찾아야지 뭐
// swap을 한다는건 자기보다 앞의 위치한 수들 중 큰 수를 찾으면 되는거임 ㅇㅈ? ㅇㅈ
// 그러면 자기 보다 큰 수가 앞에 있는걸 어케 아는데
// 1. 세크먼트 트리를 쓰면 된대 -> 그게 뭔데 -> 모름
// 2. 병합 정렬을 하는 과정에서 자기보다 큰 수를 확인할 수 있자나?!!! -> 그러면 병합정렬 할때 divide 하고 merge 할때 자기보다 큰 수 있을 때마다 cnt에 추가해주면 되네? 대박
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const n = +input.shift();
    const arr = input[0].split(" ").map(Number);
    let sorted = Array(n);
    let answer = 0n;

    const merge = (low, high) => {
        if (low === high) return;
        let mid = Math.floor((low + high) / 2);
        merge(low, mid);
        merge(mid + 1, high);
        // 병합
        let i = low;
        let j = mid + 1;
        for (let k = low; k <= high; k++) {
            // j>high 면 이미 정렬된 상태로 순서대로 삽입
            // arri<arrj 면 순서대로 삽입
            if (j > high || (i <= mid && arr[i] <= arr[j])) {
                sorted[k] = arr[i++];
            } else {
                // swap
                sorted[k] = arr[j++];
                // arrj 뒤로 이동
                answer += BigInt(mid - i + 1);
            }
        }
        // 정렬 반영
        for (let k = low; k <= high; k++) {
            arr[k] = sorted[k];
        }
    };

    merge(0, n - 1);
    // console.log(sorted.join("\n"));
    console.log(answer.toString());
}
