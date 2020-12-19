# arithmetic interpreter

This project implements a CLI interpreter which can evalute simple arithmetic expressions.

---
Table of Contents

1. [Description](#1-description)
1. [Motivation](#2-motivation)
1. [TODO](#3-todo)
1. [Future](#4-future)
---

## 1 Description

The program takes a string of operands and infix operators (limited to +,-,*, and /), tokenizes them, forms the tokens into an expression, creates a tree of the expression based on order of operations, and then evaluates the tree in order to get the arithmetic result. It's basically a calculator.

## 2 Motivation

I've been interested in language processing recently, and I got the idea in my head of an algorithm to evaluate a mathematical expression w.r.t. order of operations through utilizing a tree. So I decided to make this small interpreter to combine the two interests into a project I thought was cool.

## 3 Development

### 3.1 TODO

* Improve documentation
* Add repasting past command when up arrow hit
* Implement regular expressions
* Increase value ceiling
* Implement floating point arithmetic
* Implement lexical analysis using regex
* Implement context free grammars
* Implement syntax analysis using grammars
* Implement expression table functionality
* Add exponentiation, parenthetical precedence, logarithms
* Add variable binding
* Add equation composition
* Add function defining capabilities

### 3.2 Doing

* Implement finite automata, currently finish implementing dfa_map unit tests
* Re-format code to standard in dfa_state.h

### 3.3 Done

* Add simple code commentary
* Implement rudimentary tokenization
* Implement expressions
* Implement interactive input loop
* Implement parsing of expressions into a syntax tree
* Implement syntax tree evaluation
* Implement rudimentary expression table
* Implement rudimentary "command" options
