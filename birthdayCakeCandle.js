function birthdayCakeCandles(candles) {
    // Write your code here
    let maximum = -Infinity
    let index=0;
    count = {}
    for(const num of candles){
       if(!(num in count)) count[num]=0;
       count[num]++
    }
    for(const [key, value] of Object.entries(count)){
        if(key>maximum){
            maximum=key;
            index = value;
        }
    }
    return index
}
console.log(birthdayCakeCandles([3,2,1,3]))