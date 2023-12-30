
package main

import (
"fmt"
"strings"
)

func main() {
var num int
var word string
var line []string
fmt.Scan(&num)
for i := 0; i < num; i++ {
fmt.Scan(&word)
if contains(line, word) {
line = remove(line, word)

} else {
line = append(line, word)

}
}
fmt.Println(strings.Join(line, " "))
}
func contains(line []string, word string) bool {
for _, w := range line {
if w == word {
return true
}
}
return false
}
func remove(line []string, word string) []string {
newline := []string{}
for _, w := range line {
if w != word {
newline = append(newline, w)
}
}
return newline

}

