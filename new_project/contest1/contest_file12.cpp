
package main
import "fmt"

func main(){
    var a int
    var b int
    fmt.Scan(&a)
    for a != 1 {
        if a % 2 != 0 {
            a = a * 3 + 1
            b++
            
        }else{
            a = a / 2
            b++
        }
        
    }
    fmt.Println(b)
    
    
}
