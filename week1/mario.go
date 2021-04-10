package main

import (
	"fmt"
	"strconv"
	"strings"
)

//take users height input
func get_user_input() int {
	for {
		fmt.Print("Enter desired height: ")
		var input string
		fmt.Scanln(&input)

		//simple error handling
		height, err := strconv.Atoi(input)
		if err != nil {
			fmt.Println("Error encountered while getting user input.\n%v\n", err)
			return 1
		}

		//input constraints
		if height < 0 || height > 100 {
			fmt.Println("Height has to be between 0 and 100\n")
		} else {
			return height
		}
	}
}

func main() {
	//get height from the user
	height := get_user_input()

	//print the shape line by line
	for i := 0; i <= height; i++ {
		spaces := strings.Repeat(" ", height-i)
		blocks := strings.Repeat("#", i)
		fmt.Println(spaces + blocks)
	}
}
