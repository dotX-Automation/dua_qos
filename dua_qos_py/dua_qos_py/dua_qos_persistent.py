"""
Implementation of persistent reference QoS profile getters for DUA Python modules.

Roberto Masocco <r.masocco@dotxautomation.com>

February 27, 2025
"""

# Copyright 2025 dotX Automation s.r.l.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy.qos

from typing import TypeVar

QoSProfile = TypeVar('QoSProfile')


def get_datum_qos(depth: int = 20) -> QoSProfile:
    """
    Returns the QoS profile for regular data topics.

    :returns: The QoS profile.
    """
    return rclpy.qos.QoSProfile(
        depth=depth,
        history=rclpy.qos.HistoryPolicy.KEEP_LAST,
        reliability=rclpy.qos.ReliabilityPolicy.RELIABLE,
        durability=rclpy.qos.DurabilityPolicy.TRANSIENT_LOCAL)
