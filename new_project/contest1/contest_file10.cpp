
package main
import "fmt"

func main(){
    var a string
    var b string
    var c string
//    var d 
    fmt.Scan(&a, &b, &c)
    if a == "Да" {
        if b == "Да" {
            if c == "Да" {
               fmt.Println("Утка") 
            }
        }
    }
    if a == "Да" {
        if b == "Да" {
            if c == "Нет" {
               fmt.Println("Пингвин") 
            }
        }
    }
    if a == "Нет" {
        if b == "Нет" {
            if c == "Нет" {
               fmt.Println("Кот")   
            }
        }
    }
    if a == "Нет" {
        if b == "Нет" {
            if c == "Да" {
               fmt.Println("Жираф") 
            }
        }
    }
    if a == "Нет" {
        if b == "Да" {
            if c == "Нет" {
               fmt.Println("Курица") 
            }
        }
    }
    if a == "Нет" {
        if b == "Да" {
            if c == "Да" {
               fmt.Println("Страус") 
            }
        }
    }
    if a == "Да" {
        if b == "Нет" {
            if c == "Нет" {
               fmt.Println("Дельфин") 
            }
        }
    }
    if a == "Да" {
        if b == "Нет" {
            if c == "Да" {
               fmt.Println("Плезиозавры") 
            }
        }
    }
}
