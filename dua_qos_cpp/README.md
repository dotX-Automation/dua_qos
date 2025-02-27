# dua_qos_cpp

Collection of getter functions that return common ROS 2 Quality of Service (QoS) profiles for DUA C++ software packages.

## Contents

This library, meant to be *shared* so that multiple DUA modules can link against it, contains many different QoS profile getters. Such profiles are intended for **topics**, since services and actions have their own QoS profiles; those could be modified too, but handling the many different possible repercussions of such a change on their client-server, stateful communications is beyond the scope of this library.

Topics are divided into two categories, which correspond to the two main types of transmission in a ROS 2 network and to two distinct namespaces in the library:

- **Reliable**, which are critical for the correct functioning of the system and are intended to be used for the transmission of data. They correspond to the `dua_qos::Reliable` namespace.
- **Best-effort**, which are not critical at all and are only intended to be used for inspection purposes, *e.g.*, by external visualization tools such as RViz 2. They correspond to the `dua_qos::BestEffort` namespace.

Then, a third category is identified, which is the one of **persistent topics**. These topics transmit information that is usually identified with system state, history, and anything else that a subsystem coming up later might require to properly initialize. They correspond to the `dua_qos::Persistent` namespace and are intended to be used for the transmission of small, conventional data packets only. Their functioning is based on the `KeepLast` History policy, the `Reliable` reliability policy, and the `TransientLocal` durability policy.

The contents of each namespace are described below. Getters take an argument which is the *depth* of the QoS profile for its `KeepLast` History policy, *i.e.*, the maximum number of samples that can be stored in the history of the topic. This is necessary to avoid congestion in case of a slow consumer and/or of a lossy network, but it is not always necessary to set it to a value greater than 1. There are default values, which are suggested in most situations. For these same reasons, the `KeepAll` History policy is not used since it can cause serious congestion issues in a real, distributed robot network.

### `dua_qos`

- `get_action_server_options`: Returns an options structure for an action server, which is largely made of QoS profiles.
- `get_action_client_options`: Returns an options structure for an action client, which is largely made of QoS profiles.

#### `dua_qos::Reliable` and `dua_qos::BestEffort`

- `get_datum_qos`: Returns a QoS profile for a data topic that is critical for the correct functioning of the system.
- `get_scan_qos`: Returns a QoS profile for a spatial scan topic, *e.g.*, laser scan, pointcloud, or map, with a low depth because of their potential size.
- `get_image_qos`: Returns a QoS profile for an image topic, *e.g.*, camera image, with a configurable depth; reliable transmission of large messages such as images is very bandwidth-intensive and could clog a DDS network over a lossy link (*i.e.*, WiFi), so use this with care.

#### `dua_qos::Persistent`

- `get_datum_qos`: Returns a QoS profile for a data topic that is critical for the correct functioning of the system and/or whose information must be retained for a long time.

---

## Copyright and License

Copyright 2024 dotX Automation s.r.l.

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.

You may obtain a copy of the License at <http://www.apache.org/licenses/LICENSE-2.0>.

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

See the License for the specific language governing permissions and limitations under the License.
