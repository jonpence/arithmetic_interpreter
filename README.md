# arithmetic-interpreter

This project defines a CLI interpreter which can evalaute simple arithmetic expressions.

---
Table of Contents

1. [Description](#1-description)
1. [Motivation](#2-motivation)
---

## 1 Description

The program takes a string of operands and infix operators (limited to +,-,*, and /), tokenizes them, forms the tokens into an expression, creates a tree of the expression based on order of operations, and then evaluates the tree in order to get the arithmetic result. It's basically a calculator.

## 2 Motivation

I've been interested in language processing recently, and I got the idea in my head of an algorithm to evaluate a mathematical expression w.r.t. order of operations through utilizing a tree. So I decided to make this small interpreter to combine the two interests into a project I thought was cool.
