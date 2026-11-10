// Hand-written; the lifter refused it (a163 tiny).

class CB3StageLogic { public: int GetAIMode(); int GetCheckpointMarkerFlags(); int GetScoreModeFlags(); void SetFirstResultsPageContinuePressed(); void SetSecondResultsPageContinuePressed(); float GetTotalScore(); void IncrementTotalScore(float); };
// 0x00134350
int CB3StageLogic::GetCheckpointMarkerFlags() { return 3; }
