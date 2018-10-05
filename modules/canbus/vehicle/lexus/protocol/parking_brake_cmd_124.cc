/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/lexus/protocol/parking_brake_cmd_124.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace lexus {

using ::apollo::drivers::canbus::Byte;

const int32_t Parkingbrakecmd124::ID = 0x124;

// public
Parkingbrakecmd124::Parkingbrakecmd124() { Reset(); }

uint32_t Parkingbrakecmd124::GetPeriod() const {
  // TODO modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Parkingbrakecmd124::UpdateData(uint8_t* data) {
  set_p_ignore_overrides(data, ignore_overrides_);
  set_p_enable(data, enable_);
  set_p_clear_override(data, clear_override_);
  set_p_parking_brake_cmd(data, parking_brake_cmd_);
  set_p_clear_faults(data, clear_faults_);
}

void Parkingbrakecmd124::Reset() {
  // TODO you should check this manually
  ignore_overrides_ = false;
  enable_ = false;
  clear_override_ = false;
  parking_brake_cmd_ = false;
  clear_faults_ = false;
}

Parkingbrakecmd124* Parkingbrakecmd124::set_ignore_overrides(
    bool ignore_overrides) {
  ignore_overrides_ = ignore_overrides;
  return this;
}

// config detail: {'name': 'IGNORE_OVERRIDES', 'offset': 0.0, 'precision': 1.0,
// 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 1,
// 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
void Parkingbrakecmd124::set_p_ignore_overrides(uint8_t* data,
                                                bool ignore_overrides) {
  int x = ignore_overrides;

  Byte to_set(data + 0);
  to_set.set_value(x, 1, 1);
}

Parkingbrakecmd124* Parkingbrakecmd124::set_enable(bool enable) {
  enable_ = enable;
  return this;
}

// config detail: {'name': 'ENABLE', 'offset': 0.0, 'precision': 1.0, 'len': 1,
// 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 0, 'type': 'bool',
// 'order': 'motorola', 'physical_unit': ''}
void Parkingbrakecmd124::set_p_enable(uint8_t* data, bool enable) {
  int x = enable;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}

Parkingbrakecmd124* Parkingbrakecmd124::set_clear_override(
    bool clear_override) {
  clear_override_ = clear_override;
  return this;
}

// config detail: {'name': 'CLEAR_OVERRIDE', 'offset': 0.0, 'precision': 1.0,
// 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 2,
// 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
void Parkingbrakecmd124::set_p_clear_override(uint8_t* data,
                                              bool clear_override) {
  int x = clear_override;

  Byte to_set(data + 0);
  to_set.set_value(x, 2, 1);
}

Parkingbrakecmd124* Parkingbrakecmd124::set_parking_brake_cmd(
    bool parking_brake_cmd) {
  parking_brake_cmd_ = parking_brake_cmd;
  return this;
}

// config detail: {'name': 'PARKING_BRAKE_CMD', 'offset': 0.0, 'precision': 1.0,
// 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 8,
// 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
void Parkingbrakecmd124::set_p_parking_brake_cmd(uint8_t* data,
                                                 bool parking_brake_cmd) {
  int x = parking_brake_cmd;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 1);
}

Parkingbrakecmd124* Parkingbrakecmd124::set_clear_faults(bool clear_faults) {
  clear_faults_ = clear_faults;
  return this;
}

// config detail: {'name': 'CLEAR_FAULTS', 'offset': 0.0, 'precision': 1.0,
// 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 3,
// 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
void Parkingbrakecmd124::set_p_clear_faults(uint8_t* data, bool clear_faults) {
  int x = clear_faults;

  Byte to_set(data + 0);
  to_set.set_value(x, 3, 1);
}

}  // namespace lexus
}  // namespace canbus
}  // namespace apollo