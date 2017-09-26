# fdf

Fil de fer, or "Wireframe", was a project at 42, Silicon Valley which involved recreating a wireframe program.

![alt text][42-logo]

The program runs on the [MLX](https://github.com/abouvier/minilibx) backbone which calls X-Windows. The program takes a file to populate a grid-space. The contents of the file must be numbers (0 >= n) arranged in a rectangle grid. These numbers are read from left to right, top to bottom, respecting the X and Y axes. The Z axis is created from the actual value supplied at each X, Y coordinate.

An example file:
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

![alt text][pyramid]

[42-logo]:https://github.com/scollet1/scollet1.github.io/blob/master/images/Screen%20Shot%202017-09-26%20at%201.33.01%20PM.png "42: The answer to life, the universe and everything"
[pyramid]:https://github.com/scollet1/scollet1.github.io/blob/master/images/Screen%20Shot%202017-09-26%20at%201.36.08%20PM.png "Py"
