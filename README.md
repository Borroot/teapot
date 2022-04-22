![](misc/showcase.gif)

I used javidx9 his [great tutorial series](https://www.youtube.com/watch?v=ih20l3pJoeU) as a basis for this project. In addition I used Scratchapixel for several parts such as the [barycentric coordinates](https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/barycentric-coordinates).

This graphics engine is capable of rendering the Utah teapot from scratch. Meaning all pixel calculations are programmed by me, including the basics such as drawing a line between two points, filling a triangle and matrix calculations. The graphics engine implements creative Minecraft like movement with the keyboard and mouse. The engine also implements more advanced techniques such as frustum culling and clipping, which is also visible in the animation.

The teapot might look a bit strange because of the colors. The colors represent the barycentric coordinates for every triangle. I was planning to make texture mapping, where this is a prerequisite for. However, I moved on to other projects before finishing this.
