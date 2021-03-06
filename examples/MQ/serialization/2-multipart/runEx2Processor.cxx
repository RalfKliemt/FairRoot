/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *              GNU Lesser General Public Licence (LGPL) version 3,             *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "runFairMQDevice.h"
#include "Ex2Processor.h"

namespace bpo = boost::program_options;

void addCustomOptions(bpo::options_description& options)
{
    options.add_options()
        ("num-msgs", bpo::value<int>()->default_value(0), "Stop after <n> msgs (0 - no limit).");
}

FairMQDevicePtr getDevice(const FairMQProgOptions& /*config*/)
{
    return new Ex2Processor();
}
