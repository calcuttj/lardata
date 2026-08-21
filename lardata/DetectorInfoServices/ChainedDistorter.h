////////////////////////////////////////////////////////////////////////
// \file ChainedDistorter.h
//
// \brief IPositionDistorter that composes an ordered set of IDistortion
//        links as a first-match chain of responsibility.
//
// Each link is an art tool (detinfo::IDistortion) loaded from a fhicl
// "Links" sequence via art::make_tool. For a given point, Distort()/Correct()
// hand it to the first link whose PointValidForDistort()/PointValidForCorrect()
// returns true and return that link's transform; if no link applies, the
// point is returned unchanged (identity). ChainedDistorter is itself an
// IPositionDistorter (a total transform, consumed by DetectorProperties); it
// is deliberately NOT an IDistortion, so it can never be nested as a link and
// no recursion is possible.
//
////////////////////////////////////////////////////////////////////////
#ifndef LARDATA_DETINFOSERVICES_CHAINEDDISTORTER_H
#define LARDATA_DETINFOSERVICES_CHAINEDDISTORTER_H

#include "lardataalg/DetectorInfo/IDistortion.h"
#include "lardataalg/DetectorInfo/IPositionDistorter.h"

#include "art/Utilities/make_tool.h"
#include "fhiclcpp/ParameterSet.h"

#include <memory>
#include <vector>

namespace detinfo {

  class ChainedDistorter : public IPositionDistorter {
  public:
    explicit ChainedDistorter(fhicl::ParameterSet const& pset)
    {
      // Each entry of "Links" is a tool pset (must carry "tool_type"). Order
      // is the first-match priority order.
      for (auto const& linkPset :
           pset.get<std::vector<fhicl::ParameterSet>>("Links", {})) {
        fLinks.push_back(art::make_tool<detinfo::IDistortion>(linkPset));
      }
      for (size_t i = 0; i+1 < fLinks.size(); ++i) {
        fLinks[i]->SetNextDistortion(fLinks[i+1].get());
      }
    }

    geo::Point_t Distort(geo::Point_t const& point) const override
    {
      return (
        fLinks.empty() ?
        point :
        fLinks.front()->Distort(point)
      );
    }

    geo::Point_t Correct(geo::Point_t const& point) const override
    {
      return (
        fLinks.empty() ?
        point :
        fLinks.front()->Correct(point)
      );
    }

  private:
    std::vector<std::unique_ptr<detinfo::IDistortion>> fLinks;
  }; // class ChainedDistorter

} // namespace detinfo

#endif // LARDATA_DETINFOSERVICES_CHAINEDDISTORTER_H
