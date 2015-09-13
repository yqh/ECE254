/**
 * @file:   point.c
 * @brief:  a point in 2D space  
 * @date:   2015/09/12
 */

#include "point.h"

/**
 * @brief: fill the coordinates of a point pointed by buf 
 * @param: int x x coordinate
 * @param: int y y coordinate
 * @param: struct point *buf points to the point to be set  
 * @return: none
 */
inline void
set_position(int x, int y, struct point *buf)
{
	buf->x = x;
	buf->y = y;
}

/**
 * @brief:  get x coordinate of a point
 * @param:  struct point pt the point of the interest  
 * @return: int the x coordinate
 */
inline int
get_x_coord(struct point pt) 
{
	return pt.x;
}

/**
 * @brief:  get y coordinate of a point
 * @param:  struct point pt the point of the interest  
 * @return: int the y coordinate
 */
inline int
get_y_coord(struct point pt) 
{
	return pt.y;
}
