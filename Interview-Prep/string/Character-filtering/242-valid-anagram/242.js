var isAnagram = function(s, t) {
   let count = {}
   for(let c of s){
    count[c]=(count[c] || 0)+1
   }
   for(let c of t){
    if(!(c in count)) return false;
    count[c]--;
    if(count[c]==0){
        delete(count[c])
    }
   }
   return count.size()==0

};
console.log(isAnagram())