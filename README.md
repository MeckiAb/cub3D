# cub3D

42 Málaga project in which we code a "Wolfenstein 3D" style video game in C. Team project between [C42joseri](https://github.com/C42joseri) and [me](https://github.com/MeckiAb).

## Installation & Usage

Clone repo and run 'make' to build executable. Takes a mapfile.cub as argument to work

```bash
git clone https://github.com/MeckiAb/cub3D
make
./cub3D maps/test_map.cub
```

## Programming cub3D

### Reading the map
...

### Position, direction and raycasting

To simulate a 3d environment, we take coordinates of the player into de map and apply "viewing direction" normalized vector 'DIR'. This points directly to the vertical center of the screen. 
At that point, we calculate vector 'P' perpendicular to our direction, scaled by a coefficient tied to our FoV (120 degree in our example) and raycast from the player position to each resultant direction. For example, to fill a 1024x768 screen we would cast 1024 rays, in the directions (dir_x, dir_y) · 512 · (p_x, p_y) to (dir_x, dir_y) · -512 · (p_x, p_y). Each ray casted will test for collisions with walls.

Once the collision ocurs, we acquire face found (north, south, east or west), horizontal coordinate of the collision in the wall and distance. The face tells us the texture to draw, coord tells us the exact pixels to draw, while distance compresses the height of the texture, filling with ceiling and floor colors the remaining pixels.

Finally, we apply a correction factor to the distance found, to negate de spherical aberration effect in the screen left and right borders. This factor is proportional to the distance from the middle of the screen.

### Movement


## Extras

