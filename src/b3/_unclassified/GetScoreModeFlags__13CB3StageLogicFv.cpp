// Hand-written; the lifter refused it (a163 tiny).

class CB3StageLogic { public: int GetAIMode(); int GetCheckpointMarkerFlags(); int GetScoreModeFlags(); void SetFirstResultsPageContinuePressed(); void SetSecondResultsPageContinuePressed(); float GetTotalScore(); void IncrementTotalScore(float); };
// 0x00134360
int CB3StageLogic::GetScoreModeFlags() { return -1; }
