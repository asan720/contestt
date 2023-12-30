
package main 

import "fmt"

func main () {
    var column int
    var line int
    var relult int
    fmt.Scan(&column, &line)
    fmt.Print("    |")
    for i := 1; i <= line; i++{
        fmt.Printf("%4d", i)
        
    }
    fmt.Println()
    fmt.Print("   --")
    for i := 1; i <= line; i++{
        fmt.Print("----")
        
    }
    fmt.Println()
    
        for  i:= 1; i <= column; i++ {
            fmt.Printf("%4d", i)
        fmt.Print("|")
            for j := 1; j <= line; j++{
                relult = i*j
                fmt.Printf("%4d", relult)
            }
        fmt.Println()
        }
    }    



