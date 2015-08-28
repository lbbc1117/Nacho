# Nacho
A lightweight matrix lib in C++
## Get start
Define a matrix instance with code:
```cpp
CMatrix mat = CMatrix(rowNum, colNum);
```
Set the element at 2nd row and 3rd column to be 1.5:
```cpp
mat.set(2, 3, 1.5); 
```
Get the element at 2nd row and 3rd column:
```cpp
mat.get(2, 3);  //return double
```
Get the row number:
```cpp
mat.getRowNum();  //return int
```
Get the column number:
```cpp
mat.getColNum();  //return int
```
Get the F-norm:
```cpp
mat.norm(); //return double
```
Get a transposed cpoy:
```cpp
CMatrix transposedMat = mat.trans();  //return CMatrix
```
