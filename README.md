# arithmetic interpreter

This project implements a CLI interpreter which can evalute simple arithmetic expressions.

---
Table of Contents

1. [Description](#1-description)
1. [Motivation](#2-motivation)
1. [Future](#3-future)
---

## 1 Description

The program takes a string of operands and infix operators (limited to +,-,*, and /), tokenizes them, forms the tokens into an expression, creates a tree of the expression based on order of operations, and then evaluates the tree in order to get the arithmetic result. It's basically a calculator.

## 2 Motivation

I've been interested in language processing recently, and I got the idea in my head of an algorithm to evaluate a mathematical expression w.r.t. order of operations through utilizing a tree. So I decided to make this small interpreter to combine the two interests into a project I thought was cool.

## 3 Future

In the future, I'd like to:

* Do more rigorous testing
* Comment the code
* Make documentation
* Add QoL improvements, like saving expressions in a table, being able to print them out, hitting the up arrow to paste the most recent expression into the buffer, etc.
* Extend operations to add exponents, parenthetical precedence, logarithms, symbol bindings, other functions
* Refactor tokenization to utilize regular expressions/context free grammars (which I'd like to implement myself)
