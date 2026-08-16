@echo off
set NAME=%1
g++ -O3 -std=c++17 -Wall -Wextra %NAME%.cpp -o %NAME%.exe