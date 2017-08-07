package main

import "fmt"

func fibonacci() func() int {
    a, b := 1, 1
    return func() int {
        a, b = b, a + b
        return a
    }
}

func main() {
    sum := 0
    f := fibonacci()
    n := f()

    for n < 4000000{
        if n % 2 == 0 {
            sum += n
        }
        n = f()
    }

    fmt.Println(sum)
}
