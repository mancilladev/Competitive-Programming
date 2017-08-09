package main

import "fmt"
import "strconv"

func isPalindrome(n int) bool {
    s := strconv.Itoa(n)
    for i := 0; i < len(s) / 2; i++ {
        if s[i] != s[len(s)-i-1] {
            return false
        }
    }
    return true
}

func main() {
    ans := 1
    for a := 100; a < 1000; a++ {
        for b := a + 1; b < 1000; b++ {
            if isPalindrome(a*b) && a * b > ans {
                ans = a * b
            }
        }
    }
    fmt.Println(ans)
}
