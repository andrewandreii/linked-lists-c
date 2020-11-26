## linked lists
singly linked lists implementation for C
this supports any type but does not guarantee type safety so use it with care

### how to build
`make sharedobj` makes the `liblinked_list.so` file, but `make` installs it as well

IMPORTANT: `make` installs the library without the need of `sudo` so it installs it in `$HOME/.local/include` and `$HOME/.local/lib`, so make sure to add those folders to `C_INCLUDE_PATH` and `LD_LIBRARY_PATH` or simply modify the Makefile and install the library directly in locations where gcc looks for stuff

### how to test
run `./test`
this compiles `test.c`, runs it and checks for memory leaks with `mtrace`
the file `test.c` can be treated as an example of how to use the library too

### the man page
coming soon
