
package main
import "fmt"

func main(){
    var a int
    var p int = 0
    var o int = 0
    var py int
    var d int
    var s int
    fmt.Scan(&a)
    if a >= 5000 {
        for p = 0; a >= 5000; {
            a = a - 5000
            p++
            
        }
        
    }
    if a >= 1000 {
        for o = 0; a >= 1000; {
            a = a - 1000
            o++
            
        }
        
    }
    if a >= 500 {
        for py = 0; a >= 500 ; {
            a = a - 500
            py++
            
        }
        
    }
    if a >= 200 {
        for d = 0; a >= 200; {
            a = a - 200
            d++
            
        }
        
    }
    if a >= 100 {
        for s = 0; a >= 100; {
            a = a - 100
            s++
            
        }
        
    }
    
    
    
    
    fmt.Println(p, o, py, d, s)
    
    
    
    
    
}

