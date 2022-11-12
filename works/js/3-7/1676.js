let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

let N = parseInt(input[0])
let five = 0, two = 0 

for(i = 2; i <= N; i++) {
    Cal(i) 
}

console.log(Math.min(two, five))

function Cal(num) {
    while(num > 0) {
        if(num % 5 == 0) {
            five++ 
            num = Math.floor(num / 5)
        }   
        else if(num % 2 == 0) {
            two++ 
            num = Math.floor(num / 2) 
        }
        else {
            break 
        }
    }
}



