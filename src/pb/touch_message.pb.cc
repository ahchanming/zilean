// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: touch_message.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "touch_message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* TouchMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TouchMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_touch_5fmessage_2eproto() {
  protobuf_AddDesc_touch_5fmessage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "touch_message.proto");
  GOOGLE_CHECK(file != NULL);
  TouchMessage_descriptor_ = file->message_type(0);
  static const int TouchMessage_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TouchMessage, uid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TouchMessage, dataversion_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TouchMessage, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TouchMessage, appversion_),
  };
  TouchMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TouchMessage_descriptor_,
      TouchMessage::default_instance_,
      TouchMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TouchMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TouchMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(TouchMessage));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_touch_5fmessage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TouchMessage_descriptor_, &TouchMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_touch_5fmessage_2eproto() {
  delete TouchMessage::default_instance_;
  delete TouchMessage_reflection_;
}

void protobuf_AddDesc_touch_5fmessage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023touch_message.proto\"W\n\014TouchMessage\022\013\n"
    "\003uid\030\001 \002(\t\022\023\n\013dataVersion\030\002 \002(\t\022\021\n\ttimeS"
    "tamp\030\003 \002(\t\022\022\n\nappVersion\030\004 \002(\t", 110);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "touch_message.proto", &protobuf_RegisterTypes);
  TouchMessage::default_instance_ = new TouchMessage();
  TouchMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_touch_5fmessage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_touch_5fmessage_2eproto {
  StaticDescriptorInitializer_touch_5fmessage_2eproto() {
    protobuf_AddDesc_touch_5fmessage_2eproto();
  }
} static_descriptor_initializer_touch_5fmessage_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int TouchMessage::kUidFieldNumber;
const int TouchMessage::kDataVersionFieldNumber;
const int TouchMessage::kTimeStampFieldNumber;
const int TouchMessage::kAppVersionFieldNumber;
#endif  // !_MSC_VER

TouchMessage::TouchMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void TouchMessage::InitAsDefaultInstance() {
}

TouchMessage::TouchMessage(const TouchMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void TouchMessage::SharedCtor() {
  _cached_size_ = 0;
  uid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  dataversion_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  timestamp_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  appversion_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TouchMessage::~TouchMessage() {
  SharedDtor();
}

void TouchMessage::SharedDtor() {
  if (uid_ != &::google::protobuf::internal::kEmptyString) {
    delete uid_;
  }
  if (dataversion_ != &::google::protobuf::internal::kEmptyString) {
    delete dataversion_;
  }
  if (timestamp_ != &::google::protobuf::internal::kEmptyString) {
    delete timestamp_;
  }
  if (appversion_ != &::google::protobuf::internal::kEmptyString) {
    delete appversion_;
  }
  if (this != default_instance_) {
  }
}

void TouchMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TouchMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TouchMessage_descriptor_;
}

const TouchMessage& TouchMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_touch_5fmessage_2eproto();
  return *default_instance_;
}

TouchMessage* TouchMessage::default_instance_ = NULL;

TouchMessage* TouchMessage::New() const {
  return new TouchMessage;
}

void TouchMessage::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_uid()) {
      if (uid_ != &::google::protobuf::internal::kEmptyString) {
        uid_->clear();
      }
    }
    if (has_dataversion()) {
      if (dataversion_ != &::google::protobuf::internal::kEmptyString) {
        dataversion_->clear();
      }
    }
    if (has_timestamp()) {
      if (timestamp_ != &::google::protobuf::internal::kEmptyString) {
        timestamp_->clear();
      }
    }
    if (has_appversion()) {
      if (appversion_ != &::google::protobuf::internal::kEmptyString) {
        appversion_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool TouchMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string uid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_uid()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->uid().data(), this->uid().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_dataVersion;
        break;
      }

      // required string dataVersion = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_dataVersion:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_dataversion()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->dataversion().data(), this->dataversion().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_timeStamp;
        break;
      }

      // required string timeStamp = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_timeStamp:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_timestamp()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->timestamp().data(), this->timestamp().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_appVersion;
        break;
      }

      // required string appVersion = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_appVersion:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_appversion()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->appversion().data(), this->appversion().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void TouchMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string uid = 1;
  if (has_uid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->uid().data(), this->uid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->uid(), output);
  }

  // required string dataVersion = 2;
  if (has_dataversion()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->dataversion().data(), this->dataversion().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->dataversion(), output);
  }

  // required string timeStamp = 3;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->timestamp().data(), this->timestamp().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->timestamp(), output);
  }

  // required string appVersion = 4;
  if (has_appversion()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->appversion().data(), this->appversion().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->appversion(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* TouchMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string uid = 1;
  if (has_uid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->uid().data(), this->uid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->uid(), target);
  }

  // required string dataVersion = 2;
  if (has_dataversion()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->dataversion().data(), this->dataversion().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->dataversion(), target);
  }

  // required string timeStamp = 3;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->timestamp().data(), this->timestamp().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->timestamp(), target);
  }

  // required string appVersion = 4;
  if (has_appversion()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->appversion().data(), this->appversion().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->appversion(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int TouchMessage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string uid = 1;
    if (has_uid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->uid());
    }

    // required string dataVersion = 2;
    if (has_dataversion()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->dataversion());
    }

    // required string timeStamp = 3;
    if (has_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->timestamp());
    }

    // required string appVersion = 4;
    if (has_appversion()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->appversion());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TouchMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const TouchMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const TouchMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TouchMessage::MergeFrom(const TouchMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_uid()) {
      set_uid(from.uid());
    }
    if (from.has_dataversion()) {
      set_dataversion(from.dataversion());
    }
    if (from.has_timestamp()) {
      set_timestamp(from.timestamp());
    }
    if (from.has_appversion()) {
      set_appversion(from.appversion());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void TouchMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TouchMessage::CopyFrom(const TouchMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TouchMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void TouchMessage::Swap(TouchMessage* other) {
  if (other != this) {
    std::swap(uid_, other->uid_);
    std::swap(dataversion_, other->dataversion_);
    std::swap(timestamp_, other->timestamp_);
    std::swap(appversion_, other->appversion_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata TouchMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TouchMessage_descriptor_;
  metadata.reflection = TouchMessage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
