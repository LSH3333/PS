const { BADFLAGS } = require('dns');
let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

const MAX = 10000

let bridge = new Array(MAX+1).fill(0).map(() => new Array())
let [N, M] = input[0].split(' ').map(Number) 
let left = 0, right = 0 

for(i = 1; i <= M; i++) {
    let [a,b,c] = input[i].split(' ').map(Number) 
    bridge[a].push([b,c])
    bridge[b].push([a,c])
    right = Math.max(right, c)
}

let [fac1, fac2] = input[M+1].split(' ').map(Number)

let ans = Math.floor((left + right) / 2) 
while(left <= right) {
    let mark = new Array(N+1).fill(false) 

    let mid = Math.floor((left + right) / 2) 

    // mid 중량 가능 
    if(bfs(mid, mark)) {
        ans = mid 
        left = mid + 1 
    }
    else {
        right = mid - 1
    }
}

console.log(ans) 



function bfs(mid, mark) {
    // queue 는 그냥 array.shift 로 대체 
    let q = [] 
    q.push(fac1) 
    mark[fac1] = true 
    
    while(q.length > 0) {
        let node = q[0] 
        q.shift() 

        if(node == fac2) return true

        bridge[node].map((x) => {
            let next_node = x[0] 
            let next_w = x[1] 

            if(!mark[next_node] && next_w >= mid) {
                mark[next_node] = true
                q.push(next_node)
            }    
        })
    }

    return false    
}