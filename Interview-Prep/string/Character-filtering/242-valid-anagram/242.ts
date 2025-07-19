function iAnagram(s: string, t: string): boolean {
    let count:Map<string, number>= new Map();
    for(const c of s){
        count[c] = (count[c] || 0)+1
    }
    for(const c of t){
        if(!(c in count)) return false;
        count[c]--;
        if(count[c]==0) count.delete(c);
    }
    return count.size==0;
};
iAnagram("ann", "nan")