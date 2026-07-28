////////////////////////////////////////////////////////////////////////
// DriftVolElectricFieldService.h
//
// ElectricFieldService serving a detinfo::DriftVolEFieldProvider provider.
//
////////////////////////////////////////////////////////////////////////
#ifndef DRIFTVOLELECTRICFIELDSERVICE_H
#define DRIFTVOLELECTRICFIELDSERVICE_H

#include "lardata/DetectorInfoServices/ElectricFieldService.h"
#include "lardataalg/DetectorInfo/DriftVolEFieldProvider.h"

#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"

namespace art {
  class ActivityRegistry;
}
namespace fhicl {
  class ParameterSet;
}

namespace detinfo {
  class DriftVolElectricFieldService : public ElectricFieldService {
  public:
    DriftVolElectricFieldService(fhicl::ParameterSet const& pset, art::ActivityRegistry&)
      : fProp{pset}
    {}

  private:
    provider_type const* provider() const override { return &fProp; }

    detinfo::DriftVolEFieldProvider fProp;
  };
} // namespace detinfo

DECLARE_ART_SERVICE_INTERFACE_IMPL(detinfo::DriftVolElectricFieldService,
                                   detinfo::ElectricFieldService,
                                   SHARED)

#endif // DRIFTVOLELECTRICFIELDSERVICE_H
