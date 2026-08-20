////////////////////////////////////////////////////////////////////////
// \file ChainedDistorterService.h
//
// PositionDistorterService serving a detinfo::ChainedDistorter: a first-match
// chain of IDistortion links loaded as art tools from a "Links" sequence.
//
// Example configuration:
//   services.PositionDistorterService: {
//     service_provider: ChainedDistorterService
//     Links: [
//       { tool_type: VDMaracasDistortion  TopFile: "..."  BotFile: "..."  OriginCm: [...] }
//       { tool_type: NullDistortion }   # optional explicit catch-all
//     ]
//   }
//
////////////////////////////////////////////////////////////////////////
#ifndef LARDATA_DETINFOSERVICES_CHAINEDDISTORTERSERVICE_H
#define LARDATA_DETINFOSERVICES_CHAINEDDISTORTERSERVICE_H

#include "lardata/DetectorInfoServices/ChainedDistorter.h"
#include "lardata/DetectorInfoServices/PositionDistorterService.h"

#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"

namespace art {
  class ActivityRegistry;
}
namespace fhicl {
  class ParameterSet;
}

namespace detinfo {
  class ChainedDistorterService : public PositionDistorterService {
  public:
    ChainedDistorterService(fhicl::ParameterSet const& pset, art::ActivityRegistry&)
      : fProp{pset}
    {}

  private:
    provider_type const* provider() const override { return &fProp; }

    detinfo::ChainedDistorter fProp;
  };
} // namespace detinfo

DECLARE_ART_SERVICE_INTERFACE_IMPL(detinfo::ChainedDistorterService,
                                   detinfo::PositionDistorterService,
                                   SHARED)

#endif // LARDATA_DETINFOSERVICES_CHAINEDDISTORTERSERVICE_H
