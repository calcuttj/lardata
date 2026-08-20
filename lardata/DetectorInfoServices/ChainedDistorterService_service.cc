#include "lardata/DetectorInfoServices/ChainedDistorterService.h"

#include "art/Framework/Services/Registry/ServiceDefinitionMacros.h"

//------------------------------------------------
DEFINE_ART_SERVICE_INTERFACE_IMPL(detinfo::ChainedDistorterService,
                                  detinfo::PositionDistorterService)
