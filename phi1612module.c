//phi1612 module

#include <Python.h>

#include "phi1612.h"

static PyObject *phi1612_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    phi1612_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    phi1612_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef Phi1612Methods[] = {
    { "getPoWHash", phi1612_getpowhash, METH_VARARGS, "Returns the proof of work hash using phi1612 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef Phi1612Module = {
    PyModuleDef_HEAD_INIT,
    "phi1612_hash",
    "...",
    -1,
    Phi1612Methods
};

PyMODINIT_FUNC PyInit_phi1612_hash(void) {
    return PyModule_Create(&Phi1612Module);
}

#else

PyMODINIT_FUNC initphi1612_hash(void) {
    (void) Py_InitModule("phi1612_hash", Phi1612Methods);
}
#endif
