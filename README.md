## Description
**C++23 WinAPI**

* **`win_path_test`** - a collection of methods to retrieve the current executable path.
* **`create_hard_link`** - a utility to create a hard link at the path specified in `./path.txt`.
* **`start`** - a utility to launch the executable located at the path specified in `./path.txt`.

**Usage:**
1. Either rename one of the examples to `./path.txt`, or create `./path.txt` and write the desired path for testing.
2. Run `create_hard_link.exe` to create a hard link to `win_path_test` at the path specified in `./path.txt`.
3. Now, running `start.exe` will launch the `win_path_test` instance located at the path from `./path.txt`. This allows you to compare how different methods handle relative, long, short, and other Windows-specific paths.

## Building
```
git clone https://github.com/NsPro04/win_path_test.git
.\win_path_test\win_path_test.slnx
Ctrl+Shift+B
```
