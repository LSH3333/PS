let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let answer = 0 
let [N, C] = input[0].split(' ').map(Number) 
let v = new Array() 
for(i = 1; i <= N; i++) {
    v.push(parseInt(input[i]))
}

// sort 는 기본적으로 알파벳 순 정렬됨 (원소가 정수여도 스트링으로 변환 후 정렬함 )
v.sort((a,b) => a-b) 

let left = 1, right = v[N-1] - v[0] 
while(left <= right) {
    let mid = Math.floor((left + right) / 2) 
    let cnt = 1 
    let start = v[0] 

    for(i = 1; i < N; i++) {
        if(mid <= v[i] - start) {
            cnt++ 
            start = v[i] 
        }
    }

    if(cnt >= C) {
        left = mid + 1 
        answer = mid 
    }
    else {
        right = mid - 1
    }
}

console.log(answer)