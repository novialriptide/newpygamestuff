# `pygame.geometry` Python Prototype Project
Hello! This project is a Python prototype for a pygame.geometry module. You will be able to use new Shape types like `Circle`, `Line`, and `Polygon` to enchance, simplify, and optimize your game code!
This project adds new shapes along with new shape functionality. Each shape will have many methods for updating as well as methods for collision detection and shape conversion (shape->enclosing rect).
This project will also focus on adding widely used functionalities in game engines such as Rays and RayCasting.

**Implements**
- `Line` (line segment)
- `Circle`
- `Polygon`
- `raycast()`

### Implementation

The `shapes` directory includes all the currently implemented shapes source(`.py`) files, including the shape.py file.
The `src_c` directory includes all `.c` and `.h` files that constitute the geometry module.

### Examples

The `examples` directory includes visual and functional examples to show the usage of new functionality.
   
### Tests

The `tests` directory includes unittests that ensure the current implementations work as intended.
   
### Benchmarks

The `benchmarks` directory includes runtime benchmarks for each shape. Benchmarks typically test basic shape functionalities, but can also test interactions between different functionalities.
