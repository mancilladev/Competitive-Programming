package main

import "fmt"

func main() {
    largest := 1
    n := 600851475143
    for i := 2; i <= n; {
        if n % i == 0 {
            largest = i
            n /= i
        } else {
            i++
        }
    }
    fmt.Println(largest)
}
