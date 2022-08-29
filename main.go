package main

import "C"
import (
	"bytes"
	"flag"
	"fmt"
	"os"
	"path"
	"path/filepath"

	compiler "github.com/richinsley/goflav/compiler"
	pp "github.com/richinsley/goflav/parser"
	preproc "github.com/richinsley/goflav/preprocess"
)

func compile_cpp(sourcefile string, targetpath string) {
	// preprocess the file
	var includes []string

	// create include paths list starting with cwd
	cwd, _ := os.Getwd()
	var includepaths []string
	includepaths = append(includepaths, cwd)
	sourcefile, _ = preproc.GetAbsPath(sourcefile, "", &includepaths)
	lines, _ := preproc.Preprocess(sourcefile, sourcefile, "", &includes, &includepaths)

	// compact lines to []byte
	var ba []byte
	for _, l := range *lines {
		ba = append(ba, l...)
		ba = append(ba, '\n')
	}

	// create io.reader for ba
	r := bytes.NewReader(ba)

	p := pp.ParseReader(r, sourcefile)

	c := compiler.NewCompilerContext(p)
	c.Program = "goflavor"
	c.Filename = sourcefile
	filebase := path.Base(sourcefile)
	var extension = filepath.Ext(filebase)
	var base = filebase[0 : len(filebase)-len(extension)]

	c.OutputFileNames["source"] = path.Join(targetpath, base+".cpp")
	c.OutputFileNames["header"] = path.Join(targetpath, base+".hpp")
	c.OutputFiles["source"], _ = os.Create(c.OutputFileNames["source"])
	c.OutputFiles["header"], _ = os.Create(c.OutputFileNames["header"])

	c.Compile()

	c.OutputFiles["source"].(*os.File).Close()
	c.OutputFiles["header"].(*os.File).Close()

	pp.Cleanup()
}

func main() {
	var compFile string
	var outputPath string
	flag.StringVar(&compFile, "c", "", "input file")
	flag.StringVar(&outputPath, "o", "", "output path")
	flag.Parse()

	if compFile == "" {
		fmt.Printf("No input file file given")
		os.Exit(1)
	}

	if outputPath == "" {
		outputPath, _ = os.Getwd()
	}

	compile_cpp(compFile, outputPath)
}
