package main

import (
	"fmt"
	"strings"
)

//map letters to scrabble points
var PM = make(map[rune]int)

func main() {
	//set up the map for scoring letters
	PM['A'] = 1
	PM['B'] = 3
	PM['C'] = 3
	PM['D'] = 2
	PM['E'] = 1
	PM['F'] = 4
	PM['G'] = 2
	PM['H'] = 4
	PM['I'] = 1
	PM['J'] = 8
	PM['K'] = 5
	PM['L'] = 1
	PM['M'] = 3
	PM['N'] = 1
	PM['O'] = 1
	PM['P'] = 3
	PM['Q'] = 10
	PM['R'] = 1
	PM['S'] = 1
	PM['T'] = 1
	PM['U'] = 1
	PM['V'] = 4
	PM['W'] = 4
	PM['X'] = 8
	PM['Y'] = 4
	PM['Z'] = 10

	//prompt players for input
	fmt.Printf("Player 1: ")
	word1 := get_user_input()
	fmt.Printf("Player 2: ")
	word2 := get_user_input()
	fmt.Println("")

	//compute the winner
	score1 := compute_score(word1)
	score2 := compute_score(word2)

	//print out who wins
	if score1 > score2 {
		fmt.Println("Player 1 wins!")
	} else if score1 < score2 {
		fmt.Println("Player 2 wins!")
	} else {
		fmt.Println("Tie!")
	}
}

func get_user_input() string {
	var input string
	fmt.Scanln(&input)

	return input
}

func compute_score(word string) int {
	//clean the data so it's shiny
	upperWord := strings.ToUpper(word)
	wordSlice := []rune(upperWord)

	//compute the score
	score := 0
	for _, b := range wordSlice {
		score += PM[b]
		fmt.Printf("%c(%d)", b, PM[b])
	}
	//return the score
	fmt.Printf("= %d\n", score)
	return score
}
