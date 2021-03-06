/*************************************************************************
	> File Name: linalgmodule.h
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2018-05-28 Mon 19:06:04 CST
 ************************************************************************/
#ifndef LINALG_MODULE_H
#define LINALG_MODULE_H
#include <Python.h>
#include "LinAlg.h"
#include <structmember.h>
using namespace LinAlg;

// 定义Vector类
typedef struct {
    PyObject_HEAD;
	Vector ob_vector;
} PyVectorObject;

// 定义Matrix类
typedef struct {
    PyObject_HEAD;
    Matrix ob_matrix;
} PyMatrixObject;

// 函数接口
static bool
isNumber(PyObject *o, bool throwErr = true);

static double
getNumber(PyObject *o);

static PyVectorObject *
PyVector_Copy(PyVectorObject *self);

static void
PyLinAlg_dealloc(PyObject *self);

static PyObject *
PyVector_T(PyVectorObject *self);

static Py_ssize_t
PyVector_len(PyVectorObject *self);

static int
PyVector_init(PyVectorObject *self, PyObject *args, PyObject *kwds);

static PyObject *
PyVector_str(PyVectorObject *self);

static PyObject *
PyVector_GetItem(PyVectorObject *self, Py_ssize_t i);

static int
PyVector_SetItem(PyVectorObject *self, Py_ssize_t i, PyObject *v);

// *=
static PyObject *
PyVector_imul(PyVectorObject *self, PyObject *arg);

// +=
static PyObject *
PyVector_iadd(PyVectorObject *self, PyVectorObject *arg);

// -=
static PyObject *
PyVector_isub(PyVectorObject *self, PyVectorObject *arg);

// 乘法
static PyVectorObject *
PyVector_mul(PyVectorObject *self, PyObject *arg);

// 向量加法
static PyObject *
PyVector_add(PyVectorObject *self, PyVectorObject *arg);

// 向量减法
static PyObject *
PyVector_sub(PyVectorObject *self, PyVectorObject *arg);

static int
PyMatrix_init(PyMatrixObject *self, PyObject *args, PyObject *kwds);

static PyObject *
PyMatrix_str(PyMatrixObject *self);

static PyObject*
PyMatrix_getRowSize(PyMatrixObject *self);

static PyObject*
PyMatrix_getColSize(PyMatrixObject *self);

static PyVectorObject*
PyMatrix_getNRowVec(PyMatrixObject *self, PyObject* i);

static PyVectorObject*
PyMatrix_getNColVec(PyMatrixObject *self, PyObject* i);

static PyMatrixObject *
PyMatrix_Copy(PyMatrixObject *self);

static PyMatrixObject *
PyMatrix_LUdecomp(PyMatrixObject *self);

static PyVectorObject *
PyMatrix_LUsolve(PyMatrixObject *self, PyVectorObject *y);

static PyObject *
PyMatrix_det(PyMatrixObject *self);

static PyMatrixObject *
PyMatrix_inv(PyMatrixObject *self);

static PyVectorObject *
PyMatrix_Jacobi(PyMatrixObject *self);
#endif
