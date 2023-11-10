/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: testData.proto */

#ifndef PROTOBUF_C_testData_2eproto__INCLUDED
#define PROTOBUF_C_testData_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct Person Person;
typedef struct Array Array;
typedef struct ArrayDouble ArrayDouble;
typedef struct PersonInfo PersonInfo;


/* --- enums --- */


/* --- messages --- */

struct  Person
{
  ProtobufCMessage base;
  char *name;
};
#define PERSON__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&person__descriptor) \
    , (char *)protobuf_c_empty_string }


struct  Array
{
  ProtobufCMessage base;
  size_t n_arr;
  int32_t *arr;
};
#define ARRAY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&array__descriptor) \
    , 0,NULL }


struct  ArrayDouble
{
  ProtobufCMessage base;
  size_t n_arr;
  double *arr;
};
#define ARRAY_DOUBLE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&array_double__descriptor) \
    , 0,NULL }


struct  PersonInfo
{
  ProtobufCMessage base;
  char *name;
  int32_t age;
  double height;
  double weight;
};
#define PERSON__INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&person__info__descriptor) \
    , (char *)protobuf_c_empty_string, 0, 0, 0 }


/* Person methods */
void   person__init
                     (Person         *message);
size_t person__get_packed_size
                     (const Person   *message);
size_t person__pack
                     (const Person   *message,
                      uint8_t             *out);
size_t person__pack_to_buffer
                     (const Person   *message,
                      ProtobufCBuffer     *buffer);
Person *
       person__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   person__free_unpacked
                     (Person *message,
                      ProtobufCAllocator *allocator);
/* Array methods */
void   array__init
                     (Array         *message);
size_t array__get_packed_size
                     (const Array   *message);
size_t array__pack
                     (const Array   *message,
                      uint8_t             *out);
size_t array__pack_to_buffer
                     (const Array   *message,
                      ProtobufCBuffer     *buffer);
Array *
       array__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   array__free_unpacked
                     (Array *message,
                      ProtobufCAllocator *allocator);
/* ArrayDouble methods */
void   array_double__init
                     (ArrayDouble         *message);
size_t array_double__get_packed_size
                     (const ArrayDouble   *message);
size_t array_double__pack
                     (const ArrayDouble   *message,
                      uint8_t             *out);
size_t array_double__pack_to_buffer
                     (const ArrayDouble   *message,
                      ProtobufCBuffer     *buffer);
ArrayDouble *
       array_double__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   array_double__free_unpacked
                     (ArrayDouble *message,
                      ProtobufCAllocator *allocator);
/* PersonInfo methods */
void   person__info__init
                     (PersonInfo         *message);
size_t person__info__get_packed_size
                     (const PersonInfo   *message);
size_t person__info__pack
                     (const PersonInfo   *message,
                      uint8_t             *out);
size_t person__info__pack_to_buffer
                     (const PersonInfo   *message,
                      ProtobufCBuffer     *buffer);
PersonInfo *
       person__info__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   person__info__free_unpacked
                     (PersonInfo *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Person_Closure)
                 (const Person *message,
                  void *closure_data);
typedef void (*Array_Closure)
                 (const Array *message,
                  void *closure_data);
typedef void (*ArrayDouble_Closure)
                 (const ArrayDouble *message,
                  void *closure_data);
typedef void (*PersonInfo_Closure)
                 (const PersonInfo *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor person__descriptor;
extern const ProtobufCMessageDescriptor array__descriptor;
extern const ProtobufCMessageDescriptor array_double__descriptor;
extern const ProtobufCMessageDescriptor person__info__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_testData_2eproto__INCLUDED */
