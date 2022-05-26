# **push_swap**
A Codam Coding College project made by Saladin Afoh
## Project Goal
Write a program in C called push_swap which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received.
You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.
## Learning Targets
- Sorting algoritms
- Linked lists
- Complexity
- Rigor
- README.md
- Version control
## Documentation
- [Instructions](/docs/instructions.md)
- [Game rules](/docs/game_rules.md)
- [The “push_swap” program](/docs/push_swap.md)
## Usage
Compile the project
```console
make;
```
Recompile the project
```console
make re:	
```
to clean all of the libraries, including libft.
```console
5. make fclean; make fclean DEBUG=1:
```
Prepare and run a debuggable executable
```console
6. make re main; ./push_swap_lldb:
```
## Bonus Goals
### VimPlugins
- Learning the basics of the following Neovim plugins:
  - [Nerdtree](https://github.com/preservim/nerdtree)
  - [coc](https://github.com/neoclide/coc.nvim)
  - [nerdcommenter](https://github.com/preservim/nerdcommenter)
### [The Pragmatic Programmer](https://www.goodreads.com/en/book/show/4099.The_Pragmatic_Programmer)
Be able to perform all of the listed actions from alinea 18, chapter 3
- When editing text, move and make selections by character, word, line, and paragraph.
- When editing code, move by various syntactic units (matching delimiters, fuctions)
- Reindent code following changes
- Comment and uncomment blocks of code with a single command
- Undo redo changes
- Split the editor window into multiple panels, and navigate between them
- Navigate to a particular line number
- Sort selected lines
- Search for both strings and regular expressions, and repeat previous searches
- Temporarily create multiple cursors based on a selection or a pattern match, and edit the text at each in parallel
- Display compilation errors in the current project
- Run the current project's tests
### ZSH
- Reorder configuration structure
- Add vim commands
- Good example
  - https://github.com/seebi/zshrc
### Credits
- A good guide for making a comprehensive Makefile:
https://readmetips.github.io/
- A lot of usefull links:
https://github.com/rsapkf/42
## License
The MIT License (MIT)

Copyright (c) 2021 Saladin Lorenzo Afoh

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
