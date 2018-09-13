# functional_cpp

### functional cpp examples

building the project:

```
build() {
    cmake -H. -Bbuild &&
    cmake --build build -- -j3
}

build
```

running the project:

```
$ ./bin/hello
# fibonacci sequence across an array
  array:   0, 1, 2, 3, 4, 5, 6, 7
  results: 1, 1, 2, 3, 5, 8, 13, 21

# filter only odd numbers
  odd only: 1, 1, 3, 5, 13, 21,

# Sum of only odd numbers in fibonacci sequence
  sum: 44

```
