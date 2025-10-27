function miniMaxSum(arr) {
    // Write your code here
    arr.sort((a,b)=>a-b)
    console.log(arr)
    let sum = arr.reduce((a,b)=> a+b, 0)
    console.log(sum-arr.at(-1)," ",sum-arr[0])
}
function miniMaxSum(arr) {
    // Write your code here
    let min = Infinity
    let max = -Infinity
    let sum = 0
    for(let num of arr){
        if(num>max) max=num
        if(num<min) min=num 
        sum+=num
    }
    console.log(sum-max, ' ', sum-min)
}
miniMaxSum([7,69,2,221,8974])