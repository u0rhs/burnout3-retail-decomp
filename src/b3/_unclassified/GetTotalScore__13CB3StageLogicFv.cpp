// Hand-written; the lifter refused it (a163 tiny).

class CB3StageLogic { public: int GetAIMode(); int GetCheckpointMarkerFlags(); int GetScoreModeFlags(); void SetFirstResultsPageContinuePressed(); void SetSecondResultsPageContinuePressed(); float GetTotalScore(); void IncrementTotalScore(float); };
// 0x001343E0
float CB3StageLogic::GetTotalScore() { return 1.0f; }
