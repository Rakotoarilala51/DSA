var isAnagram = function(s, t) {
    if(s.length!=t.length) return false
    let frequency = Array(26).fill(0)
    for(let i=0; i<s.length; i++){
        frequency[s[i].charCodeAt()-97]++
        frequency[t[i].charCodeAt()-97]--
    }
    for(let i=0; i<26; i++){
        if(frequency[i]!=0) return false;
    }
    return true;
};
console.log(isAnagram("ann", "nan"))