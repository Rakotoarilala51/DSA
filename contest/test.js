function countVowels(s){
    const matches = s.match(/[aeiou]/gi);
    return matches?matches.length:0;
}
function reverse(s){
    return s.split('').reverse().join('')
}
var reverseCountWords = function(s){
    const words = s.split(" ");
    for(let i=1;i<words.length; i++){
        if(countVowels(words[0])===countVowels(words[i])) words[i]=reverse(words[i]);
    }
    return words.join(' ');
}

console.log(reverseCountWords("I am a legend man"));