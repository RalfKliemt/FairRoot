/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *              GNU Lesser General Public Licence (LGPL) version 3,             *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
// -------------------------------------------------------------------------
// -----                     FairBaseContFact source file              -----
// -----                Created 25/10/04  by  Ilse Koenig              -----
// -------------------------------------------------------------------------


//  Factory for the parameter containers in Base

#include <string.h>

#include "FairBaseContFact.h"
#include "FairBaseParSet.h"
#include "FairGeoParSet.h"
#include "FairRuntimeDb.h"
#include "TList.h"
#include "TString.h"

class FairParSet;


ClassImp(FairBaseContFact)

static FairBaseContFact gFairBaseContFact;

FairBaseContFact::FairBaseContFact()
  :FairContFact()
{
  // Constructor (called when the library is loaded)
  fName="FairBaseContFact";
  fTitle="Factory for parameter containers in libSts";
  setAllContainers();
  FairRuntimeDb::instance()->addContFactory(this);
}

void FairBaseContFact::setAllContainers()
{
  /** Creates the Container objects with all accepted contexts and adds them to
   *  the list of containers for the base library.*/
  FairContainer* pTest= new FairContainer("FairBaseParSet",
                                          "class for parameter io",
                                          "DefaultContext");
  pTest->addContext("TestNonDefaultContext");
  containers->Add(pTest);

  FairContainer* pGeo= new FairContainer("FairGeoParSet",
                                         "class for Geo parameter",
                                         "DefaultContext");
  pTest->addContext("TestNonDefaultContext");
  containers->Add(pGeo);



}

FairParSet* FairBaseContFact::createContainer(FairContainer* c)
{
  /** Calls the constructor of the corresponding parameter container.
   * For an actual context, which is not an empty string and not the default context
   * of this container, the name is concatinated with the context. */
  const char* name=c->GetName();
  FairParSet* p=0;
  if (strcmp(name,"FairBaseParSet")==0) {
    p=new FairBaseParSet(c->getConcatName().Data(),c->GetTitle(),c->getContext());
  } else if (strcmp(name,"FairGeoParSet")==0) {
    p=new FairGeoParSet(c->getConcatName().Data(),c->GetTitle(),c->getContext());
  }

  return p;
}

