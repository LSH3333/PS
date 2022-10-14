let fs = require('fs');
// let input = fs.readFileSaync(0).toString().trim().split('\n');
var input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var money1 = [0, 5000000, 3000000, 2000000, 500000, 300000, 100000, 0]
var count1 = [0, 1, 3, 6, 10, 15, 21, 100]
var money2 = [0, 5120000, 2560000, 1280000, 640000, 320000, 0]
var count2 = [0, 1, 3, 7, 15, 31, 64]

var T = parseInt(input[0]) 
for(t = 1; t <= T; t++) {
    var [a, b] = input[t].split(' ').map(Number) 
    var sum = 0 
    
    for(i = 0; i < count1.length; i++) {
        if(count1[i] >= a) {
            sum += money1[i] 
            break
        }
    }
    for(i = 0; i < count2.length; i++) {
        if(count2[i] >= b) {
            sum += money2[i]
            break
        }
    }
    console.log(sum)
}