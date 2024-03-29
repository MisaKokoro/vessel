// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: testData.proto

#include "testData.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR Person::Person(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PersonDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PersonDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PersonDefaultTypeInternal() {}
  union {
    Person _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PersonDefaultTypeInternal _Person_default_instance_;
PROTOBUF_CONSTEXPR Array::Array(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.arr_)*/{}
  , /*decltype(_impl_._arr_cached_byte_size_)*/{0}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ArrayDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ArrayDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ArrayDefaultTypeInternal() {}
  union {
    Array _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ArrayDefaultTypeInternal _Array_default_instance_;
PROTOBUF_CONSTEXPR ArrayDouble::ArrayDouble(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.arr_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ArrayDoubleDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ArrayDoubleDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ArrayDoubleDefaultTypeInternal() {}
  union {
    ArrayDouble _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ArrayDoubleDefaultTypeInternal _ArrayDouble_default_instance_;
PROTOBUF_CONSTEXPR Person_Info::Person_Info(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.height_)*/0
  , /*decltype(_impl_.weight_)*/0
  , /*decltype(_impl_.age_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct Person_InfoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Person_InfoDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~Person_InfoDefaultTypeInternal() {}
  union {
    Person_Info _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Person_InfoDefaultTypeInternal _Person_Info_default_instance_;
static ::_pb::Metadata file_level_metadata_testData_2eproto[4];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_testData_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_testData_2eproto = nullptr;

const uint32_t TableStruct_testData_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Person, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Person, _impl_.name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Array, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Array, _impl_.arr_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ArrayDouble, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ArrayDouble, _impl_.arr_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Person_Info, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Person_Info, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::Person_Info, _impl_.age_),
  PROTOBUF_FIELD_OFFSET(::Person_Info, _impl_.height_),
  PROTOBUF_FIELD_OFFSET(::Person_Info, _impl_.weight_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Person)},
  { 7, -1, -1, sizeof(::Array)},
  { 14, -1, -1, sizeof(::ArrayDouble)},
  { 21, -1, -1, sizeof(::Person_Info)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_Person_default_instance_._instance,
  &::_Array_default_instance_._instance,
  &::_ArrayDouble_default_instance_._instance,
  &::_Person_Info_default_instance_._instance,
};

const char descriptor_table_protodef_testData_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016testData.proto\"\026\n\006Person\022\014\n\004name\030\001 \001(\t"
  "\"\024\n\005Array\022\013\n\003arr\030\001 \003(\005\"\032\n\013ArrayDouble\022\013\n"
  "\003arr\030\001 \003(\001\"H\n\013Person_Info\022\014\n\004name\030\001 \001(\t\022"
  "\013\n\003age\030\002 \001(\005\022\016\n\006height\030\003 \001(\001\022\016\n\006weight\030\004"
  " \001(\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_testData_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_testData_2eproto = {
    false, false, 172, descriptor_table_protodef_testData_2eproto,
    "testData.proto",
    &descriptor_table_testData_2eproto_once, nullptr, 0, 4,
    schemas, file_default_instances, TableStruct_testData_2eproto::offsets,
    file_level_metadata_testData_2eproto, file_level_enum_descriptors_testData_2eproto,
    file_level_service_descriptors_testData_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_testData_2eproto_getter() {
  return &descriptor_table_testData_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_testData_2eproto(&descriptor_table_testData_2eproto);

// ===================================================================

class Person::_Internal {
 public:
};

Person::Person(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Person)
}
Person::Person(const Person& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Person* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:Person)
}

inline void Person::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Person::~Person() {
  // @@protoc_insertion_point(destructor:Person)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Person::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
}

void Person::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:Person)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Person::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Person.name"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Person::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Person)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Person.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Person)
  return target;
}

size_t Person::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Person)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Person::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Person::GetClassData() const { return &_class_data_; }


void Person::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Person*>(&to_msg);
  auto& from = static_cast<const Person&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Person)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person::IsInitialized() const {
  return true;
}

void Person::InternalSwap(Person* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata Person::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_testData_2eproto_getter, &descriptor_table_testData_2eproto_once,
      file_level_metadata_testData_2eproto[0]);
}

// ===================================================================

class Array::_Internal {
 public:
};

Array::Array(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Array)
}
Array::Array(const Array& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Array* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.arr_){from._impl_.arr_}
    , /*decltype(_impl_._arr_cached_byte_size_)*/{0}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Array)
}

inline void Array::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.arr_){arena}
    , /*decltype(_impl_._arr_cached_byte_size_)*/{0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Array::~Array() {
  // @@protoc_insertion_point(destructor:Array)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Array::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.arr_.~RepeatedField();
}

void Array::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Array::Clear() {
// @@protoc_insertion_point(message_clear_start:Array)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.arr_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Array::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated int32 arr = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_arr(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 8) {
          _internal_add_arr(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Array::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Array)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated int32 arr = 1;
  {
    int byte_size = _impl_._arr_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(
          1, _internal_arr(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Array)
  return target;
}

size_t Array::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Array)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int32 arr = 1;
  {
    size_t data_size = ::_pbi::WireFormatLite::
      Int32Size(this->_impl_.arr_);
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    int cached_size = ::_pbi::ToCachedSize(data_size);
    _impl_._arr_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Array::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Array::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Array::GetClassData() const { return &_class_data_; }


void Array::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Array*>(&to_msg);
  auto& from = static_cast<const Array&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Array)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.arr_.MergeFrom(from._impl_.arr_);
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Array::CopyFrom(const Array& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Array)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Array::IsInitialized() const {
  return true;
}

void Array::InternalSwap(Array* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.arr_.InternalSwap(&other->_impl_.arr_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Array::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_testData_2eproto_getter, &descriptor_table_testData_2eproto_once,
      file_level_metadata_testData_2eproto[1]);
}

// ===================================================================

class ArrayDouble::_Internal {
 public:
};

ArrayDouble::ArrayDouble(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:ArrayDouble)
}
ArrayDouble::ArrayDouble(const ArrayDouble& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ArrayDouble* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.arr_){from._impl_.arr_}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:ArrayDouble)
}

inline void ArrayDouble::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.arr_){arena}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

ArrayDouble::~ArrayDouble() {
  // @@protoc_insertion_point(destructor:ArrayDouble)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ArrayDouble::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.arr_.~RepeatedField();
}

void ArrayDouble::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ArrayDouble::Clear() {
// @@protoc_insertion_point(message_clear_start:ArrayDouble)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.arr_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ArrayDouble::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated double arr = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedDoubleParser(_internal_mutable_arr(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 9) {
          _internal_add_arr(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ArrayDouble::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ArrayDouble)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated double arr = 1;
  if (this->_internal_arr_size() > 0) {
    target = stream->WriteFixedPacked(1, _internal_arr(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ArrayDouble)
  return target;
}

size_t ArrayDouble::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ArrayDouble)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated double arr = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_arr_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ArrayDouble::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ArrayDouble::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ArrayDouble::GetClassData() const { return &_class_data_; }


void ArrayDouble::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ArrayDouble*>(&to_msg);
  auto& from = static_cast<const ArrayDouble&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ArrayDouble)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.arr_.MergeFrom(from._impl_.arr_);
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ArrayDouble::CopyFrom(const ArrayDouble& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ArrayDouble)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArrayDouble::IsInitialized() const {
  return true;
}

void ArrayDouble::InternalSwap(ArrayDouble* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.arr_.InternalSwap(&other->_impl_.arr_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ArrayDouble::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_testData_2eproto_getter, &descriptor_table_testData_2eproto_once,
      file_level_metadata_testData_2eproto[2]);
}

// ===================================================================

class Person_Info::_Internal {
 public:
};

Person_Info::Person_Info(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Person_Info)
}
Person_Info::Person_Info(const Person_Info& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Person_Info* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.height_){}
    , decltype(_impl_.weight_){}
    , decltype(_impl_.age_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.height_, &from._impl_.height_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.age_) -
    reinterpret_cast<char*>(&_impl_.height_)) + sizeof(_impl_.age_));
  // @@protoc_insertion_point(copy_constructor:Person_Info)
}

inline void Person_Info::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.height_){0}
    , decltype(_impl_.weight_){0}
    , decltype(_impl_.age_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Person_Info::~Person_Info() {
  // @@protoc_insertion_point(destructor:Person_Info)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Person_Info::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
}

void Person_Info::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Person_Info::Clear() {
// @@protoc_insertion_point(message_clear_start:Person_Info)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  ::memset(&_impl_.height_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.age_) -
      reinterpret_cast<char*>(&_impl_.height_)) + sizeof(_impl_.age_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Person_Info::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Person_Info.name"));
        } else
          goto handle_unusual;
        continue;
      // int32 age = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.age_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double height = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 25)) {
          _impl_.height_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double weight = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 33)) {
          _impl_.weight_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Person_Info::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Person_Info)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Person_Info.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // int32 age = 2;
  if (this->_internal_age() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_age(), target);
  }

  // double height = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = this->_internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(3, this->_internal_height(), target);
  }

  // double weight = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_weight = this->_internal_weight();
  uint64_t raw_weight;
  memcpy(&raw_weight, &tmp_weight, sizeof(tmp_weight));
  if (raw_weight != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(4, this->_internal_weight(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Person_Info)
  return target;
}

size_t Person_Info::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Person_Info)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // double height = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = this->_internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    total_size += 1 + 8;
  }

  // double weight = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_weight = this->_internal_weight();
  uint64_t raw_weight;
  memcpy(&raw_weight, &tmp_weight, sizeof(tmp_weight));
  if (raw_weight != 0) {
    total_size += 1 + 8;
  }

  // int32 age = 2;
  if (this->_internal_age() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_age());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person_Info::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Person_Info::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Person_Info::GetClassData() const { return &_class_data_; }


void Person_Info::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Person_Info*>(&to_msg);
  auto& from = static_cast<const Person_Info&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Person_Info)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = from._internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    _this->_internal_set_height(from._internal_height());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_weight = from._internal_weight();
  uint64_t raw_weight;
  memcpy(&raw_weight, &tmp_weight, sizeof(tmp_weight));
  if (raw_weight != 0) {
    _this->_internal_set_weight(from._internal_weight());
  }
  if (from._internal_age() != 0) {
    _this->_internal_set_age(from._internal_age());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person_Info::CopyFrom(const Person_Info& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Person_Info)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person_Info::IsInitialized() const {
  return true;
}

void Person_Info::InternalSwap(Person_Info* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Person_Info, _impl_.age_)
      + sizeof(Person_Info::_impl_.age_)
      - PROTOBUF_FIELD_OFFSET(Person_Info, _impl_.height_)>(
          reinterpret_cast<char*>(&_impl_.height_),
          reinterpret_cast<char*>(&other->_impl_.height_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Person_Info::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_testData_2eproto_getter, &descriptor_table_testData_2eproto_once,
      file_level_metadata_testData_2eproto[3]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Person*
Arena::CreateMaybeMessage< ::Person >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Person >(arena);
}
template<> PROTOBUF_NOINLINE ::Array*
Arena::CreateMaybeMessage< ::Array >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Array >(arena);
}
template<> PROTOBUF_NOINLINE ::ArrayDouble*
Arena::CreateMaybeMessage< ::ArrayDouble >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ArrayDouble >(arena);
}
template<> PROTOBUF_NOINLINE ::Person_Info*
Arena::CreateMaybeMessage< ::Person_Info >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Person_Info >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
