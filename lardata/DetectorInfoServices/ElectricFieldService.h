////////////////////////////////////////////////////////////////////////
// ElectricFieldService.h
//
// Pure virtual art service interface handing out a position-aware
// detinfo::IElectricFieldProvider. Modeled on spacecharge::SpaceChargeService.
//
////////////////////////////////////////////////////////////////////////
#ifndef ELECTRICFIELDSERVICE_H
#define ELECTRICFIELDSERVICE_H

#include "lardataalg/DetectorInfo/IElectricFieldProvider.h"

#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"

namespace detinfo {
  class ElectricFieldService {
  public:
    using provider_type = detinfo::IElectricFieldProvider;

    virtual ~ElectricFieldService() = default;
    virtual provider_type const* provider() const = 0;
  };
} // namespace detinfo

DECLARE_ART_SERVICE_INTERFACE(detinfo::ElectricFieldService, SHARED)

#endif // ELECTRICFIELDSERVICE_H
