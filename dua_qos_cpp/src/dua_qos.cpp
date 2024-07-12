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

#include <dua_qos_cpp/dua_qos.hpp>

namespace dua_qos
{

/**
 * @brief Returns the default settings for action servers.
 *
 * @return Action server options structure.
 */
rcl_action_server_options_t get_action_server_options()
{
  rcl_action_server_options_t options{};
  rmw_qos_profile_t status_qos = rmw_qos_profile_default;
  status_qos.durability = RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL;

  options.allocator = rcl_get_default_allocator();
  options.goal_service_qos = rmw_qos_profile_services_default;
  options.cancel_service_qos = rmw_qos_profile_services_default;
  options.result_service_qos = rmw_qos_profile_services_default;
  options.feedback_topic_qos = rmw_qos_profile_default;
  options.status_topic_qos = status_qos;

  return options;
}

/**
 * @brief Returns the default settings for action clients.
 *
 * @return Action server options structure.
 */
rcl_action_client_options_t get_action_client_options()
{
  rcl_action_client_options_t options{};
  rmw_qos_profile_t status_qos = rmw_qos_profile_default;
  status_qos.durability = RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL;

  options.allocator = rcl_get_default_allocator();
  options.goal_service_qos = rmw_qos_profile_services_default;
  options.cancel_service_qos = rmw_qos_profile_services_default;
  options.result_service_qos = rmw_qos_profile_services_default;
  options.feedback_topic_qos = rmw_qos_profile_default;
  options.status_topic_qos = status_qos;

  return options;
}

namespace Reliable
{

/**
 * @brief Returns the QoS profile for regular data topics.
 *
 * @return The QoS profile.
 */
rclcpp::QoS get_datum_qos()
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepAll());
  qos.reliable();
  qos.durability_volatile();
  return qos;
}

/**
 * @brief Returns the QoS profile for scan topics, like pointclouds or laser scans.
 *
 * @param depth The depth of the QoS profile.
 * @return The QoS profile.
 */
rclcpp::QoS get_scan_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.reliable();
  qos.durability_volatile();
  return qos;
}

/**
 * @brief Returns the QoS profile for image topics.
 *
 * @param depth The depth of the QoS profile.
 * @return The QoS profile.
 */
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

/**
 * @brief Returns the QoS profile for regular data topics.
 *
 * @return The QoS profile.
 */
rclcpp::QoS get_datum_qos()
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepAll());
  qos.best_effort();
  qos.durability_volatile();
  return qos;
}

/**
 * @brief Returns the QoS profile for scan topics, like pointclouds or laser scans.
 *
 * @param depth The depth of the QoS profile.
 * @return The QoS profile.
 */
rclcpp::QoS get_scan_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.best_effort();
  qos.durability_volatile();
  return qos;
}

/**
 * @brief Returns the QoS profile for image topics.
 *
 * @param depth The depth of the QoS profile.
 * @return The QoS profile.
 */
rclcpp::QoS get_image_qos(uint depth)
{
  rclcpp::QoS qos = rclcpp::QoS(rclcpp::KeepLast(depth));
  qos.best_effort();
  qos.durability_volatile();
  return qos;
}

} // namespace BestEffort

} // namespace dua_qos
