////////////////////////////////////////////////////////////////////////
// BoxElectricFieldService.h
//
// ElectricFieldService serving a detinfo::BoxElectricField provider.
//
////////////////////////////////////////////////////////////////////////
#ifndef BOXELECTRICFIELDSERVICE_H
#define BOXELECTRICFIELDSERVICE_H

#include "lardata/DetectorInfoServices/ElectricFieldService.h"
#include "lardataalg/DetectorInfo/BoxElectricField.h"

#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"

namespace art {
  class ActivityRegistry;
}
namespace fhicl {
  class ParameterSet;
}

namespace detinfo {
  class BoxElectricFieldService : public ElectricFieldService {
  public:
    BoxElectricFieldService(fhicl::ParameterSet const& pset, art::ActivityRegistry&) : fProp{pset}
    {}

  private:
    provider_type const* provider() const override { return &fProp; }

    detinfo::BoxElectricField fProp;
  };
} // namespace detinfo

DECLARE_ART_SERVICE_INTERFACE_IMPL(detinfo::BoxElectricFieldService,
                                   detinfo::ElectricFieldService,
                                   SHARED)

#endif // BOXELECTRICFIELDSERVICE_H
