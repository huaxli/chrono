// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Alessandro Tasora, Radu Serban
// =============================================================================

#ifndef CHC_CONE_H
#define CHC_CONE_H

#include "chrono/geometry/ChGeometry.h"

namespace chrono {
namespace geometry {

/// A conical geometric object for collisions and visualization.

class ChApi ChCone : public ChGeometry {
    // Chrono simulation of RTTI, needed for serialization
    CH_RTTI(ChCone, ChGeometry);

  public:
    ChVector<> center;  ///< base center
    ChVector<> rad;     ///< cone radius

  public:
    ChCone() : center(VNULL), rad(0) {}
    ChCone(ChVector<>& mc, ChVector<> mrad) : center(mc), rad(mrad) {}
    ChCone(const ChCone& source);
    ~ChCone() {}

    /// "Virtual" copy constructor (covariant return type).
    virtual ChCone* Clone() const override { return new ChCone(*this); }

    virtual GeometryType GetClassType() const override { return CONE; }

    virtual void GetBoundingBox(double& xmin,
                                double& xmax,
                                double& ymin,
                                double& ymax,
                                double& zmin,
                                double& zmax,
                                ChMatrix33<>* Rot = NULL) const override {
        //// TODO
    }

    virtual ChVector<> Baricenter() const override { return center; }

    virtual void CovarianceMatrix(ChMatrix33<>& C) const override {
        //// TODO
    }

    /// This is a solid
    virtual int GetManifoldDimension() const override { return 3; }

    virtual void ArchiveOUT(ChArchiveOut& marchive) override {
        // version number
        marchive.VersionWrite(1);
        // serialize parent class
        ChGeometry::ArchiveOUT(marchive);
        // serialize all member data:
        marchive << CHNVP(center);
        marchive << CHNVP(rad);
    }

    /// Method to allow de serialization of transient data from archives.
    virtual void ArchiveIN(ChArchiveIn& marchive) override {
        // version number
        int version = marchive.VersionRead();
        // deserialize parent class
        ChGeometry::ArchiveIN(marchive);
        // stream in all member data:
        marchive >> CHNVP(center);
        marchive >> CHNVP(rad);
    }
};

}  // end namespace geometry
}  // end namespace chrono

#endif
