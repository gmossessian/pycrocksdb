#include <Python.h>
#include "rocksdb/c.h"

typedef struct {
    PyObject_HEAD
    rocksdb_t *db;
} PyRocksDBObject;

static PyTypeObject PyRocksDBType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pycrocksdb.RocksDB",              /* tp_name */
    sizeof(PyRocksDBObject),  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    0,                                 /* tp_dealloc */
    0,                                 /* tp_print */
    0,                                 /* tp_getattr */
    0,                                 /* tp_setattr */
    0,                                 /* tp_compare */
    0,                                 /* tp_repr */
    0,                                 /* tp_as_number */
    0,                                 /* tp_as_sequence */
    0,                                 /* tp_as_mapping */
    0,                                 /* tp_hash */
    0,                                 /* tp_call */
    0,                                 /* tp_str */
    0,                                 /* tp_getattro */
    0,                                 /* tp_setattro */
    0,                                 /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                /* tp_flags */
    "george's RocksDB object",         /* tp_doc */
};

static PyMethodDef pycrocksdb_methods[] = {
    {NULL}  /* Sentinel */
};

#ifndef PyMODINIT_FUNC	/* declarations for DLL import/export */
#define PyMODINIT_FUNC void
#endif
PyMODINIT_FUNC
initpycrocksdb(void)
{
    PyObject* m;

    PyRocksDBType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&PyRocksDBType) < 0)
        return;

    m = Py_InitModule3(
      "pycrocksdb", pycrocksdb_methods,
      "Example module that creates an extension type."
    );

    Py_INCREF(&PyRocksDBType);
    PyModule_AddObject(m, "RocksDB", (PyObject *)&PyRocksDBType);
}
