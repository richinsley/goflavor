package preprocess

import (
	"bufio"

	"os"
	"path/filepath"
	"strings"
)

func hasstring(s string, l []string) bool {
	for _, v := range l {
		if s == v {
			return true
		}
	}
	return false
}

// loadfile reads a whole file into memory
// and returns a slice of its lines.
func loadfile(path string) ([]string, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	var lines []string
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	return lines, scanner.Err()
}

func GetAbsPath(infile string, previous string, includepaths *[]string) (string, error) {
	// is it an absolute path?
	if filepath.IsAbs(infile) {
		if _, err := os.Stat(infile); err == nil {
			return filepath.Clean(infile), nil
		}
	}

	// is it relative to previous file?
	if previous != "" {
		npath := filepath.Clean(filepath.Dir(previous) + string(os.PathSeparator) + infile)
		if _, err := os.Stat(npath); err == nil {
			return npath, nil
		}
	}

	// is it in the include paths?
	ipaths := (*includepaths)
	for _, p := range ipaths {
		npath := filepath.Clean(p + string(os.PathListSeparator) + infile)
		if _, err := os.Stat(npath); err == nil {
			return npath, nil
		}
	}

	// none of the above, try merge with cwd
	pwd, _ := os.Getwd()
	npath := filepath.Clean(pwd + string(os.PathSeparator) + infile)
	if _, err := os.Stat(npath); err == nil {
		return npath, nil
	}

	// not a file
	return "", os.ErrNotExist
}

func Preprocess(rootfile string, infile string, previous string, includes *[]string, includepaths *[]string) (*[]string, error) {
	ifile, ferr := GetAbsPath(infile, previous, includepaths)
	if ferr != nil {
		return nil, ferr
	}

	if hasstring(ifile, *includes) {
		return nil, nil
	}

	a := append(*includes, ifile)
	includes = &a
	lines, err := loadfile(ifile)
	if err != nil {
		return nil, err
	}
	retv := new([]string)
	for _, l := range lines {
		if strings.HasPrefix(l, "%include") {
			p := strings.Split(l, " ")
			incfile := strings.Replace(p[1], "\"", "", -1)
			inc, ierr := Preprocess(rootfile, incfile, ifile, includes, includepaths)
			if ierr != nil {
				return nil, ierr
			}
			if inc != nil {
				r := append((*retv)[:], "%pushinclude \""+incfile+"\"")
				r = append(r, (*inc)...)
				r = append(r, "%popinclude \""+incfile+"\"")
				retv = &r
			}
		} else if strings.HasPrefix(l, "%import") {
			p := strings.Split(l, " ")
			incfile := strings.Replace(p[1], "\"", "", -1)
			inc, ierr := Preprocess(rootfile, incfile, infile, includes, includepaths)
			if ierr != nil {
				return nil, ierr
			}
			if inc != nil {
				r := append((*retv)[:], (*inc)...)
				retv = &r
			}
		} else {
			a := append(*retv, l)
			retv = &a
		}
	}
	return retv, nil
}
