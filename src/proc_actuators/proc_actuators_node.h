/**
 *
 * \file	proc_actuators_node.h
 * \author	Olivier Beguin <olivier.beguinti@gmail.com>
 * \date	06/10/2017
 *
 * \copyright Copyright (c) 2017 S.O.N.I.A. All rights reserved.
 *
 * \section LICENSE
 *
 * This file is part of S.O.N.I.A. software.
 *
 * S.O.N.I.A. software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * S.O.N.I.A. software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with S.O.N.I.A. software. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROC_ACTUATORS_PROC_ACTUATORS_NODE_H_
#define PROC_ACTUATORS_PROC_ACTUATORS_NODE_H_

#include <ros/node_handle.h>
#include <provider_actuators/DoActionSrv.h>
#include <proc_actuators/cmActionSrv.h>

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

namespace proc_actuators {

class ProcActuatorsNode {
 public:
  //==========================================================================
  // T Y P E D E F   A N D   E N U M

  //==========================================================================
  // P U B L I C   C / D T O R S

  explicit ProcActuatorsNode(const ros::NodeHandlePtr &nh);

  ~ProcActuatorsNode();

  /// Taking care of the spinning of the ROS thread.
  /// Each iteration of the loop, this will take the objects in the object
  /// registery, empty it and publish the objects.
  void Spin();

private:

    ros::NodeHandlePtr nh_;
    ros::ServiceServer cmServer;
    ros::ServiceClient providerClient;

    bool cmContactCallback(cmActionSrv::Request &request, cmActionSrv::Response &response);
};

}  // namespace proc_actuators

#endif  // PROC_ACTUATORS_PROC_ACTUATORS_NODE_H_
