let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var a = input[0].split(' ').map(Number) 
var asc = true, desc = true 
for(i = 1; i <= 8; i++) {
    if(a[i-1] != i) {
        asc = false 
    }
    if(a[i-1] != 9-i) {
        desc = false 
    }
}

if(asc) {
    console.log("ascending")
}
else if(desc) {
    console.log("descending")
}
else {
    console.log("mixed")
}
