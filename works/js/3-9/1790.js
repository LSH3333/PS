let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let [n,k] = input[0].split(' ').map(Number) 

if(getlength(n) < k) {
    console.log(-1) 
}
else {
    let l = 0, m = 0, s = 0, e = 0 
    let cc = 0
    do {
        l++
        m = (m == 0) ? 1 : m * 10
        s = e
        e += 9 * m * l
    } while(k > e) 

    let number = m + Math.floor((k - s) / l) 
    let index = (k - s) % l 
    
    if(index == 0) {
        number -= 1
        index = l 
    }

    let res = 0
    do {
        res = Math.floor(number / m)
        number -= res * m 
        m = Math.floor(m / 10 )
    } while(--index)

    console.log(res) 
}

function len(n) {
    let res = 0 
    while(n) { 
        res++; 
        n = Math.floor(n / 10)
    }
    return res 
}

function getlength(n) {
    let length = len(n) 
    let i = 0, m = 1, res = 0
    for(i = 1; i < length; i++) {
        res += 9 * m * i 
        m *= 10 
    }
    res += (n - m + 1) * i 
    return res 
}