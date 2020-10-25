package main

import (
	"bufio"
	"log"
	"os"
)

const debug = false

var in = bufio.NewReader(os.Stdin)

func init() {
	if debug {
		log.SetFlags(log.LstdFlags | log.Lshortfile)
	}
}

func main() {
}
