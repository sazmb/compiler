# Compiler for Lexical, Syntax, and Semantic Analysis with Pcode Generation

This project is a compiler designed to perform lexical analysis, syntax analysis, semantic analysis, and code generation similar to pcode. It is built using a lexer for lexical analysis, yacc for syntax analysis, and custom logic for semantic checking and code generation.

## Features
- **Lexical Analysis**: Tokenizes the input source code using a lexer.
- **Syntax Analysis**: Analyzes the syntax using **Yacc** to generate a syntax tree and validate grammatical structure.
- **Semantic Analysis**: Performs semantic checks to ensure the code follows language rules and logical consistency.
- **Pcode Generation**: Translates the input code into a form of intermediate code resembling pcode.

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/your-repository.git
   cd your-repository
   ```

2. Install dependencies for lex, yacc, and the required tools:
   ```bash
   sudo apt-get install flex bison
   ```

3. Compile the lexer and parser:
   ```bash
   make
   ```

## Usage

1. To compile your source code file, run the following command:
   ```bash
   ./bup input_file
   ```

2. The compiler will generate intermediate pcode-like output and display errors or warnings (if any) related to lexical, syntax, or semantic issues.

## File Structure

- **lexer.lex**: Lexer definition file where tokens and regular expressions are defined.
- **parser.y**: Yacc grammar file for syntax parsing.
- **symbolTable.c**: Contains the logic for semantic analysis, such as type checking and scope resolution.
- **genCode.c**: Responsible for generating pcode-like intermediate code.
- **main.c**: Main driver for running the compiler.

## Example

Input: `example_source_code.txt`
```text
types
  Pair = {n1: int, n2: int};

variables
  number: int;
  pairfib: Pair;

functions
  fibstep(pair: Pair): Pair
    {pair.n2, pair.n1 + pair.n2}
  end

  fibpair(n: int): Pair
    if n == 0 then
      {0,1}
    else
      fibstep(fibpair(n-1))
    end
  end

run
  write "Insert an integer number";
  read numero;
  if numero < 0 then
    write "Error: negative number";
  else
    pairfib = fibpair(number);
    write pairfib.n1;
  end;
end
```

After running the compiler, you would get an output in pcode-like format:
```text
Pcode Output:
0	5	52
1	54	2
2	41	4	1
3	41	8	1
4	29	"Insert an integer number"
5	55	s
6	44	0	i
7	26	0	0
8	27	0
9	31	
10	47	4
11	29	"Error: negative number"
12	55	s
13	46	10
14	30	0	1
15	26	0	0
16	43	1
17	22	34
18	2	
19	48	
20	30	0	1
21	20	0	4
22	55	i
23	18	
24	11	2
25	30	1	0
26	20	4	4
27	30	1	0
28	20	0	4
29	30	1	0
30	20	4	4
31	0	
32	42	2	8	1
33	45	
34	11	3
35	26	1	0
36	27	0
37	10	
38	47	5
39	27	0
40	27	1
41	42	2	8	1
42	46	10
43	26	1	0
44	27	1
45	49	
46	43	1
47	22	34
48	2	
49	43	1
50	22	24
51	2	
52	45
```
Or in the extended version:
```text
Code size: 53

0	CODE	52
1	VARS	2
2	NEWO	4	1
3	NEWO	8	1
4	LOCS	"Insert an integer number"
5	WRIT	s
6	READ	number i
7	LOAD	0	number
8	LOCI	0
9	LTHI	
10	SKPF	4
11	LOCS	"Error:negative number"
12	WRIT	s
13	SKIP	10
14	LODA	0	pairfib
15	LOAD	0	number
16	PUSH	1
17	JUMP	34
18	APOP	
19	STOR	
20	LODA	0	pairfib
21	INDL	0	4
22	WRIT	i
23	HALT	
24	FUNC	fibstep
25	LODA	1	pair
26	INDL	4	4
27	LODA	1	pair
28	INDL	0	4
29	LODA	1	pair
30	INDL	4	4
31	ADDI	
32	PACK	2	8	1
33	RETN	
34	FUNC	fibpair
35	LOAD	1	n
36	LOCI	0
37	EQUA	
38	SKPF	5
39	LOCI	0
40	LOCI	1
41	PACK	2	8	1
42	SKIP	10
43	LOAD	1	n
44	LOCI	1
45	SUBI	
46	PUSH	1
47	JUMP	34
48	APOP	
49	PUSH	1
50	JUMP	24
51	APOP	
52	RETN	
```


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
