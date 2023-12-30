
package main
import "fmt"

func main(){
    var a int = 0
    var b int = 0
    var c int = 0
    var d int = 0
    fmt.Scan(&a, &b, &c)
    d = a
    if d < b {
        d = b
    }
    if d < c {
        d = c
    }
    fmt.Println(d)
}
