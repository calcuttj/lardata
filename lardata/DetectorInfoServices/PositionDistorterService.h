////////////////////////////////////////////////////////////////////////
// PositionDistorterService.h
//
// Pure virtual art service interface handing out a
// detinfo::IPositionDistorter. Modeled on spacecharge::SpaceChargeService.
//
////////////////////////////////////////////////////////////////////////
#ifndef POSITIONDISTORTERSERVICE_H
#define POSITIONDISTORTERSERVICE_H

#include "lardataalg/DetectorInfo/IPositionDistorter.h"

#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"

namespace detinfo {
  class PositionDistorterService {
  public:
    using provider_type = detinfo::IPositionDistorter;

    virtual ~PositionDistorterService() = default;
    virtual provider_type const* provider() const = 0;
  };
} // namespace detinfo

DECLARE_ART_SERVICE_INTERFACE(detinfo::PositionDistorterService, SHARED)

#endif // POSITIONDISTORTERSERVICE_H
