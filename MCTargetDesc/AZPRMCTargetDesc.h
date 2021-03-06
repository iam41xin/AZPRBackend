//===-- AZPRMCTargetDesc.h - AZPR Target Descriptions -----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides AZPR specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef SAMPLEMCTARGETDESC_H
#define SAMPLEMCTARGETDESC_H

#include "llvm/Support/DataTypes.h"
#include "llvm/Support/Debug.h"

namespace llvm {
class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCObjectWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class StringRef;
class Target;
class raw_ostream;

extern Target TheAZPRTarget;

MCCodeEmitter *createAZPRMCCodeEmitter(const MCInstrInfo &MCII,
                                         const MCRegisterInfo &MRI,
                                         const MCSubtargetInfo &STI,
                                         MCContext &Ctx);

MCAsmBackend *createAZPRAsmBackend(const Target &T, StringRef TT, StringRef CPU);

MCObjectWriter *createAZPRELFObjectWriter(raw_ostream &OS,
                                            uint8_t OSABI);
} // End llvm namespace

// Defines symbolic names for AZPR registers.  This defines a mapping from
// register name to register number.
#define GET_REGINFO_ENUM
#include "AZPRGenRegisterInfo.inc"

// Defines symbolic names for the AZPR instructions.
#define GET_INSTRINFO_ENUM
#include "AZPRGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "AZPRGenSubtargetInfo.inc"

#endif
