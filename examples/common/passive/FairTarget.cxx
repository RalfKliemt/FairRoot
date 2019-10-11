/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *              GNU Lesser General Public Licence (LGPL) version 3,             *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
/* Generated by Together */
#include "FairTarget.h"

#include "FairGeoInterface.h"           // for FairGeoInterface
#include "FairGeoLoader.h"              // for FairGeoLoader
#include "FairGeoNode.h"                // for FairGeoNode
#include "FairGeoPassivePar.h"          // for FairGeoPassivePar
#include "FairGeoTarget.h"              // for FairGeoTarget
#include "FairGeoVolume.h"              // for FairGeoVolume
#include "FairRun.h"                    // for FairRun
#include "FairRuntimeDb.h"              // for FairRuntimeDb

#include <TList.h>                      // for TListIter, TList (ptr only)
#include <TObjArray.h>                  // for TObjArray
#include <TString.h>                    // for TString

#include <stddef.h>                     // for NULL

FairTarget::~FairTarget()
{
}
FairTarget::FairTarget()
  : FairModule("FairTarget", "")
{
}

FairTarget::FairTarget(const char* name,  const char* title)
  : FairModule(name ,title)
{
}

FairTarget::FairTarget(const FairTarget& rhs)
 : FairModule(rhs)
{
}

void FairTarget::ConstructGeometry()
{
    FairGeoTarget* MGeo=new FairGeoTarget();

    ConstructASCIIGeometry<FairGeoTarget, FairGeoPassivePar>(MGeo, "FairGeoPassivePar");
}

FairModule* FairTarget::CloneModule() const
{
  return new FairTarget(*this);
}

ClassImp(FairTarget)
