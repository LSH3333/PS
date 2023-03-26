let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let [N,M] = input[0].split(' ').map(Number) 
let v = input[1].split(' ').map(Number) 

let left = 0, right = 0, sum = 0, cnt = 0
while(right <= v.length) {
    if(sum < M) {
        sum += v[right] 
        right++ 
    }
    else if(sum > M) {
        sum -= v[left]
        left++ 
    }
    else if(sum == M) {
        cnt++ 
        sum += v[right];
        right++ 
    }
}

console.log(cnt)
