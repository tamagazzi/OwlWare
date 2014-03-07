#ifndef __PatchController_h__
#define __PatchController_h__

#include "PatchProcessor.h"
#include "owlcontrol.h"

class PatchController;
extern PatchController patches;

class PatchController {
public:  
  PatchController();
  ~PatchController();
  void init();
  void process(AudioBuffer& buffer);
  void setPatch(LedPin slot, uint8_t index);
  LedPin getActiveSlot();
  void toggleActiveSlot();
  void setActiveSlot(LedPin slot);
  PatchProcessor* getCurrentPatchProcessor();
private:
  void processParallel(AudioBuffer& buffer);
  PatchProcessor green;
  PatchProcessor red;
  LedPin activeSlot = NONE;
  uint8_t mode;
};

#endif // __PatchController_h__
