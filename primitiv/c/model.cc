#include <primitiv/config.h>

#include <string>
#include <vector>

#include <primitiv/model.h>
#include <primitiv/c/internal.h>
#include <primitiv/c/model.h>

using primitiv::Model;
using primitiv::c::internal::to_c_ptr;
using primitiv::c::internal::to_cpp_ptr;

PRIMITIV_C_STATUS primitiv_Model_new(primitiv_Model **model) try {
  PRIMITIV_C_CHECK_NOT_NULL(model);
  *model = to_c_ptr(new Model());
  return PRIMITIV_C_OK;
} PRIMITIV_C_HANDLE_EXCEPTIONS

PRIMITIV_C_STATUS primitiv_Model_delete(primitiv_Model *model) try {
  PRIMITIV_C_CHECK_NOT_NULL(model);
  delete to_cpp_ptr(model);
  return PRIMITIV_C_OK;
} PRIMITIV_C_HANDLE_EXCEPTIONS

PRIMITIV_C_STATUS primitiv_Model_load(
    primitiv_Model *model, const char *path, PRIMITIV_C_BOOL with_stats,
    primitiv_Device *device) try {
  PRIMITIV_C_CHECK_NOT_NULL(model);
  PRIMITIV_C_CHECK_NOT_NULL(path);
  to_cpp_ptr(model)->load(path, with_stats, to_cpp_ptr(device));
  return PRIMITIV_C_OK;
} PRIMITIV_C_HANDLE_EXCEPTIONS

PRIMITIV_C_STATUS primitiv_Model_save(
    const primitiv_Model *model, const char *path,
    PRIMITIV_C_BOOL with_stats) try {
  PRIMITIV_C_CHECK_NOT_NULL(model);
  PRIMITIV_C_CHECK_NOT_NULL(path);
  to_cpp_ptr(model)->save(path, with_stats);
  return PRIMITIV_C_OK;
} PRIMITIV_C_HANDLE_EXCEPTIONS

PRIMITIV_C_STATUS primitiv_Model_add_parameter(
    primitiv_Model *model, const char *name, primitiv_Parameter *param) try {
  PRIMITIV_C_CHECK_NOT_NULL(model);
  PRIMITIV_C_CHECK_NOT_NULL(name);
  PRIMITIV_C_CHECK_NOT_NULL(param);
  to_cpp_ptr(model)->add(name, *to_cpp_ptr(param));
  return PRIMITIV_C_OK;
} PRIMITIV_C_HANDLE_EXCEPTIONS

PRIMITIV_C_STATUS primitiv_Model_add_model(
    primitiv_Model *model, const char *name, primitiv_Model *submodel) try {
  PRIMITIV_C_CHECK_NOT_NULL(model);
  PRIMITIV_C_CHECK_NOT_NULL(name);
  PRIMITIV_C_CHECK_NOT_NULL(submodel);
  to_cpp_ptr(model)->add(name, *to_cpp_ptr(submodel));
  return PRIMITIV_C_OK;
} PRIMITIV_C_HANDLE_EXCEPTIONS

PRIMITIV_C_STATUS primitiv_Model_get_parameter(
    const primitiv_Model *model, const char **names, size_t n,
    const primitiv_Parameter **param) try {
  PRIMITIV_C_CHECK_NOT_NULL(model);
  PRIMITIV_C_CHECK_NOT_NULL(names);
  PRIMITIV_C_CHECK_NOT_NULL(param);
  *param = to_c_ptr(&(to_cpp_ptr(model)->get_parameter(
      std::vector<std::string>(names, names + n))));
  return PRIMITIV_C_OK;
} PRIMITIV_C_HANDLE_EXCEPTIONS

PRIMITIV_C_STATUS primitiv_Model_get_submodel(
    const primitiv_Model *model, const char **names, size_t n,
    const primitiv_Model **submodel) try {
  PRIMITIV_C_CHECK_NOT_NULL(model);
  PRIMITIV_C_CHECK_NOT_NULL(names);
  PRIMITIV_C_CHECK_NOT_NULL(submodel);
  *submodel = to_c_ptr(&(to_cpp_ptr(model)->get_submodel(
      std::vector<std::string>(names, names + n))));
  return PRIMITIV_C_OK;
} PRIMITIV_C_HANDLE_EXCEPTIONS
