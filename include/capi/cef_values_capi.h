// Copyright (c) 2014 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_VALUES_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_VALUES_CAPI_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "include/capi/cef_base_capi.h"

struct _cef_dictionary_value_t;
struct _cef_list_value_t;

///
// Structure representing a binary value. Can be used on any process and thread.
///
typedef struct _cef_binary_value_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Returns true (1) if this object is valid. Do not call any other functions
  // if this function returns false (0).
  ///
  int (CEF_CALLBACK *is_valid)(struct _cef_binary_value_t* self);

  ///
  // Returns true (1) if this object is currently owned by another object.
  ///
  int (CEF_CALLBACK *is_owned)(struct _cef_binary_value_t* self);

  ///
  // Returns a copy of this object. The data in this object will also be copied.
  ///
  struct _cef_binary_value_t* (CEF_CALLBACK *copy)(
      struct _cef_binary_value_t* self);

  ///
  // Returns the data size.
  ///
  size_t (CEF_CALLBACK *get_size)(struct _cef_binary_value_t* self);

  ///
  // Read up to |buffer_size| number of bytes into |buffer|. Reading begins at
  // the specified byte |data_offset|. Returns the number of bytes read.
  ///
  size_t (CEF_CALLBACK *get_data)(struct _cef_binary_value_t* self,
      void* buffer, size_t buffer_size, size_t data_offset);
} cef_binary_value_t;


///
// Creates a new object that is not owned by any other object. The specified
// |data| will be copied.
///
CEF_EXPORT cef_binary_value_t* cef_binary_value_create(const void* data,
    size_t data_size);


///
// Structure representing a dictionary value. Can be used on any process and
// thread.
///
typedef struct _cef_dictionary_value_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Returns true (1) if this object is valid. Do not call any other functions
  // if this function returns false (0).
  ///
  int (CEF_CALLBACK *is_valid)(struct _cef_dictionary_value_t* self);

  ///
  // Returns true (1) if this object is currently owned by another object.
  ///
  int (CEF_CALLBACK *is_owned)(struct _cef_dictionary_value_t* self);

  ///
  // Returns true (1) if the values of this object are read-only. Some APIs may
  // expose read-only objects.
  ///
  int (CEF_CALLBACK *is_read_only)(struct _cef_dictionary_value_t* self);

  ///
  // Returns a writable copy of this object. If |exclude_NULL_children| is true
  // (1) any NULL dictionaries or lists will be excluded from the copy.
  ///
  struct _cef_dictionary_value_t* (CEF_CALLBACK *copy)(
      struct _cef_dictionary_value_t* self, int exclude_empty_children);

  ///
  // Returns the number of values.
  ///
  size_t (CEF_CALLBACK *get_size)(struct _cef_dictionary_value_t* self);

  ///
  // Removes all values. Returns true (1) on success.
  ///
  int (CEF_CALLBACK *clear)(struct _cef_dictionary_value_t* self);

  ///
  // Returns true (1) if the current dictionary has a value for the given key.
  ///
  int (CEF_CALLBACK *has_key)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key);

  ///
  // Reads all keys for this dictionary into the specified vector.
  ///
  int (CEF_CALLBACK *get_keys)(struct _cef_dictionary_value_t* self,
      cef_string_list_t keys);

  ///
  // Removes the value at the specified key. Returns true (1) is the value was
  // removed successfully.
  ///
  int (CEF_CALLBACK *remove)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key);

  ///
  // Returns the value type for the specified key.
  ///
  cef_value_type_t (CEF_CALLBACK *get_type)(
      struct _cef_dictionary_value_t* self, const cef_string_t* key);

  ///
  // Returns the value at the specified key as type bool.
  ///
  int (CEF_CALLBACK *get_bool)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key);

  ///
  // Returns the value at the specified key as type int.
  ///
  int (CEF_CALLBACK *get_int)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key);

  ///
  // Returns the value at the specified key as type double.
  ///
  double (CEF_CALLBACK *get_double)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key);

  ///
  // Returns the value at the specified key as type string.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t (CEF_CALLBACK *get_string)(
      struct _cef_dictionary_value_t* self, const cef_string_t* key);

  ///
  // Returns the value at the specified key as type binary.
  ///
  struct _cef_binary_value_t* (CEF_CALLBACK *get_binary)(
      struct _cef_dictionary_value_t* self, const cef_string_t* key);

  ///
  // Returns the value at the specified key as type dictionary.
  ///
  struct _cef_dictionary_value_t* (CEF_CALLBACK *get_dictionary)(
      struct _cef_dictionary_value_t* self, const cef_string_t* key);

  ///
  // Returns the value at the specified key as type list.
  ///
  struct _cef_list_value_t* (CEF_CALLBACK *get_list)(
      struct _cef_dictionary_value_t* self, const cef_string_t* key);

  ///
  // Sets the value at the specified key as type null. Returns true (1) if the
  // value was set successfully.
  ///
  int (CEF_CALLBACK *set_null)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key);

  ///
  // Sets the value at the specified key as type bool. Returns true (1) if the
  // value was set successfully.
  ///
  int (CEF_CALLBACK *set_bool)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key, int value);

  ///
  // Sets the value at the specified key as type int. Returns true (1) if the
  // value was set successfully.
  ///
  int (CEF_CALLBACK *set_int)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key, int value);

  ///
  // Sets the value at the specified key as type double. Returns true (1) if the
  // value was set successfully.
  ///
  int (CEF_CALLBACK *set_double)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key, double value);

  ///
  // Sets the value at the specified key as type string. Returns true (1) if the
  // value was set successfully.
  ///
  int (CEF_CALLBACK *set_string)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key, const cef_string_t* value);

  ///
  // Sets the value at the specified key as type binary. Returns true (1) if the
  // value was set successfully. If |value| is currently owned by another object
  // then the value will be copied and the |value| reference will not change.
  // Otherwise, ownership will be transferred to this object and the |value|
  // reference will be invalidated.
  ///
  int (CEF_CALLBACK *set_binary)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key, struct _cef_binary_value_t* value);

  ///
  // Sets the value at the specified key as type dict. Returns true (1) if the
  // value was set successfully. After calling this function the |value| object
  // will no longer be valid. If |value| is currently owned by another object
  // then the value will be copied and the |value| reference will not change.
  // Otherwise, ownership will be transferred to this object and the |value|
  // reference will be invalidated.
  ///
  int (CEF_CALLBACK *set_dictionary)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key, struct _cef_dictionary_value_t* value);

  ///
  // Sets the value at the specified key as type list. Returns true (1) if the
  // value was set successfully. After calling this function the |value| object
  // will no longer be valid. If |value| is currently owned by another object
  // then the value will be copied and the |value| reference will not change.
  // Otherwise, ownership will be transferred to this object and the |value|
  // reference will be invalidated.
  ///
  int (CEF_CALLBACK *set_list)(struct _cef_dictionary_value_t* self,
      const cef_string_t* key, struct _cef_list_value_t* value);
} cef_dictionary_value_t;


///
// Creates a new object that is not owned by any other object.
///
CEF_EXPORT cef_dictionary_value_t* cef_dictionary_value_create();


///
// Structure representing a list value. Can be used on any process and thread.
///
typedef struct _cef_list_value_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Returns true (1) if this object is valid. Do not call any other functions
  // if this function returns false (0).
  ///
  int (CEF_CALLBACK *is_valid)(struct _cef_list_value_t* self);

  ///
  // Returns true (1) if this object is currently owned by another object.
  ///
  int (CEF_CALLBACK *is_owned)(struct _cef_list_value_t* self);

  ///
  // Returns true (1) if the values of this object are read-only. Some APIs may
  // expose read-only objects.
  ///
  int (CEF_CALLBACK *is_read_only)(struct _cef_list_value_t* self);

  ///
  // Returns a writable copy of this object.
  ///
  struct _cef_list_value_t* (CEF_CALLBACK *copy)(
      struct _cef_list_value_t* self);

  ///
  // Sets the number of values. If the number of values is expanded all new
  // value slots will default to type null. Returns true (1) on success.
  ///
  int (CEF_CALLBACK *set_size)(struct _cef_list_value_t* self, size_t size);

  ///
  // Returns the number of values.
  ///
  size_t (CEF_CALLBACK *get_size)(struct _cef_list_value_t* self);

  ///
  // Removes all values. Returns true (1) on success.
  ///
  int (CEF_CALLBACK *clear)(struct _cef_list_value_t* self);

  ///
  // Removes the value at the specified index.
  ///
  int (CEF_CALLBACK *remove)(struct _cef_list_value_t* self, int index);

  ///
  // Returns the value type at the specified index.
  ///
  cef_value_type_t (CEF_CALLBACK *get_type)(struct _cef_list_value_t* self,
      int index);

  ///
  // Returns the value at the specified index as type bool.
  ///
  int (CEF_CALLBACK *get_bool)(struct _cef_list_value_t* self, int index);

  ///
  // Returns the value at the specified index as type int.
  ///
  int (CEF_CALLBACK *get_int)(struct _cef_list_value_t* self, int index);

  ///
  // Returns the value at the specified index as type double.
  ///
  double (CEF_CALLBACK *get_double)(struct _cef_list_value_t* self, int index);

  ///
  // Returns the value at the specified index as type string.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t (CEF_CALLBACK *get_string)(
      struct _cef_list_value_t* self, int index);

  ///
  // Returns the value at the specified index as type binary.
  ///
  struct _cef_binary_value_t* (CEF_CALLBACK *get_binary)(
      struct _cef_list_value_t* self, int index);

  ///
  // Returns the value at the specified index as type dictionary.
  ///
  struct _cef_dictionary_value_t* (CEF_CALLBACK *get_dictionary)(
      struct _cef_list_value_t* self, int index);

  ///
  // Returns the value at the specified index as type list.
  ///
  struct _cef_list_value_t* (CEF_CALLBACK *get_list)(
      struct _cef_list_value_t* self, int index);

  ///
  // Sets the value at the specified index as type null. Returns true (1) if the
  // value was set successfully.
  ///
  int (CEF_CALLBACK *set_null)(struct _cef_list_value_t* self, int index);

  ///
  // Sets the value at the specified index as type bool. Returns true (1) if the
  // value was set successfully.
  ///
  int (CEF_CALLBACK *set_bool)(struct _cef_list_value_t* self, int index,
      int value);

  ///
  // Sets the value at the specified index as type int. Returns true (1) if the
  // value was set successfully.
  ///
  int (CEF_CALLBACK *set_int)(struct _cef_list_value_t* self, int index,
      int value);

  ///
  // Sets the value at the specified index as type double. Returns true (1) if
  // the value was set successfully.
  ///
  int (CEF_CALLBACK *set_double)(struct _cef_list_value_t* self, int index,
      double value);

  ///
  // Sets the value at the specified index as type string. Returns true (1) if
  // the value was set successfully.
  ///
  int (CEF_CALLBACK *set_string)(struct _cef_list_value_t* self, int index,
      const cef_string_t* value);

  ///
  // Sets the value at the specified index as type binary. Returns true (1) if
  // the value was set successfully. After calling this function the |value|
  // object will no longer be valid. If |value| is currently owned by another
  // object then the value will be copied and the |value| reference will not
  // change. Otherwise, ownership will be transferred to this object and the
  // |value| reference will be invalidated.
  ///
  int (CEF_CALLBACK *set_binary)(struct _cef_list_value_t* self, int index,
      struct _cef_binary_value_t* value);

  ///
  // Sets the value at the specified index as type dict. Returns true (1) if the
  // value was set successfully. After calling this function the |value| object
  // will no longer be valid. If |value| is currently owned by another object
  // then the value will be copied and the |value| reference will not change.
  // Otherwise, ownership will be transferred to this object and the |value|
  // reference will be invalidated.
  ///
  int (CEF_CALLBACK *set_dictionary)(struct _cef_list_value_t* self, int index,
      struct _cef_dictionary_value_t* value);

  ///
  // Sets the value at the specified index as type list. Returns true (1) if the
  // value was set successfully. After calling this function the |value| object
  // will no longer be valid. If |value| is currently owned by another object
  // then the value will be copied and the |value| reference will not change.
  // Otherwise, ownership will be transferred to this object and the |value|
  // reference will be invalidated.
  ///
  int (CEF_CALLBACK *set_list)(struct _cef_list_value_t* self, int index,
      struct _cef_list_value_t* value);
} cef_list_value_t;


///
// Creates a new object that is not owned by any other object.
///
CEF_EXPORT cef_list_value_t* cef_list_value_create();


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_VALUES_CAPI_H_
