The "fast vector vector" is for vector operations which are compiled inline with the constexpr keyword.

The idea is that eventually I will be able to specify and use this (once complete, it is currently not) when performance is vital and the more convenient "vector vector" parent directory in the typical case.

dot -- takes the dot product and returns the value

scale -- saves a scaled vector into the origional vector

add -- adds second vector into the first vector

subtract -- subtracts the second vector into the first vector

addScale -- adds a scaled version of the second vector into the first vector (does not permenantly effect second vector)

subtractScale -- subtracts a scaled version of the second vector into the first vector (does not effect second vector)

