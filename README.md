# Nacho
A lightweight matrix lib in C++
## Get start
Define a matrix instance with zeros:
```cpp
CMatrix mat = CMatrix(rowNum, colNum);  // demensions : rowNum*colNum
CMatrix mat = CMatrix(n);  // demensions : n*n
CMatrix mat = anotherMat;  // demension : same as the right CMatrix
```
Set the element at 2nd row and 3rd column to 1.5:
```cpp
mat.set(2, 3, 1.5); 
```
Get the element at 2nd row and 3rd column:
```cpp
mat.get(2, 3);  // return double
```
Get the row number:
```cpp
mat.getRowNum();  // return int
```
Get the column number:
```cpp
mat.getColNum();  // return int
```
Get the F-norm:
```cpp
mat.norm(); // return double
```
Get a transposed cpoy:
```cpp
CMatrix transposedMat = mat.trans();  // return CMatrix
```
Unitize diagnoal elements:
```cpp
mat.diagUnitize(); 
```
Set all elements to zero:
```cpp
mat.clear(); 
```
Addtion:
```cpp
CMatrix mat = mat1 + mat2;
```
Subtraction:
```cpp
CMatrix mat = mat1 - mat2;
```
Multiplication with CMatrix:
```cpp
CMatrix mat = mat1 * mat2;
```
Multiplication with single number:
```cpp
CMatrix mat = mat1 * 1.5;
```
Division:
```cpp
CMatrix mat = mat1 / 1.5;
```
Exponentiation:
```cpp
CMatrix mat = mat1 ^ 1.5;
```
