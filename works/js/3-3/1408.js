let fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n');
// let input = fs.readFileSync('input.txt').toString().split('\n');

var begin = input[0].split(':').map(Number) 
var end = input[1].split(':').map(Number) 
if(begin[0] == 0 && begin[1] == 0 && begin[2] == 0)
    begin[0] = 24 
if(end[0] == 0 && end[1] == 0 && end[2] == 0) 
    end[0] = 24

var beginSec = (begin[0]*60*60) + (begin[1]*60) + begin[2] 
var endSec = (end[0]*60*60) + (end[1]*60) + end[2] 
var ansSec 
if(beginSec > endSec)  {
    ansSec = (3600 * 24) - (beginSec - endSec) 
}
else {
    ansSec = endSec - beginSec 
}

if(ansSec < 0) ansSec *= -1 
var ansH, ansM, ansS 
ansH = Math.floor(ansSec / 3600) 
ansSec -= (ansH * 3600) 
ansM = Math.floor(ansSec / 60) 
ansSec -= (ansM * 60)
ansS = ansSec 

var h = ansH.toString(), m = ansM.toString(), s = ansS.toString()  
if(ansH < 10) h = '0' + ansH.toString() 
if(ansM < 10) m = '0' + ansM.toString() 
if(ansS < 10) s = '0' + ansS.toString()     
console.log(`${h}:${m}:${s}`)
