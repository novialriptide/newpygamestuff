#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include "pygame.h"

typedef struct {
    double x, y, r, r_sqr;
} pgCircleBase;

typedef struct {
    PyObject_HEAD pgCircleBase circle;
    PyObject *weakreflist;
} pgCircleObject;

#define pgCircle_CAST(o) ((pgCircleObject *)(o))
#define pgCircle_CIRCLE(o) (pgCircle_CAST(o)->circle)
#define pgCircle_GETX(self) (pgCircle_CAST(self)->circle.x)
#define pgCircle_GETY(self) (pgCircle_CAST(self)->circle.y)
#define pgCircle_GETR(self) (pgCircle_CAST(self)->circle.r)
#define pgCircle_GETRSQR(self) (pgCircle_CAST(self)->circle.r_sqr)

typedef struct {
    double x1, y1;
    double x2, y2;
} pgLineBase;

typedef struct {
    PyObject_HEAD pgLineBase line;
    PyObject *weakreflist;
} pgLineObject;

#define pgLine_CAST(o) ((pgLineObject *)(o))

#define pgLine_GETLINE(o) (pgLine_CAST(o)->line)
#define pgLine_GETX1(self) (pgLine_CAST(self)->line.x1)
#define pgLine_GETY1(self) (pgLine_CAST(self)->line.y1)
#define pgLine_GETX2(self) (pgLine_CAST(self)->line.x2)
#define pgLine_GETY2(self) (pgLine_CAST(self)->line.y2)

#endif /* ~_GEOMETRY_H */
