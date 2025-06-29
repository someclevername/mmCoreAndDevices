///////////////////////////////////////////////////////////////////////////////
// FILE:          ASICRISP.h
// PROJECT:       Micro-Manager
// SUBSYSTEM:     DeviceAdapters
//-----------------------------------------------------------------------------
// DESCRIPTION:   ASI CRISP autofocus device adapter
//
// COPYRIGHT:     Applied Scientific Instrumentation, Eugene OR
//
// LICENSE:       This file is distributed under the BSD license.
//
//                This file is distributed in the hope that it will be useful,
//                but WITHOUT ANY WARRANTY; without even the implied warranty
//                of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
//                IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//                CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//                INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES.
//
// AUTHOR:        Jon Daniels (jon@asiimaging.com) 09/2013
//
// BASED ON:      ASIStage.h and others
//

#ifndef ASICRISP_H
#define ASICRISP_H

#include "ASIPeripheralBase.h"
#include "MMDevice.h"
#include "DeviceBase.h"

class CCRISP : public ASIPeripheralBase<CAutoFocusBase, CCRISP>
{
public:
   CCRISP(const char* name);
   ~CCRISP() { }
  
   // Device API
   // ----------
   int Initialize();
   bool Busy();

   // AutoFocus API
   // -------------
   int SetContinuousFocusing(bool state);
   int GetContinuousFocusing(bool& state);
   bool IsContinuousFocusLocked();
   int FullFocus();
   int IncrementalFocus();
   int GetLastFocusScore(double& score);
   int GetCurrentFocusScore(double& score);
   int GetOffset(double& offset);
   int SetOffset(double offset);

   // action interface
   // ----------------
   int OnRefreshProperties (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnFocusState        (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnWaitAfterLock     (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnNA                (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnCalGain           (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnCalRange(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnLockRange         (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnLEDIntensity      (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnLoopGainMultiplier(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnNumAvg            (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnSNR               (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnDitherError	   (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnLogAmpAGC         (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnNumSkips          (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnInFocusRange      (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnSum		       (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnOffset			   (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnState	           (MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnSetLogAmpAGC(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnSetLockOffset(MM::PropertyBase* pProp, MM::ActionType eAct);
   // For backwards compatibility with Tiger firmware < 3.40
   int OnSumLegacy(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnDitherErrorLegacy(MM::PropertyBase* pProp, MM::ActionType eAct);

private:
   std::string axisLetter_;
   std::string focusState_;
   long waitAfterLock_;

   int UpdateFocusState();
   int SetFocusState(const std::string& focusState);
   int ForceSetFocusState(const std::string& focusState);
};

#endif // ASICRISP_H
