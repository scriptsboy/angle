//
// Copyright (c) 2017 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Regardless of the shader type, the following AST transformations are applied:
// - Add declaration of View_ID_OVR.
// - Replace every occurrence of gl_ViewID_OVR with ViewID_OVR, mark ViewID_OVR as internal and
// declare it as a flat varying.
//
// If the shader type is a vertex shader, the following AST transformations are applied:
// - Replace every occurrence of gl_InstanceID with InstanceID, mark InstanceID as internal and set
// its qualifier to EvqTemporary.
// - Add initializers of ViewID_OVR and InstanceID to the beginning of the body of main. The pass
// should be executed before any variables get collected so that usage of gl_InstanceID is recorded.
// - If the output is ESSL or GLSL and the SH_SELECT_VIEW_IN_NV_GLSL_VERTEX_SHADER option is
// enabled, the expression "gl_ViewportIndex = int(ViewID_OVR)" is added after ViewID and InstanceID
// are initialized.
//

#ifndef COMPILER_TRANSLATOR_DECLAREANDINITBUILTINSFORINSTANCEDMULTIVIEW_H_
#define COMPILER_TRANSLATOR_DECLAREANDINITBUILTINSFORINSTANCEDMULTIVIEW_H_

#include "GLSLANG/ShaderLang.h"
#include "angle_gl.h"

class TIntermBlock;

namespace sh
{

void DeclareAndInitBuiltinsForInstancedMultiview(TIntermBlock *root,
                                                 unsigned numberOfViews,
                                                 GLenum shaderType,
                                                 ShCompileOptions compileOptions,
                                                 ShShaderOutput shaderOutput);

}  // namespace sh

#endif  // COMPILER_TRANSLATOR_DECLAREANDINITBUILTINSFORINSTANCEDMULTIVIEW_H_