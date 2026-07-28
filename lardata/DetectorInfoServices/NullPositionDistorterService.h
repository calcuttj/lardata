////////////////////////////////////////////////////////////////////////
// NullPositionDistorterService.h
//
// PositionDistorterService serving a detinfo::NullPositionDistorter
// (identity) provider.
//
////////////////////////////////////////////////////////////////////////
#ifndef NULLPOSITIONDISTORTERSERVICE_H
#define NULLPOSITIONDISTORTERSERVICE_H

#include "lardata/DetectorInfoServices/PositionDistorterService.h"
#include "lardataalg/DetectorInfo/NullPositionDistorter.h"

#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"

namespace art {
  class ActivityRegistry;
}
namespace fhicl {
  class ParameterSet;
}

namespace detinfo {
  class NullPositionDistorterService : public PositionDistorterService {
  public:
    NullPositionDistorterService(fhicl::ParameterSet const& pset, art::ActivityRegistry&)
      : fProp{pset}
    {}

  private:
    provider_type const* provider() const override { return &fProp; }

    detinfo::NullPositionDistorter fProp;
  };
} // namespace detinfo

DECLARE_ART_SERVICE_INTERFACE_IMPL(detinfo::NullPositionDistorterService,
                                   detinfo::PositionDistorterService,
                                   SHARED)

#endif // NULLPOSITIONDISTORTERSERVICE_H
