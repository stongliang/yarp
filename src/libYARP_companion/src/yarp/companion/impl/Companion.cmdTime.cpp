/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include <yarp/companion/impl/Companion.h>

#include <yarp/os/SystemClock.h>
#include <yarp/os/Time.h>

using yarp::companion::impl::Companion;
using yarp::os::SystemClock;

int Companion::cmdTime(int argc, char *argv[])
{
    SystemClock clk;
    bool ros = false;
    if (argc>0) {
        if (std::string(argv[0])=="--ros") {
            ros = true;
        }
    }
    while (true) {
        double t = yarp::os::Time::now();
        if (ros) {
            int sec = (int) t;
            int nsec = (int)((t-sec)*1e9);
            yCInfo(COMPANION, "%d %d", sec, nsec);
        } else {
            yCInfo(COMPANION, "%f", t);
        }
        fflush(stdout);
        clk.delay(0.1);
    }
    return 0;
}
