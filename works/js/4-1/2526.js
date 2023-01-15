let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n')
// let input = fs.readFileSync('input.txt').toString().split('\n')

let [a,b] = input[0].split(' ').map(Number) 
let m = new Map() 
let num = a, cnt = 1

while(true) {
    if(m.has(num)) {
        console.log(m.size - (m.get(num) - 1))
        break 
    }
    m.set(num, cnt++)
    num = num * a % b 
}
