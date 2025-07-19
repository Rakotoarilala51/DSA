package main

import "fmt"

func isAnagram(s string, t string) bool {
	if len(s)!= len(t){
		return false;
	}
    frequency := make([]int, 26)
	for i:=0; i<len(s); i++{
		frequency[s[i]-97]++;
		frequency[t[i]-97]--;
	}
	for i:=0; i<26; i++{
		if frequency[i]!=0{
			return false;
		}
	}
	return true;

}
func main(){
	fmt.Println(isAnagram("aina", "ania"));
}