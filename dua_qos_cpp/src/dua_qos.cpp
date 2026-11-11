/**
 * Implementation of reference QoS profile getters for DUA modules.
 *
 * Roberto Masocco <r.masocco@dotxautomation.com>
 *
 * June 3, 2023
 */

/**
 * Copyright 2024 dotX Automation s.r.l.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <rcutils/time.h>

#include <dua_qos_cpp/dua_qos.hpp>

namespace dua_qos
{

rcl_action_server_options_t get_action_server_options(int result_timeout_s)
{
  rcl_action_server_options_t opts = rcl_action_server_get_default_options();
  if (result_timeout_s > 0) {
    opts.result_timeout.nanoseconds = RCUTILS_S_TO_NS(result_timeout_s);
  }
  return opts;
}

rcl_action_client_options_t get_action_client_options()
{
  return rcl_action_client_get_default_options();
}

namespace Reliable
{

rclcpp::QoS get_datum_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.reliable();
  qos.durability_volatile();
  return qos;
}

rclcpp::QoS get_scan_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.reliable();
  qos.durability_volatile();
  return qos;
}

rclcpp::QoS get_image_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.reliable();
  qos.durability_volatile();
  return qos;
}

} // namespace Reliable

namespace BestEffort
{

rclcpp::QoS get_datum_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.best_effort();
  qos.durability_volatile();
  return qos;
}

rclcpp::QoS get_scan_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.best_effort();
  qos.durability_volatile();
  return qos;
}

rclcpp::QoS get_image_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.best_effort();
  qos.durability_volatile();
  return qos;
}

} // namespace BestEffort

namespace Persistent
{

rclcpp::QoS get_datum_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.reliable();
  qos.durability(rclcpp::DurabilityPolicy::TransientLocal);
  return qos;
}

} // namespace Persistent

} // namespace dua_qos
