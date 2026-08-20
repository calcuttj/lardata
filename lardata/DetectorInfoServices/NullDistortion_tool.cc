////////////////////////////////////////////////////////////////////////
// \file NullDistortion_tool.cc
//
// Registers detinfo::NullDistortion as an art tool so it can be loaded as a
// link of a ChainedDistortion via art::make_tool<detinfo::IDistortion>.
////////////////////////////////////////////////////////////////////////

#include "lardataalg/DetectorInfo/NullDistortion.h"

#include "art/Utilities/ToolMacros.h"

DEFINE_ART_CLASS_TOOL(detinfo::NullDistortion)
