/**
 * \file	proc_actuators_node.cc
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

#include <ros/ros.h>
#include "proc_actuators_node.h"

namespace proc_actuators {

    //==============================================================================
    // C / D T O R S   S E C T I O N

    //------------------------------------------------------------------------------
    //
    ProcActuatorsNode::ProcActuatorsNode(const ros::NodeHandlePtr &nh)
        : nh_(nh)
    {
        providerClient = nh->serviceClient<sonia_common::ActuatorDoActionSrv>("/provider_actuators/do_action_srv");
        cmServer = nh->advertiseService("/proc_actuators/cm_action_srv", &ProcActuatorsNode::cmContactCallback, this);
    }

    //------------------------------------------------------------------------------
    //
    ProcActuatorsNode::~ProcActuatorsNode() {}

    //==============================================================================
    // M E T H O D   S E C T I O N
    //------------------------------------------------------------------------------
    //

    void ProcActuatorsNode::Spin()
    {
        ros::Rate r(1);
        while(ros::ok())
        {
            ros::spinOnce();
            r.sleep();
        }
    }

    bool ProcActuatorsNode::cmContactCallback(sonia_common::ActuatorDoActionSrv::Request &request, sonia_common::ActuatorDoActionSrv::Response &response)
    {
        sonia_common::ActuatorDoActionSrv srv;

        srv.request.action = request.action;
        srv.request.element = request.element;
        srv.request.side = request.side;

        if(providerClient.call(srv))
        {
            ROS_INFO("/provider_actuators/do_action_srv call succeed!");
        }
        else
        {
            ROS_ERROR("failed to call /provider_actuators/do_action_srv");
        }

        return true;
    }


}  // namespace proc_actuators
