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

#include "chrono/motion_functions/ChFunction_Repeat.h"

namespace chrono {

// Register into the object factory, to enable run-time dynamic creation and persistence
ChClassRegister<ChFunction_Repeat> a_registration_repeat;

ChFunction_Repeat::ChFunction_Repeat() : window_start(0), window_length(1) {
    fa = std::make_shared<ChFunction_Const>();  // default
}

ChFunction_Repeat::ChFunction_Repeat(const ChFunction_Repeat& other) {
    window_start = other.window_start;
    window_length = other.window_length;
    fa = std::shared_ptr<ChFunction>(other.fa->Clone());
}

double ChFunction_Repeat::Get_y(double x) const {
    return fa->Get_y(this->window_start + fmod(x, this->window_length));
}

void ChFunction_Repeat::Estimate_x_range(double& xmin, double& xmax) const {
    fa->Estimate_x_range(xmin, xmax);
}

}  // end namespace chrono
