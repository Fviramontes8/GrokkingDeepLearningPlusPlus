# GrokkingDeepLearningPlusPlus
Code examples from Grokking Deep Learning by Andrew W. Trask rewritten in C++.

## CMake instructions
Many of these folders contain CMake projects (trying to learn CMake too, please be patient) and Makefiles can be generated with the following command:

```bash
cmake -B build
```

### Building the CMake projects
There are two recommended ways of compiling each CMake project:
```bash
cmake --build build
```
which is primarily recommended, but the following is valid as well:
```bash
cd build
make
```

### Running the CMake projects
If a folder contain an `app` folder, after the project is built, the executable can be run with:

```bash
./build/app/EXE_NAME
```
Where `EXE_NAME` is the name of the executable.

Otherwise, `app/` can be omitted:
```bash
./build/EXE_NAME
```

### Running CMake tests
Fewer of these projects have a `test/` folder. After generating the Makefile the following command should run the tests:
```bash
cmake --build build --target test
```
It should start running tests, and they should all pass.