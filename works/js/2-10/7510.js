let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var N = parseInt(input[0]) 
for(t = 1; t <= N; t++) {
    var arr = input[t].split(' ').map(Number)  
    arr.sort((a,b) => (a-b)) 
    
    console.log(`Scenario #${t}:`)
    if((arr[0]*arr[0]) + (arr[1]*arr[1]) == (arr[2]*arr[2])) {        
        console.log('yes\n')
    }
    else {
        console.log('no\n')
    }
}