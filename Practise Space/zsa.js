// input an array, and return its sum

function sumarr(arr){
    var sum = 0;
    for (var i = 0; i<arr.length; i++){
        sum += arr[i];
    }
    console.log(sum);
}
function main(){
    let n ;
    let arr = [];
    let sum = 0;
    let i = 0;
    const readline = require('readline-sync');
    n = readline.question();
    for (i = 0; i < n; i++){
        arr[i] = parseInt(readline.question());
    }
    sumarr(arr);
}

main();
