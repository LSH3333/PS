let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n')

var N = parseInt(input[0])

for(i = N; i > 0; i--) {
    var str = i.toString() 
    var check = true 
    for(j = 0; j < str.length; j++) {
        if(str[j] != '4' && str[j] != '7') {
            check = false 
            break;
        }
    }

    if(check) {
        console.log(i)
        break 
    }
}

