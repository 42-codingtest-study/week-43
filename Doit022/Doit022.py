def solution(input):
    n = int(input[0])
    answer = ""
    arr = [0] * 10001
    
    for e in input[1:]:
        arr[int(e)] += 1

    for idx, e in enumerate(arr):
        if e:
            for i in range(e):
                answer += f"{idx}\n"

    print(answer.strip())