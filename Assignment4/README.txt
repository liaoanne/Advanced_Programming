README---------------------------------------------------------------------

COMP 5421 Assignment 4
By Anne Liao, student ID 40215517

Purpose: This program implements shape abstractions using the C++ features
that support encapsulation, information hiding, inheritance and polymorphism.
Four types of shapes are represented; rectangle, rhombus, acute triangle, 
and right triangle. The base class is Shape with all other classes being 
the derived classes under it. Rectangle, Rhombus, and Triangle are classes 
directly derived from Shape. Triangle forms a base class for two derived 
classes; AcuteTriangle and RightTriangle.

As well, a Canvas class is implemented for shapes to be drawn onto and 
manipulated. The ShapeTestDriver creates a Canvas and utilizes all the 
Shape objects defined to draw a house.

Instructions on how to run the program:

- ShapeTestDriver.cpp contains the main() method, which when run will print 
a description of the shapes constructed and a final image of the combined 
shapes, which make a house.

Extra Features:

- N/A

Testing:

- Program was tested and run on Microsoft Visual Studio 2022 using C++20.

- ShapeTestDriver.cpp gave the correct output and exited with code 0.

- No known bugs were found.

Additional notes:

- For the overlap member function of Canvas.h, I asked the professor whether
it was neccessary to resize the invoking Canvas if the overlapping canvas 
is out of bounds. The professor said he did not require this and we could 
just omit the parts of the overlapping canvas that are out of bounds.

README---------------------------------------------------------------------