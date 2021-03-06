// Copyright 2004-present Facebook. All Rights Reserved.

#pragma once

#include <string>
#include <vector>

#include <folly/Optional.h>
#include <folly/dynamic.h>

namespace facebook {
namespace ReactABI25_0_0 {

struct MethodDescriptor {
  std::string name;
  // type is one of js MessageQueue.MethodTypes
  std::string type;

  MethodDescriptor(std::string n, std::string t)
      : name(std::move(n))
      , type(std::move(t)) {}
};

  using MethodCallResult = folly::Optional<folly::dynamic>;

class NativeModule {
 public:
  virtual ~NativeModule() {}
  virtual std::string getName() = 0;
  virtual std::vector<MethodDescriptor> getMethods() = 0;
  virtual folly::dynamic getConstants() = 0;
  virtual void invoke(unsigned int ReactABI25_0_0MethodId, folly::dynamic&& params, int callId) = 0;
  virtual MethodCallResult callSerializableNativeHook(unsigned int ReactABI25_0_0MethodId, folly::dynamic&& args) = 0;
};

}
}
