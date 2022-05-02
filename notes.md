considering a new organization:

It would be cool to have two main classes that can interact with one another

Matrix and Vector

that way I could overload normal math operators and use them more normally as objects.

I think I will need a secondary class, or at least a set of functions usable by both
that can transition between the two, ie) extracting a row or column as a vector, or
finding the eigenvectors of a matrix and extracting them as vectors.

I think this will mean I want "The solving of linear equations" ie) everthing
which relyies on elimination to be one degree seperated from the matrix class.
But also it needs the ability to act upon a matrix object, and should be callable
within the matrix class so I can have A.invert() as a callable matrix class method.
