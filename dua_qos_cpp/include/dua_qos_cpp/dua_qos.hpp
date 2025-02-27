/**
 * Reference QoS profile getters for DUA modules.
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

#ifndef DUA_QOS_CPP__DUA_QOS_HPP_
#define DUA_QOS_CPP__DUA_QOS_HPP_

#include "visibility_control.h"

#include <rcl_action/rcl_action.h>
#include <rclcpp/rclcpp.hpp>

namespace dua_qos
{

/**
 * @brief Returns the default settings for action servers.
 *
 * @return Action server options structure.
 */
rcl_action_server_options_t DUA_QOS_PUBLIC get_action_server_options();

/**
 * @brief Returns the default settings for action clients.
 *
 * @return Action server options structure.
 */
rcl_action_client_options_t DUA_QOS_PUBLIC get_action_client_options();

namespace Reliable
{

/**
 * @brief Returns the QoS profile for regular data topics.
 *
 * @return The QoS profile.
 */
rclcpp::QoS DUA_QOS_PUBLIC get_datum_qos(uint depth = 10);

/**
 * @brief Returns the QoS profile for scan topics, like pointclouds or laser scans.
 *
 * @param depth The depth of the QoS profile.
 * @return The QoS profile.
 */
rclcpp::QoS DUA_QOS_PUBLIC get_scan_qos(uint depth = 5);

/**
 * @brief Returns the QoS profile for image topics.
 *
 * @param depth The depth of the QoS profile.
 * @return The QoS profile.
 */
rclcpp::QoS DUA_QOS_PUBLIC get_image_qos(uint depth = 1);

} // namespace Reliable

namespace BestEffort
{

/**
 * @brief Returns the QoS profile for regular data topics.
 *
 * @return The QoS profile.
 */
rclcpp::QoS DUA_QOS_PUBLIC get_datum_qos(uint depth = 10);

/**
 * @brief Returns the QoS profile for scan topics, like pointclouds or laser scans.
 *
 * @param depth The depth of the QoS profile.
 * @return The QoS profile.
 */
rclcpp::QoS DUA_QOS_PUBLIC get_scan_qos(uint depth = 5);

/**
 * @brief Returns the QoS profile for image topics.
 *
 * @param depth The depth of the QoS profile.
 * @return The QoS profile.
 */
rclcpp::QoS DUA_QOS_PUBLIC get_image_qos(uint depth = 1);

} // namespace BestEffort

namespace Persistent
{

/**
 * @brief Returns the QoS profile for regular data topics.
 *
 * @return The QoS profile.
 */
rclcpp::QoS DUA_QOS_PUBLIC get_datum_qos(uint depth = 20);

} // namespace Persistent

} // namespace dua_qos

#endif // DUA_QOS_CPP__DUA_QOS_HPP_
