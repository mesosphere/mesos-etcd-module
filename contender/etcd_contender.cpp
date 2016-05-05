// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <mesos/mesos.hpp>
#include <mesos/module.hpp>

#include <mesos/master/contender.hpp>

#include <mesos/module/contender.hpp>
#include <process/future.hpp>

#include <stout/try.hpp>

using namespace mesos;
using namespace process;
using namespace mesos::master;
using namespace mesos::master::contender;

class EtcdMasterContender : public MasterContender
{
public:
  explicit EtcdMasterContender();
  virtual ~EtcdMasterContender();

  // MasterContender implementation.
  virtual void initialize(const MasterInfo& masterInfo);
  virtual process::Future<process::Future<Nothing>> contend();
};

EtcdMasterContender::EtcdMasterContender()
{
  std::cout << "######### Constructor!" << std::endl;
}

EtcdMasterContender::~EtcdMasterContender()
{
  std::cout << "######### Destructor" << std::endl;
}

void EtcdMasterContender::initialize(const MasterInfo& masterInfo)
{
  std::cout << "######### initialize()" << std::endl;
}

Future<Future<Nothing>> EtcdMasterContender::contend()
{
  std::cout << "######### contend()" << std::endl;
  Future<Future<Nothing>> f;
  return f;
}

static MasterContender* createContender(const Parameters& parameters)
{
  std::cout << "######### Hello, world!" << std::endl;
  std::cout << parameters.DebugString() << std::endl;
  return new EtcdMasterContender();
}

// Declares a MasterContender module named
// 'org_apache_mesos_TestMasterContender'.
mesos::modules::Module<MasterContender> org_apache_mesos_EtcdMasterContender(
    MESOS_MODULE_API_VERSION,
    MESOS_VERSION,
    "Apache Mesos",
    "modules@mesos.apache.org",
    "Test MasterContender module.",
    NULL,
    createContender);
