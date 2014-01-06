// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/binary_value_cpptoc.h"
#include "libcef_dll/cpptoc/dictionary_value_cpptoc.h"
#include "libcef_dll/cpptoc/list_value_cpptoc.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_list_value_t* cef_list_value_create() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefRefPtr<CefListValue> _retval = CefListValue::Create();

  // Return type: refptr_same
  return CefListValueCppToC::Wrap(_retval);
}


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK list_value_is_valid(struct _cef_list_value_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->IsValid();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_is_owned(struct _cef_list_value_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->IsOwned();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_is_read_only(struct _cef_list_value_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->IsReadOnly();

  // Return type: bool
  return _retval;
}

struct _cef_list_value_t* CEF_CALLBACK list_value_copy(
    struct _cef_list_value_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefListValue> _retval = CefListValueCppToC::Get(self)->Copy();

  // Return type: refptr_same
  return CefListValueCppToC::Wrap(_retval);
}

int CEF_CALLBACK list_value_set_size(struct _cef_list_value_t* self,
    size_t size) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetSize(
      size);

  // Return type: bool
  return _retval;
}

size_t CEF_CALLBACK list_value_get_size(struct _cef_list_value_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefListValueCppToC::Get(self)->GetSize();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK list_value_clear(struct _cef_list_value_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->Clear();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_remove(struct _cef_list_value_t* self, int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->Remove(
      index);

  // Return type: bool
  return _retval;
}

cef_value_type_t CEF_CALLBACK list_value_get_type(
    struct _cef_list_value_t* self, int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return VTYPE_INVALID;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return VTYPE_INVALID;

  // Execute
  cef_value_type_t _retval = CefListValueCppToC::Get(self)->GetType(
      index);

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK list_value_get_bool(struct _cef_list_value_t* self,
    int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->GetBool(
      index);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_get_int(struct _cef_list_value_t* self, int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  int _retval = CefListValueCppToC::Get(self)->GetInt(
      index);

  // Return type: simple
  return _retval;
}

double CEF_CALLBACK list_value_get_double(struct _cef_list_value_t* self,
    int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  double _retval = CefListValueCppToC::Get(self)->GetDouble(
      index);

  // Return type: simple
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK list_value_get_string(
    struct _cef_list_value_t* self, int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return NULL;

  // Execute
  CefString _retval = CefListValueCppToC::Get(self)->GetString(
      index);

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_binary_value_t* CEF_CALLBACK list_value_get_binary(
    struct _cef_list_value_t* self, int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return NULL;

  // Execute
  CefRefPtr<CefBinaryValue> _retval = CefListValueCppToC::Get(self)->GetBinary(
      index);

  // Return type: refptr_same
  return CefBinaryValueCppToC::Wrap(_retval);
}

cef_dictionary_value_t* CEF_CALLBACK list_value_get_dictionary(
    struct _cef_list_value_t* self, int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return NULL;

  // Execute
  CefRefPtr<CefDictionaryValue> _retval = CefListValueCppToC::Get(
      self)->GetDictionary(
      index);

  // Return type: refptr_same
  return CefDictionaryValueCppToC::Wrap(_retval);
}

struct _cef_list_value_t* CEF_CALLBACK list_value_get_list(
    struct _cef_list_value_t* self, int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return NULL;

  // Execute
  CefRefPtr<CefListValue> _retval = CefListValueCppToC::Get(self)->GetList(
      index);

  // Return type: refptr_same
  return CefListValueCppToC::Wrap(_retval);
}

int CEF_CALLBACK list_value_set_null(struct _cef_list_value_t* self,
    int index) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetNull(
      index);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_bool(struct _cef_list_value_t* self, int index,
    int value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetBool(
      index,
      value?true:false);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_int(struct _cef_list_value_t* self, int index,
    int value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetInt(
      index,
      value);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_double(struct _cef_list_value_t* self,
    int index, double value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetDouble(
      index,
      value);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_string(struct _cef_list_value_t* self,
    int index, const cef_string_t* value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;
  // Unverified params: value

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetString(
      index,
      CefString(value));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_binary(struct _cef_list_value_t* self,
    int index, cef_binary_value_t* value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetBinary(
      index,
      CefBinaryValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_dictionary(struct _cef_list_value_t* self,
    int index, cef_dictionary_value_t* value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetDictionary(
      index,
      CefDictionaryValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_list(struct _cef_list_value_t* self, int index,
    struct _cef_list_value_t* value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetList(
      index,
      CefListValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}


// CONSTRUCTOR - Do not edit by hand.

CefListValueCppToC::CefListValueCppToC(CefListValue* cls)
    : CefCppToC<CefListValueCppToC, CefListValue, cef_list_value_t>(cls) {
  struct_.struct_.is_valid = list_value_is_valid;
  struct_.struct_.is_owned = list_value_is_owned;
  struct_.struct_.is_read_only = list_value_is_read_only;
  struct_.struct_.copy = list_value_copy;
  struct_.struct_.set_size = list_value_set_size;
  struct_.struct_.get_size = list_value_get_size;
  struct_.struct_.clear = list_value_clear;
  struct_.struct_.remove = list_value_remove;
  struct_.struct_.get_type = list_value_get_type;
  struct_.struct_.get_bool = list_value_get_bool;
  struct_.struct_.get_int = list_value_get_int;
  struct_.struct_.get_double = list_value_get_double;
  struct_.struct_.get_string = list_value_get_string;
  struct_.struct_.get_binary = list_value_get_binary;
  struct_.struct_.get_dictionary = list_value_get_dictionary;
  struct_.struct_.get_list = list_value_get_list;
  struct_.struct_.set_null = list_value_set_null;
  struct_.struct_.set_bool = list_value_set_bool;
  struct_.struct_.set_int = list_value_set_int;
  struct_.struct_.set_double = list_value_set_double;
  struct_.struct_.set_string = list_value_set_string;
  struct_.struct_.set_binary = list_value_set_binary;
  struct_.struct_.set_dictionary = list_value_set_dictionary;
  struct_.struct_.set_list = list_value_set_list;
}

#ifndef NDEBUG
template<> long CefCppToC<CefListValueCppToC, CefListValue,
    cef_list_value_t>::DebugObjCt = 0;
#endif

