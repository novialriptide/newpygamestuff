#include "line.c"
#include "circle.c"
#include "collisions.c"
#ifdef __AVX2__
#include "simd_collisions_avx2.c"
#endif /* ~__AVX2__ */

#define PYGAMEAPI_GEOMETRY_NUMSLOTS 17

static PyMethodDef _pg_module_methods[] = {{NULL, NULL, 0, NULL}};

MODINIT_DEFINE(geometry)
{
    PyObject *module, *apiobj;
    static void *c_api[PYGAMEAPI_GEOMETRY_NUMSLOTS];

    static struct PyModuleDef _module = {PyModuleDef_HEAD_INIT,
                                         "geometry",
                                         "Module for shapes like Line, Circle "
                                         "Polygon and extra functionalities\n",
                                         -1,
                                         _pg_module_methods,
                                         NULL,
                                         NULL,
                                         NULL,
                                         NULL};

    import_pygame_base();
    import_pygame_rect();
    if (PyErr_Occurred()) {
        return NULL;
    }

    /* Create the module and add the functions */
    if (PyType_Ready(&pgLine_Type) < 0) {
        return NULL;
    }
    if (PyType_Ready(&pgCircle_Type) < 0) {
        return NULL;
    }

    module = PyModule_Create(&_module);
    if (module == NULL) {
        return NULL;
    }

    Py_INCREF(&pgLine_Type);
    if (PyModule_AddObject(module, "LineType", (PyObject *)&pgLine_Type)) {
        Py_DECREF(&pgLine_Type);
        Py_DECREF(module);
        return NULL;
    }
    Py_INCREF(&pgLine_Type);
    if (PyModule_AddObject(module, "Line", (PyObject *)&pgLine_Type)) {
        Py_DECREF(&pgLine_Type);
        Py_DECREF(module);
        return NULL;
    }

    Py_INCREF(&pgCircle_Type);
    if (PyModule_AddObject(module, "CircleType", (PyObject *)&pgCircle_Type)) {
        Py_DECREF(&pgCircle_Type);
        Py_DECREF(module);
        return NULL;
    }

    Py_INCREF(&pgCircle_Type);
    if (PyModule_AddObject(module, "Circle", (PyObject *)&pgCircle_Type)) {
        Py_DECREF(&pgCircle_Type);
        Py_DECREF(module);
        return NULL;
    }

    /* export the c api */
    c_api[0] = pgCollision_LineLine;
    c_api[1] = pgIntersection_LineLine;
    c_api[2] = pgCollision_LineCircle;
    c_api[3] = pgCollision_CircleCircle;
    c_api[4] = pgCollision_RectLine;
    c_api[5] = pgCollision_RectCircle;
    c_api[6] = &pgLine_Type;
    c_api[7] = pgLine_New;
    c_api[8] = pgLine_New4;
    c_api[9] = pgLine_FromObject;
    c_api[10] = pgLine_FromObjectFastcall;
    c_api[11] = pgLine_Length;
    c_api[12] = pgLine_LengthSquared;
    c_api[13] = &pgCircle_Type;
    c_api[14] = pgCircle_New;
    c_api[15] = pgCircle_New3;
    c_api[16] = pgCircle_FromObject;

    apiobj = encapsulate_api(c_api, "geometry");
    if (PyModule_AddObject(module, PYGAMEAPI_LOCAL_ENTRY, apiobj)) {
        Py_XDECREF(apiobj);
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
